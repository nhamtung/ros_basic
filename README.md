----------------------------------------------------------------------------------------------
# ros_basic
- Reference link: http://wiki.ros.org/ROS/Tutorials

- Msg/Srv Documentation
    + std_msgs: https://docs.ros.org/en/melodic/api/std_msgs/html/index-msg.html
    + geometry_msgs: https://docs.ros.org/en/noetic/api/geometry_msgs/html/index-msg.html
    + sensor_msgs: https://docs.ros.org/en/noetic/api/sensor_msgs/html/index-msg.html
    + nav_msgs: https://docs.ros.org/en/noetic/api/nav_msgs/html/index-msg.html
    + actionlib_msgs: https://docs.ros.org/en/kinetic/api/actionlib_msgs/html/index-msg.html
    + tf2_msgs: https://docs.ros.org/en/jade/api/tf2_msgs/html/index-msg.html
    + diagnostic_msgs: https://docs.ros.org/en/noetic/api/diagnostic_msgs/html/index-msg.html
    + visualization_msgs: https://docs.ros.org/en/noetic/api/visualization_msgs/html/index-msg.html
    + control_msgs: https://docs.ros.org/en/api/control_msgs/html/index-msg.html
    + trajectory_msgs: https://docs.ros.org/en/noetic/api/trajectory_msgs/html/index-msg.html
    + move_base_msgs: https://docs.ros.org/en/fuerte/api/move_base_msgs/html/index-msg.html
    + rosgraph_msgs: https://docs.ros.org/en/melodic/api/rosgraph_msgs/html/index-msg.html
    + shape_msgs: https://docs.ros.org/en/melodic/api/shape_msgs/html/index-msg.html
    + std_srvs: https://docs.ros.org/en/jade/api/std_srvs/html/index-msg.html
    + gazebo_msgs: https://docs.ros.org/en/jade/api/gazebo_msgs/html/index-msg.html
    + grid_map_msgs: https://docs.ros.org/en/kinetic/api/grid_map_msgs/html/index-msg.html
    + octomap_msgs: https://docs.ros.org/en/noetic/api/octomap_msgs/html/index-msg.html
    + stereo_msgs: https://docs.ros2.org/foxy/api/stereo_msgs/index-msg.html

----------------------------------------------------------------------------------------------
# Descriptions
- actionlib_pkg: Create a simple action (.action) used in ROS
    + Reference link: http://wiki.ros.org/actionlib_tutorials/Tutorials
- libcpp_pkg: Create a simple library of cpp language (.h, .cpp) used in ROS
    + Reference link: https://roboticsbackend.com/ros-include-cpp-header-from-another-package/
- msg_pkg: Create a simple message (.msg) used in ROS
- param_pkg: Create a simple file parameter (.yaml) used in ROS
- srv_pkg: Create a simple service (.srv) used in ROS
- topic_pkg: Create a simple topic used in ROS

# Autostart
- Permit bash file:
    + Direct to folder: $cd /home/nhamtung/TungNV/ros_basic_ws/src/ros_basic/
    + Create packgage startup: $catkin_create_pkg startup roscpp rospy
    + Direct to startup folder: $cd /home/nhamtung/TungNV/ros_basic_ws/src/ros_basic/startup
    + Create and edit bash file: $sudo nano autostart.sh
    + Add to bash file:
        + #!/bin/bash
        + echo Add by TungNV
        + echo cd $HOME/TungNV/ros_basic_ws/
        + cd $HOME/TungNV/ros_basic_ws/
        + echo source install/setup.bash
        + source install/setup.bash
        + echo roslaunch topic_pkg topic_cpp.launch
        + roslaunch topic_pkg topic_cpp.launch
        + exit 0
    + Add to CMakeList.txt file in startup:
        + install(FILES autostart.sh
        + DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
    + Build file: $catkin_make install
    + Permit bash file: 
        + Direct to install folder: $cd $HOME/TungNV/ros_basic_ws/install/share/startup
        + $sudo chmod +x autostart.sh
- Create service:
    + Direct to system folder: $cd /etc/systemd/system/
    + Create service: $sudo nano autostart.service
    + Add to dervice file:
        + [Unit]
        + After=network.target
        + StartLimitIntervalSec=0
        + [Service]
        + User=robotics
        + Type=simple
        + Restart=always
        + RestartSec=1
        + ExecStart=/home/robotics/TungNV/ros_basic_ws/install/share/startup/autostart.sh
        + RemainAfterExit=no
        + [Install]
        + WantedBy=multi-user.target
- Enable service: $sudo systemctl enable autostart.service
- Start service: $sudo systemctl start autostart.service
- Stop service: $sudo systemctl stop autostart.service
- Disable service: $sudo systemctl disable autostart.service
- Restart service: $sudo systemctl restart autostart.service
- Check status service: $sudo systemctl status autostart.service
- Reload daemon: $sudo systemctl daemon-reload