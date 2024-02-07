import time
import json
# import argparse
# import vizier.node as node
import vrpn
import math
# import threading
# import concurrent.futures as futures
# import logging
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from firmware_interfaces.msg import Position

# global logger
# logging.basicConfig(format='%(asctime)s - %(levelname)s - %(module)s - %(message)s')
# logger = logging.getLogger('root')
# logger.setLevel(logging.DEBUG)

# The IP address of the computer running the VRPN server (Vicon computer)
global tracker_host
tracker_host = "143.215.159.25"

# Timeout for VRPN data in seconds
# timeout = 10

# tracker data dictionary
# Add one to actually include max value
# global robot_data
# global robot_data_lock
# global getting_data
# global robots

# robot_data = {}
# robot_data_lock = threading.Lock()
# getting_data = {}
# robots = []


# def create_vrpn_handler(node):
#     """Creates and returns a function that represents a data handler for incoming VRPN data.

#     Args:
#         robot_name:

#     Returns:

#     """
#     # TODO: Round sent numbers to millimeter or something
#     def f(user_data, msg):
#         global robot_data
#         global getting_data

#         # Position data is in x y z format
#         robot_data['x'] = round(msg['position'][0], 3)
#         robot_data['y'] = round(msg['position'][1], 3)
#         (qx, qy, qz, qw) = msg['quaternion']

#         robot_data['theta'] = round(math.atan2(2.0*(qw*qz + qx*qy), 1.0 - 2.0*(qy*qy + qz*qz)), 3)

#         # Set last time we got VRPN data.  Used in timeout detection later
#         getting_data['vrpn'] = time.time()

#     return f

class TrackerNode(Node):
    def __init__(self, robot_id):
        super().__init__('overhead_tracker' + robot_id)
        self.getting_data = dict({'vrpn': time.time()})
        self.robot_data = dict({'x': 0, 'y': 0, 'theta': 0})

        # Create all VRPN callbacks for receiving position data
        self.tracker = vrpn.receiver.Tracker(robot_id+"@"+tracker_host)
        self.tracker_cb = None
        
        # Create publisher for position data
        self.publisher_ = self.create_publisher(Position, 'GTernal' + robot_id + '/position', 10)
        self.timer_period = 0.033  # seconds
        self.timer = self.create_timer(self.timer_period, self.update_position)

        # Initialize the timer for checking VRPN data timeout
        self.current_time = time.time()
        self.timeout = 10 # VRPN data timeout in seconds

        self.get_logger().info('Tracker node for GTernal ({0}) initialized'.format(robot_id))
        time.sleep(0.1) # Don't try to make nodes too quickly

    def create_vrpn_handler(self):
        def f(user_data, msg):
            self.robot_data['x'] = round(msg['position'][0], 3)
            self.robot_data['y'] = round(msg['position'][1], 3)
            (qx, qy, qz, qw) = msg['quaternion']

            self.robot_data['theta'] = round(math.atan2(2.0*(qw*qz + qx*qy), 1.0 - 2.0*(qy*qy + qz*qz)), 3)

            # Set last time we got VRPN data.  Used in timeout detection later
            self.getting_data['vrpn'] = time.time()

        return f
    
    def register_vrpn_handler(self):
        self.tracker_cb = self.create_vrpn_handler()
        self.tracker.register_change_handler(None, self.tracker_cb, "position")

    def update_position(self):
        self.tracker.mainloop()
        if(self.current_time - self.getting_data['vrpn'] <= self.timeout):
            msg = Position()
            msg.x = round(self.robot_data['x'], 3)
            msg.y = round(self.robot_data['y'], 3)
            msg.theta = round(self.robot_data['theta'], 3)
            self.publisher_.publish(msg)
        self.current_time = time.time()

