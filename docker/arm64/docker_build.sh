#!/bin/bash

sudo docker build --no-cache \
                  --tag firmware_ros \
                  --platform=linux/arm64/v8 \
                  -f Dockerfile .
