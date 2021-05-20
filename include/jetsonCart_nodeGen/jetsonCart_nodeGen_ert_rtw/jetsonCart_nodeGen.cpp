//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: jetsonCart_nodeGen.cpp
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
#include "jetsonCart_nodeGen.h"
#include "jetsonCart_nodeGen_private.h"

// Block signals (default storage)
B_jetsonCart_nodeGen_T jetsonCart_nodeGen_B;

// Block states (default storage)
DW_jetsonCart_nodeGen_T jetsonCart_nodeGen_DW;

// Real-time model
RT_MODEL_jetsonCart_nodeGen_T jetsonCart_nodeGen_M_ =
  RT_MODEL_jetsonCart_nodeGen_T();
RT_MODEL_jetsonCart_nodeGen_T *const jetsonCart_nodeGen_M =
  &jetsonCart_nodeGen_M_;

// Model step function
void jetsonCart_nodeGen_step(void)
{
  SL_Bus_jetsonCart_nodeGen_std_msgs_Int8 rtb_BusAssignment;
  SL_Bus_jetsonCart_nodeGen_std_msgs_UInt16 b_varargout_2;
  real_T drivingTime;
  int32_T pose;
  int32_T xpageoffset;
  real32_T rtb_Saturation;
  boolean_T b_varargout_1;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  b_varargout_1 = Sub_jetsonCart_nodeGen_422.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    jetsonCart_nodeGen_B.In1_o = b_varargout_2;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  b_varargout_1 = Sub_jetsonCart_nodeGen_419.getLatestMessage
    (&jetsonCart_nodeGen_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (b_varargout_1) {
    jetsonCart_nodeGen_B.In1 = jetsonCart_nodeGen_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Saturate: '<Root>/Saturation'
  if (jetsonCart_nodeGen_B.In1.Range_ > jetsonCart_nodeGen_P.Saturation_UpperSat)
  {
    rtb_Saturation = jetsonCart_nodeGen_P.Saturation_UpperSat;
  } else if (jetsonCart_nodeGen_B.In1.Range_ <
             jetsonCart_nodeGen_P.Saturation_LowerSat) {
    rtb_Saturation = jetsonCart_nodeGen_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = jetsonCart_nodeGen_B.In1.Range_;
  }

  // End of Saturate: '<Root>/Saturation'

  // MATLABSystem: '<Root>/StartCart'
  ParamGet_jetsonCart_nodeGen_471.get_parameter(&drivingTime);

  // Outputs for Enabled SubSystem: '<Root>/Scan Logic' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (drivingTime > 0.0) {
    // MATLAB Function: '<S5>/MATLAB Function' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion'

    pose = jetsonCart_nodeGen_B.In1_o.Data;
    if (jetsonCart_nodeGen_B.In1_o.Data < 36) {
      pose = 36;
    }

    if (pose > 136) {
      pose = 136;
    }

    if (!jetsonCart_nodeGen_DW.j_not_empty) {
      jetsonCart_nodeGen_DW.j = ((static_cast<real_T>(pose) - 36.0) + 2.0) / 2.0;
      jetsonCart_nodeGen_DW.j = floor(jetsonCart_nodeGen_DW.j);
      jetsonCart_nodeGen_DW.j_not_empty = true;
    }

    if (jetsonCart_nodeGen_DW.i < 5.0) {
      jetsonCart_nodeGen_DW.rangeMat[(static_cast<int32_T>
        (jetsonCart_nodeGen_DW.i) + ((static_cast<int32_T>
        (jetsonCart_nodeGen_DW.j) - 1) << 2)) - 1] = rtb_Saturation;
      jetsonCart_nodeGen_DW.j = ((static_cast<real_T>(pose) - 36.0) + 2.0) / 2.0;
      jetsonCart_nodeGen_DW.j = floor(jetsonCart_nodeGen_DW.j);
    }

    if ((jetsonCart_nodeGen_DW.j == 51.0) && (jetsonCart_nodeGen_DW.flag == 0.0))
    {
      jetsonCart_nodeGen_DW.i++;
      jetsonCart_nodeGen_DW.flag = 1.0;
    }

    if ((jetsonCart_nodeGen_DW.j == 1.0) && (jetsonCart_nodeGen_DW.flag == 1.0))
    {
      jetsonCart_nodeGen_DW.flag = 0.0;
      jetsonCart_nodeGen_DW.i++;
    }

    if (jetsonCart_nodeGen_DW.i == 5.0) {
      jetsonCart_nodeGen_B.ready = 1.0;
      jetsonCart_nodeGen_DW.i = 1.0;
      jetsonCart_nodeGen_DW.j = 1.0;
      jetsonCart_nodeGen_DW.flag = 0.0;
    } else {
      jetsonCart_nodeGen_B.ready = 0.0;
    }

    memcpy(&jetsonCart_nodeGen_B.distMatrix[0], &jetsonCart_nodeGen_DW.rangeMat
           [0], 204U * sizeof(real_T));

    // End of MATLAB Function: '<S5>/MATLAB Function'
  }

  // End of MATLABSystem: '<Root>/StartCart'
  // End of Outputs for SubSystem: '<Root>/Scan Logic'

  // Outputs for Atomic SubSystem: '<Root>/Driving Logic'
  // MATLAB Function: '<S2>/MATLAB Function'
  if (rtIsNaN(jetsonCart_nodeGen_B.ready)) {
    jetsonCart_nodeGen_DW.cmdTmp = 1.0;
    pose = 0;
    jetsonCart_nodeGen_DW.counter = 0.0;
  } else if (jetsonCart_nodeGen_B.ready == 0.0) {
    jetsonCart_nodeGen_DW.cmdTmp = 1.0;
    pose = 0;
    jetsonCart_nodeGen_DW.counter = 0.0;
  } else {
    pose = 1;
    memcpy(&jetsonCart_nodeGen_DW.matrixTmp[0],
           &jetsonCart_nodeGen_B.distMatrix[0], 204U * sizeof(real_T));
  }

  if ((pose == 1) && (jetsonCart_nodeGen_DW.counter == 0.0)) {
    jetsonCart_nodeGen_DW.counter = 1.0;
    for (pose = 0; pose < 51; pose++) {
      xpageoffset = pose << 2;
      jetsonCart_nodeGen_DW.meanMatrixTmp[pose] =
        jetsonCart_nodeGen_DW.matrixTmp[xpageoffset];
      jetsonCart_nodeGen_DW.meanMatrixTmp[pose] +=
        jetsonCart_nodeGen_DW.matrixTmp[xpageoffset + 1];
      jetsonCart_nodeGen_DW.meanMatrixTmp[pose] +=
        jetsonCart_nodeGen_DW.matrixTmp[xpageoffset + 2];
      jetsonCart_nodeGen_DW.meanMatrixTmp[pose] +=
        jetsonCart_nodeGen_DW.matrixTmp[xpageoffset + 3];
      jetsonCart_nodeGen_DW.meanMatrixTmp[pose] /= 4.0;
      jetsonCart_nodeGen_B.gapsTmp[pose] = 0.0;
    }

    for (pose = 0; pose < 46; pose++) {
      drivingTime = jetsonCart_nodeGen_DW.meanMatrixTmp[pose];
      for (xpageoffset = 0; xpageoffset < 5; xpageoffset++) {
        drivingTime += jetsonCart_nodeGen_DW.meanMatrixTmp[(xpageoffset + pose)
          + 1];
      }

      jetsonCart_nodeGen_B.gapsTmp[pose] = drivingTime / 6.0;
    }

    if (!rtIsNaN(jetsonCart_nodeGen_B.gapsTmp[0])) {
      pose = 1;
    } else {
      pose = 0;
      xpageoffset = 2;
      exitg1 = false;
      while ((!exitg1) && (xpageoffset < 52)) {
        if (!rtIsNaN(jetsonCart_nodeGen_B.gapsTmp[xpageoffset - 1])) {
          pose = xpageoffset;
          exitg1 = true;
        } else {
          xpageoffset++;
        }
      }
    }

    if (pose == 0) {
      drivingTime = jetsonCart_nodeGen_B.gapsTmp[0];
      pose = 1;
    } else {
      drivingTime = jetsonCart_nodeGen_B.gapsTmp[pose - 1];
      for (xpageoffset = pose; xpageoffset < 51; xpageoffset++) {
        if (drivingTime < jetsonCart_nodeGen_B.gapsTmp[xpageoffset]) {
          drivingTime = jetsonCart_nodeGen_B.gapsTmp[xpageoffset];
          pose = xpageoffset + 1;
        }
      }
    }

    jetsonCart_nodeGen_DW.dirTmp = pose;
    if (drivingTime < 50.0) {
      jetsonCart_nodeGen_DW.cmdTmp = 3.0;
    } else if ((pose <= 30) && (pose >= 15)) {
      jetsonCart_nodeGen_DW.cmdTmp = 2.0;
    } else if (pose > 30) {
      jetsonCart_nodeGen_DW.cmdTmp = 5.0;
    } else {
      jetsonCart_nodeGen_DW.cmdTmp = 4.0;
    }
  }

  if (rtb_Saturation < 50.0F) {
    jetsonCart_nodeGen_DW.cmdTmp = 1.0;
  }

  if (jetsonCart_nodeGen_DW.cmdTmp != 1.0) {
    jetsonCart_nodeGen_DW.counter++;
  }

  if ((jetsonCart_nodeGen_DW.cmdTmp == 2.0) || (jetsonCart_nodeGen_DW.cmdTmp ==
       3.0)) {
    drivingTime = 60.0;
  } else if (jetsonCart_nodeGen_DW.cmdTmp == 4.0) {
    drivingTime = fabs((1.0 - 15.0 / jetsonCart_nodeGen_DW.dirTmp) * 10.0 + 10.0)
      / 2.0;
  } else {
    drivingTime = fabs((1.0 - 30.0 / jetsonCart_nodeGen_DW.dirTmp) * 60.0 + 10.0)
      / 2.0;
  }

  if (jetsonCart_nodeGen_DW.counter > drivingTime) {
    jetsonCart_nodeGen_DW.cmdTmp = 1.0;
    jetsonCart_nodeGen_DW.counter = 0.0;
  }

  // DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
  //   MATLAB Function: '<S2>/MATLAB Function'

  drivingTime = floor(jetsonCart_nodeGen_DW.cmdTmp);

  // End of Outputs for SubSystem: '<Root>/Driving Logic'
  if (rtIsNaN(drivingTime) || rtIsInf(drivingTime)) {
    drivingTime = 0.0;
  } else {
    drivingTime = fmod(drivingTime, 256.0);
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  rtb_BusAssignment.Data = static_cast<int8_T>(drivingTime < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-drivingTime)))) : static_cast<int32_T>
    (static_cast<int8_T>(static_cast<uint8_T>(drivingTime))));

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_jetsonCart_nodeGen_429.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Outputs for Atomic SubSystem: '<Root>/Driving Logic'
  // MATLABSystem: '<Root>/Set Parameter' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S3>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   MATLAB Function: '<S2>/MATLAB Function'
  //   RelationalOperator: '<S3>/Compare'
  //   Sum: '<Root>/Add'

  ParamSet_jetsonCart_nodeGen_479.set_parameter(static_cast<real_T>
    (jetsonCart_nodeGen_DW.cmdTmp - jetsonCart_nodeGen_P.Constant_Value_o ==
     jetsonCart_nodeGen_P.Constant_Value_a));

  // End of Outputs for SubSystem: '<Root>/Driving Logic'
}

