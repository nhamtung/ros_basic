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
- Publish to topic /control_dynparam:
    + setDynparam:          0
    + loadDynparamDefault:  1
    + loadDynparamRuntime:  2
    + saveDynparamRuntime:  3

- Save parameter  to  .yaml file: $rosrun dynamic_reconfigure dynparam dump /param_runtime ./src/ros_basic/param_pkg/param/param_runtime.yaml
- Load parameter from .yaml file: $rosrun dynamic_reconfigure dynparam load /param_runtime ./src/ros_basic/param_pkg/param/param_runtime.yaml
