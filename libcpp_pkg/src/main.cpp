
#include "ros/ros.h"
#include <libcpp_pkg/mylib.h>

using std::cout;
using namespace std;

static MyLib *myLib;

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


  func();

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

  std::string host_name = "NhamTung";
  myLib = new MyLib(host_name);
  myLib->sayHello();
  
  ros::spin();
  delete(myLib);
  return 0;
}