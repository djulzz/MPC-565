#ifndef __c1_stateflow_for_loop_no_mpc_h__
#define __c1_stateflow_for_loop_no_mpc_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint8_T *c1_count_address;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_testPointAddrMap[3];
  int32_T c1_count_index;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_isStable;
  uint8_T c1_cnt;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_active_c1_stateflow_for_loop_no_mpc;
  uint8_T c1_is_c1_stateflow_for_loop_no_mpc;
  uint8_T c1_tp_Rest_Mode;
  uint8_T c1_tp_STEP1;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
} SFc1_stateflow_for_loop_no_mpcInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_stateflow_for_loop_no_mpc_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_stateflow_for_loop_no_mpc_get_check_sum(mxArray *plhs[]);
extern void c1_stateflow_for_loop_no_mpc_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
