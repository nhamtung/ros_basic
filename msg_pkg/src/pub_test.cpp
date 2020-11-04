#include "ros/ros.h"
#include "msg_pkg/test_msg.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub_test_msg");
  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<msg_pkg::test_msg>("chatter", 1000);
  ros::Rate loop_rate(10);
  
  int count = 0;
  while (ros::ok())
  {
    msg_pkg::test_msg data;
    data.first_name = "Nham";
    data.last_name = "Tung";
    data.age = 28;

    ROS_INFO("first_name: %s", data.first_name.c_str());
    ROS_INFO("last_name: %s", data.last_name.c_str());

    chatter_pub.publish(data);
    ROS_INFO("Publish data");

    ros::spinOnce();

    loop_rate.sleep();
    // ++count;
  }
  return 0;
}