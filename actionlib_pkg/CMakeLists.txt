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