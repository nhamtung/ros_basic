#ifndef MYLIB_H
#define MYLIB_H
#pragma once

#include <ros/ros.h>
#include <unistd.h>
#include <stdint.h>

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

class MyLib
{
private:
    std::string host_;
public:
    std::string d;
    void sayHello();
    MyLib(std::string host);
    ~MyLib();
};


MyLib::MyLib(std::string host){
    ROS_INFO("MyLib");
    host_ = host;
}
MyLib::~MyLib() {}
void MyLib::sayHello()
{
    ROS_INFO("sayHello");
    cout << "std::endl duoc su dung voi std!" << std::endl;
}


#endif