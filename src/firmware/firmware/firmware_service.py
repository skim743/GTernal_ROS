from .gritsbotserial import GritsbotSerial
import os
import json
import time
import netifaces
# import subprocess
import rclpy
from rclpy.node import Node
from firmware_interfaces.msg import Status
from firmware_interfaces.msg import Input
from ament_index_python.packages import get_package_share_directory


# Constants
MAX_QUEUE_SIZE = 100
LOW_BATT_THRESHOLD = 3900.0 # Low battery threshold voltage in mV
BATT_VOLT_WINDOW = 30 # Time window in seconds for the moving average of the battery voltage. Currently, it is set to 1 sample per second.

global timer_period
timer_period = 0.033 # In seconds

def get_mac():
    """Gets the MAC address for the robot from the network config info.

    Returns:
        str: A MAC address for the robot.

    Example:
        >>> print(get_mac())
        AA:BB:CC:DD:EE:FF

    """

    # interface = [x for x in netifaces.interfaces() if 'eth0' in x][0]
    interface = [x for x in netifaces.interfaces() if 'wlan' in x][0]
    return netifaces.ifaddresses(interface)[netifaces.AF_LINK][0]['addr']

def get_robot_id(mac_address, mac_list):
    """Gets the robot ID from the MAC address.

    Args:
        mac_address (str): The MAC address of the robot.
        mac_list (dict): A dictionary mapping MAC addresses to robot IDs.

    Returns:
        str: The robot ID.

    Example:
        >>> print(get_robot_id('AA:BB:CC:DD:EE:FF', {'AA:BB:CC:DD:EE:FF': 'robot1'}))
        robot1

    """

    if(mac_address in mac_list):
        return mac_list[mac_address]
    else:
        print('MAC address {} not in supplied MAC list file'.format(mac_address))
        raise ValueError()

class Robot(Node):
    def __init__(self, robot_id, mac_address):
        super().__init__('GTernal' + robot_id)
        self.serial = None
        self.status_data = {'batt_volt': -1, 'charge_status': False, 'bus_volt': -1, 'bus_current': -1, 'power': -1}
        self.input_data = {'v': 0, 'w': 0, 'left_led': [0, 0, 0], 'right_led': [0, 0, 0]}
        self.input_time = time.time()
        self.input_time_old = time.time()

        # Create publisher for status data
        self.publisher_ = self.create_publisher(Status, 'GTernal' + robot_id + '/status', 10)
        self.timer_period = timer_period
        self.timer = self.create_timer(self.timer_period, self.update_status)

        # Create subscriber for input data
        # self.service = self.create_service(Status, 'GTernal' + robot_id + '/status', self.status_callback)
        self.subscription = self.create_subscription(Input, 'GTernal' + robot_id + '/publish', self.input_callback, 10)
        self.subscription # To prevent unused variable warning
        self.get_logger().info('This is robot: ({0}) with MAC address: ({1})'.format(robot_id, mac_address))

    def begin_serial(self):
        started = False
        while (not started):
            self.serial = GritsbotSerial(serial_dev='/dev/ttyAMA0', baud_rate=500000)
            try:
                self.serial.start()
                started = True
            except Exception as e:
                # This class stops itself if the device cannot be initially acquired, so we don't need to stop it.
                self.get_logger().critical('Could not acquire serial device.')
                self.get_logger().critical(repr(e))

            # Don't try to acquire the serial device too quickly
            time.sleep(1)

        self.get_logger().info('Acquired serial device.')

    def update_status(self):
        # Serial requests
        request = Request()
        handlers = []

        # Reset status data
        self.status_data = {'batt_volt': -1, 'charge_status': False, 'bus_volt': -1, 'bus_current': -1, 'power': -1}

        # Retrieve status data: battery voltage and charging status
        request.add_read_request('batt_volt').add_read_request('charge_status')
        request.add_read_request('bus_volt').add_read_request('bus_current').add_read_request('power')
        handlers.append(lambda status, body: handle_read_response('batt_volt', status, body))
        handlers.append(lambda status, body: handle_read_response('charge_status', status, body))
        handlers.append(lambda status, body: handle_read_response('bus_volt', status, body))
        handlers.append(lambda status, body: handle_read_response('bus_current', status, body))
        handlers.append(lambda status, body: handle_read_response('power', status, body))

        # Check if new input data has been received and update the serial request
        if (self.input_time is not self.input_time_old):
            request.add_write_request('motor', {'v': self.input_data['v'], 'w': self.input_data['w']})
            handlers.append(handle_write_response)

            request.add_write_request('left_led', {'rgb': self.input_data['left_led']})
            handlers.append(handle_write_response)

            request.add_write_request('right_led', {'rgb': self.input_data['right_led']})
            handlers.append(handle_write_response)

            # Update the input time
            self.input_time_old = self.input_time

        # Write to serial port
        teensy_response = None
        if(len(handlers) > 0 and self.serial._serial.is_open):
            try:
                teensy_response = self.serial.serial_request(request.to_json_encodable())
            except Exception as e:
                self.get_logger().critical('Serial exception.')
                self.get_logger().critical(e)

        # Call handlers
        # We'll have a status and body for each request
        if(teensy_response is not None and 'status' in teensy_response and 'body' in teensy_response
           and len(teensy_response['status']) == len(handlers) and len(teensy_response['body']) == len(handlers)):
            status = teensy_response['status']
            body = teensy_response['body']
            # Ensure the appropriate handler gets each teensy_response
            for i, handler in enumerate(handlers):
                self.status_data.update(handler(status[i], body[i]))

            # Publish status data
            msg = Status()
            msg.batt_volt = self.status_data['batt_volt']
            msg.charge_status = self.status_data['charge_status']
            msg.bus_volt = self.status_data['bus_volt']
            msg.bus_current = self.status_data['bus_current']
            msg.power = self.status_data['power']

            # Log status data
            self.get_logger().info('Status data ({})'.format(self.status_data))
            self.get_logger().info('Response ({})'.format(teensy_response))
            # logger.info('Battery Voltage ({})'.format(status_data['bus_volt']))
            # logger.info('Length of handlers ({})'.format(len(handlers))) # For debugging
        else:
            # If we should have teensy_responses, but we don't
            if(len(handlers) > 0):
                self.get_logger().critical('Malformed response ({})'.format(teensy_response))
                self.get_logger().info('Length of handlers ({})'.format(len(handlers)))
    
    def input_callback(self, input_msg):
        # Update input data
        self.input_data['v'] = input_msg.v
        self.input_data['w'] = input_msg.w
        self.input_data['left_led'] = input_msg.left_led.tolist()
        self.input_data['right_led'] = input_msg.right_led.tolist()

        # Update input time
        self.input_time = time.time()


