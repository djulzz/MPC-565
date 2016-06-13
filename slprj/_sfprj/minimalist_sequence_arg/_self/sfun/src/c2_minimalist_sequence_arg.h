#ifndef __c2_minimalist_sequence_arg_h__
#define __c2_minimalist_sequence_arg_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint8_T (*c2_buffer_receive_nav_mode_address)[37];
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_testPointAddrMap[1];
  int32_T c2_buffer_receive_nav_mode_index;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_isStable;
  uint8_T c2_doSetSimStateSideEffects;
  uint8_T c2_is_active_c2_minimalist_sequence_arg;
  uint8_T c2_is_c2_minimalist_sequence_arg;
  uint8_T c2_tp_STEP;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
} SFc2_minimalist_sequence_argInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_minimalist_sequence_arg_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_minimalist_sequence_arg_get_check_sum(mxArray *plhs[]);
extern void c2_minimalist_sequence_arg_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
