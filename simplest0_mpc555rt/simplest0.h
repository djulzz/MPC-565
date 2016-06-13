/*
 * File: simplest0.h
 *
 * Real-Time Workshop code generated for Simulink model simplest0.
 *
 * Model version                        : 1.268
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Mon Nov 23 12:31:30 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Mon Nov 23 12:31:31 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simplest0_h_
#define RTW_HEADER_simplest0_h_
#ifndef simplest0_COMMON_INCLUDES_
# define simplest0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* simplest0_COMMON_INCLUDES_ */

#include "simplest0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* user code (top of export header file) */

/* The interrupt level for rtOnestep function */
#define RT_ONE_STEP_IRQ                INT_LEVEL0

/* The oscillator frequency of the processor  */
#define OSCILLATOR_FREQ                4000000                   /* hz */

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T nElems;                     /* '<S3>/Data Store Memory' */
  uint32_T nIters;                     /* '<S3>/Data Store Memory1' */
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
} D_Work_simplest0;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_simplest0;

/* Real-time Model Data Structure */
struct RT_MODEL_simplest0 {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_simplest0 simplest0_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_simplest0 simplest0_ConstP;

/* Model entry point functions */
extern void simplest0_initialize(boolean_T firstTime);
extern void simplest0_step(void);

/* Real-time Model object */
extern RT_MODEL_simplest0 *simplest0_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Display' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('simplest/simplest')    - opens subsystem simplest/simplest
 * hilite_system('simplest/simplest/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : simplest
 * '<S1>'   : simplest/simplest
 * '<S2>'   : simplest/simplest/MPC555 Resource Configuration
 * '<S3>'   : simplest/simplest/Subsystem
 * '<S4>'   : simplest/simplest/Switch Target Hardware Configuration
 * '<S5>'   : simplest/simplest/Subsystem/For Iterator Subsystem
 * '<S6>'   : simplest/simplest/Subsystem/For Iterator Subsystem/If Action Subsystem
 * '<S7>'   : simplest/simplest/Subsystem/For Iterator Subsystem/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_simplest0_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
