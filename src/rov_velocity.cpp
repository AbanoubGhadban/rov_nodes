#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <iostream>

void velocityCallback(const geometry_msgs::Twist& msg)
{
  ROS_INFO("ROV Velocity: Linear[%f, %f, %f], Angular[%f, %f, %f]",
           msg.linear.x, msg.linear.y, msg.linear.z, msg.angular.x, msg.angular.y, msg.angular.z);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rov_velocity_node");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("rov_velocity", 1000, velocityCallback);
  ros::spin();
  return 0;
}
