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
- Add command to install in CMakeLists.txt:
```
#############
## Install ##
#############

## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS scripts/test_param.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark executables for installation
install(TARGETS 
  test_param
  loadParam
  dynparam_server
  control_dynparam
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark launch file for installation
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)
## Mark param file for installation
install(DIRECTORY param/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/param
  PATTERN ".svn" EXCLUDE
)
## Mark cfg file for installation
install(DIRECTORY cfg/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/cfg
  PATTERN ".svn" EXCLUDE
)
```
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)
