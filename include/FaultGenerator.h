/*
 * File: FaultGenerator.h
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

#ifndef RTW_HEADER_FaultGenerator_h_
#define RTW_HEADER_FaultGenerator_h_
#ifndef FaultGenerator_COMMON_INCLUDES_
# define FaultGenerator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultGenerator_COMMON_INCLUDES_ */

#include "FaultGenerator_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Zero-crossing (trigger) state for model 'FaultGenerator' */
typedef struct {
  ZCSigState TmpModelReferenceSubsystem_Trig;/* synthesized block */
} ZCE_FaultGenerator_T;

/* Real-time Model Data Structure */
struct tag_RTM_FaultGenerator_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_FaultGenerator_T rtm;
  ZCE_FaultGenerator_T rtzce;
} MdlrefDW_FaultGenerator_T;

/* Model reference registration function */
extern void FaultGenerator_initialize(const char_T **rt_errorStatus,
  RT_MODEL_FaultGenerator_T *const FaultGenerator_M, ZCE_FaultGenerator_T
  *localZCE);
extern void FaultGenerator(const real32_T *rtu_vcmax, const real32_T *rtu_vcmin,
  const real32_T *rtu_Soc, const boolean_T *rtu_Trigger, uint8_T
  *rty_VCellMaxAlarm, uint8_T *rty_VCellMinAlarm, uint8_T *rty_SocMaxAlarm,
  uint8_T *rty_SocMinAlarm, uint8_T *rty_FaultLevel, ZCE_FaultGenerator_T
  *localZCE);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FaultGenerator'
 * '<S1>'   : 'FaultGenerator/Compare To Constant'
 * '<S2>'   : 'FaultGenerator/Compare To Constant1'
 * '<S3>'   : 'FaultGenerator/Compare To Constant2'
 * '<S4>'   : 'FaultGenerator/Compare To Constant3'
 */
#endif                                 /* RTW_HEADER_FaultGenerator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
