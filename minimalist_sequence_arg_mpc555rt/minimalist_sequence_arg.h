/*
 * File: minimalist_sequence_arg.h
 *
 * Real-Time Workshop code generated for Simulink model minimalist_sequence_arg.
 *
 * Model version                        : 1.271
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 18:09:26 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 18:09:29 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_minimalist_sequence_arg_h_
#define RTW_HEADER_minimalist_sequence_arg_h_
#ifndef minimalist_sequence_arg_COMMON_INCLUDES_
# define minimalist_sequence_arg_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* minimalist_sequence_arg_COMMON_INCLUDES_ */

#include "minimalist_sequence_arg_types.h"

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
  uint8_T out;                         /* '<S3>/Chart' */
} BlockIO_minimalist_sequence_arg;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T nElems;                     /* '<S5>/Data Store Memory' */
  uint32_T nIters;                     /* '<S5>/Data Store Memory1' */
  uint32_T nElems_b;                   /* '<S6>/Data Store Memory' */
  uint32_T nIters_p;                   /* '<S6>/Data Store Memory1' */
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint8_T packet_cfg;                  /* '<S13>/Data Store Memory' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[17];    /* '<S1>/Data Store Memory4' */
  uint8_T is_active_c1_minimalist_sequenc;/* '<S9>/Chart' */
  uint8_T is_c1_minimalist_sequence_arg;/* '<S9>/Chart' */
  uint8_T is_active_c2_minimalist_sequenc;/* '<S3>/Chart' */
  uint8_T is_c2_minimalist_sequence_arg;/* '<S3>/Chart' */
} D_Work_minimalist_sequence_arg;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: DataStoreMemory4_Ini
   * Referenced by: '<S1>/Data Store Memory4'
   */
  uint8_T DataStoreMemory4_Ini[17];
} ConstParam_minimalist_sequence_;

/* Real-time Model Data Structure */
struct RT_MODEL_minimalist_sequence_ar {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_minimalist_sequence_arg minimalist_sequence_arg_B;

/* Block states (auto storage) */
extern D_Work_minimalist_sequence_arg minimalist_sequence_arg_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_minimalist_sequence_ minimalist_sequence_arg_ConstP;

/* Model entry point functions */
extern void minimalist_sequence_arg_initialize(boolean_T firstTime);
extern void minimalist_sequence_arg_step(void);

/* Real-time Model object */
extern RT_MODEL_minimalist_sequence_ar *minimalist_sequence_arg_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S14>/Display' : Unused code path elimination
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
 * hilite_system('minimalist14/minimalist_sequence_arg')    - opens subsystem minimalist14/minimalist_sequence_arg
 * hilite_system('minimalist14/minimalist_sequence_arg/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : minimalist14
 * '<S1>'   : minimalist14/minimalist_sequence_arg
 * '<S2>'   : minimalist14/minimalist_sequence_arg/MPC555 Resource Configuration
 * '<S3>'   : minimalist14/minimalist_sequence_arg/Print
 * '<S4>'   : minimalist14/minimalist_sequence_arg/Switch Target Hardware Configuration
 * '<S5>'   : minimalist14/minimalist_sequence_arg/rcvNAV
 * '<S6>'   : minimalist14/minimalist_sequence_arg/reqNAV
 * '<S7>'   : minimalist14/minimalist_sequence_arg/Print/Chart
 * '<S8>'   : minimalist14/minimalist_sequence_arg/rcvNAV/For Iterator Subsystem
 * '<S9>'   : minimalist14/minimalist_sequence_arg/rcvNAV/For Iterator Subsystem/If Action Subsystem
 * '<S10>'  : minimalist14/minimalist_sequence_arg/rcvNAV/For Iterator Subsystem/If Action Subsystem1
 * '<S11>'  : minimalist14/minimalist_sequence_arg/rcvNAV/For Iterator Subsystem/If Action Subsystem/Chart
 * '<S12>'  : minimalist14/minimalist_sequence_arg/reqNAV/For Iterator Subsystem
 * '<S13>'  : minimalist14/minimalist_sequence_arg/reqNAV/Nav420 - Request Packet
 * '<S14>'  : minimalist14/minimalist_sequence_arg/reqNAV/For Iterator Subsystem/If Action Subsystem
 * '<S15>'  : minimalist14/minimalist_sequence_arg/reqNAV/For Iterator Subsystem/If Action Subsystem1
 * '<S16>'  : minimalist14/minimalist_sequence_arg/reqNAV/Nav420 - Request Packet/Shift Arithmetic1
 * '<S17>'  : minimalist14/minimalist_sequence_arg/reqNAV/Nav420 - Request Packet/Switch Case Action Subsystem
 * '<S18>'  : minimalist14/minimalist_sequence_arg/reqNAV/Nav420 - Request Packet/Switch Case Action Subsystem1
 * '<S19>'  : minimalist14/minimalist_sequence_arg/reqNAV/Nav420 - Request Packet/Switch Case Action Subsystem2
 */
#endif                                 /* RTW_HEADER_minimalist_sequence_arg_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
