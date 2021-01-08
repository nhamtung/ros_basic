#include <actionlib_pkg/doDishesAction.h>  // Note: "Action" is appended
#include <actionlib/server/simple_action_server.h>

// http://wiki.ros.org/actionlib_tutorials/Tutorials

typedef actionlib::SimpleActionServer<actionlib_pkg::doDishesAction> Server;

void execute(const actionlib_pkg::doDishesGoalConstPtr& goal, Server* as)  // Note: "Action" is not appended to DoDishes here
{
  // Do lots of awesome groundbreaking robot stuff here
  ROS_INFO("actionServer.cpp-9 -> dishwasher_id: %d", goal->dishwasher_id);
  as->setSucceeded();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "actionServer");
  ros::NodeHandle n;
  Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}