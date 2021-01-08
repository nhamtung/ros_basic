#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib_pkg/fibonacciAction.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/Writing%20a%20Callback%20Based%20Simple%20Action%20Client

using namespace actionlib_pkg;
typedef actionlib::SimpleActionClient<fibonacciAction> Client;

class MyNode
{
    public:
        MyNode():ac("fibonacci", true){
            ROS_INFO("fibonacciClassClient.cpp-14 -> Waiting for action server to start.");
            ac.waitForServer();
            ROS_INFO("fibonacciClassClient.cpp-16 -> Action server started, sending goal.");
        }

        void doStuff(int order){
            fibonacciGoal goal;
            goal.order = order;
            // Need boost::bind to pass in the 'this' pointer
            ac.sendGoal(goal, boost::bind(&MyNode::doneCb, this, _1, _2), Client::SimpleActiveCallback(), Client::SimpleFeedbackCallback());
        }

        void doneCb(const actionlib::SimpleClientGoalState& state, const fibonacciResultConstPtr& result){
            ROS_INFO("fibonacciClassClient.cpp-27 -> Finished in state [%s]", state.toString().c_str());
            ROS_INFO("fibonacciClassClient.cpp-28 -> Answer: %i", result->sequence.back());
            ros::shutdown();
        }

    private:
        Client ac;
};

int main (int argc, char **argv)
{
  ros::init(argc, argv, "fibonacciClassClient");
  ROS_INFO("fibonacciClassClient.cpp-39 -> Create node fibonacciClassClient");

  MyNode my_node;
  my_node.doStuff(10);

  ros::spin();
  return 0;
}