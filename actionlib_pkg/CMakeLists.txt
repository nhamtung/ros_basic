cmake_minimum_required(VERSION 3.0.2)
project(actionlib_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  actionlib_msgs
  actionlib
  message_generation
)

add_action_files(
  DIRECTORY action
  FILES doDishes.action fibonacci.action averaging.action
)

generate_messages(
  DEPENDENCIES actionlib_msgs std_msgs 
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs actionlib_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(doDishesActionServer src/doDishesActionServer.cpp)
target_link_libraries(doDishesActionServer ${catkin_LIBRARIES})
add_dependencies(doDishesActionServer ${actionlib_pkg_EXPORTED_TARGETS})
add_executable(doDishesActionClient src/doDishesActionClient.cpp)
target_link_libraries(doDishesActionClient ${catkin_LIBRARIES})
add_dependencies(doDishesActionClient ${actionlib_pkg_EXPORTED_TARGETS})


add_executable(fibonacciActionServer src/fibonacciActionServer.cpp)
target_link_libraries(fibonacciActionServer ${catkin_LIBRARIES})
add_dependencies(fibonacciActionServer ${actionlib_pkg_EXPORTED_TARGETS})
add_executable(fibonacciActionClient src/fibonacciActionClient.cpp)
target_link_libraries(fibonacciActionClient ${catkin_LIBRARIES})
add_dependencies(fibonacciActionClient ${actionlib_pkg_EXPORTED_TARGETS})


add_executable(averagingActionServer src/averagingActionServer.cpp)
target_link_libraries(averagingActionServer ${catkin_LIBRARIES})
add_dependencies(averagingActionServer ${actionlib_pkg_EXPORTED_TARGETS})
add_executable(averagingActionClient src/averagingActionClient.cpp)
target_link_libraries(averagingActionClient ${catkin_LIBRARIES})
add_dependencies(averagingActionClient ${actionlib_pkg_EXPORTED_TARGETS})


add_executable(fibonacciCallbackClient src/fibonacciCallbackClient.cpp)
target_link_libraries(fibonacciCallbackClient ${catkin_LIBRARIES})
add_dependencies(fibonacciCallbackClient ${actionlib_pkg_EXPORTED_TARGETS})
add_executable(fibonacciClassClient src/fibonacciClassClient.cpp)
target_link_libraries(fibonacciClassClient ${catkin_LIBRARIES})
add_dependencies(fibonacciClassClient ${actionlib_pkg_EXPORTED_TARGETS})

#############
## Install ##
#############

## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS 
  scripts/doDishesActionClient.py 
  scripts/doDishesActionServer.py
  scripts/fibonacciActionClient.py
  scripts/fibonacciActionServer.py
  scripts/gen_numbers.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark executables for installation
install(TARGETS 
  doDishesActionServer
  doDishesActionClient
  fibonacciActionServer
  fibonacciActionClient
  averagingActionServer
  averagingActionClient
  fibonacciCallbackClient
  fibonacciClassClient
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark launch file for installation
# install(DIRECTORY launch/
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
#   PATTERN ".svn" EXCLUDE
# )
## Mark libraries for installation
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )
## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )
## Mark other files for installation (e.g. launch and bag files, etc.)
install(DIRECTORY action/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)