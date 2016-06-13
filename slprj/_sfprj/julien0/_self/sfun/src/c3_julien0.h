#ifndef __c3_julien0_h__
#define __c3_julien0_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_doneDoubleBufferReInit;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_julien0;
  ChartInfoStruct chartInfo;
} SFc3_julien0InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_julien0_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_julien0_get_check_sum(mxArray *plhs[]);
extern void c3_julien0_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
