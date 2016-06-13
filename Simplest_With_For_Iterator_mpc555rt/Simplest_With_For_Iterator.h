/*
 * File: Simplest_With_For_Iterator.h
 *
 * Real-Time Workshop code generated for Simulink model Simplest_With_For_Iterator.
 *
 * Model version                        : 1.353
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 23:09:19 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 23:09:21 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Simplest_With_For_Iterator_h_
#define RTW_HEADER_Simplest_With_For_Iterator_h_
#ifndef Simplest_With_For_Iterator_COMMON_INCLUDES_
# define Simplest_With_For_Iterator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "qsmcm_sci.h"
#include "mpc5xx.h"
#endif                                 /* Simplest_With_For_Iterator_COMMON_INCLUDES_ */

#include "Simplest_With_For_Iterator_types.h"

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
  uint8_T buffer_transmit_com3[17];    /* '<Root>/_DataStoreBlk_1' */
} D_Work_Simplest_With_For_Iterat;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: _DataStoreBlk_1_Init
   * Referenced by: '<Root>/_DataStoreBlk_1'
   */
  uint8_T _DataStoreBlk_1_Init[17];
} ConstParam_Simplest_With_For_It;

/* Real-time Model Data Structure */
struct RT_MODEL_Simplest_With_For_Iter {
  const char_T *errorStatus;
};

/* Block states (auto storage) */
extern D_Work_Simplest_With_For_Iterat Simplest_With_For_Iterato_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_Simplest_With_For_It Simplest_With_For_Iterat_ConstP;

/* Model entry point functions */
extern void Simplest_With_For_Iterator_initialize(boolean_T firstTime);
extern void Simplest_With_For_Iterator_step(void);

/* Real-time Model object */
extern RT_MODEL_Simplest_With_For_Iter *Simplest_With_For_Iterator_M;

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
 * hilite_system('simplest2/Simplest_With_For_Iterator')    - opens subsystem simplest2/Simplest_With_For_Iterator
 * hilite_system('simplest2/Simplest_With_For_Iterator/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : simplest2
 * '<S1>'   : simplest2/Simplest_With_For_Iterator
 * '<S2>'   : simplest2/Simplest_With_For_Iterator/For Iterator Subsystem
 * '<S3>'   : simplest2/Simplest_With_For_Iterator/MPC555 Resource Configuration
 * '<S4>'   : simplest2/Simplest_With_For_Iterator/Switch Target Hardware Configuration
 */
#endif                                 /* RTW_HEADER_Simplest_With_For_Iterator_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
