#!/bin/bash

sudo docker run -it \
           --rm \
	   --platform=linux/arm64/v8 \
           --net host \
           arm64v8/ros:humble-ros-base \