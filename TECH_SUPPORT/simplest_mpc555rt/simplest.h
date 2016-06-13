/*
 * File: simplest.h
 *
 * Real-Time Workshop code generated for Simulink model simplest.
 *
 * Model version                        : 1.266
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Mon Nov 16 17:42:18 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Mon Nov 16 17:42:19 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simplest_h_
#define RTW_HEADER_simplest_h_
#ifndef simplest_COMMON_INCLUDES_
# define simplest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* simplest_COMMON_INCLUDES_ */

#include "simplest_types.h"

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
} D_Work_simplest;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_simplest;

/* Real-time Model Data Structure */
struct RT_MODEL_simplest {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_simplest simplest_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_simplest simplest_ConstP;

/* Model entry point functions */
extern void simplest_initialize(boolean_T firstTime);
extern void simplest_step(void);

/* Real-time Model object */
extern RT_MODEL_simplest *simplest_M;

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
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
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
#endif                                 /* RTW_HEADER_simplest_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
