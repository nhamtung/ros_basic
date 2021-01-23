#include <ros/ros.h>
#include <std_msgs/Float32.h>
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
            // ac.sendGoal(goal, boost::bind(&MyNode::doneCb, this, _1, _2), Client::SimpleActiveCallback(), Client::SimpleFeedbackCallback());
            ac.sendGoal(goal, boost::bind(&MyNode::nodActionDoneCb, this, _1, _2), boost::bind(&MyNode::nodActionActiveCb, this), boost::bind(&MyNode::nodActionFeedbackCb, this, _1));
        }

        void nodActionDoneCb(const actionlib::SimpleClientGoalState& state, const actionlib_pkg::fibonacciResultConstPtr& result){
            ROS_INFO("fibonacciClassClient.cpp-27 -> Finished in state [%s]", state.toString().c_str());
            ROS_INFO("fibonacciClassClient.cpp-28 -> Answer: %i", result->sequence.back());
            ros::shutdown();
        }

        void nodActionActiveCb(){  // Called once when the goal becomes active
            ROS_INFO("agv_main.cpp -> nodActionActiveCb() -> Goal just went active");
        }
        void nodActionFeedbackCb(const actionlib_pkg::fibonacciFeedbackConstPtr& feedback){  // Called every time feedback is received for the goal
            ROS_INFO("agv_main.cpp -> nodActionFeedbackCb() -> Got Feedback of percent_complete");
        }

    private:
        Client ac;
};
void analysisCB(const std_msgs::Float32::ConstPtr& msg){
    ROS_INFO("fibonacciClassClient.cpp -> analysisCB()");
    MyNode my_node;
    my_node.doStuff(10);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "fibonacciClassClient");
    ros::NodeHandle n;
    ROS_INFO("fibonacciClassClient.cpp-39 -> Create node fibonacciClassClient");

    // sub_ = nh_.subscribe("/random_number", 1, &MyNode::analysisCB, this);
    ros::Subscriber agv_action_sub = n.subscribe("/random_number", 10, analysisCB);
    ROS_INFO("agv_main.cpp- Subscriber topic /random_number");

    ros::spin();
    return 0;
}