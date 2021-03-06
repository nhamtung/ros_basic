#! /usr/bin/env python

import rospy
import actionlib
import actionlib_pkg.msg

# http://wiki.ros.org/actionlib_tutorials/Tutorials/Writing%20a%20Simple%20Action%20Server%20using%20the%20Execute%20Callback%20%28Python%29

class FibonacciAction(object):
    # create messages that are used to publish feedback/result
    _feedback = actionlib_pkg.msg.fibonacciFeedback()
    _result = actionlib_pkg.msg.fibonacciResult()

    def __init__(self, name):
        self._action_name = name
        self._as = actionlib.SimpleActionServer(self._action_name, actionlib_pkg.msg.fibonacciAction, execute_cb=self.execute_cb, auto_start = False)
        self._as.start()
      
    def execute_cb(self, goal):
        # helper variables
        r = rospy.Rate(1)
        success = True
        
        # append the seeds for the fibonacci sequence
        self._feedback.sequence = []
        self._feedback.sequence.append(0)
        self._feedback.sequence.append(1)
        
        # publish info to the console for the user
        rospy.loginfo('fibonacciActionServer.py -> %s: Executing, creating fibonacci sequence of order %i with seeds %i, %i' % (self._action_name, goal.order, self._feedback.sequence[0], self._feedback.sequence[1]))
        
        # start executing the action
        for i in range(1, goal.order):
            # check that preempt has not been requested by the client
            if self._as.is_preempt_requested():
                rospy.loginfo('fibonacciActionServer.py -> %s: Preempted' % self._action_name)
                self._as.set_preempted()
                success = False
                break
            self._feedback.sequence.append(self._feedback.sequence[i] + self._feedback.sequence[i-1])
            # publish the feedback
            self._as.publish_feedback(self._feedback)
            rospy.loginfo("fibonacciActionServer.py -> executing action - publish the feedback")
            # this step is not necessary, the sequence is computed at 1 Hz for demonstration purposes
            r.sleep()
          
        if success:
            self._result.sequence = self._feedback.sequence
            rospy.loginfo('fibonacciActionServer.py -> %s: Succeeded' % self._action_name)
            self._as.set_succeeded(self._result)
        
if __name__ == '__main__':
    rospy.init_node('fibonacciActionServer')
    print("fibonacciActionServer.py - Create node fibonacciActionServer")
    server = FibonacciAction("fibonacci")
    rospy.spin()