// Model initialize function
void jetsonCart_nodeGen_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T tmp_0[11] = { '/', 'u', 'l', 't', 'r', 'a', 's', 'o',
      'u', 'n', 'd' };

    static const char_T tmp_2[10] = { '/', 's', 't', 'a', 'r', 't', 'C', 'a',
      'r', 't' };

    static const char_T tmp_1[9] = { '/', 'c', 'o', 'm', 'm', 'a', 'n', 'd', 's'
    };

    static const char_T tmp[6] = { '/', 's', 'e', 'r', 'v', 'o' };

    int32_T i;
    char_T b_zeroDelimTopic_0[12];
    char_T b_zeroDelimName[11];
    char_T b_zeroDelimName_tmp[11];
    char_T b_zeroDelimTopic_1[10];
    char_T b_zeroDelimTopic[7];

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1' incorporates:
    //   Inport: '<S11>/In1'

    jetsonCart_nodeGen_B.In1_o = jetsonCart_nodeGen_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    jetsonCart_nodeGen_DW.obj_k.matlabCodegenIsDeleted = false;
    jetsonCart_nodeGen_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[6] = '\x00';
    Sub_jetsonCart_nodeGen_422.createSubscriber(&b_zeroDelimTopic[0], 1);
    jetsonCart_nodeGen_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    jetsonCart_nodeGen_B.In1 = jetsonCart_nodeGen_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    jetsonCart_nodeGen_DW.obj_lu.matlabCodegenIsDeleted = false;
    jetsonCart_nodeGen_DW.obj_lu.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[11] = '\x00';
    Sub_jetsonCart_nodeGen_419.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    jetsonCart_nodeGen_DW.obj_lu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<Root>/Scan Logic'
    // SystemInitialize for MATLAB Function: '<S5>/MATLAB Function'
    jetsonCart_nodeGen_DW.i = 1.0;

    // SystemInitialize for Outport: '<S5>/ready'
    jetsonCart_nodeGen_B.ready = jetsonCart_nodeGen_P.ready_Y0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Driving Logic'
    for (i = 0; i < 204; i++) {
      // SystemInitialize for Outport: '<S5>/distMatrix'
      jetsonCart_nodeGen_B.distMatrix[i] = jetsonCart_nodeGen_P.distMatrix_Y0;
    }

    // End of SystemInitialize for SubSystem: '<Root>/Driving Logic'
    // End of SystemInitialize for SubSystem: '<Root>/Scan Logic'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    jetsonCart_nodeGen_DW.obj_d.matlabCodegenIsDeleted = false;
    jetsonCart_nodeGen_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_jetsonCart_nodeGen_429.createPublisher(&b_zeroDelimTopic_1[0], 1);
    jetsonCart_nodeGen_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // Start for MATLABSystem: '<Root>/StartCart' incorporates:
    //   MATLABSystem: '<Root>/Set Parameter'

    jetsonCart_nodeGen_DW.obj.matlabCodegenIsDeleted = false;
    jetsonCart_nodeGen_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimName_tmp[i] = tmp_2[i];
    }

    b_zeroDelimName_tmp[10] = '\x00';
    for (i = 0; i < 11; i++) {
      b_zeroDelimName[i] = b_zeroDelimName_tmp[i];
    }

    ParamGet_jetsonCart_nodeGen_471.initialize(&b_zeroDelimName[0]);
    ParamGet_jetsonCart_nodeGen_471.initialize_error_codes(0, 1, 2, 3);
    ParamGet_jetsonCart_nodeGen_471.set_initial_value(0.0);
    jetsonCart_nodeGen_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/StartCart'

    // Start for MATLABSystem: '<Root>/Set Parameter'
    jetsonCart_nodeGen_DW.obj_l.matlabCodegenIsDeleted = false;
    jetsonCart_nodeGen_DW.obj_l.isInitialized = 1;
    ParamSet_jetsonCart_nodeGen_479.initialize(&b_zeroDelimName_tmp[0]);
    jetsonCart_nodeGen_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void jetsonCart_nodeGen_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!jetsonCart_nodeGen_DW.obj_k.matlabCodegenIsDeleted) {
    jetsonCart_nodeGen_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!jetsonCart_nodeGen_DW.obj_lu.matlabCodegenIsDeleted) {
    jetsonCart_nodeGen_DW.obj_lu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<Root>/StartCart'
  if (!jetsonCart_nodeGen_DW.obj.matlabCodegenIsDeleted) {
    jetsonCart_nodeGen_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/StartCart'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!jetsonCart_nodeGen_DW.obj_d.matlabCodegenIsDeleted) {
    jetsonCart_nodeGen_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for MATLABSystem: '<Root>/Set Parameter'
  if (!jetsonCart_nodeGen_DW.obj_l.matlabCodegenIsDeleted) {
    jetsonCart_nodeGen_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Set Parameter'
}

//
// File trailer for generated code.
//
// [EOF]
//
