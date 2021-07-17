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

catkin_package(CATKIN_DEPENDS roscpp rospy std_msgs message_runtime)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(pub_test src/pub_test.cpp)
target_link_libraries(pub_test ${catkin_LIBRARIES})
add_dependencies(pub_test msg_pkg_gencpp)

## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS scripts/pub_test.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark executables for installation
install(TARGETS pub_test
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)