#! /usr/bin/env python

import roslib
roslib.load_manifest('actionlib_pkg')
import rospy
import actionlib

from actionlib_pkg.msg import doDishesAction, doDishesGoal

if __name__ == '__main__':
    rospy.init_node('doDishesActionClient')
    client = actionlib.SimpleActionClient('do_dishes', doDishesAction)
    client.wait_for_server()

    goal = doDishesGoal()
    # Fill in the goal here
    client.send_goal(goal)
    client.wait_for_result(rospy.Duration.from_sec(5.0))
    print("doDishesActionClient.py-19->Wait for resuilt")
    