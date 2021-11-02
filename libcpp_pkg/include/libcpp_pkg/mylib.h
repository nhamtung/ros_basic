#ifndef MYLIB_H
#define MYLIB_H
#pragma once

#include <ros/ros.h>
#include <unistd.h>
#include <stdint.h>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

using namespace std;

struct testStruct{
    double a;
    double b;
};

enum State{
    STATE_EXECUTED,
    STATE_CANCEL,
    STATE_DONE
};

namespace MyLib_ns{
    class MyLib
    {
        private:
            std::string host_;
            ros::Publisher cmd_vel_pub;
            ros::Subscriber listener, client_count_sub;
            void chatterCallback(const std_msgs::String::ConstPtr& msg);
            void clientCountCallback(const std_msgs::Int32::ConstPtr& msg);
        public:
            MyLib(ros::NodeHandle* nh, std::string host);
            ~MyLib();
            std::string d;
            void sayHello();
    };
}
#endif