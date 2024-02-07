import time
import json
import vrpn
import math
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from firmware_interfaces.msg import Position


# The IP address of the computer running the VRPN server (Vicon computer)
global tracker_host
tracker_host = "143.215.159.25"

# Constants for timing
global timeout # Timeout for VRPN data
global timer_period # Timer for publishing position data
timeout = 10 # In seconds
timer_period = 0.016  # seconds

# Node descriptor file
global node_descriptor_file
node_descriptor_file = '/home/GTernal_ROS/src/firmware/config/mac_list.json'

# Vicon tracker class
class TrackerNode(Node):
    def __init__(self, robot_id):
        super().__init__('overhead_tracker' + robot_id)
        self.getting_data = dict({'vrpn': time.time()})
        self.robot_data = dict({'x': 0.0, 'y': 0.0, 'theta': 0.0})

        # Create all VRPN callbacks for receiving position data
        self.tracker = vrpn.receiver.Tracker(robot_id+"@"+tracker_host)
        self.tracker_cb = None
        
        # Create publisher for position data
        self.publisher_ = self.create_publisher(Position, 'GTernal' + robot_id + '/position', 10)
        self.timer_period = timer_period  # seconds
        self.timer = self.create_timer(self.timer_period, self.update_position)

        # Initialize the timer for checking VRPN data timeout
        self.current_time = time.time()
        self.timeout = timeout # VRPN data timeout in seconds

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

    # Ensure that we can open the nodes file
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


if __name__ == "__main__":
    main()
