
#include "ros/ros.h"
#include "libcpp_pkg/mylib.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "main_lib");

  my_lib::MyLib sayHello();
  my_lib::MyLib test();
  ROS_INFO("main.cpp");
  
  ros::spin();

  return 0;
}