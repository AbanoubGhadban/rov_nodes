#include "ros/ros.h"
#include "rov_nodes/GetMetalType.h"

std::string checkMetalType() {
    // Simulating detection of metal
    sleep(1);
    int rnd = std::rand()%4;
    if (!rnd)
        throw "Can't Detect Metal";
    if (rnd == 1)
        return "Iron";
    if (rnd == 2)
        return "Copper";
    return "Aluminum";
}

bool getMetalType(rov_nodes::GetMetalType::Request &req,
         rov_nodes::GetMetalType::Response &res)
{
    ROS_INFO("Received Request to Check Metal Type");
    try {
        std::string metalType = checkMetalType();
        res.metalType = metalType;
        ROS_INFO("Metal Type is %s", metalType.c_str());
        return true;
    } catch (...) {
        ROS_INFO("Could't detect metal");
        return false;
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_metal_type_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_metal_type", getMetalType);
  ROS_INFO("Ready to Receive Requests");
  ros::spin();

  return 0;
}
