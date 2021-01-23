#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib_pkg/fibonacciAction.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/SimpleActionServer%28ExecuteCallbackMethod%29

class FibonacciAction
{
    protected:
    ros::NodeHandle nh_;
    actionlib::SimpleActionServer<actionlib_pkg::fibonacciAction> as_; // NodeHandle instance must be created before this line. Otherwise strange error occurs.
    std::string action_name_;
    // create messages that are used to published feedback/result
    actionlib_pkg::fibonacciFeedback feedback_;
    actionlib_pkg::fibonacciResult result_;

    public:
    FibonacciAction(std::string name) :
        as_(nh_, name, boost::bind(&FibonacciAction::executeCB, this, _1), false), action_name_(name)
    {
        as_.start();
    }

    ~FibonacciAction(void){}

    void executeCB(const actionlib_pkg::fibonacciGoalConstPtr &goal){
        // helper variables
        ros::Rate r(1);
        bool success = true;

        // push_back the seeds for the fibonacci sequence
        feedback_.sequence.clear();
        feedback_.sequence.push_back(0);
        feedback_.sequence.push_back(1);

        // publish info to the console for the user
        ROS_INFO("fibonacciActionServer.cpp -> %s: Executing, creating fibonacci sequence of order %i with seeds %i, %i", action_name_.c_str(), goal->order, feedback_.sequence[0], feedback_.sequence[1]);

        // start executing the action
        for(int i=1; i<=goal->order; i++){
            // check that preempt has not been requested by the client
            if (as_.isPreemptRequested() || !ros::ok()){  // Check Cancel
                ROS_INFO("fibonacciActionServer.cpp -> %s: Preempted", action_name_.c_str());
                as_.setPreempted();  // set the action state to preempted
                success = false;
                break;
            }
            feedback_.sequence.push_back(feedback_.sequence[i] + feedback_.sequence[i-1]);
            as_.publishFeedback(feedback_); // publish the feedback
            ROS_INFO("fibonacciActionServer.cpp - executing action - publish the feedback");
            // this sleep is not necessary, the sequence is computed at 1 Hz for demonstration purposes
            r.sleep();
        }

        if(success){
            result_.sequence = feedback_.sequence;
            as_.setSucceeded(result_);  // set the action state to succeeded
            ROS_INFO("fibonacciActionServer.cpp -> %s: Succeeded", action_name_.c_str());
        }
    }
};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "fibonacciActionServer");
  ROS_INFO ("fibonacciActionServer.cpp - Create node fibonacciActionServer");
  FibonacciAction fibonacci("fibonacci");
  ros::spin();

  return 0;
}