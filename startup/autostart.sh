#!/bin/bash

echo Add by TungNV
echo cd /home/nhamtung/TungNV/ros_basic_ws/
cd /home/nhamtung/TungNV/ros_basic_ws/
echo source install/setup.bash
source install/setup.bash
echo roslaunch topic_pkg topic_cpp.launch
roslaunch topic_pkg topic_cpp.launch
exit 0