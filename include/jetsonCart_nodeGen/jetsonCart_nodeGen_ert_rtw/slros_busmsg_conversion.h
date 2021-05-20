#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int8.h>
#include <std_msgs/UInt16.h>
#include "jetsonCart_nodeGen_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(ros::Time* msgPtr, SL_Bus_jetsonCart_nodeGen_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_jetsonCart_nodeGen_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sensor_msgs::Range* msgPtr, SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range const* busPtr);
void convertToBus(SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range* busPtr, sensor_msgs::Range const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_Int8 const* busPtr);
void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr);

void convertFromBus(std_msgs::UInt16* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 const* busPtr);
void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16* busPtr, std_msgs::UInt16 const* msgPtr);


#endif
