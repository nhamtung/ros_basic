
#include "ros/ros.h"
#include <iostream>
#include <libcpp_pkg/mylib.h>
#include <libcpp_pkg/MathLibrary.h>

using std::cout;
using namespace std;

MyLib_ns::MyLib *mylib_;

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

void math(){
  double a = 7.4;
  int b = 99;

  std::cout << "a + b = " << MathLibrary::Arithmetic::Add(a, b) << std::endl;
  std::cout << "a - b = " << MathLibrary::Arithmetic::Subtract(a, b) << std::endl;
  std::cout << "a * b = " << MathLibrary::Arithmetic::Multiply(a, b) << std::endl;
  std::cout << "a / b = " << MathLibrary::Arithmetic::Divide(a, b) << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "main_lib");
  ROS_INFO("main.cpp");

  ros::NodeHandle nh("");

  func();
  math();

  testStruct testStruct_;

  uint8_t state_ = State(0);
  switch(state_){
    case STATE_EXECUTED:
      ROS_INFO("state: STATE_EXECUTED");
    break;
    case STATE_CANCEL:
      ROS_INFO("state: STATE_CANCEL");
    break;
    case STATE_DONE:
      ROS_INFO("state: STATE_DONE");
    break;
  }
  
  mylib_ = new MyLib_ns::MyLib(&nh, "nhamtung");
  mylib_->sayHello();
  
  ros::spin();
  delete(mylib_);
  return 0;
}