/*
 * File: minimalist_sequence_A.h
 *
 * Real-Time Workshop code generated for Simulink model minimalist_sequence_A.
 *
 * Model version                        : 1.261
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 18:23:21 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 18:23:23 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_minimalist_sequence_A_h_
#define RTW_HEADER_minimalist_sequence_A_h_
#ifndef minimalist_sequence_A_COMMON_INCLUDES_
# define minimalist_sequence_A_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* minimalist_sequence_A_COMMON_INCLUDES_ */

#include "minimalist_sequence_A_types.h"

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
} D_Work_minimalist_sequence_A;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_minimalist_sequence_;

/* Real-time Model Data Structure */
struct RT_MODEL_minimalist_sequence_A {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_minimalist_sequence_A minimalist_sequence_A_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_minimalist_sequence_ minimalist_sequence_A_ConstP;

/* Model entry point functions */
extern void minimalist_sequence_A_initialize(boolean_T firstTime);
extern void minimalist_sequence_A_step(void);

/* Real-time Model object */
extern RT_MODEL_minimalist_sequence_A *minimalist_sequence_A_M;

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
 * hilite_system('minimalist13/minimalist_sequence_A')    - opens subsystem minimalist13/minimalist_sequence_A
 * hilite_system('minimalist13/minimalist_sequence_A/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : minimalist13
 * '<S1>'   : minimalist13/minimalist_sequence_A
 * '<S2>'   : minimalist13/minimalist_sequence_A/MPC555 Resource Configuration
 * '<S3>'   : minimalist13/minimalist_sequence_A/Subsystem
 * '<S4>'   : minimalist13/minimalist_sequence_A/Switch Target Hardware Configuration
 * '<S5>'   : minimalist13/minimalist_sequence_A/Subsystem/For Iterator Subsystem
 * '<S6>'   : minimalist13/minimalist_sequence_A/Subsystem/For Iterator Subsystem/If Action Subsystem
 * '<S7>'   : minimalist13/minimalist_sequence_A/Subsystem/For Iterator Subsystem/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_minimalist_sequence_A_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
