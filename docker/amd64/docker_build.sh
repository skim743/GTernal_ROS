#!/bin/bash

sudo docker build --no-cache \
                  --tag firmware_ros_amd64 \
                  -f Dockerfile .
