#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <param_pkg/robotConfig.h>

// Reference: https://answers.ros.org/question/270034/run-rosparam-load-in-runtime/


void callback(param_pkg::robotConfig &config, uint32_t level) {
    ROS_INFO("bool_param: %d", config.bool_param);
    ROS_INFO("str_param: %s", config.str_param.c_str());

    ROS_INFO("L: %f", config.L);
    ROS_INFO("R: %f", config.R);
    ROS_INFO("K: %d", config.K);
    ROS_INFO("SpeedMotorMax: %lf", config.SpeedMotorMax);
    ROS_INFO("SpeedMotorMin: %d", config.SpeedMotorMin);
    ROS_INFO("thesholdQualityPose: %d", config.thesholdQualityPose);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "param_runtime");
    ROS_INFO("param_runtime.cpp - Create node param_runtime");

    dynamic_reconfigure::Server<param_pkg::robotConfig> server;
    dynamic_reconfigure::Server<param_pkg::robotConfig>::CallbackType f;
    f = boost::bind(&callback, _1, _2);
    server.setCallback(f);

    ros::spin();

    return 0;
}