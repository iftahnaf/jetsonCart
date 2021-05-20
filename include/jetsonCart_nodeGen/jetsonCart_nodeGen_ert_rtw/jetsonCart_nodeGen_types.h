//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: jetsonCart_nodeGen_types.h
//
// Code generated for Simulink model 'jetsonCart_nodeGen'.
//
// Model version                  : 3.479
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Thu May  6 20:03:16 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_jetsonCart_nodeGen_types_h_
#define RTW_HEADER_jetsonCart_nodeGen_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_Int8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_Int8_

// MsgType=std_msgs/Int8
typedef struct {
  int8_T Data;
} SL_Bus_jetsonCart_nodeGen_std_msgs_Int8;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_jetsonCart_nodeGen_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_jetsonCart_nodeGen_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
} SL_Bus_jetsonCart_nodeGen_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range_
#define DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range_

// MsgType=sensor_msgs/Range
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_jetsonCart_nodeGen_std_msgs_Header Header;
  uint8_T RadiationType;
  real32_T FieldOfView;
  real32_T MinRange;
  real32_T MaxRange;
  real32_T Range_;
} SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16_
#define DEFINED_TYPEDEF_FOR_SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16_

// MsgType=std_msgs/UInt16
typedef struct {
  uint16_T Data;
} SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16;

#endif

#ifndef struct_tag_D6QYIVJDjoKN0blLVEpT8F
#define struct_tag_D6QYIVJDjoKN0blLVEpT8F

struct tag_D6QYIVJDjoKN0blLVEpT8F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_D6QYIVJDjoKN0blLVEpT8F

#ifndef typedef_ros_slroscpp_internal_block_P_T
#define typedef_ros_slroscpp_internal_block_P_T

typedef tag_D6QYIVJDjoKN0blLVEpT8F ros_slroscpp_internal_block_P_T;

#endif                                 //typedef_ros_slroscpp_internal_block_P_T

#ifndef struct_tag_rVaL2jCthDg1Nc4cghuMrG
#define struct_tag_rVaL2jCthDg1Nc4cghuMrG

struct tag_rVaL2jCthDg1Nc4cghuMrG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rVaL2jCthDg1Nc4cghuMrG

#ifndef typedef_ros_slros_internal_block_SetP_T
#define typedef_ros_slros_internal_block_SetP_T

typedef tag_rVaL2jCthDg1Nc4cghuMrG ros_slros_internal_block_SetP_T;

#endif                                 //typedef_ros_slros_internal_block_SetP_T

#ifndef struct_tag_KSdGoEc2IyOHz4CLi4rcCD
#define struct_tag_KSdGoEc2IyOHz4CLi4rcCD

struct tag_KSdGoEc2IyOHz4CLi4rcCD
{
  int32_T __dummy;
};

#endif                                 //struct_tag_KSdGoEc2IyOHz4CLi4rcCD

#ifndef typedef_f_robotics_slcore_internal_bl_T
#define typedef_f_robotics_slcore_internal_bl_T

typedef tag_KSdGoEc2IyOHz4CLi4rcCD f_robotics_slcore_internal_bl_T;

#endif                                 //typedef_f_robotics_slcore_internal_bl_T

#ifndef struct_tag_PzhaB0v2Sx4ikuHWZx5WUB
#define struct_tag_PzhaB0v2Sx4ikuHWZx5WUB

struct tag_PzhaB0v2Sx4ikuHWZx5WUB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                 //struct_tag_PzhaB0v2Sx4ikuHWZx5WUB

#ifndef typedef_ros_slros_internal_block_GetP_T
#define typedef_ros_slros_internal_block_GetP_T

typedef tag_PzhaB0v2Sx4ikuHWZx5WUB ros_slros_internal_block_GetP_T;

#endif                                 //typedef_ros_slros_internal_block_GetP_T

#ifndef struct_tag_eFCXAaC7vLdwjksE0MwgOD
#define struct_tag_eFCXAaC7vLdwjksE0MwgOD

struct tag_eFCXAaC7vLdwjksE0MwgOD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_eFCXAaC7vLdwjksE0MwgOD

#ifndef typedef_ros_slroscpp_internal_block_S_T
#define typedef_ros_slroscpp_internal_block_S_T

typedef tag_eFCXAaC7vLdwjksE0MwgOD ros_slroscpp_internal_block_S_T;

#endif                                 //typedef_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_jetsonCart_nodeGen_T_ P_jetsonCart_nodeGen_T;

// Forward declaration for rtModel
typedef struct tag_RTM_jetsonCart_nodeGen_T RT_MODEL_jetsonCart_nodeGen_T;

#endif                                // RTW_HEADER_jetsonCart_nodeGen_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
