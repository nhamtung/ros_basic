cmake_minimum_required(VERSION 3.0.2)
project(actionlib_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  actionlib_msgs
  actionlib
)

add_action_files(
  DIRECTORY action
  FILES doDishes.action
)

generate_messages(
  DEPENDENCIES actionlib_msgs std_msgs 
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES actionlib_pkg
   CATKIN_DEPENDS roscpp rospy std_msgs actionlib_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(actionServer src/actionServer.cpp)
target_link_libraries(actionServer ${catkin_LIBRARIES})

add_executable(actionClient src/actionClient.cpp)
target_link_libraries(actionClient ${catkin_LIBRARIES})
