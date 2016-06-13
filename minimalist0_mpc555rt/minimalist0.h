/*
 * File: minimalist0.h
 *
 * Real-Time Workshop code generated for Simulink model minimalist0.
 *
 * Model version                        : 1.179
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Oct 29 16:53:48 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Oct 29 16:53:51 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_minimalist0_h_
#define RTW_HEADER_minimalist0_h_
#ifndef minimalist0_COMMON_INCLUDES_
# define minimalist0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* minimalist0_COMMON_INCLUDES_ */

#include "minimalist0_types.h"

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
  uint8_T VectorConcatenate[3];        /* '<S8>/Vector Concatenate' */
  uint8_T VectorConcatenate_p[11];     /* '<S4>/Vector Concatenate' */
  uint8_T call_request_nav_packet;     /* '<S1>/Chart' */
  uint8_T call_write_com3_buffer_third_by;/* '<S1>/Chart' */
} BlockIO_minimalist0;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint32_T nElems;                     /* '<S9>/Data Store Memory' */
  uint32_T nIters;                     /* '<S9>/Data Store Memory1' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[3];     /* '<S1>/Data Store Memory4' */
  uint8_T packet_cfg;                  /* '<S10>/Data Store Memory' */
  uint8_T is_active_c2_minimalist0;    /* '<S1>/Chart' */
  uint8_T is_c2_minimalist0;           /* '<S1>/Chart' */
} D_Work_minimalist0;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T VectorConcatenate[3];  /* '<S7>/Vector Concatenate' */
  const uint8_T VectorConcatenate_d[3];/* '<S6>/Vector Concatenate' */
} ConstBlockIO_minimalist0;

/* Real-time Model Data Structure */
struct RT_MODEL_minimalist0 {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_minimalist0 minimalist0_B;

/* Block states (auto storage) */
extern D_Work_minimalist0 minimalist0_DWork;
extern ConstBlockIO_minimalist0 minimalist0_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void minimalist0_initialize(boolean_T firstTime);
extern void minimalist0_step(void);

/* Real-time Model object */
extern RT_MODEL_minimalist0 *minimalist0_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Display' : Unused code path elimination
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
 * hilite_system('minimalist/minimalist')    - opens subsystem minimalist/minimalist
 * hilite_system('minimalist/minimalist/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : minimalist
 * '<S1>'   : minimalist/minimalist
 * '<S2>'   : minimalist/minimalist/Chart
 * '<S3>'   : minimalist/minimalist/MPC555 Resource Configuration
 * '<S4>'   : minimalist/minimalist/Request NAV Packet
 * '<S5>'   : minimalist/minimalist/Switch Target Hardware Configuration
 * '<S6>'   : minimalist/minimalist/Write to PC COM3 "BUFFER", "C"
 * '<S7>'   : minimalist/minimalist/Write to PC COM3 "BUFFER", "O"
 * '<S8>'   : minimalist/minimalist/Write to PC COM3 "BUFFER", 3rd byte
 * '<S9>'   : minimalist/minimalist/Write to PC COM3, 3 bytes
 * '<S10>'  : minimalist/minimalist/Request NAV Packet/Nav420 - Request Packet
 * '<S11>'  : minimalist/minimalist/Request NAV Packet/Nav420 - Request Packet/Shift Arithmetic1
 * '<S12>'  : minimalist/minimalist/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem
 * '<S13>'  : minimalist/minimalist/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem1
 * '<S14>'  : minimalist/minimalist/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem2
 * '<S15>'  : minimalist/minimalist/Write to PC COM3 "BUFFER", 3rd byte/Embedded MATLAB Function
 * '<S16>'  : minimalist/minimalist/Write to PC COM3, 3 bytes/For Iterator Subsystem
 * '<S17>'  : minimalist/minimalist/Write to PC COM3, 3 bytes/For Iterator Subsystem/If Action Subsystem
 * '<S18>'  : minimalist/minimalist/Write to PC COM3, 3 bytes/For Iterator Subsystem/If Action Subsystem1
 */
#endif                                 /* RTW_HEADER_minimalist0_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
