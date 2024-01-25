# GTernal_ROS
Prototype firmware development repo for GTernal in ROS 2 (Humble). The firmware is containerized in a Docker image.

# Overview
There are two versions of the Docker image. One of them is built for arm64 processors, and this version is to be run on robots. The other version is built for amd64 processors, and this is run on the main computer.

> [!NOTE]
> Currently, ROS2 messages cannot be exchanged from Mac and Windows machines to Linux machines and vice versa. This is because Mac and Windows machines run Docker desktop which is pretty much a virtual machine, and Docker desktop does not have the feature to set the network settings for a Docker image to that of the host machine using '--net host' flag.

# How to use
## Using the current version of the firmware
### On a robot (RPi)
1. Clone this repository to '~/git/' directory
```
cd git/
git clone https://github.com/skim743/GTernal_ROS.git
```
2. Move to the cloned repo 
```
cd GTernal_ROS/arm64
```
3. Run the firmware Docker image
```
./docker_run.sh
```
This will pull and run the firmware Docker image currently pushed to my account on the Docker Hub.
4. Source the ROS 2 environment
```
source install/setup.bash
```
5. Run the robot firmware
```
ros2 run firmware service
```

### On the main computer (Linux)
1. Clone this repository to '~/git/' directory
```
cd git/
git clone https://github.com/skim743/GTernal_ROS.git
```
2. Move to the cloned repo 
```
cd GTernal_ROS/amd64
```
3. Run the firmware Docker image
```
./docker_run.sh
```
This will pull and run the firmware Docker image currently pushed to my account on the Docker Hub.
4. Source the ROS 2 environment
```
source install/setup.bash
```
5. Request Status & Publish Commands
To request the status of a robot
```
ros2 run firmware client <robot-id>
```
(ex) ros2 run firmware client 101
To publish motor commands to a robot
```
ros2 run firmware publisher <robot-id> <command>
```
(ex:motor command) ros2 run firmware publisher 101 '{"v":0.0,"w":1.0}'
(ex:led command) ros2 run firmware publisher 101 '{"right_led":[0,255,0]}'
(ex:mixed) ros2 run firmware publisher 101 '{"v":0.0,"w":1.0,"right_led":[0,255,0]}'