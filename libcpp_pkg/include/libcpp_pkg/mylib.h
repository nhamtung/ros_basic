#ifndef MYLIB_H
#define MYLIB_H

#include <ros/ros.h>

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
        public:
            MyLib(std::string host);
            ~MyLib();
            std::string d;
            void sayHello();
    };
}

void testLib(uint8_t state);

#endif