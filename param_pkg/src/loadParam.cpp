
#include "ros/ros.h"

float L = 0;
int thesholdQualityPose = 0;
bool loadParam(std::string node_name);

bool loadParam(std::string node_name){
	ROS_INFO("loadParam.cpp-loadParam() -> node_name: %s", node_name.c_str());

	if(!ros::param::get(node_name + "/L", L)){
		return false;
	}
	ROS_INFO("loadParam.cpp- L: %f", L);
	
	if(!ros::param::get(node_name + "/thesholdQualityPose", thesholdQualityPose)){
		return false;
	}
	ROS_INFO("loadParam.cpp- thesholdQualityPose: %d", thesholdQualityPose);

	return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "loadParam");
    ros::NodeHandle n;
    ROS_INFO("Create node: loadParam");

    std::string node_name = ros::this_node::getName();
	ROS_INFO("loadParam.cpp-node_name: %s", node_name.c_str());
	if(loadParam(node_name)){
		ROS_INFO("loadParam.cpp-Load parameter successfull");
	}else{
		ROS_ERROR("loadParam.cpp-Error when load parameter");
	}

    ros::spin();
    return 0;
}