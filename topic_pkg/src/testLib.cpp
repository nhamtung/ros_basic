
#include "libcpp_pkg/mylib.h"

static MyLib *myLib;

void testLib(uint8_t state){
  uint8_t state_ = State(state);
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
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "testLib");
  ros::NodeHandle n;
  
  std::string host_name = "NhamTung";
  myLib = new MyLib(host_name);
  myLib->sayHello();

  testLib(0);
  
  ros::spin();
  delete(myLib);
  return 0;
}