/*
 * File: exp03.h
 *
 * Real-Time Workshop code generated for Simulink model exp03.
 *
 * Model version                        : 1.311
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Nov 05 17:25:32 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Nov 05 17:25:34 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_exp03_h_
#define RTW_HEADER_exp03_h_
#ifndef exp03_COMMON_INCLUDES_
# define exp03_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* exp03_COMMON_INCLUDES_ */

#include "exp03_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  uint8_T syscall;                     /* '<S1>/Chart' */
} BlockIO_exp03;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint32_T nElems;                     /* '<S6>/Data Store Memory' */
  uint32_T nIters;                     /* '<S6>/Data Store Memory1' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
  uint8_T is_active_c1_exp03;          /* '<S1>/Chart' */
  uint8_T is_c1_exp03;                 /* '<S1>/Chart' */
  uint8_T cnt;                         /* '<S1>/Chart' */
} D_Work_exp03;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_exp03;

/* Real-time Model Data Structure */
struct RT_MODEL_exp03 {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_exp03 exp03_B;

/* Block states (auto storage) */
extern D_Work_exp03 exp03_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_exp03 exp03_ConstP;

/* Model entry point functions */
extern void exp03_initialize(boolean_T firstTime);
extern void exp03_step(void);

/* Real-time Model object */
extern RT_MODEL_exp03 *exp03_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
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
 * hilite_system('exp3/exp03')    - opens subsystem exp3/exp03
 * hilite_system('exp3/exp03/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : exp3
 * '<S1>'   : exp3/exp03
 * '<S2>'   : exp3/exp03/Chart
 * '<S3>'   : exp3/exp03/MPC555 Resource Configuration
 * '<S4>'   : exp3/exp03/Subsystem
 * '<S5>'   : exp3/exp03/Switch Target Hardware Configuration
 * '<S6>'   : exp3/exp03/Subsystem/Subsystem
 * '<S7>'   : exp3/exp03/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)
 * '<S8>'   : exp3/exp03/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)/If Action Subsystem
 * '<S9>'   : exp3/exp03/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_exp03_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
