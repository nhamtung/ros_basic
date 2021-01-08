#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_pkg/averagingAction.h>
#include <boost/thread.hpp>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/SimpleActionClient%28Threaded%29

void spinThread(){
  ros::spin();
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "averagingActionClient");

  // create the action client
  actionlib::SimpleActionClient<actionlib_pkg::averagingAction> ac("averaging");
  boost::thread spin_thread(&spinThread);

  ROS_INFO("averagingActionClient.cpp -> Waiting for action server to start.");
  ac.waitForServer();

  ROS_INFO("averagingActionClient.cpp -> Action server started, sending goal.");
  // send a goal to the action
  actionlib_pkg::averagingGoal goal;
  goal.samples = 100;
  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout){
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("averagingActionClient.cpp -> Action finished: %s",state.toString().c_str());
  }else
    ROS_INFO("averagingActionClient.cpp -> Action did not finish before the time out.");

  // shutdown the node and join the thread back before exiting
  ros::shutdown();
  spin_thread.join();

  return 0;  //exit
}