#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from msg_pkg.msg import test_msg

def pub_test():
    pub = rospy.Publisher('pub_test', test_msg, queue_size=10)
    rospy.init_node('pub_test', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        data = test_msg()
        data.first_name = "Nham"
        data.last_name = "Tung"
        data.age = 28
        rospy.loginfo(data)
        pub.publish(data)
        rate.sleep()

if __name__ == '__main__':
    try:
        pub_test()
    except rospy.ROSInterruptException:
        pass