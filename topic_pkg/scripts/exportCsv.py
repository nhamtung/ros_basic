#!/usr/bin/env python
import rospy
import time
import pandas as pd
from std_msgs.msg import String

def callback(data):
    header_ = False
    dataSave_ = data.data
    rospy.loginfo(" -> error: %f", dataSave_)
    exportCsv(0, dataSave_, header_)

def exportCsv(seconds_, data_, header_):
    t = rospy.Time.from_sec(time.time())
    seconds_ = t.to_sec() #floating point
    content = {'time(s)': [seconds_], 'data': [data_]}

    df = pd.DataFrame(content, columns= ['time(s)', 'data'])
    df.to_csv (r'./exported.csv',mode = 'a', index = False, header=header_)
    # print ("Saved file exported")
    
def subsciberTopic(topicName_, type_):
    rospy.Subscriber(topicName_, type_, callback)
    rospy.loginfo("exportCsv.py-11 - Subscriber topic %s", topicName_)
    rospy.spin()

if __name__ == '__main__':
    rospy.init_node('exportCsv', anonymous=True)
    rospy.loginfo("exportCsv.py")
    
    exportCsv(0,0,True)

    topicName_ = "/chatter"    
    type_ = String
    subsciberTopic(topicName_, type_)