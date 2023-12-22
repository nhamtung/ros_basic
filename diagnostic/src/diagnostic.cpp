#include "ros/ros.h"
#include <boost/thread.hpp>

#include "agv_define/define.h"
#include <diagnostic_msgs/DiagnosticArray.h>

boost::thread* diagnostic_thread;
ros::Publisher diagnostic_pub;

double frequence = 5.0;			// Hz
DiagnosticStruct diagnostic_define;

void pubDiagnostic() {
    diagnostic_msgs::DiagnosticArray prev_diagnostic;
    diagnostic_msgs::DiagnosticArray diagnostic;
    diagnostic_msgs::DiagnosticStatus node_status;

    diagnostic_msgs::KeyValue connection;
    diagnostic_msgs::KeyValue runtime_name;
    diagnostic_msgs::KeyValue runtime_status;
    diagnostic_msgs::KeyValue runtime_msg;

    diagnostic.header.stamp = ros::Time::now();
    diagnostic.header.frame_id = diagnostic_define.frame_id;
    node_status.level = diagnostic_define.operator_level;
    node_status.name = diagnostic_define.node_name;
    node_status.message = diagnostic_define.node_message;
    node_status.hardware_id = diagnostic_define.hardware_id;

    connection.key = "connection";
    connection.value = diagnostic_define.connection;
    node_status.values.push_back(connection);

    runtime_name.key = "runtime name";
    runtime_name.value = diagnostic_define.runtime_name;
    node_status.values.push_back(runtime_name);
    runtime_status.key = "runtime status";
    runtime_status.value = to_string(diagnostic_define.runtime_status);
    node_status.values.push_back(runtime_status);
    runtime_msg.key = "runtime ressage";
    runtime_msg.value = diagnostic_define.runtime_msg;
    node_status.values.push_back(runtime_msg);

    diagnostic.status.push_back(node_status);
    if(diagnostic.status != prev_diagnostic.status) diagnostic_pub.publish(diagnostic);
    prev_diagnostic = diagnostic;
}
void diagnosticThread(ros::NodeHandle n){
    ros::Rate r((int)frequence);
    int count = 0;
    while (ros::ok()){
        ros::spinOnce();               // check for incoming messages
        if(diagnostic_define.operator_level == OPERATOR_OK){
          count++;
          ROS_INFO("count = %d", count);
          if(count % (int)frequence == 0){
            diagnostic_define.runtime_name = "Count";
            diagnostic_define.runtime_status = ActionStatus::SUCCEEDED;
            diagnostic_define.runtime_msg = to_string(count);
            pubDiagnostic();
          }
          if(count > 10*frequence){
            diagnostic_define.runtime_name = "Break";
            diagnostic_define.runtime_status = ActionStatus::SUCCEEDED;
            diagnostic_define.runtime_msg = "Break and close loop";
            pubDiagnostic();
            break;
          }
        }
        r.sleep();
    }
}

void loadParam(ros::NodeHandle n, std::string node_name){
    n.param<double>(node_name + "/frequence", frequence, 5.0);
    ROS_INFO("%s/frequence: %.1f", node_name.c_str(), frequence);
}
int main(int argc, char **argv)
{	
    ros::init(argc, argv, "diagnostic");
    ros::NodeHandle n;

    std::string node_name = ros::this_node::getName();
    ROS_INFO("node_name: %s", node_name.c_str());
    loadParam(n, node_name);

  	diagnostic_pub = n.advertise<diagnostic_msgs::DiagnosticArray>("/diagnostic_test", 10);
  	diagnostic_thread = new boost::thread (&diagnosticThread, n);

    diagnostic_define.frame_id = "None";
    diagnostic_define.operator_level = OPERATOR_ERROR;
    diagnostic_define.node_name = "node_name";
    diagnostic_define.node_message = "Starting node";
    diagnostic_define.hardware_id = "hardware test";
    diagnostic_define.connection = "Disconnected";
    diagnostic_define.runtime_status = ActionStatus::PENDING;
    diagnostic_define.runtime_msg = "";
    pubDiagnostic();
    ROS_INFO("Starting node");
	
    ros::Duration(2).sleep();

    diagnostic_define.operator_level = OPERATOR_WARN;
    diagnostic_define.node_message = "Node started";
    diagnostic_define.connection = "Connected";
    diagnostic_define.runtime_name = "Waiting";
    diagnostic_define.runtime_status = ActionStatus::ACTIVE;
    diagnostic_define.runtime_msg = "Waiting for 5s";
    pubDiagnostic();
    ROS_INFO("Node started");

    ros::Duration(5).sleep();

    diagnostic_define.operator_level = OPERATOR_OK;
    diagnostic_define.node_message = "Node started";
    diagnostic_define.connection = "Connected";
    diagnostic_define.runtime_name = "Waiting";
    diagnostic_define.runtime_status = ActionStatus::SUCCEEDED;
    diagnostic_define.runtime_msg = "Done";
    pubDiagnostic();
    ROS_INFO("Connected");

    ros::spin();
	  return 0;
}