class Request:
    """Represents serial requests to the microcontroller.

    The serial communications operate on a request/response architecture.  For example, the request is of a form (when JSON encoded)

    .. code-block:: python

        {'request': ['read', 'write', 'read'], 'iface': [iface1, iface2, iface3], body: [body1, body2, body3]}

    Attributes:
        request (list): A list of requests (or actions) to perform.  Must be 'read' or 'write'.
        iface (list): A list of interfaces on which to perform the request
        body (list): A list of bodies for the requests.  These are empty if the request is a read.

    """

    def __init__(self):
        """Initializes a request with optional iface, request, and body parameters.

        Returns:
            The created request.

        """
        self.iface = []
        self.request = []
        self.body = []

    def add_write_request(self, iface, body):
        """Adds a write to the request.

        Args:
            iface (str): The interface to write.
            body (dict): A JSON-encodable body to be written.

        Returns:
            The modified request containing the new interface and body.

        Examples:
            >>> r = Request().add_write_request('motor', {'v': 0.1, 'w': 0.0})

        """

        self.iface.append(iface)
        self.request.append('write')
        self.body.append(body)

        return self

    def add_read_request(self, iface):
        """Adds a read to the request.

        Args:
            iface (str): Interface from which to read.

        Returns:
            The request with the added read.

        """

        self.iface.append(iface)
        self.request.append('read')
        self.body.append({})

        return self

    def to_json_encodable(self):
        """Turns the request into a JSON-encodable dict.

        Raises:
            Exception: If an underlying body element is not JSON-encodable.

        Returns:
            dict: A JSON-encodable dict representing the request.

        """

        req = {'request': self.request, 'iface': self.iface}

        if(self.body):
            req['body'] = self.body

        return req


def handle_write_response(status, body):
    return {}


def handle_read_response(iface, status, body):

    if(iface in body):
        return {iface: body[iface]}
    else:
        logger.critical('Request for ({0}) not in body ({1}) after request.'.format(iface, body))
        return {}

def avgVoltage(battVoltArray, voltNew, battVoltIndx, chargeStatusArray, statusNew):
    battVoltArray[battVoltIndx] = voltNew
    avgVolt = sum(battVoltArray)/len(battVoltArray)
    chargeStatusArray[battVoltIndx] = statusNew

    battVoltIndx = battVoltIndx + 1
    if battVoltIndx >= BATT_VOLT_WINDOW:
        battVoltIndx = 0

    return avgVolt, battVoltIndx

