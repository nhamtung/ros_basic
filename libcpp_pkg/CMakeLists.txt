cmake_minimum_required(VERSION 3.0.2)
project(libcpp_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} src/mylib.cpp src/MathLibrary.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${GSTREAMER_LIBRARIES})

add_executable(main src/main.cpp)
target_link_libraries(main ${PROJECT_NAME})
add_dependencies(main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#############
## Install ##
#############

## Mark executable scripts (Python etc.) for installation
#catkin_install_python(PROGRAMS
#  scripts/.py
#  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}/scripts
#)
## Mark executables for installation
install(TARGETS main
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark libraries for installation
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
## Mark other files for installation (e.g. launch and bag files, etc.)
#install(FILES
#  launch/.launch
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
#)