def main():

    # parser = argparse.ArgumentParser()
    # parser.add_argument("node_descriptor", help=".json file node information")
    # parser.add_argument("-port", type=int, help="MQTT Port", default=1884)
    # parser.add_argument("-host", help="MQTT Host IP", default="localhost")
    # parser.add_argument("-interval", type=int, help="Publishing interval in milliseconds", default=16)
    # parser.add_argument("-tracker_host", help="Tracking computer (VRPN) IP", default="192.168.10.1")

    # args = parser.parse_args()

    # interval = args.interval/1000

    # Ensure that we can open the nodes file
    node_descriptor_file = '/home/GTernal_ROS/src/firmware/config/mac_list.json'
    node_descriptor = None

    try:
        f = open(node_descriptor_file, 'r')
        node_descriptor = json.load(f)
        f.close()
    except Exception as e:
        print(repr(e))
        print("Couldn't open given node file " + node_descriptor_file)
        return -1
    
    rclpy.init()

    # Initialize tracker nodes
    tracker_node = {}
    for robot_id in node_descriptor.values():
        tracker_node[robot_id] = TrackerNode(robot_id)

    for robot_id in node_descriptor.values():
        tracker_node[robot_id].register_vrpn_handler()

    # Initialize the multi-threaded executor for running tracker nodes
    executor = MultiThreadedExecutor()
    for robot_id in node_descriptor.values():
        executor.add_node(tracker_node[robot_id])

    # Start the tracker nodes
    executor.spin()
    for robot_id in node_descriptor.values():
        tracker_node[robot_id].get_logger().info('Tracker node for GTernal ({0}) started'.format(robot_id))

    # Destroy the nodes
    for robot_id in node_descriptor.values():
        tracker_node[robot_id].destroy_node()

    rclpy.shutdown()
    
    # try:
    #     tracker_node.start()
    # except Exception as e:
    #     print(repr(e))
    #     #print("I'm quitting...")
    #     quit()

    # global robots
    # global robot_data
    # global robot_data_lock
    # global getting_data

    # potential_topics = tracker_node.gettable_links
    # print('Potential available robots: ', potential_topics)
    # robots = list({x.split('/')[0] for x in potential_topics})
    # getting_data = dict({r: {'vrpn': time.time(), 'viz': False} for r in robots})
    # robot_data = dict({r: {'x': 0, 'y': 0, 'theta': 0} for r in robots})

    # executor = futures.ThreadPoolExecutor(max_workers=len(robots))
    # running = True

    # def get_data_task():
    #     global robots
    #     global robot_data
    #     global robot_data_lock
    #     global getting_data
    #     nonlocal executor
    #     nonlocal running

    #     links = list([r+'/status' for r in robots])

    #     while running:
    #         current_time = time.time()
    #         data = []
    #         try:
    #             data = list(executor.map(lambda x: tracker_node.get(x, timeout=0.5, attempts=4), links, timeout=3))
    #         except Exception as e:
    #             print(repr(e))

    #         for i, d in enumerate(data):
    #             r = robots[i]
    #             with robot_data_lock:
    #                 if d is not None:
    #                     try:
    #                         d = json.loads(d)
    #                         robot_data[r].update(d)
    #                         getting_data[r]['viz'] = True
    #                     except Exception as e:
    #                         getting_data[r]['viz'] = False
    #                         print(repr(e))
    #                 else:
    #                     getting_data[r]['viz'] = False

    #         print(data)
    #         # TODO: Make this sleep for at most 2 seconds
    #         time.sleep(max(0, 2 - (time.time() - current_time)))

    # # Start thread to get data for robots
    # robot_data_thread = threading.Thread(target=get_data_task)
    # robot_data_thread.start()

    # # Create all VRPN callbacks for receiving position data
    # vrpn_tuples = {x: (vrpn.receiver.Tracker(x+"@"+args.tracker_host), create_vrpn_handler(x)) for x in robots}
    # for (tracker, tracker_cb) in vrpn_tuples.values():
    #     tracker.register_change_handler(None, tracker_cb, "position")

    # current_time = time.time()

    # while True:

    #     # In this case, we catastrophically delete stuff because Vicon is being
    #     # weird
    #     for v in vrpn_tuples:
    #         #     Call the tracker mainloop
    #         vrpn_tuples[v][0].mainloop()

    #     # Prune for active robots
    #     to_send = {}
    #     for r in robots:
    #         if(getting_data[r]['viz'] and (current_time - getting_data[r]['vrpn']) <= timeout):
    #             to_send[r] = robot_data[r]

    #     with robot_data_lock:
    #         # Send only if we don't have an empty message
    #         if(len(to_send) > 0):
    #             msg = json.dumps(to_send)
    #             msg += ''.join(' ' for __ in range(1500 - len(msg)))
    #             tracker_node.publish('overhead_tracker/all_robot_pose_data', msg)

    #     if(min([current_time - getting_data[x]['vrpn'] for x in robots]) >= timeout):
    #         logger.error('All robots timed out.  Exiting.')
    #         running = False
    #         tracker_node.stop()
    #         quit()

    #     # Wait for the right amount of time
    #     elapsed_time = time.time() - current_time
    #     time.sleep(max(0, interval - elapsed_time))

    #     #print(time.time() - current_time)

    #     current_time = time.time()


if __name__ == "__main__":
    main()
