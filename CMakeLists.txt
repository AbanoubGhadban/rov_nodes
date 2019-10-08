# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(rov_nodes)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS geometry_msgs roscpp rospy std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

# %EndTag(FULLTEXT)%
