/*
 * File: BMS.c
 *
 * Code generated for Simulink model 'BMS'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 16:54:01 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BMS.h"
#include "BMS_private.h"

/* Block signals (auto storage) */
B_BMS_T BMS_B;

/* Block states (auto storage) */
DW_BMS_T BMS_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_BMS_T BMS_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_BMS_T BMS_Y;

/* Real-time model */
RT_MODEL_BMS_T BMS_M_;
RT_MODEL_BMS_T *const BMS_M = &BMS_M_;

/* Model step function */
void BMS_step(void)
{
  /* ModelReference: '<Root>/schedule' */
  Schedule(&BMS_B.schedule_o1, &BMS_B.schedule_o2, &BMS_B.schedule_o3,
           &(BMS_DW.schedule_DWORK1.rtdw));

  /* ModelReference: '<Root>/Model1' */
  Statistic(&BMS_U.VCell[0], &BMS_B.schedule_o1, &BMS_B.VCellMax, &BMS_Y.Out1,
            &BMS_B.VCellMin, &BMS_Y.Out2, &(BMS_DW.Model1_DWORK1.rtzce));

  /* ModelReference: '<Root>/Model' */
  CoreAlgorithm(&BMS_B.VCellMin, &BMS_U.TCell, &BMS_U.IBat, &BMS_B.schedule_o2,
                &BMS_B.Soc, &(BMS_DW.Model_DWORK1.rtzce));

  /* ModelReference: '<Root>/Model2' */
  FaultGenerator(&BMS_B.VCellMax, &BMS_B.VCellMin, &BMS_B.Soc,
                 &BMS_B.schedule_o3, &BMS_Y.Out3, &BMS_Y.Out4, &BMS_Y.Out5,
                 &BMS_Y.Out6, &BMS_B.FaultLevel, &(BMS_DW.Model2_DWORK1.rtzce));

  /* ModelReference: '<Root>/Model3' */
  CoreLogic(&BMS_U.Acc, &BMS_U.CC, &BMS_B.FaultLevel, &BMS_B.Soc,
            &BMS_B.schedule_o3, &(BMS_DW.Model3_DWORK1.rtdw),
            &(BMS_DW.Model3_DWORK1.rtzce));
}

/* Model initialize function */
void BMS_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BMS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &BMS_B), 0,
                sizeof(B_BMS_T));

  /* states (dwork) */
  (void) memset((void *)&BMS_DW, 0,
                sizeof(DW_BMS_T));

  /* external inputs */
  (void) memset((void *)&BMS_U, 0,
                sizeof(ExtU_BMS_T));

  /* external outputs */
  (void) memset((void *)&BMS_Y, 0,
                sizeof(ExtY_BMS_T));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  CoreAlgorithm_initialize(rtmGetErrorStatusPointer(BMS_M),
    &(BMS_DW.Model_DWORK1.rtm), &(BMS_DW.Model_DWORK1.rtzce));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model1' */
  Statistic_initialize(rtmGetErrorStatusPointer(BMS_M),
                       &(BMS_DW.Model1_DWORK1.rtm), &(BMS_DW.Model1_DWORK1.rtzce));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model2' */
  FaultGenerator_initialize(rtmGetErrorStatusPointer(BMS_M),
    &(BMS_DW.Model2_DWORK1.rtm), &(BMS_DW.Model2_DWORK1.rtzce));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model3' */
  CoreLogic_initialize(rtmGetErrorStatusPointer(BMS_M),
                       &(BMS_DW.Model3_DWORK1.rtm), &(BMS_DW.Model3_DWORK1.rtdw),
                       &(BMS_DW.Model3_DWORK1.rtzce));

  /* Model Initialize fcn for ModelReference Block: '<Root>/schedule' */
  Schedule_initialize(rtmGetErrorStatusPointer(BMS_M),
                      &(BMS_DW.schedule_DWORK1.rtm),
                      &(BMS_DW.schedule_DWORK1.rtdw));

  /* SystemInitialize for ModelReference: '<Root>/Model3' */
  CoreLogic_Init(&(BMS_DW.Model3_DWORK1.rtdw));
}

/* Model terminate function */
void BMS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
