/*
 * File: FaultGenerator.c
 *
 * Code generated for Simulink model 'FaultGenerator'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 16:53:41 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FaultGenerator.h"
#include "FaultGenerator_private.h"

/* Output and update for referenced model: 'FaultGenerator' */
void FaultGenerator(const real32_T *rtu_vcmax, const real32_T *rtu_vcmin, const
                    real32_T *rtu_Soc, const boolean_T *rtu_Trigger, uint8_T
                    *rty_VCellMaxAlarm, uint8_T *rty_VCellMinAlarm, uint8_T
                    *rty_SocMaxAlarm, uint8_T *rty_SocMinAlarm, uint8_T
                    *rty_FaultLevel, ZCE_FaultGenerator_T *localZCE)
{
  if ((*rtu_Trigger) && (localZCE->TmpModelReferenceSubsystem_Trig != POS_ZCSIG))
  {
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     */
    *rty_VCellMaxAlarm = (uint8_T)(*rtu_vcmax >= 4.18F);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    *rty_VCellMinAlarm = (uint8_T)(*rtu_vcmin <= 3.2F);

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     */
    *rty_SocMaxAlarm = (uint8_T)(*rtu_Soc > 100.0F);

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     */
    *rty_SocMinAlarm = (uint8_T)(*rtu_Soc < 5.0F);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Logic: '<Root>/Logical Operator'
     */
    *rty_FaultLevel = (uint8_T)((*rty_VCellMaxAlarm != 0) && (*rty_VCellMinAlarm
      != 0) && (*rty_SocMaxAlarm != 0) && (*rty_SocMinAlarm != 0));
  }

  localZCE->TmpModelReferenceSubsystem_Trig = *rtu_Trigger;
}

/* Model initialize function */
void FaultGenerator_initialize(const char_T **rt_errorStatus,
  RT_MODEL_FaultGenerator_T *const FaultGenerator_M, ZCE_FaultGenerator_T
  *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(FaultGenerator_M, rt_errorStatus);
  localZCE->TmpModelReferenceSubsystem_Trig = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
