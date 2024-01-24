#!/bin/bash

docker run -it \
           --rm \
           --net host \
           firmware_ros:latest \