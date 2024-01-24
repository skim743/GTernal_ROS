#!/bin/bash

sudo docker run -it \
           --rm \
           --net host \
	   --device $(sudo -u pi python3 detect_serial.py):/dev/ttyAMA0 \
           skim743/gternal-ros:latest