--------------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Publish the topic
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun topic_pkg talker.py
    + cpp: $rosrun topic_pkg talker

--------------------------------------------------------------------------------------
# Subscriber the topic
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun topic_pkg listener.py
    + cpp: $rosrun topic_pkg listener

--------------------------------------------------------------------------------------
# Install package
- Add command to install in CMakeLists.txt:
```
#############
## Install ##
#############

## Mark executable scripts (Python etc.) for installation
catkin_install_python(PROGRAMS
  scripts/exportCsv.py
  scripts/talker.py
  scripts/listener.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}/scripts
)
## Mark executables for installation
install(TARGETS talker listener testLib
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
install(FILES
  launch/topic_cpp.launch
  launch/topic_py.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)
```
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)

# Export data to cvs file
- Install pandas: $sudo pip install pandas
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Directory: $cd src/ros_basic/topic_pkg/scripts/
- Run: $python exportCsv.py
- Result: Create exported.csv file in scripts folder