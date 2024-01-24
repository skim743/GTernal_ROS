FROM ros:humble-ros-base

RUN apt-get -y update && apt-get -y upgrade

# Get python + deps.  Most of these are actually for netifaces install
RUN apt-get -y install git python3 python3-dev python3-pip gcc musl-dev net-tools nano

# Get ssh and sshpass for shutting down the Raspberry Pi within a Docker container
RUN apt-get -y install openssh-client sshpass

# Install firmware
RUN cd /home && \
    git clone https://github.com/skim743/GTernal_ROS.git && \
    cd GTernal_ROS/ && \
    sudo chown -R pi:pi GTernal_ROS && \
    rosdep install -i --from-path src --rosdistro humble -y && \
    colcon build --packages-select firmware_interfaces && \
    colcon build --packages-select firmware
