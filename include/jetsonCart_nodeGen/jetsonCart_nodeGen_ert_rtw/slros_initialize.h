#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block jetsonCart_nodeGen/Subscribe
extern SimulinkSubscriber<sensor_msgs::Range, SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range> Sub_jetsonCart_nodeGen_419;

// For Block jetsonCart_nodeGen/Subscribe1
extern SimulinkSubscriber<std_msgs::UInt16, SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16> Sub_jetsonCart_nodeGen_422;

// For Block jetsonCart_nodeGen/Publish
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_jetsonCart_nodeGen_std_msgs_Int8> Pub_jetsonCart_nodeGen_429;

// For Block jetsonCart_nodeGen/StartCart
extern SimulinkParameterGetter<real64_T, double> ParamGet_jetsonCart_nodeGen_471;

// For Block jetsonCart_nodeGen/Set Parameter
extern SimulinkParameterSetter<real64_T, double> ParamSet_jetsonCart_nodeGen_479;

void slros_node_init(int argc, char** argv);

#endif
