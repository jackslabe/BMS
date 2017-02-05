/*
 * File: BMS.h
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

#ifndef RTW_HEADER_BMS_h_
#define RTW_HEADER_BMS_h_
#include <stddef.h>
#include <string.h>
#ifndef BMS_COMMON_INCLUDES_
# define BMS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* BMS_COMMON_INCLUDES_ */

#include "BMS_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Child system includes */
#include "Statistic.h"
#include "Schedule.h"
#include "FaultGenerator.h"
#include "CoreLogic.h"
#include "CoreAlgorithm.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T VCellMax;                   /* '<Root>/Model1' */
  real32_T VCellMin;                   /* '<Root>/Model1' */
  real32_T Soc;                        /* '<Root>/Model' */
  uint8_T FaultLevel;                  /* '<Root>/Model2' */
  boolean_T schedule_o1;               /* '<Root>/schedule' */
  boolean_T schedule_o2;               /* '<Root>/schedule' */
  boolean_T schedule_o3;               /* '<Root>/schedule' */
} B_BMS_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  MdlrefDW_Schedule_T schedule_DWORK1; /* '<Root>/schedule' */
  MdlrefDW_Statistic_T Model1_DWORK1;  /* '<Root>/Model1' */
  MdlrefDW_CoreAlgorithm_T Model_DWORK1;/* '<Root>/Model' */
  MdlrefDW_FaultGenerator_T Model2_DWORK1;/* '<Root>/Model2' */
  MdlrefDW_CoreLogic_T Model3_DWORK1;  /* '<Root>/Model3' */
} DW_BMS_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T VCell[96];                  /* '<Root>/In1' */
  real32_T TCell;                      /* '<Root>/In2' */
  real32_T IBat;                       /* '<Root>/In3' */
  uint8_T Acc;                         /* '<Root>/In4' */
  real32_T CC;                         /* '<Root>/In5' */
} ExtU_BMS_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T Out1;                        /* '<Root>/Out1' */
  uint8_T Out2;                        /* '<Root>/Out2' */
  uint8_T Out3;                        /* '<Root>/Out3' */
  uint8_T Out4;                        /* '<Root>/Out4' */
  uint8_T Out5;                        /* '<Root>/Out5' */
  uint8_T Out6;                        /* '<Root>/Out6' */
} ExtY_BMS_T;

/* Real-time Model Data Structure */
struct tag_RTM_BMS_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_BMS_T BMS_B;

/* Block states (auto storage) */
extern DW_BMS_T BMS_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_BMS_T BMS_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_BMS_T BMS_Y;

/* Model entry point functions */
extern void BMS_initialize(void);
extern void BMS_step(void);
extern void BMS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BMS_T *const BMS_M;

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
 * '<Root>' : 'BMS'
 */
#endif                                 /* RTW_HEADER_BMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
