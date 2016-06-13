/*
 * File: simplest0_private.h
 *
 * Real-Time Workshop code generated for Simulink model simplest0.
 *
 * Model version                        : 1.268
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Mon Nov 23 12:31:30 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Mon Nov 23 12:31:31 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simplest0_private_h_
#define RTW_HEADER_simplest0_private_h_
#include "rtwtypes.h"
#ifndef MPC555_VARIANT

/* For processors other than mpc555 such as the mpc565 the QSMCM is known as
   the QSMCM_A, QSMCM_B. Currently, we support only a single QSMCM */
#define QSMCM                          QSMCM_A
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */
#endif                                 /* RTW_HEADER_simplest0_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
