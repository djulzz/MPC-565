/*
 * profile_vars.h
 *
 * Real-Time Workshop code generation for Simulink model "gimme.mdl".
 *
 * Model Version              : 1.336
 * Real-Time Workshop version : 7.4  (R2009b)  29-Jun-2009
 * C source code generated on : Tue Nov 03 11:53:41 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * Description  : Header file to define model dependent variables required
 *                by execution profiling, if it is enabled.
 */

#include "profile_utils.h"

/* Number of nano seconds per decrementer tick */
#define PROFILING_TIME_PER_TICK        400