def main():
    # Retrieve the MAC address for the robot
    mac_address = get_mac()

    # Retrieve the MAC list file, containing a mapping from MAC address to robot ID
    # package_path = get_package_share_directory('firmware')
    # mac_list_file = os.path.join(package_path, 'config', 'mac_list.json')
    mac_list_file = '/home/GTernal_ROS/src/firmware/config/mac_list.json'
    try:
        with open(mac_list_file, 'r') as f:
            mac_list = json.load(f)
    except Exception as e:
        print(repr(e))
        print('Could not open file ({})'.format(mac_list_file))

    if(mac_address in mac_list):
        robot_id = mac_list[mac_address]
    else:
        print('MAC address {} not in supplied MAC list file'.format(mac_address))
        raise ValueError()

    rclpy.init()

    robot_node = Robot(robot_id, mac_address)
    robot_node.begin_serial()

    rclpy.spin(robot_node)

    rclpy.shutdown()

# def main():

#     parser = argparse.ArgumentParser()
#     parser.add_argument("mac_list", help="JSON file containing MAC to id mapping")
#     parser.add_argument("-port", type=int, help="MQTT Port", default=8080)
#     parser.add_argument("-host", help="MQTT Host IP", default="localhost")
#     parser.add_argument('-update_rate', type=float, help='Update rate for robot main loop', default=0.016)
#     parser.add_argument('-status_update_rate', type=float, help='How often to check status info', default=1)

    # Parser and set CLI arguments
#     args = parser.parse_args()
#     update_rate = args.update_rate
#     status_update_rate = args.status_update_rate

#     started = False
#     serial = None
#     while (not started):
#         serial = gritsbotserial.GritsbotSerial(serial_dev='/dev/ttyAMA0', baud_rate=500000)
#         try:
#             serial.start()
#             started = True
#         except Exception as e:
#             # This class stops itself if the device cannot be initially acquired, so we don't need to stop it.
#             logger.critical('Could not acquire serial device.')
#             logger.critical(repr(e))

#         # Don't try to acquire the serial device too quickly
#         time.sleep(1)

#     logger.info('Acquired serial device.')

#     # Create node descriptor for robot and set up links
#     node_descriptor = create_node_descriptor(mac_list[mac_address])
#     status_link = robot_id + '/status'
#     input_link = 'matlab_api/' + robot_id

#     started = False
#     robot_node = None
#     while (not started):
#         robot_node = node.Node(args.host, args.port, node_descriptor)
#         try:
#             robot_node.start()
#             started = True
#         except Exception as e:
#             logger.critical('Could not start robot node.')
#             logger.critical(repr(e))
#             robot_node.stop()

#         # Don't try to make nodes too quickly
#         time.sleep(1)

#     logger.info('Started robot node.')



#     # Queues for STREAM links
#     inputs = robot_node.subscribe(input_link)

#     # Initialize times for various activities
#     start_time = time.time()
#     print_time = time.time()
#     status_update_time = time.time()

#     # Fast charging
#     battVoltArray = [0]*BATT_VOLT_WINDOW
#     battVoltIndx = 0
#     battThreshold = LOW_BATT_THRESHOLD
#     chargeStatusArray = [0]*BATT_VOLT_WINDOW

#     # Initialize data
#     status_data = {'batt_volt': -1, 'charge_status': False, 'bus_volt':-1, 'bus_current':-1, 'power':-1}
#     last_input_msg = {}

#     # Main loop for the robot
#     serial._serial.reset_input_buffer()
#     serial._serial.reset_output_buffer()
#     while True:
#         start_time = time.time()

#         # Serial requests
#         request = Request()
#         handlers = []

#         # Retrieve status data: battery voltage and charging status
#         if((start_time - status_update_time) >= status_update_rate):
#             request.add_read_request('batt_volt').add_read_request('charge_status')
#             request.add_read_request('bus_volt').add_read_request('bus_current').add_read_request('power')
#             handlers.append(lambda status, body: handle_read_response('batt_volt', status, body))
#             handlers.append(lambda status, body: handle_read_response('charge_status', status, body))
#             handlers.append(lambda status, body: handle_read_response('bus_volt', status, body))
#             handlers.append(lambda status, body: handle_read_response('bus_current', status, body))
#             handlers.append(lambda status, body: handle_read_response('power', status, body))

