#include "libcpp_pkg/mylib.h"
#include <ros/ros.h>

using std::cout;
using namespace std;

// namespace my_lib {
//     // MyLib::MyLib(){
//     //     ROS_INFO("MyLib");
//     // }
//     // MyLib::~MyLib(){
//     //     ROS_INFO("~MyLib");
//     // }
//     // void MyLib::sayHello()
//     // {
//     //     ROS_INFO("sayHello");
//     //     cout << "std::endl duoc su dung voi std!" << std::endl;
//     // }

//     void test()
//     {
//         ROS_INFO("sayHello");
//         cout << "std::endl duoc su dung voi std!" << std::endl;
//     }
// };
void test(void)
{
    ROS_INFO("sayHello");
    cout << "std::endl duoc su dung voi std!" << std::endl;
}