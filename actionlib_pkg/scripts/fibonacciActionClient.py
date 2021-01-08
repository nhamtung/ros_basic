#! /usr/bin/env python

import rospy
# from __future__ import print_function
# Brings in the SimpleActionClient
import actionlib
# Brings in the messages used by the fibonacci action, including the
# goal message and the result message.
import actionlib_pkg.msg

# http://wiki.ros.org/actionlib_tutorials/Tutorials/Writing%20a%20Simple%20Action%20Client%20%28Python%29

def fibonacci_client():
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    client = actionlib.SimpleActionClient('fibonacci', actionlib_pkg.msg.fibonacciAction)

    # Waits until the action server has started up and started
    # listening for goals.
    client.wait_for_server()
    print("fibonacciActionClient.py - wait_for_server")
    goal = actionlib_pkg.msg.fibonacciGoal(order=20)  # Creates a goal to send to the action server.
    client.send_goal(goal)  # Sends the goal to the action server.
    # print("fibonacciActionClient.py - Call action")

    client.wait_for_result()  # Waits for the server to finish performing the action.
    return client.get_result()  # A FibonacciResult

if __name__ == '__main__':
    try:
        rospy.init_node('fibonacciActionClient')
        # print("fibonacciActionClient.py - Create node fibonacciActionClient")
        result = fibonacci_client()
        print("fibonacciActionClient.py -> Result:", ', '.join([str(n) for n in result.sequence]))
    except rospy.ROSInterruptException:
        print("fibonacciActionClient.py -> program interrupted before completion")