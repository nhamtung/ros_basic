cmake_minimum_required(VERSION 3.0.2)
project(msg_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
   FILES
   test_msg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES msg_pkg
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



add_executable(pub_test src/pub_test.cpp)
target_link_libraries(pub_test ${catkin_LIBRARIES})
add_dependencies(pub_test msg_pkg_gencpp)