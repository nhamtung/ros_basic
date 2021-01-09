#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_pkg/averagingAction.h>
#include <boost/thread.hpp>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/SimpleActionClient%28Threaded%29

int TIME_OUT = 10;

void actionThread(){
  // create the action client
  actionlib::SimpleActionClient<actionlib_pkg::averagingAction> ac("averaging");

  ROS_INFO("averagingActionClient.cpp-actionThread() -> Waiting for action server to start.");
  ac.waitForServer();

  ROS_INFO("averagingActionClient.cpp-actionThread() -> Action server started, sending goal.");
  // send a goal to the action
  actionlib_pkg::averagingGoal goal;
  goal.samples = 100;
  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(TIME_OUT));
  ROS_INFO("averagingActionClient.cpp-actionThread() -> wait for the action to return");

  if (finished_before_timeout){
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("averagingActionClient.cpp-actionThread() -> Action finished: %s",state.toString().c_str());
  }else
    ROS_INFO("averagingActionClient.cpp-actionThread() -> Action did not finish before the time out.");
}

void mainThread(uint8_t total){
  ros::Rate loop_rate(1);
  uint8_t num_ = 0;
  while (ros::ok())
  {
    ROS_INFO("averagingActionClient.cpp-mainThread() -> num : %d", num_);
    num_ = num_ + 1;
    if(num_ > total){
      ROS_INFO("averagingActionClient.cpp-mainThread() -> Finished");
      break;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "averagingActionClient");
  ros::NodeHandle n;

  boost::thread action_thread(&actionThread);
  boost::thread main_thread(&mainThread, TIME_OUT);
  action_thread.join();  //join the thread
  main_thread.join();  //join the thread 

  return 0;  //exit
}