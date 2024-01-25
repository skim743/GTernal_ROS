#!/bin/bash

sudo docker run -it \
           --rm \
           --net host \
	   --device $(sudo -u pi python3 detect_serial.py):/dev/ttyAMA0 \
	   -w /home/GTernal_ROS \
           skim743/gternal-ros:latest