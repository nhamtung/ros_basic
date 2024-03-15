#include "ros/ros.h"
#include <boost/thread.hpp>
#include <agv_define/define.h>
#include <diagnostic_msgs/DiagnosticArray.h>

double frequence = 5.0;			// Hz

boost::thread* loop_thread;
ros::Publisher diagnostic_pub;
diagnostic_msgs::DiagnosticArray prev_diagnostic;

// Mandatory
diagnostic_msgs::DiagnosticStatus init_node;
// Mandatory if node connect to other devices
diagnostic_msgs::DiagnosticStatus connection;
// Optional
diagnostic_msgs::DiagnosticStatus other_status;

void pubDiagnostic() {
    diagnostic_msgs::DiagnosticArray diagnostic;
    
    diagnostic.status.push_back(init_node);
    diagnostic.status.push_back(connection);
    diagnostic.status.push_back(other_status);

    if(diagnostic.status != prev_diagnostic.status) {
      diagnostic.header.seq = prev_diagnostic.header.seq+1;
      diagnostic.header.stamp = ros::Time::now();
      diagnostic.header.frame_id = "frame_id";

      diagnostic_pub.publish(diagnostic);
      prev_diagnostic = diagnostic;
    }
}
void loopThread(ros::NodeHandle n){
    ros::Rate r((int)frequence);
    int count = 0;
    while (ros::ok()){
        ros::spinOnce();               // check for incoming messages

        if(connection.level == OPERATOR_OK){
          // getVoltate();
          if(count%10 == 0){
            other_status.level = OPERATOR_ERROR;
            other_status.message = "Can not get Voltate of Battery";
          }
          if(count%20 == 0){
            other_status.level = OPERATOR_WARN;
            other_status.message = "Battery low";
            diagnostic_msgs::KeyValue voltate;
            voltate.key = "voltate";
            voltate.value = to_string(count);
            other_status.values.clear();
            other_status.values.push_back(voltate);
          }
        }
        if(count >= 300){
          connection.level = OPERATOR_ERROR;
          connection.message = "Disconnection with Battery";
        }
        pubDiagnostic();
        count++;
        r.sleep();
    }
}

void loadParam(ros::NodeHandle n, std::string node_name){
    n.param<double>(node_name + "/frequence", frequence, 5.0);
    ROS_INFO("%s/frequence: %.1f", node_name.c_str(), frequence);
}
int main(int argc, char **argv)
{	
    ros::init(argc, argv, "diagnostic_example");
    ros::NodeHandle n;

    std::string node_name = ros::this_node::getName();
    ROS_INFO("node_name: %s", node_name.c_str());
    loadParam(n, node_name);

  	diagnostic_pub = n.advertise<diagnostic_msgs::DiagnosticArray>("/diagnostic", 10);  // Note: Change the name of topic
  	loop_thread = new boost::thread (&loopThread, n);

    ros::Duration(0.5).sleep();
    // Example Init node
    init_node.name = "init_node";
    init_node.hardware_id = "None";
    init_node.level = OPERATOR_STABLE;
    init_node.message = "Start Node";
    // Example connection with Battery
    connection.name = "connection";
    connection.hardware_id = "Battery";
    connection.level = OPERATOR_STABLE;
    connection.message = "Start Node";
    // Example other status
    other_status.name = "get_voltate";
    other_status.hardware_id = "Battery";
    other_status.level = OPERATOR_STABLE;
    other_status.message = "Start Node";
    pubDiagnostic();
	
    // Connect to Battery
    ros::Duration(2).sleep();
    connection.level = OPERATOR_OK;
    connection.message = "Connected to Battery";
    pubDiagnostic();

    if(connection.level == OPERATOR_OK){
      init_node.level = OPERATOR_OK;
      init_node.message = "Started Node";
    }else{
      init_node.level = OPERATOR_ERROR;
      init_node.message = "Cannot connect to device";
    }
    pubDiagnostic();

    ros::spin();
	  return 0;
}