--------------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Test message
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun msg_pkg pub_test.py
    + cpp: $rosrun msg_pkg pub_test

# Install package
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)
- Run
