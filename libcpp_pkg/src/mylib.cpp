#include "libcpp_pkg/mylib.h"
#include <ros/ros.h>

using std::cout;
using namespace std;

MyLib::MyLib(std::string host){
    ROS_INFO("MyLib");
    host_ = host;
}
MyLib::~MyLib(void) = default;

void MyLib::sayHello()
{
    ROS_INFO("sayHello");
    cout << "std::endl duoc su dung voi std!" << std::endl;
}