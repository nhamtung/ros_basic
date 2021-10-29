#include "libcpp_pkg/mylib.h"

namespace MyLib_ns{
    MyLib::MyLib(ros::NodeHandle* nh, std::string host){
        ROS_INFO("MyLib");
        ros::Subscriber listener;
        
        host_ = host;
        cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("cmd_vel", 1, true);
        // listener = nh->subscribe<std_msgs::String>("/chatter", 10, &MyLib::chatterCallback, this);
        listener = nh->subscribe<std_msgs::String>("/chatter", 10, boost::bind(&MyLib::chatterCallback, this, _1));
        ROS_INFO("mylib.cpp- Subscriber topic /chatter");
    }
    MyLib::~MyLib(){};

    void MyLib::chatterCallback(const std_msgs::String::ConstPtr& msg){
        ROS_INFO("I heard: [%s]", msg->data.c_str());

        geometry_msgs::Twist cmd_vel;
        cmd_vel_pub.publish(cmd_vel);
    }
    void MyLib::sayHello()
    {
        ROS_INFO("sayHello");
        cout << "std::endl duoc su dung voi std!" << std::endl;
    }
}