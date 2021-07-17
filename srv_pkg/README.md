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
- Directory to workspace
- Build install: $catkin_make install
- Source: $source install/setup.bash
- Delete the src folder (delete source code)
- Run