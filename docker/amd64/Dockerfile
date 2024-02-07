FROM ros:humble-ros-base

RUN apt-get -y update && apt-get -y upgrade

# Get python + deps.  Most of these are actually for netifaces install
RUN apt-get -y install git python3 python3-dev python3-pip gcc g++ cmake musl-dev net-tools netbase nano

# Get ssh and sshpass for shutting down the Raspberry Pi within a Docker container
RUN apt-get -y install openssh-client sshpass

# Install firmware
RUN cd /home && \
    git clone https://github.com/skim743/GTernal_ROS.git && \
    cd GTernal_ROS/ && \
    . /opt/ros/humble/setup.sh && \
    rosdep install -i --from-path src --rosdistro humble -y && \
    colcon build --packages-select firmware_interfaces && \
    colcon build --packages-select firmware

# Install VRPN for Vicon Tracker
RUN rm -rf /var/lib/apt/lists/*

ADD https://api.github.com/repos/pglotfel/vrpn/git/refs/heads/master version.json
RUN cd /home && \
git clone https://github.com/pglotfel/vrpn.git && \
cd vrpn && mkdir build && cd build && \
cmake .. && make -j $(($(nproc)-1)) && make install

# VRPN cmake puts this in the wrong place for some reason
RUN cp /usr/local/lib/python3.1/dist-packages/vrpn.so /usr/lib/python3.10/

RUN python3 -m pip uninstall -y paho-mqtt
RUN python3 -m pip install paho-mqtt==1.3.1

RUN cd /home/GTernal_ROS/ && \
    . /opt/ros/humble/setup.sh && \
    colcon build --packages-select vicon_tracker