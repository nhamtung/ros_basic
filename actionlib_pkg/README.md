------------------------------------------------------------------------------
# Run roscore
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run: $roscore

--------------------------------------------------------------------------------------
# Run action Server
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun actionlib_pkg actionServer.py
    + cpp: $rosrun actionlib_pkg actionServer

--------------------------------------------------------------------------------------
# Run action Client
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rosrun actionlib_pkg actionClient.py
    + cpp: $rosrun actionlib_pkg actionClient