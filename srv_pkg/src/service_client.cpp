#include "ros/ros.h"
#include "srv_pkg/test_srv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<srv_pkg::test_srv>("add_two_ints");
  srv_pkg::test_srv srv;
  
  srv.request.a = 1;
  srv.request.b = 2;
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}