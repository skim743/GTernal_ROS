#!/bin/bash

sudo docker run -it \
                --rm \
                --net host \
	            -w /home/GTernal_ROS \
                skim743/gternal-ros-amd64