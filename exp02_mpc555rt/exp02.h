/*
 * File: exp02.h
 *
 * Real-Time Workshop code generated for Simulink model exp02.
 *
 * Model version                        : 1.301
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Nov 05 17:08:27 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Nov 05 17:08:29 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_exp02_h_
#define RTW_HEADER_exp02_h_
#ifndef exp02_COMMON_INCLUDES_
# define exp02_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* exp02_COMMON_INCLUDES_ */

#include "exp02_types.h"

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
} BlockIO_exp02;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint32_T nElems;                     /* '<S6>/Data Store Memory' */
  uint32_T nIters;                     /* '<S6>/Data Store Memory1' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
  uint8_T is_active_c1_exp02;          /* '<S1>/Chart' */
  uint8_T is_c1_exp02;                 /* '<S1>/Chart' */
} D_Work_exp02;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_exp02;

/* Real-time Model Data Structure */
struct RT_MODEL_exp02 {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_exp02 exp02_B;

/* Block states (auto storage) */
extern D_Work_exp02 exp02_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_exp02 exp02_ConstP;

/* Model entry point functions */
extern void exp02_initialize(boolean_T firstTime);
extern void exp02_step(void);

/* Real-time Model object */
extern RT_MODEL_exp02 *exp02_M;

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
 * hilite_system('exp2/exp02')    - opens subsystem exp2/exp02
 * hilite_system('exp2/exp02/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : exp2
 * '<S1>'   : exp2/exp02
 * '<S2>'   : exp2/exp02/Chart
 * '<S3>'   : exp2/exp02/MPC555 Resource Configuration
 * '<S4>'   : exp2/exp02/Subsystem
 * '<S5>'   : exp2/exp02/Switch Target Hardware Configuration
 * '<S6>'   : exp2/exp02/Subsystem/Subsystem
 * '<S7>'   : exp2/exp02/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)
 * '<S8>'   : exp2/exp02/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)/If Action Subsystem
 * '<S9>'   : exp2/exp02/Subsystem/Subsystem/Subsystem (Used to be a modified for subsystem)/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_exp02_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
