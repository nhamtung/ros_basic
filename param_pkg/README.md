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

# dynamic_reconfigure
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roslaunch param_pkg param_runtime.launch
- Open new sheet and run: $rosrun rqt_reconfigure rqt_reconfigure

- Update parameter: #rosrun param_pkg update_dynparam

- Directory: /param_pkg/param
- Save parameter to .yaml file: $rosrun dynamic_reconfigure dynparam dump /param_runtime robot.yaml
- Load parameter from .yaml file: $rosrun dynamic_reconfigure dynparam load /param_runtime param_runtime.yaml
