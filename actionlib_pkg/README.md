------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Run action doDishes
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run action Server:
    + Python: $rosrun actionlib_pkg doDishesActionServer.py
    + cpp: $rosrun actionlib_pkg doDishesActionServer
- Run action Client:
    + Python: $rosrun actionlib_pkg doDishesActionClient.py
    + cpp: $rosrun actionlib_pkg doDishesActionClient

--------------------------------------------------------------------------------------
# Run action fibonacci
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run action Server: 
    + python: $rosrun actionlib_pkg fibonacciActionServer.py
    + cpp: $rosrun actionlib_pkg fibonacciActionServer
- Run action Client: 
    + python: $rosrun actionlib_pkg fibonacciActionClient.py
    + cpp: $rosrun actionlib_pkg fibonacciActionClient

--------------------------------------------------------------------------------------
# Run action averaging with other nodes (multithread)
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run data node: $rosrun actionlib_pkg gen_numbers.py
- Run action Server: $rosrun actionlib_pkg averagingActionServer
- Run action Client: $rosrun actionlib_pkg averagingActionClient

--------------------------------------------------------------------------------------
# Writing a Callback Based SimpleActionClient
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run action Server: $rosrun actionlib_pkg fibonacciActionServer
- Run action Client: 
    + Callback: $rosrun actionlib_pkg fibonacciCallbackClient
    + Class: $rosrun actionlib_pkg fibonacciClassClient

# Install package
- Add command to install in CMakeLists.txt:
```
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
```
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)