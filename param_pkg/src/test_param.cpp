
// http://wiki.ros.org/roscpp/Overview/Parameter%20Server

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void setParam();
void getParam();
void checkParam();

void getParam(){
    ROS_INFO("test_param.cpp- getParam()");
    ros::NodeHandle nh;
    std::string string_;
    float float_;

    if (nh.getParam("/param_cpp/float", float_)){
        ROS_INFO("float: %f", float_);
    }
    nh.param<std::string>("/param_cpp/string", string_, "string_");

    if (ros::param::get("/param_cpp/float", float_)){
        ROS_INFO("float: %f", float_);
    }
    ros::param::param<std::string>("/param_cpp/string", string_, "string_");
}

void setParam(){
    ROS_INFO("test_param.cpp- setParam()");
    ros::NodeHandle nh;

    nh.setParam("/global_param", 5);
    nh.setParam("relative_param", "my_string");
    nh.setParam("bool_param", false);
    // ros::param::set("/global_param", 5);
    // ros::param::set("relative_param", "my_string");
    // ros::param::set("bool_param", false);
}

void checkParam(){
    ROS_INFO("test_param.cpp- checkParam()");
    ros::NodeHandle nh;

    if (nh.hasParam("/param_cpp/string")){
        nh.deleteParam("/param_cpp/string");
    }
    // if (ros::param::has("/param_cpp/string")){
    //     ros::param::del("/param_cpp/string");
    // }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_param");
  ros::NodeHandle n;
  
  setParam();
  getParam();

  ros::spin();
  return 0;
}