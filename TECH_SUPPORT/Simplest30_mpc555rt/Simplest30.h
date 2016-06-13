/*
 * File: Simplest30.h
 *
 * Real-Time Workshop code generated for Simulink model Simplest30.
 *
 * Model version                        : 1.358
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Wed Nov 04 00:40:45 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Wed Nov 04 00:40:47 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Simplest30_h_
#define RTW_HEADER_Simplest30_h_
#ifndef Simplest30_COMMON_INCLUDES_
# define Simplest30_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* Simplest30_COMMON_INCLUDES_ */

#include "Simplest30_types.h"

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
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
  uint8_T step_iter;                   /* '<S1>/Data Store Memory5' */
} D_Work_Simplest30;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_Simplest30;

/* Real-time Model Data Structure */
struct RT_MODEL_Simplest30 {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_Simplest30 Simplest30_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_Simplest30 Simplest30_ConstP;

/* Model entry point functions */
extern void Simplest30_initialize(boolean_T firstTime);
extern void Simplest30_step(void);

/* Real-time Model object */
extern RT_MODEL_Simplest30 *Simplest30_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
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
 * hilite_system('simplest3/Simplest3')    - opens subsystem simplest3/Simplest3
 * hilite_system('simplest3/Simplest3/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : simplest3
 * '<S1>'   : simplest3/Simplest3
 * '<S2>'   : simplest3/Simplest3/MPC555 Resource Configuration
 * '<S3>'   : simplest3/Simplest3/Subsystem
 * '<S4>'   : simplest3/Simplest3/Switch Target Hardware Configuration
 * '<S5>'   : simplest3/Simplest3/Subsystem/For Iterator Subsystem
 */
#endif                                 /* RTW_HEADER_Simplest30_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
