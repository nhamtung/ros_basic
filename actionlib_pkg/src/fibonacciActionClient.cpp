#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_pkg/fibonacciAction.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/SimpleActionClient

int main (int argc, char **argv)
{
  ros::init(argc, argv, "fibonacciActionClient");
  ROS_INFO("fibonacciActionClient.cpp - Create node fibonacciActionClient");

  // create the action client
  // true causes the client to spin its own thread
  actionlib::SimpleActionClient<actionlib_pkg::fibonacciAction> ac("fibonacci", true);

  ROS_INFO("fibonacciActionClient.cpp - Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time

  ROS_INFO("fibonacciActionClient.cpp - Action server started, sending goal.");
  // send a goal to the action
  actionlib_pkg::fibonacciGoal goal;
  goal.order = 50;
  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(goal.order + 5));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("fibonacciActionClient.cpp - Action finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("fibonacciActionClient.cpp - Action did not finish before the time out.");

  //exit
  return 0;
}