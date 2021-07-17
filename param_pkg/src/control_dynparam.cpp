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

// param_pkg::robotConfig config;

int32_t count = 50;
bool isSaveDynparamDefault = true;

void setDynparam(int32_t count_);
void loadDynparamDefault();
void saveDynparamDefault();
void loadDynparamRuntime();
void saveDynparamRuntime();

void controlParamCallback(const std_msgs::UInt8& msg){
    uint8_t data_ = msg.data;
    // ROS_INFO("control_dynparam.cpp- I heard: %d", data_);
    if(data_ == 0){
        count = count+1;
        setDynparam(count);
    }else if(data_ == 1){
        loadDynparamDefault();
    }else if(data_ == 2){
        loadDynparamRuntime();
    }else if(data_ == 3){
        saveDynparamRuntime();
    }
}
void dynparamCallBack(const param_pkg::robotConfig &config){
    ROS_INFO("control_dynparam.cpp- bool_param: %d", config.bool_param);
    ROS_INFO("control_dynparam.cpp- str_param: %s", config.str_param.c_str());

    ROS_INFO("control_dynparam.cpp- L: %f", config.L);
    ROS_INFO("control_dynparam.cpp- R: %f", config.R);
    ROS_INFO("control_dynparam.cpp- K: %d", config.K);
    ROS_INFO("control_dynparam.cpp- SpeedMotorMax: %.0lf", config.SpeedMotorMax);
    ROS_INFO("control_dynparam.cpp- SpeedMotorMin: %d", config.SpeedMotorMin);
    ROS_INFO("control_dynparam.cpp- thesholdQualityPose: %d", config.thesholdQualityPose);
}

void setDynparam(int32_t count_){
    ROS_INFO("control_dynparam.cpp- Update dynparam");
    dynamic_reconfigure::Config dynparam;
    dynamic_reconfigure::BoolParameter boolParam;
    dynamic_reconfigure::IntParameter intParam;
    dynamic_reconfigure::StrParameter stringParam;
    dynamic_reconfigure::DoubleParameter doubleParam;
    dynamic_reconfigure::GroupState groupState;

    boolParam.name = "bool_param";
    boolParam.value = false;
    dynparam.bools.push_back(boolParam);

    intParam.name = "K";
    intParam.value = 20;
    dynparam.ints.push_back(intParam);
    intParam.name = "SpeedMotorMin";
    intParam.value = 50;
    dynparam.ints.push_back(intParam);
    intParam.name = "thesholdQualityPose";
    intParam.value = count_;
    dynparam.ints.push_back(intParam);

    stringParam.name = "str_param";
    stringParam.value = "Update param by TungNV";
    dynparam.strs.push_back(stringParam);

    doubleParam.name = "L";
    doubleParam.value = 1;
    dynparam.doubles.push_back(doubleParam);
    doubleParam.name = "R";
    doubleParam.value = 0.1;
    dynparam.doubles.push_back(doubleParam);
    doubleParam.name = "SpeedMotorMax";
    doubleParam.value = 2000;
    dynparam.doubles.push_back(doubleParam);

    srv_req.config = dynparam;
    if(ros::service::call("/dynparam_server/set_parameters", srv_req, srv_resp)){
    // if(ros::service::call("/control_dynparam/set_parameters", srv_req, srv_resp)){
        ROS_INFO("control_dynparam.cpp- call to set parameters succeeded");
    }else{
        ROS_ERROR("control_dynparam.cpp- call to set parameters failed");
    }
}
void loadDynparamDefault(){
    system("rosrun dynamic_reconfigure dynparam load /dynparam_server /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_default.yaml");
    ROS_INFO("control_dynparam.cpp- loadDynparamDefault");
}
void saveDynparamDefault(){
    if(isSaveDynparamDefault){
        system("rosrun dynamic_reconfigure dynparam dump /dynparam_server /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_default.yaml");
        ROS_INFO("control_dynparam.cpp- saved Dynparam Default");
        isSaveDynparamDefault = false;
    }
}
void loadDynparamRuntime(){
    system("rosrun dynamic_reconfigure dynparam load /dynparam_server /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_runtime.yaml");
    ROS_INFO("control_dynparam.cpp- loadDynparamRuntime");
}
void saveDynparamRuntime(){
    system("rosrun dynamic_reconfigure dynparam dump /dynparam_server /home/nhamtung/TungNV/ros_basic_ws/install/share/param_pkg/cfg/param_runtime.yaml");
    ROS_INFO("control_dynparam.cpp- saveDynparamRuntime");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "control_dynparam");
    ros::NodeHandle n;
    ROS_INFO("control_dynparam.cpp - Create node control_dynparam");

    ros::Subscriber sub = n.subscribe("/control_dynparam", 10, controlParamCallback);
    ROS_INFO("control_dynparam.cpp- Subscriber topic /control_dynparam");

    dynamic_reconfigure::Client<param_pkg::robotConfig> client("dynparam_server", dynparamCallBack); //Subscribe to the service and set the callback function to read back the latest parameters after the change

    saveDynparamDefault();

    ros::spin();
    return 0;
}