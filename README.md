----------------------------------------------------------------------------------------------
# ros_basic
- Reference link: http://wiki.ros.org/ROS/Tutorials

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
    + Direct to bash folder: $cd /home/nhamtung/TungNV/ros_basic_ws/
    + Create and edit bash file: $sudo nano autostart.sh
    + Add to bash file:
        + #!/bin/bash
        + echo Add by TungNV
        + echo cd /home/nhamtung/TungNV/ros_basic_ws/
        + cd /home/nhamtung/TungNV/ros_basic_ws/
        + echo source devel/setup.bash
        + source devel/setup.bash
        + echo roslaunch topic_pkg topic_cpp.launch
        + roslaunch topic_pkg topic_cpp.launch
        + exit 0
    + Permit bash file: $sudo chmod +x autostart.sh
- Create service:
    + Direct to system folder: $cd /etc/systemd/system/
    + Create service: $sudo vim autostart.service
    + Add to dervice file:
        + [Unit]
        + After=network.target
        + StartLimitIntervalSec=0
        + [Service]
        + User=nhamtung
        + Type=simple
        + Restart=always
        + RestartSec=1
        + ExecStart=/home/nhamtung/TungNV/ros_basic_ws/install/share/startup/autostart.sh
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