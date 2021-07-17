cmake_minimum_required(VERSION 3.0.2)
project(srv_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_service_files(
   FILES
   test_srv.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES srv_pkg
#  CATKIN_DEPENDS roscpp rospy std_msg
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(service_server src/service_server.cpp)
target_link_libraries(service_server ${catkin_LIBRARIES})
add_dependencies(service_server srv_pkg_gencpp)

add_executable(service_client src/service_client.cpp)
target_link_libraries(service_client ${catkin_LIBRARIES})
add_dependencies(service_client srv_pkg_gencpp)


## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS scripts/service_server.py scripts/service_client.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark executables for installation
install(TARGETS service_server service_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)