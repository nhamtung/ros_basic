cmake_minimum_required(VERSION 3.0.2)
project(startup)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)
catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

install(FILES autostart.sh
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})