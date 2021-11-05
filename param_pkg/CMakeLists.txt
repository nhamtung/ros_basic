cmake_minimum_required(VERSION 3.0.2)
project(param_pkg)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/robot.cfg
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES param_pkg
  CATKIN_DEPENDS roscpp rospy std_msgs dynamic_reconfigure
#  DEPENDS system_lib
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(test_param src/test_param.cpp)
target_link_libraries(test_param ${catkin_LIBRARIES})
add_executable(loadParam src/loadParam.cpp)
target_link_libraries(loadParam ${catkin_LIBRARIES})

add_executable(dynparam_server src/dynparam_server.cpp)
add_dependencies(dynparam_server ${PROJECT_NAME}_gencfg)
target_link_libraries(dynparam_server ${catkin_LIBRARIES})
add_executable(control_dynparam src/control_dynparam.cpp)
add_dependencies(control_dynparam ${PROJECT_NAME}_gencfg)
target_link_libraries(control_dynparam ${catkin_LIBRARIES})

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