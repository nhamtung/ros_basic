#!/usr/bin/env python

# http://wiki.ros.org/rospy/Overview/Parameter%20Server

from __future__ import print_function
import rospy
import sys
from std_msgs.msg import String

def getParam():
    print("test_param.py-6- getParam()")

    angle1 = rospy.get_param("/param_py/angle1")
    print("test_param.py-11- angle1: ", angle1)
    float_ = rospy.get_param("/param_py/float")
    print("test_param.py-13- float_: ", float_)

    # a_string = rospy.get_param("a_string")
    # print("test_param.py-8-a_string: ", a_string)
    # relative_name = rospy.get_param("relative_name")
    # private_param = rospy.get_param('~private_name')
    # default_param = rospy.get_param('default_param', 'default_value')
    # gains = rospy.get_param('gains')
    # p, i, d = gains['p'], gains['i'], gains['d']

def setParam():
    print("test_param.py-7- setParam()")
    # Using rospy and raw python objects
    rospy.set_param('a_string', 'baz')
    rospy.set_param('~private_int', 2)
    rospy.set_param('list_of_floats', [1., 2., 3., 4.])
    rospy.set_param('bool_True', True)
    rospy.set_param('gains', {'p': 1, 'i': 2, 'd': 3})

    # Using rosparam and yaml strings
    # rosparam.set_param('a_string', 'baz')
    # rosparam.set_param('~private_int', '2')
    # rosparam.set_param('list_of_floats', "[1., 2., 3., 4.]")
    # rosparam.set_param('bool_True', "true")
    # rosparam.set_param('gains', "{'p': 1, 'i': 2, 'd': 3}")

def checkParam():
    if rospy.has_param('/param_py/angle1'):
        rospy.delete_param('/param_py/angle1')

if __name__ == '__main__':
    try:
        print("test_param.py-37- main()")
        # setParam()
        getParam()
        checkParam()
    except rospy.ROSInterruptException:
        pass
