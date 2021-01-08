#!/usr/bin/env python

import rospy
from std_msgs.msg import Float32
import random

# http://wiki.ros.org/actionlib_tutorials/Tutorials/RunningServerAndClientWithNodes

def gen_number():
    pub = rospy.Publisher('random_number', Float32)
    rospy.init_node('gen_numbers', log_level=rospy.INFO)
    rospy.loginfo("gen_numbers.py -> Generating random numbers")

    while not rospy.is_shutdown():
        pub.publish(Float32(random.normalvariate(5, 1)))
        rospy.loginfo("gen_numbers.py -> Publish the random numbers")
        rospy.sleep(0.05)

if __name__ == '__main__':
  try:
    gen_number()
  except Exception, e:
    print "gen_numbers.py -> Exception: ", e