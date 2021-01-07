
#include "libcpp_pkg/mylib.h"


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

  testLib(0);
  return 0;
}