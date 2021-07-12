#include "ros/ros.h"
#include <boost/thread.hpp>
#include "std_msgs/String.h"
#include <sstream>

ros::Publisher chatter_pub;
boost::thread* talker_thread;
void excuteTalkerThread(ros::Rate loop_rate);

void excuteTalkerThread(ros::Rate loop_rate){
  int count = 0;
  while (ros::ok()){
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);

    // ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}

int main(int argc, char **argv){
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  chatter_pub = n.advertise<std_msgs::String>("chatter", 10);

  talker_thread = new boost::thread (&excuteTalkerThread, loop_rate);
  
  ros::spin();
  return 0;
}