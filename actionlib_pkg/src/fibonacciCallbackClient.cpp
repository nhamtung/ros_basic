#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib_pkg/fibonacciAction.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/Writing%20a%20Callback%20Based%20Simple%20Action%20Client

using namespace actionlib_pkg;
typedef actionlib::SimpleActionClient<fibonacciAction> Client;

// Called once when the goal completes
void doneCb(const actionlib::SimpleClientGoalState& state, const fibonacciResultConstPtr& result){
  ROS_INFO("fibonacciCallbackClient.cpp-12 -> Finished in state [%s]", state.toString().c_str());
  ROS_INFO("fibonacciCallbackClient.cpp-13 -> Answer: %i", result->sequence.back());
  ros::shutdown();
}

// Called once when the goal becomes active
void activeCb(){
  ROS_INFO("fibonacciCallbackClient.cpp-19 -> activeCb() -> Goal just went active");
}

// Called every time feedback is received for the goal
void feedbackCb(const fibonacciFeedbackConstPtr& feedback){
  ROS_INFO("fibonacciCallbackClient.cpp-24 -> feedbackCb() -> Got Feedback of length %lu", feedback->sequence.size());
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "fibonacciCallbackClient");
  ROS_INFO("fibonacciCallbackClient.cpp-30 -> Create node fibonacciCallbackClient");
  
  Client ac("fibonacci", true);  // Create the action client

  ROS_INFO("fibonacciCallbackClient.cpp-34 -> Waiting for action server to start.");
  ac.waitForServer();
  ROS_INFO("fibonacciCallbackClient.cpp-36 -> Action server started, sending goal.");

  // Send Goal
  fibonacciGoal goal;
  goal.order = 20;
  ac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);

  ros::spin();
  return 0;
}