
#include "ros/ros.h"
#include <libcpp_pkg/mylib.h>

using std::cout;
using namespace std;

void func(){
  ROS_INFO("main.cpp-func()");
}
namespace my_namespace {
    void test_namespace()
    {
        ROS_INFO("test_namespace");
        cout << "std::endl duoc su dung voi std!" << std::endl;
    }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "main_lib");
  ROS_INFO("main.cpp");

  // my_lib::test();

  // my_lib::MyLib sayHello();
  // my_lib::MyLib test();
  // my_lib::test();
  // my_namespace::test_namespace();
  // mylib::test();
  // libcpp_pkg::mylib a;
  // a.test();
  // test();

  // func();
  
  ros::spin();

  return 0;
}