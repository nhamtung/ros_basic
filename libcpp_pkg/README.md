--------------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Test library from internal package
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $rosrun libcpp_pkg main

--------------------------------------------------------------------------------------
# Test library from external package
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $rosrun topic_pkg testLib
