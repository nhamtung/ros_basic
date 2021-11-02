#include "libcpp_pkg/mylib.h"

namespace MyLib_ns{
    MyLib::MyLib(ros::NodeHandle* nh, std::string host){
        ROS_INFO("MyLib");
        
        host_ = host;
        cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("cmd_vel", 1, true);
        ROS_INFO("mylib.cpp- Publish the topic /chatter");

        listener = nh->subscribe<std_msgs::String>("/chatter", 10, boost::bind(&MyLib::chatterCallback, this, _1));
        ROS_INFO("mylib.cpp- Subscriber topic /chatter");
        client_count_sub = nh->subscribe<std_msgs::Int32>("/client_count", 1, boost::bind(&MyLib::clientCountCallback, this, _1));
        ROS_INFO("mylib.cpp- Subscriber topic /client_count");
    }
    MyLib::~MyLib(){};

    void MyLib::chatterCallback(const std_msgs::String::ConstPtr& msg){
        ROS_INFO("I heard: [%s]", msg->data.c_str());

        geometry_msgs::Twist cmd_vel;
        cmd_vel_pub.publish(cmd_vel);
    }
    void MyLib::clientCountCallback(const std_msgs::Int32::ConstPtr& msg){  
        ROS_INFO("clientCountCallback");
    }
    void MyLib::sayHello()
    {
        ROS_INFO("sayHello");
        cout << "std::endl duoc su dung voi std!" << std::endl;
    }
}