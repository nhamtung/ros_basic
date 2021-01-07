--------------------------------------------------------------------------------------
# Test parameter
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roslaunch param_pkg test_param.launch

--------------------------------------------------------------------------------------
# Load parameter
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roslaunch param_pkg loadParam.launch
