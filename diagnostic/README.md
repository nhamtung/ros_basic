
# Require
- Ubuntu 20.04
- ROS Noetic

# Publisher
- /diagnostic (diagnostic_msgs/DiagnosticArray): Diagnostic for node

# Build
- Direct to workspace
- Catkin: $catkin_make install
- Source: $source install/setup.bash

# Test
- Run: $roslaunch diagnostic diagnostic.launch
- Check: $rostopic echo /diagnostic