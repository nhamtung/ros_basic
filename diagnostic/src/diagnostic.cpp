#include "ros/ros.h"
#include <boost/thread.hpp>

#include "agv_define/define.h"
#include <diagnostic_msgs/DiagnosticArray.h>

boost::thread* diagnostic_thread;
ros::Publisher diagnostic_pub;

double frequence = 5.0;			// Hz

agv_define::DiagnosticStruct diagnostic_define;

void pubDiagnostic(){
  diagnostic_msgs::DiagnosticArray prev_diagnostic;
  diagnostic_msgs::DiagnosticArray diagnostic;
  diagnostic_msgs::DiagnosticStatus node_status;

  diagnostic_msgs::KeyValue driver_ready;
  diagnostic_msgs::KeyValue runtime_info;

  diagnostic.header.stamp = ros::Time::now();
  diagnostic.header.frame_id = "connection";
  node_status.level = system_state;
  node_status.name = "connection";
  node_status.message = system_message;
  node_status.hardware_id = "connection";
  driver_ready.key = "driver_is_ready";
  driver_ready.value = to_string(is_ready);
  runtime_info.key = "runtime_info";
  runtime_info.value = runtime_message;

  node_status.values.push_back(driver_ready);
  node_status.values.push_back(runtime_info);
  diagnostic_connection.status.push_back(node_status);
  if(diagnostic_connection.status != prev_diagnostic_connection.status) diagnostic_pub.publish(diagnostic_connection);
  prev_diagnostic_connection = diagnostic_connection;
}
void diagnosticThread(ros::NodeHandle n){
  ros::Rate r((int)frequence);
  while (ros::ok()){
    ros::spinOnce();               // check for incoming messages
    pubDiagnostic();
    r.sleep();
  }
}

void loadParam(ros::NodeHandle n, std::string node_name){
  n.param<double>(node_name + "/frequence", frequence, 5.0);
  ROS_INFO("%s/frequence: %f", node_name.c_str(), frequence);
}
int main(int argc, char **argv)
{	
	ros::init(argc, argv, "diagnostic");
	ros::NodeHandle n;

	std::string node_name = ros::this_node::getName();
	ROS_INFO("node_name: %s", node_name.c_str());
	loadParam(n, node_name);

	diagnostic_define.operator_level = OPERATOR_ERROR;
	diagnostic_define.node_name = "test_diagnostic";
	diagnostic_define.node_message = "Start node";
	diagnostic_define.hardware_id = "test";
	diagnostic_define.frame_id = "None";
	diagnostic_define.connection = "Disconnected";
	diagnostic_define.runtime_name = "";
	diagnostic_define.runtime_status = ACTIVE;
	diagnostic_define.runtime_msg = "";
	
  	diagnostic_pub = n.advertise<diagnostic_msgs::DiagnosticArray>("/diagnostic_test", 10);
  	diagnostic_thread = new boost::thread (&diagnosticThread, n);

	return 0;
}