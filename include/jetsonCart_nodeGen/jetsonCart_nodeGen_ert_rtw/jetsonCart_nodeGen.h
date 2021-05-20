//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: jetsonCart_nodeGen.h
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
#ifndef RTW_HEADER_jetsonCart_nodeGen_h_
#define RTW_HEADER_jetsonCart_nodeGen_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "jetsonCart_nodeGen_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T distMatrix[204];              // '<S5>/MATLAB Function'
  real_T gapsTmp[51];
  SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range In1;// '<S10>/In1'
  SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range b_varargout_2;
  real_T ready;                        // '<S5>/MATLAB Function'
  SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 In1_o;// '<S11>/In1'
} B_jetsonCart_nodeGen_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_GetP_T obj; // '<Root>/StartCart'
  ros_slroscpp_internal_block_P_T obj_d;// '<S4>/SinkBlock'
  ros_slros_internal_block_SetP_T obj_l;// '<Root>/Set Parameter'
  ros_slroscpp_internal_block_S_T obj_k;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_lu;// '<S6>/SourceBlock'
  real_T rangeMat[204];                // '<S5>/MATLAB Function'
  real_T i;                            // '<S5>/MATLAB Function'
  real_T j;                            // '<S5>/MATLAB Function'
  real_T flag;                         // '<S5>/MATLAB Function'
  real_T counter;                      // '<S2>/MATLAB Function'
  real_T matrixTmp[204];               // '<S2>/MATLAB Function'
  real_T cmdTmp;                       // '<S2>/MATLAB Function'
  real_T dirTmp;                       // '<S2>/MATLAB Function'
  real_T meanMatrixTmp[51];            // '<S2>/MATLAB Function'
  boolean_T j_not_empty;               // '<S5>/MATLAB Function'
} DW_jetsonCart_nodeGen_T;

// Parameters (default storage)
struct P_jetsonCart_nodeGen_T_ {
  SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S10>/Out1'

  SL_Bus_jetsonCart_nodeGen_sensor_msgs_Range Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S6>/Constant'

  SL_Bus_jetsonCart_nodeGen_std_msgs_Int8 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                         //  Referenced by: '<S11>/Out1'

  SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                //  Referenced by: '<S7>/Constant'

  real_T distMatrix_Y0;                // Computed Parameter: distMatrix_Y0
                                          //  Referenced by: '<S5>/distMatrix'

  real_T ready_Y0;                     // Computed Parameter: ready_Y0
                                          //  Referenced by: '<S5>/ready'

  real_T Constant_Value_a;             // Expression: 0
                                          //  Referenced by: '<S3>/Constant'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<Root>/Constant'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<Root>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<Root>/Saturation'

};

// Real-time Model Data Structure
struct tag_RTM_jetsonCart_nodeGen_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_jetsonCart_nodeGen_T jetsonCart_nodeGen_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_jetsonCart_nodeGen_T jetsonCart_nodeGen_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_jetsonCart_nodeGen_T jetsonCart_nodeGen_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void jetsonCart_nodeGen_initialize(void);
  extern void jetsonCart_nodeGen_step(void);
  extern void jetsonCart_nodeGen_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_jetsonCart_nodeGen_T *const jetsonCart_nodeGen_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'jetsonCart_nodeGen'
//  '<S1>'   : 'jetsonCart_nodeGen/Blank Message'
//  '<S2>'   : 'jetsonCart_nodeGen/Driving Logic'
//  '<S3>'   : 'jetsonCart_nodeGen/IsZero'
//  '<S4>'   : 'jetsonCart_nodeGen/Publish'
//  '<S5>'   : 'jetsonCart_nodeGen/Scan Logic'
//  '<S6>'   : 'jetsonCart_nodeGen/Subscribe'
//  '<S7>'   : 'jetsonCart_nodeGen/Subscribe1'
//  '<S8>'   : 'jetsonCart_nodeGen/Driving Logic/MATLAB Function'
//  '<S9>'   : 'jetsonCart_nodeGen/Scan Logic/MATLAB Function'
//  '<S10>'  : 'jetsonCart_nodeGen/Subscribe/Enabled Subsystem'
//  '<S11>'  : 'jetsonCart_nodeGen/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_jetsonCart_nodeGen_h_

//
// File trailer for generated code.
//
// [EOF]
//
