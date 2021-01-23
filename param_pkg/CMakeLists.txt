cmake_minimum_required(VERSION 3.0.2)
project(param_pkg)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/param_runtime.cfg
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES param_pkg
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_param src/test_param.cpp)
target_link_libraries(test_param ${catkin_LIBRARIES})

add_executable(loadParam src/loadParam.cpp)
target_link_libraries(loadParam ${catkin_LIBRARIES})

add_executable(param_runtime src/param_runtime.cpp)
add_dependencies(param_runtime ${PROJECT_NAME}_gencfg)
target_link_libraries(param_runtime ${catkin_LIBRARIES})
