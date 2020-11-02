#ifndef MYLIB_H
#define MYLIB_H

#include <ros/ros.h>

namespace my_lib {
    class MyLib
    {
        public:
            MyLib();
            virtual ~MyLib();
            void sayHello();
    };

    // void sayHello();
}

#endif