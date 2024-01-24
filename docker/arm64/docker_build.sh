#!/bin/bash

sudo docker build --no-cache \
                  --tag firmware_ros \
                  -f Dockerfile .
