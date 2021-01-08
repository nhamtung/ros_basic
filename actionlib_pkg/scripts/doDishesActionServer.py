#! /usr/bin/env python

import roslib
roslib.load_manifest('actionlib_pkg')
import rospy
import actionlib

from actionlib_pkg.msg import doDishesAction

class DoDishesServer:
  def __init__(self):
    self.server = actionlib.SimpleActionServer('do_dishes', doDishesAction, self.execute, False)
    self.server.start()

  def execute(self, goal):
    # Do lots of awesome groundbreaking robot stuff here
    print("doDishesActionServer.py-17->execute()")
    self.server.set_succeeded()


if __name__ == '__main__':
  rospy.init_node('doDishesActionServer')
  server = DoDishesServer()
  rospy.spin()