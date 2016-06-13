/*
 * File: minimalist10.h
 *
 * Real-Time Workshop code generated for Simulink model minimalist10.
 *
 * Model version                        : 1.371
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 16:28:29 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 16:28:31 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_minimalist10_h_
#define RTW_HEADER_minimalist10_h_
#ifndef minimalist10_COMMON_INCLUDES_
# define minimalist10_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* minimalist10_COMMON_INCLUDES_ */

#include "minimalist10_types.h"

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
} BlockIO_minimalist10;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T buffer_transmit[10];         /* '<S1>/Data Store Memory4' */
  uint8_T step_iter;                   /* '<S1>/Data Store Memory5' */
  uint8_T is_active_c1_minimalist10;   /* '<S1>/Chart' */
  uint8_T is_c1_minimalist10;          /* '<S1>/Chart' */
} D_Work_minimalist10;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[10];
} ConstParam_minimalist10;

/* Real-time Model Data Structure */
struct RT_MODEL_minimalist10 {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_minimalist10 minimalist10_B;

/* Block states (auto storage) */
extern D_Work_minimalist10 minimalist10_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_minimalist10 minimalist10_ConstP;

/* Model entry point functions */
extern void minimalist10_initialize(boolean_T firstTime);
extern void minimalist10_step(void);

/* Real-time Model object */
extern RT_MODEL_minimalist10 *minimalist10_M;

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
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
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
#endif                                 /* RTW_HEADER_minimalist10_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