#             if status_data['bus_volt'] > 0:
#                 avgVolt, battVoltIndx = avgVoltage(battVoltArray, status_data['bus_volt'], battVoltIndx, chargeStatusArray, status_data['charge_status'])
#                 logger.info('avgVolt = ({})'.format(avgVolt))

#             status_update_time = start_time

#         # Process input commands
#         input_msg = None
#         # Make sure that the queue has few enough messages
#         if(inputs.qsize() > MAX_QUEUE_SIZE):
#             logger.critical('Queue of motor messages is too large.')

#         try:
#             # Clear out the queue
#             while True:
#                 input_msg = inputs.get_nowait()
#         except queue.Empty:
#             pass

#         if(input_msg is not None):
#             try:
#                 input_msg = json.loads(input_msg.decode(encoding='UTF-8'))
#             except Exception as e:
#                 logger.warning('Got malformed JSON motor message ({})'.format(input_msg))
#                 logger.warning(e)
#                 # Set this to None for the next checks
#                 input_msg = None

#         # If we got a valid JSON input msg, look for appropriate commands
#         if(input_msg is not None):
#             last_input_msg = input_msg
#             if('v' in input_msg and 'w' in input_msg):
#                 # Handle response?
#                 request.add_write_request('motor', {'v': input_msg['v'], 'w': input_msg['w']})
#                 handlers.append(handle_write_response)

#             if('left_led' in input_msg):
#                 request.add_write_request('left_led', {'rgb': input_msg['left_led']})
#                 handlers.append(handle_write_response)

#             if('right_led' in input_msg):
#                 request.add_write_request('right_led', {'rgb': input_msg['right_led']})
#                 handlers.append(handle_write_response)

#         # Write to serial port
#         response = None
#         if(len(handlers) > 0 and serial._serial.is_open):
#             try:
#                 response = serial.serial_request(request.to_json_encodable())
#             except Exception as e:
#                 logger.critical('Serial exception.')
#                 logger.critical(e)

#         # Call handlers
#         # We'll have a status and body for each request
#         if(response is not None and 'status' in response and 'body' in response
#            and len(response['status']) == len(handlers) and len(response['body']) == len(handlers)):
#             status = response['status']
#             body = response['body']
#             # Ensure the appropriate handler gets each response
#             for i, handler in enumerate(handlers):
#                 status_data.update(handler(status[i], body[i]))
#             logger.info('Status data ({})'.format(status_data))
#             logger.info('Response ({})'.format(response))
#             # logger.info('Battery Voltage ({})'.format(status_data['bus_volt']))
#             # logger.info('Length of handlers ({})'.format(len(handlers))) # For debugging
#         else:
#             # If we should have responses, but we don't
#             if(len(handlers) > 0):
#                 logger.critical('Malformed response ({})'.format(response))
#                 logger.info('Length of handlers ({})'.format(len(handlers)))

#         robot_node.put(status_link, json.dumps(status_data))

#         # If the average battery voltage is below the threshold, and the robot is being charged, enter fast charging mode
#         if not 0 in battVoltArray and avgVolt < battThreshold and not 0 in chargeStatusArray:
#             logger.info('Charging battery voltage for 30 seconds: ({0}) mV < ({1}) mV. Entering fast charging mode'.format(round(avgVolt, 2), battThreshold))

#             # Signal Teensy that Raspberry Pi is entering fast charging mode
#             request = Request()
#             request.add_write_request('fast_charge', {})
#             handlers.append(handle_write_response)
#             response = None
#             if(len(handlers) > 0 and serial._serial.is_open):
#                 try:
#                     response = serial.serial_request(request.to_json_encodable())
#                 except Exception as e:
#                     logger.critical('Serial exception.')
#                     logger.critical(e)

#             # Shut down the Raspberry Pi through ssh from the firmware Docker image
#             cmd = ['sshpass', '-p', 'raspberry', 'ssh', '-o', 'UserKnownHostsFile=/dev/null', '-o', 'StrictHostKeyChecking=no', 'pi@localhost', 'sudo shutdown now']
#             pid = subprocess.Popen(cmd, stdout=subprocess.PIPE)
#             pid.communicate()

#         # # Print out status data
#         # if((start_time - print_time) >= status_update_rate):
#         #     logger.info('Status data ({})'.format(status_data))
#         #     logger.info('Last input message received ({})'.format(last_input_msg))
#         #     print_time = time.time()

#         # Sleep for whatever time is left at the end of the loop
#         time.sleep(max(0, update_rate - (time.time() - start_time)))


if __name__ == '__main__':
    main()
