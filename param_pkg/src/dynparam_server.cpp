#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <param_pkg/robotConfig.h>

// Reference: https://answers.ros.org/question/270034/run-rosparam-load-in-runtime/


void dynparamCallback(param_pkg::robotConfig &config, uint32_t level) {
    // ROS_INFO("dynparam_server.cpp- bool_param: %d", config.bool_param);
    // ROS_INFO("dynparam_server.cpp- str_param: %s", config.str_param.c_str());

    // ROS_INFO("dynparam_server.cpp- L: %f", config.L);
    // ROS_INFO("dynparam_server.cpp- R: %f", config.R);
    // ROS_INFO("dynparam_server.cpp- K: %d", config.K);
    // ROS_INFO("dynparam_server.cpp- SpeedMotorMax: %.0lf", config.SpeedMotorMax);
    // ROS_INFO("dynparam_server.cpp- SpeedMotorMin: %d", config.SpeedMotorMin);
    ROS_INFO("dynparam_server.cpp- thesholdQualityPose: %d", config.thesholdQualityPose);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "dynparam_server");
    ROS_INFO("dynparam_server.cpp- Create node dynparam_server");

    dynamic_reconfigure::Server<param_pkg::robotConfig> server;
    dynamic_reconfigure::Server<param_pkg::robotConfig>::CallbackType f;
    f = boost::bind(&dynparamCallback, _1, _2);
    server.setCallback(f);

    ros::spin();
    return 0;
}