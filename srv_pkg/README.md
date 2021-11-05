--------------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Run Service Server
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun srv_pkg service_server.py
    + cpp: $rosrun srv_pkg service_server

--------------------------------------------------------------------------------------
# Run Service Client
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun srv_pkg service_client.py
    + cpp: $rosrun srv_pkg service_client
    
# Install package
- Add command to install in CMakeLists.txt:
```
#############
## Install ##
#############

## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS
  scripts/service_client.py
  scripts/service_server.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}/scripts
)
## Mark executables for installation
install(TARGETS service_server service_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark libraries for installation
#install(TARGETS ${PROJECT_NAME}
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
#)
## Mark cpp header files for installation
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#)
## Mark other files for installation (e.g. launch and bag files, etc.)
install(DIRECTORY srv/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
```
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)