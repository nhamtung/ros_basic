#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

// #include "libcpp_pkg/mylib.h"

// void testLib(uint8_t state){
//   uint8_t state_ = State(state);
//   switch(state_){
//     case STATE_EXECUTED:
//       ROS_INFO("state: STATE_EXECUTED");
//     break;
//     case STATE_CANCEL:
//       ROS_INFO("state: STATE_CANCEL");
//     break;
//     case STATE_DONE:
//       ROS_INFO("state: STATE_DONE");
//     break;
//   }
// }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  // testLib(0);
  
  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}