
#include "ros/ros.h"
#include "libcpp_pkg/mylib.h"

using std::cout;

void func(){
  ROS_INFO("main.cpp-func()");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "main_lib");
  ROS_INFO("main.cpp");

  // my_lib::MyLib sayHello();
  // my_lib::MyLib test();
  // my_lib::test();
  // test();

  func();
  
  ros::spin();

  return 0;
}