/*
 * File: minimalist_sequence.h
 *
 * Real-Time Workshop code generated for Simulink model minimalist_sequence.
 *
 * Model version                        : 1.265
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 17:00:38 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 17:00:39 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_minimalist_sequence_h_
#define RTW_HEADER_minimalist_sequence_h_
#ifndef minimalist_sequence_COMMON_INCLUDES_
# define minimalist_sequence_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* minimalist_sequence_COMMON_INCLUDES_ */

#include "minimalist_sequence_types.h"

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
  uint8_T call_write_line;             /* '<S1>/Chart' */
} BlockIO_minimalist_sequence;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint32_T nElems;                     /* '<S3>/Data Store Memory' */
  uint32_T nIters;                     /* '<S3>/Data Store Memory1' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
  uint8_T is_active_c1_minimalist_sequenc;/* '<S1>/Chart' */
  uint8_T is_c1_minimalist_sequence;   /* '<S1>/Chart' */
  uint8_T cnt;                         /* '<S1>/Chart' */
} D_Work_minimalist_sequence;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_minimalist_sequence;

/* Real-time Model Data Structure */
struct RT_MODEL_minimalist_sequence {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_minimalist_sequence minimalist_sequence_B;

/* Block states (auto storage) */
extern D_Work_minimalist_sequence minimalist_sequence_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_minimalist_sequence minimalist_sequence_ConstP;

/* Model entry point functions */
extern void minimalist_sequence_initialize(boolean_T firstTime);
extern void minimalist_sequence_step(void);

/* Real-time Model object */
extern RT_MODEL_minimalist_sequence *minimalist_sequence_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Display' : Unused code path elimination
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
 * hilite_system('minimalist12/minimalist_sequence')    - opens subsystem minimalist12/minimalist_sequence
 * hilite_system('minimalist12/minimalist_sequence/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : minimalist12
 * '<S1>'   : minimalist12/minimalist_sequence
 * '<S2>'   : minimalist12/minimalist_sequence/Chart
 * '<S3>'   : minimalist12/minimalist_sequence/Enabled Subsystem
 * '<S4>'   : minimalist12/minimalist_sequence/MPC555 Resource Configuration
 * '<S5>'   : minimalist12/minimalist_sequence/Switch Target Hardware Configuration
 * '<S6>'   : minimalist12/minimalist_sequence/Enabled Subsystem/For Iterator Subsystem
 * '<S7>'   : minimalist12/minimalist_sequence/Enabled Subsystem/For Iterator Subsystem/If Action Subsystem
 * '<S8>'   : minimalist12/minimalist_sequence/Enabled Subsystem/For Iterator Subsystem/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_minimalist_sequence_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
