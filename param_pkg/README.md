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
    + setDynparam:          data = 0
    + loadDynparamDefault:  data = 1
    + loadDynparamRuntime:  data = 2
    + saveDynparamRuntime:  data = 3

- Save parameter  to  .yaml file: $rosrun dynamic_reconfigure dynparam dump /param_runtime /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_runtime.yaml
- Load parameter from .yaml file: $rosrun dynamic_reconfigure dynparam load /param_runtime /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_runtime.yaml

# Install package
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)
- Run
