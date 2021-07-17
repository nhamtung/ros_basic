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
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)
- Run