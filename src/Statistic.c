/*
 * File: Statistic.c
 *
 * Code generated for Simulink model 'Statistic'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 16:53:52 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Statistic.h"
#include "Statistic_private.h"

/* Output and update for referenced model: 'Statistic' */
void Statistic(const real32_T rtu_VCell[96], const boolean_T *rtu_Trigger,
               real32_T *rty_VCellMax, uint8_T *rty_VCellMaxNum, real32_T
               *rty_VCellMin, uint8_T *rty_VCellMinNum, ZCE_Statistic_T
               *localZCE)
{
  int32_T in;
  int32_T j;
  int32_T rtb_Maximum_o2;
  if ((*rtu_Trigger) && (localZCE->TmpModelReferenceSubsystem_Trig != POS_ZCSIG))
  {
    /* S-Function (sdspstatminmax): '<Root>/Minimum' */
    in = 1;
    *rty_VCellMin = rtu_VCell[0];
    rtb_Maximum_o2 = 1;
    for (j = 0; j < 95; j++) {
      if (rtu_VCell[in] < *rty_VCellMin) {
        *rty_VCellMin = rtu_VCell[in];
        rtb_Maximum_o2 = j + 2;
      }

      in++;
    }

    /* End of S-Function (sdspstatminmax): '<Root>/Minimum' */

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    *rty_VCellMinNum = (uint8_T)rtb_Maximum_o2;

    /* S-Function (sdspstatminmax): '<Root>/Maximum' */
    in = 1;
    *rty_VCellMax = rtu_VCell[0];
    rtb_Maximum_o2 = 1;
    for (j = 0; j < 95; j++) {
      if (rtu_VCell[in] > *rty_VCellMax) {
        *rty_VCellMax = rtu_VCell[in];
        rtb_Maximum_o2 = j + 2;
      }

      in++;
    }

    /* End of S-Function (sdspstatminmax): '<Root>/Maximum' */

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    *rty_VCellMaxNum = (uint8_T)rtb_Maximum_o2;
  }

  localZCE->TmpModelReferenceSubsystem_Trig = *rtu_Trigger;
}

/* Model initialize function */
void Statistic_initialize(const char_T **rt_errorStatus, RT_MODEL_Statistic_T *
  const Statistic_M, ZCE_Statistic_T *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Statistic_M, rt_errorStatus);
  localZCE->TmpModelReferenceSubsystem_Trig = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
