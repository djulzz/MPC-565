/*
 * File: julien0.h
 *
 * Real-Time Workshop code generated for Simulink model julien0.
 *
 * Model version                        : 1.153
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Wed Oct 28 16:43:48 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Wed Oct 28 16:43:50 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_julien0_h_
#define RTW_HEADER_julien0_h_
#ifndef julien0_COMMON_INCLUDES_
# define julien0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* julien0_COMMON_INCLUDES_ */

#include "julien0_types.h"

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
  int32_T ForIterator;                 /* '<S19>/For Iterator' */
  uint8_T VectorConcatenate[3];        /* '<S10>/Vector Concatenate' */
  uint8_T VectorConcatenate_l[11];     /* '<S5>/Vector Concatenate' */
  uint8_T SerialReceive;               /* '<S13>/Serial Receive' */
} BlockIO_julien0;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T sz_buffer_transmit;         /* '<S1>/Data Store Memory2' */
  uint8_T count;                       /* '<S1>/Data Store Memory' */
  uint8_T buffer_transmit[11];         /* '<S1>/Data Store Memory1' */
  uint8_T buffer_receive_nav_mode[37]; /* '<S1>/Data Store Memory3' */
  uint8_T buffer_transmit_com3[3];     /* '<S1>/Data Store Memory4' */
  uint8_T packet_cfg;                  /* '<S14>/Data Store Memory' */
  uint8_T is_active_c2_julien0;        /* '<S1>/Chart' */
  uint8_T is_c2_julien0;               /* '<S1>/Chart' */
} D_Work_julien0;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T VectorConcatenate[3];  /* '<S9>/Vector Concatenate' */
  const uint8_T VectorConcatenate_f[3];/* '<S8>/Vector Concatenate' */
} ConstBlockIO_julien0;

/* Real-time Model Data Structure */
struct RT_MODEL_julien0 {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_julien0 julien0_B;

/* Block states (auto storage) */
extern D_Work_julien0 julien0_DWork;
extern ConstBlockIO_julien0 julien0_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void julien0_initialize(boolean_T firstTime);
extern void julien0_step(void);

/* Real-time Model object */
extern RT_MODEL_julien0 *julien0_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
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
 * hilite_system('julien2/julien')    - opens subsystem julien2/julien
 * hilite_system('julien2/julien/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : julien2
 * '<S1>'   : julien2/julien
 * '<S2>'   : julien2/julien/Chart
 * '<S3>'   : julien2/julien/MPC555 Resource Configuration
 * '<S4>'   : julien2/julien/Read From NAV420
 * '<S5>'   : julien2/julien/Request NAV Packet
 * '<S6>'   : julien2/julien/Switch Target Hardware Configuration
 * '<S7>'   : julien2/julien/Write to NAV420
 * '<S8>'   : julien2/julien/Write to PC COM3 "BUFFER", "C"
 * '<S9>'   : julien2/julien/Write to PC COM3 "BUFFER", "O"
 * '<S10>'  : julien2/julien/Write to PC COM3 "BUFFER", 3rd byte
 * '<S11>'  : julien2/julien/Write to PC COM3, 3 bytes
 * '<S12>'  : julien2/julien/Read From NAV420/Embedded MATLAB Function
 * '<S13>'  : julien2/julien/Read From NAV420/For Iterator Subsystem1
 * '<S14>'  : julien2/julien/Request NAV Packet/Nav420 - Request Packet
 * '<S15>'  : julien2/julien/Request NAV Packet/Nav420 - Request Packet/Shift Arithmetic1
 * '<S16>'  : julien2/julien/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem
 * '<S17>'  : julien2/julien/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem1
 * '<S18>'  : julien2/julien/Request NAV Packet/Nav420 - Request Packet/Switch Case Action Subsystem2
 * '<S19>'  : julien2/julien/Write to NAV420/For Iterator Subsystem1
 * '<S20>'  : julien2/julien/Write to PC COM3 "BUFFER", 3rd byte/Embedded MATLAB Function
 */
#endif                                 /* RTW_HEADER_julien0_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
