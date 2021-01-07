--------------------------------------------------------------------------------------
# Publish the topic
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rolaunch topic_pkg talker.py
    + cpp: $roslaunch topic_pkg talker

--------------------------------------------------------------------------------------
# Subscriber the topic
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Run:
    + Python: $rolaunch topic_pkg listener.py
    + cpp: $roslaunch topic_pkg listener

--------------------------------------------------------------------------------------
# Export data to cvs file
- Install pandas: $sudo pip install pandas
- Directory to workspace
- Build: $catkin_make
- Source: $source devel/setup.bash
- Directory: $cd src/ros_basic/topic_pkg/scripts/
- Run: $python exportCsv.py
- Result: Create exported.csv file in scripts folder