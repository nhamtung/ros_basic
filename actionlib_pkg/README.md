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