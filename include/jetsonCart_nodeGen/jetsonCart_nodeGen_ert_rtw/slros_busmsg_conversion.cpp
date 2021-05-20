#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_jetsonCart_nodeGen_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_jetsonCart_nodeGen_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_jetsonCart_nodeGen_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range and sensor_msgs::Range

void convertFromBus(sensor_msgs::Range* msgPtr, SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Range");

  msgPtr->field_of_view =  busPtr->FieldOfView;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->max_range =  busPtr->MaxRange;
  msgPtr->min_range =  busPtr->MinRange;
  msgPtr->radiation_type =  busPtr->RadiationType;
  msgPtr->range =  busPtr->Range_;
}

void convertToBus(SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range* busPtr, sensor_msgs::Range const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Range");

  busPtr->FieldOfView =  msgPtr->field_of_view;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->MaxRange =  msgPtr->max_range;
  busPtr->MinRange =  msgPtr->min_range;
  busPtr->RadiationType =  msgPtr->radiation_type;
  busPtr->Range_ =  msgPtr->range;
}


// Conversions between SL_Bus_jetsonCart_nodeGen_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_jetsonCart_nodeGen_std_msgs_Int8 and std_msgs::Int8

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_Int8 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 and std_msgs::UInt16

void convertFromBus(std_msgs::UInt16* msgPtr, SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 const* busPtr)
{
  const std::string rosMessageType("std_msgs/UInt16");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16* busPtr, std_msgs::UInt16 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/UInt16");

  busPtr->Data =  msgPtr->data;
}

