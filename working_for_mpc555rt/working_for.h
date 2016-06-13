/*
 * File: working_for.h
 *
 * Real-Time Workshop code generated for Simulink model working_for.
 *
 * Model version                        : 1.370
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 16:22:23 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 16:22:25 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_working_for_h_
#define RTW_HEADER_working_for_h_
#ifndef working_for_COMMON_INCLUDES_
# define working_for_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* working_for_COMMON_INCLUDES_ */

#include "working_for_types.h"

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
  uint8_T call_write_on_com2;          /* '<S1>/Chart' */
} BlockIO_working_for;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T buffer_transmit[10];         /* '<S1>/Data Store Memory4' */
  uint8_T step_iter;                   /* '<S1>/Data Store Memory5' */
  uint8_T is_active_c1_working_for;    /* '<S1>/Chart' */
  uint8_T is_c1_working_for;           /* '<S1>/Chart' */
} D_Work_working_for;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[10];
} ConstParam_working_for;

/* Real-time Model Data Structure */
struct RT_MODEL_working_for {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_working_for working_for_B;

/* Block states (auto storage) */
extern D_Work_working_for working_for_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_working_for working_for_ConstP;

/* Model entry point functions */
extern void working_for_initialize(boolean_T firstTime);
extern void working_for_step(void);

/* Real-time Model object */
extern RT_MODEL_working_for *working_for_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Current Byte Fed to Serial' : Unused code path elimination
 * Block '<S6>/Current Index In Buffer' : Unused code path elimination
 * Block '<S6>/Full Buffer to transmit' : Unused code path elimination
 * Block '<S6>/To Workspace' : Unused code path elimination
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
 * hilite_system('minimalist10/working_for')    - opens subsystem minimalist10/working_for
 * hilite_system('minimalist10/working_for/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : minimalist10
 * '<S1>'   : minimalist10/working_for
 * '<S2>'   : minimalist10/working_for/Chart
 * '<S3>'   : minimalist10/working_for/Enabled Subsystem
 * '<S4>'   : minimalist10/working_for/MPC555 Resource Configuration
 * '<S5>'   : minimalist10/working_for/Switch Target Hardware Configuration
 * '<S6>'   : minimalist10/working_for/Enabled Subsystem/For Iterator Subsystem
 */
#endif                                 /* RTW_HEADER_working_for_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
