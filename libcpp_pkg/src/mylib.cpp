#include "libcpp_pkg/mylib.h"


namespace MyLib_ns{
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
}
