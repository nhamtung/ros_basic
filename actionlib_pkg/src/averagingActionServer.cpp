#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib_pkg/averagingAction.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials/SimpleActionServer%28GoalCallbackMethod%29

class AveragingAction
{
    public:
        AveragingAction(std::string name) : as_(nh_, name, false), action_name_(name)
        {
            //register the goal and feeback callbacks
            as_.registerGoalCallback(boost::bind(&AveragingAction::goalCB, this));
            as_.registerPreemptCallback(boost::bind(&AveragingAction::preemptCB, this));

            //subscribe to the data topic of interest
            sub_ = nh_.subscribe("/random_number", 1, &AveragingAction::analysisCB, this);
            as_.start();
        }

        ~AveragingAction(void){}

        void goalCB(){
            ROS_INFO("averagingActionServer.cpp -> %s: goalCB", action_name_.c_str());
            // reset helper variables
            data_count_ = 0;
            sum_ = 0;
            sum_sq_ = 0;
            
            goal_ = as_.acceptNewGoal()->samples;  // accept the new goal
        }

        void preemptCB(){
            ROS_INFO("averagingActionServer.cpp -> %s: Preempted", action_name_.c_str());
            as_.setPreempted();  // set the action state to preempted (Cancel)
        }

        void analysisCB(const std_msgs::Float32::ConstPtr& msg){
            // ROS_INFO("averagingActionServer.cpp -> analysisCB()");
            if (!as_.isActive()){  // make sure that the action hasn't been canceled
                ROS_ERROR_ONCE("averagingActionServer.cpp -> Action has been canceled - Please run action Client");
                return;
            }
            
            data_count_++;
            feedback_.sample = data_count_;
            feedback_.data = msg->data;
            //compute the std_dev and mean of the data 
            sum_ += msg->data;
            ROS_INFO("averagingActionServer.cpp -> sum_ = %f", sum_);
            feedback_.mean = sum_ / data_count_;
            sum_sq_ += pow(msg->data, 2);
            feedback_.std_dev = sqrt(fabs((sum_sq_/data_count_) - pow(feedback_.mean, 2)));
            as_.publishFeedback(feedback_);

            if(data_count_ > goal_){
                result_.mean = feedback_.mean;
                result_.std_dev = feedback_.std_dev;
                if(result_.mean < 5.0){
                    ROS_INFO("averagingActionServer.cpp -> %s: Aborted", action_name_.c_str());
                    as_.setAborted(result_);  //set the action state to aborted
                }else{
                    ROS_INFO("averagingActionServer.cpp -> %s: Succeeded", action_name_.c_str());
                    as_.setSucceeded(result_);  // set the action state to succeeded
                }
            } 
        }

    protected:
        ros::NodeHandle nh_;
        actionlib::SimpleActionServer<actionlib_pkg::averagingAction> as_;
        std::string action_name_;
        int data_count_, goal_;
        float sum_, sum_sq_;
        actionlib_pkg::averagingFeedback feedback_;
        actionlib_pkg::averagingResult result_;
        ros::Subscriber sub_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "averaging");
  ROS_INFO("averagingActionServer.cpp -> Create node averagingActionServer");

  AveragingAction averaging(ros::this_node::getName());
  ros::spin();

  return 0;
}