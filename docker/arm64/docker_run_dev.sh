#!/bin/bash

sudo docker run -it \
                --rm \
	            --platform=linux/arm64/v8 \
                --net host \
                skim743/gternal-ros:latest \