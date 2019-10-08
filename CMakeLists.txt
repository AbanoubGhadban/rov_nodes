# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(rov_nodes)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS geometry_msgs roscpp rospy std_msgs
                    message_generation message_runtime)


add_service_files(
    FILES
    GetMetalType.srv
    )                    

generate_messages()

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(rov_velocity_node src/rov_velocity.cpp)
add_executable(get_metal_type_server src/get_metal_type_server.cpp)
target_link_libraries(rov_velocity_node ${catkin_LIBRARIES})
target_link_libraries(get_metal_type_server ${catkin_LIBRARIES})

# %EndTag(FULLTEXT)%
