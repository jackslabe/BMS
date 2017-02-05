/*
 * File: CoreAlgorithm.c
 *
 * Code generated for Simulink model 'CoreAlgorithm'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 16:49:59 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CoreAlgorithm.h"
#include "CoreAlgorithm_private.h"

/* Output and update for referenced model: 'CoreAlgorithm' */
void CoreAlgorithm(const real32_T *rtu_vc, const real32_T *rtu_tc, const
                   real32_T *rtu_ibat, const boolean_T *rtu_Trigger, real32_T
                   *rty_Soc, ZCE_CoreAlgorithm_T *localZCE)
{
  if ((*rtu_Trigger) && (localZCE->TmpModelReferenceSubsystem_Trig != POS_ZCSIG))
  {
    /* Gain: '<Root>/Gain' incorporates:
     *  Gain: '<Root>/Gain1'
     *  Polyval: '<Root>/Polynomial'
     *  Polyval: '<Root>/Polynomial1'
     *  Product: '<Root>/Product'
     *  Sum: '<Root>/Add'
     */
    *rty_Soc = (-((-0.3F * *rtu_tc + 19.0F) * 0.001F * *rtu_ibat + *rtu_vc) +
                4.2F) * 100.0F;
  }

  localZCE->TmpModelReferenceSubsystem_Trig = *rtu_Trigger;
}

/* Model initialize function */
void CoreAlgorithm_initialize(const char_T **rt_errorStatus,
  RT_MODEL_CoreAlgorithm_T *const CoreAlgorithm_M, ZCE_CoreAlgorithm_T *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(CoreAlgorithm_M, rt_errorStatus);
  localZCE->TmpModelReferenceSubsystem_Trig = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
