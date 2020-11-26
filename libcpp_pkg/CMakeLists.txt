cmake_minimum_required(VERSION 3.0.2)
project(libcpp_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES libcpp_pkg
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(mylib src/mylib.cpp)
target_link_libraries(mylib ${catkin_LIBRARIES})




add_executable(main_lib src/main.cpp)
target_link_libraries(main_lib ${catkin_LIBRARIES})
add_dependencies(main_lib ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
