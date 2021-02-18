#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/String.h"
#include <sstream>

#include <param_pkg/robotConfig.h>
#include "dynamic_reconfigure/client.h"

#include "dynamic_reconfigure/Config.h"
#include "dynamic_reconfigure/BoolParameter.h"
#include "dynamic_reconfigure/IntParameter.h"
#include "dynamic_reconfigure/StrParameter.h"
#include "dynamic_reconfigure/DoubleParameter.h"
#include "dynamic_reconfigure/GroupState.h"

// Reference link: https://answers.ros.org/question/12276/is-there-a-c-api-for-a-dynamic-reconfigure-client/

dynamic_reconfigure::ReconfigureRequest srv_req;
dynamic_reconfigure::ReconfigureResponse srv_resp;

dynamic_reconfigure::Config dynparam_;
dynamic_reconfigure::BoolParameter boolParam_;
dynamic_reconfigure::IntParameter intParam_;
dynamic_reconfigure::StrParameter stringParam_;
dynamic_reconfigure::DoubleParameter doubleParam_;
dynamic_reconfigure::GroupState groupState_;

void updateDynparam();
void loadDynparam();
void saveDynparam();

void controlParamCallback(const std_msgs::UInt8& msg)
{
    uint8_t data_ = msg.data;
    ROS_INFO("I heard: %d", data_);
    if(data_ == 0){
        updateDynparam();
    }else if(data_ == 1){
        loadDynparam();
    }else if(data_ == 2){
        saveDynparam();
    }
}

void updateDynparam(){
    ROS_INFO("Update dynparam");
    boolParam_.name = "bool_param";
    boolParam_.value = false;
    dynparam_.bools.push_back(boolParam_);

    intParam_.name = "K";
    intParam_.value = 20;
    dynparam_.ints.push_back(intParam_);
    intParam_.name = "SpeedMotorMin";
    intParam_.value = 50;
    dynparam_.ints.push_back(intParam_);
    intParam_.name = "thesholdQualityPose";
    intParam_.value = 80;
    dynparam_.ints.push_back(intParam_);

    stringParam_.name = "str_param";
    stringParam_.value = "Update param by TungNV";
    dynparam_.strs.push_back(stringParam_);

    doubleParam_.name = "L";
    doubleParam_.value = 1;
    dynparam_.doubles.push_back(doubleParam_);
    doubleParam_.name = "R";
    doubleParam_.value = 0.1;
    dynparam_.doubles.push_back(doubleParam_);
    doubleParam_.name = "SpeedMotorMax";
    doubleParam_.value = 2000;
    dynparam_.doubles.push_back(doubleParam_);

    srv_req.config = dynparam_;
    ros::service::call("/param_runtime/set_parameters", srv_req, srv_resp);
    ROS_INFO("update_dynparam.cpp - Call service /param_runtime/set_parameters");
}
void loadDynparam(){
    ROS_INFO("Load dynparam");
}
void saveDynparam(){
    ROS_INFO("Save dynparam");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "update_dynparam");
    ros::NodeHandle n;
    ROS_INFO("update_dynparam.cpp - Create node update_dynparam");

    ros::Subscriber sub = n.subscribe("/control_dynparam", 10, controlParamCallback);
    ROS_INFO("update_dynparam.cpp- Subscriber topic /control_dynparam");

    ros::spin();
    return 0;
}