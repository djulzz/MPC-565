/* Include files */

#include "blascompat32.h"
#include "stateflow_for_loop_no_mpc_sfun.h"
#include "c1_stateflow_for_loop_no_mpc.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "stateflow_for_loop_no_mpc_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)
#define c1_IN_STEP1                    (2)
#define c1_IN_Rest_Mode                (1)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_stateflow_for_loop_no_mpcInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_stateflow_for_loop_no_mpc(void);
static void initialize_params_c1_stateflow_for_loop_no_mpc(void);
static void enable_c1_stateflow_for_loop_no_mpc(void);
static void disable_c1_stateflow_for_loop_no_mpc(void);
static void c1_update_debugger_state_c1_stateflow_for_loop_no_mpc(void);
static const mxArray *get_sim_state_c1_stateflow_for_loop_no_mpc(void);
static void set_sim_state_c1_stateflow_for_loop_no_mpc(const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_stateflow_for_loop_no_mpc(void);
static void finalize_c1_stateflow_for_loop_no_mpc(void);
static void sf_c1_stateflow_for_loop_no_mpc(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static uint8_T c1__u8_s32_(int32_T c1_b);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static uint8_T c1_get_count(int32_T c1_b);
static void c1_set_count(int32_T c1_b, uint8_T c1_c);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_stateflow_for_loop_no_mpc(void)
{
  uint8_T *c1_call_write_sequence_to_workspace;
  c1_call_write_sequence_to_workspace = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_doSetSimStateSideEffects = 0U;
  chartInstance.c1_setSimStateSideEffectsInfo = NULL;
  chartInstance.c1_tp_Rest_Mode = 0U;
  chartInstance.c1_tp_STEP1 = 0U;
  chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc = 0U;
  chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = 0U;
  chartInstance.c1_cnt = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c1_call_write_sequence_to_workspace = 0U;
  }
}

static void initialize_params_c1_stateflow_for_loop_no_mpc(void)
{
}

static void enable_c1_stateflow_for_loop_no_mpc(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_stateflow_for_loop_no_mpc(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c1_update_debugger_state_c1_stateflow_for_loop_no_mpc(void)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG,0);
  }

  if ((int16_T)chartInstance.c1_is_c1_stateflow_for_loop_no_mpc == c1_IN_STEP1)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if ((int16_T)chartInstance.c1_is_c1_stateflow_for_loop_no_mpc ==
      c1_IN_Rest_Mode) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_stateflow_for_loop_no_mpc(void)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T *c1_call_write_sequence_to_workspace;
  c1_call_write_sequence_to_workspace = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4));
  c1_u = *c1_call_write_sequence_to_workspace;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = chartInstance.c1_cnt;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_u = chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_u = chartInstance.c1_is_c1_stateflow_for_loop_no_mpc;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_stateflow_for_loop_no_mpc(const mxArray *c1_st)
{
  const mxArray *c1_u;
  const mxArray *c1_call_write_sequence_to_workspace;
  uint8_T c1_u0;
  uint8_T c1_y;
  const mxArray *c1_b_call_write_sequence_to_workspace;
  uint8_T c1_u1;
  uint8_T c1_b_y;
  const mxArray *c1_c_call_write_sequence_to_workspace;
  uint8_T c1_u2;
  uint8_T c1_c_y;
  const mxArray *c1_d_call_write_sequence_to_workspace;
  uint8_T c1_u3;
  uint8_T c1_d_y;
  const mxArray *c1_b_setSimStateSideEffectsInfo;
  const mxArray *c1_e_y = NULL;
  uint8_T *c1_e_call_write_sequence_to_workspace;
  c1_e_call_write_sequence_to_workspace = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 1);
  c1_u = sf_mex_dup(c1_st);
  c1_call_write_sequence_to_workspace = sf_mex_dup(sf_mex_getcell(c1_u, 0));
  sf_mex_import("call_write_sequence_to_workspace", sf_mex_dup
                (c1_call_write_sequence_to_workspace), &c1_u0, 1, 3, 0U, 0, 0U,
                0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_call_write_sequence_to_workspace);
  *c1_e_call_write_sequence_to_workspace = c1_y;
  c1_b_call_write_sequence_to_workspace = sf_mex_dup(sf_mex_getcell(c1_u, 1));
  sf_mex_import("cnt", sf_mex_dup(c1_b_call_write_sequence_to_workspace), &c1_u1,
                1, 3, 0U, 0, 0U, 0);
  c1_b_y = c1_u1;
  sf_mex_destroy(&c1_b_call_write_sequence_to_workspace);
  chartInstance.c1_cnt = c1_b_y;
  c1_c_call_write_sequence_to_workspace = sf_mex_dup(sf_mex_getcell(c1_u, 2));
  sf_mex_import("is_active_c1_stateflow_for_loop_no_mpc", sf_mex_dup
                (c1_c_call_write_sequence_to_workspace), &c1_u2, 1, 3, 0U, 0, 0U,
                0);
  c1_c_y = c1_u2;
  sf_mex_destroy(&c1_c_call_write_sequence_to_workspace);
  chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc = c1_c_y;
  c1_d_call_write_sequence_to_workspace = sf_mex_dup(sf_mex_getcell(c1_u, 3));
  sf_mex_import("is_c1_stateflow_for_loop_no_mpc", sf_mex_dup
                (c1_d_call_write_sequence_to_workspace), &c1_u3, 1, 3, 0U, 0, 0U,
                0);
  c1_d_y = c1_u3;
  sf_mex_destroy(&c1_d_call_write_sequence_to_workspace);
  chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = c1_d_y;
  c1_b_setSimStateSideEffectsInfo = sf_mex_dup(sf_mex_getcell(c1_u, 4));
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_duplicatearraysafe
                (&c1_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  sf_mex_assign(&chartInstance.c1_setSimStateSideEffectsInfo, c1_e_y);
  sf_mex_destroy(&c1_u);
  chartInstance.c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_stateflow_for_loop_no_mpc();
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_stateflow_for_loop_no_mpc(void)
{
  if (chartInstance.c1_doSetSimStateSideEffects != 0) {
    if ((int16_T)chartInstance.c1_is_c1_stateflow_for_loop_no_mpc ==
        c1_IN_Rest_Mode) {
      chartInstance.c1_tp_Rest_Mode = 1U;
    } else {
      chartInstance.c1_tp_Rest_Mode = 0U;
    }

    if ((int16_T)chartInstance.c1_is_c1_stateflow_for_loop_no_mpc == c1_IN_STEP1)
    {
      chartInstance.c1_tp_STEP1 = 1U;
    } else {
      chartInstance.c1_tp_STEP1 = 0U;
    }

    chartInstance.c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_stateflow_for_loop_no_mpc(void)
{
  sf_mex_destroy(&chartInstance.c1_setSimStateSideEffectsInfo);
}

static void sf_c1_stateflow_for_loop_no_mpc(void)
{
  int32_T c1_previousEvent;
  uint8_T *c1_call_write_sequence_to_workspace;
  c1_call_write_sequence_to_workspace = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 1);
  c1_set_sim_state_side_effects_c1_stateflow_for_loop_no_mpc();
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_call_write_sequence_to_workspace, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_cnt, 1U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  if ((int16_T)chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
    chartInstance.c1_is_active_c1_stateflow_for_loop_no_mpc = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = (uint8_T)c1_IN_STEP1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
    chartInstance.c1_tp_STEP1 = 1U;
    *c1_call_write_sequence_to_workspace = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_call_write_sequence_to_workspace, 0U);
    c1_set_count(0, c1__u8_s32_(c1_get_count(0) + 1));
  } else {
    switch (chartInstance.c1_is_c1_stateflow_for_loop_no_mpc) {
     case c1_IN_Rest_Mode:
      CV_CHART_EVAL(0,0,1);
      break;

     case c1_IN_STEP1:
      CV_CHART_EVAL(0,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
      if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2,0,(((int16_T)
              c1_get_count(0) < 10)!=0))) != 0) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions= 1;
          transitionList[0] = 2;
          sf_debug_transition_conflict_check_begin();
          if ((int16_T)c1_get_count(0) >= 10) {
            transitionList[numTransitions] = 1;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c1_tp_STEP1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = (uint8_T)c1_IN_STEP1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c1_tp_STEP1 = 1U;
        *c1_call_write_sequence_to_workspace = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_call_write_sequence_to_workspace, 0U);
        c1_set_count(0, c1__u8_s32_(c1_get_count(0) + 1));
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
        if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1,0,(((int16_T)
                c1_get_count(0) >= 10)!=0))) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
          chartInstance.c1_tp_STEP1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
          chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = (uint8_T)
            c1_IN_Rest_Mode;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
          chartInstance.c1_tp_Rest_Mode = 1U;
          *c1_call_write_sequence_to_workspace = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_call_write_sequence_to_workspace, 0U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      break;

     default:
      CV_CHART_EVAL(0,0,0);
      chartInstance.c1_is_c1_stateflow_for_loop_no_mpc = (uint8_T)
        c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_stateflow_for_loop_no_mpcMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_stateflow_for_loop_no_mpc_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((uint8_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static uint8_T c1__u8_s32_(int32_T c1_b)
{
  uint8_T c1_a;
  c1_a = (uint8_T)c1_b;
  if (c1_a != c1_b) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c1_a;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_cnt;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_tp_Rest_Mode;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_tp_STEP1;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c1_testPointMappingInfo;
}

static uint8_T c1_get_count(int32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance.S, 0, NULL, c1_b);
  return chartInstance.c1_count_address[c1_b];
}

static void c1_set_count(int32_T c1_b, uint8_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance.S, 0, NULL, c1_b);
  chartInstance.c1_count_address[c1_b] = c1_c;
}

static void init_dsm_address_info(void)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance.S, sf_get_mapped_dsm_name
    (chartInstance.S, "count"), (void **)&chartInstance.
    c1_count_address, &chartInstance.c1_count_index);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_stateflow_for_loop_no_mpc_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1635795012U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(17435339U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3780548186U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(110659534U);
}

mxArray *sf_c1_stateflow_for_loop_no_mpc_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3682780666U);
    pr[1] = (double)(3401211610U);
    pr[2] = (double)(645569902U);
    pr[3] = (double)(2407895409U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_stateflow_for_loop_no_mpc(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[3],T\"call_write_sequence_to_workspace\",},{M[3],M[4],T\"cnt\",},{M[8],M[0],T\"is_active_c1_stateflow_for_loop_no_mpc\",},{M[9],M[0],T\"is_c1_stateflow_for_loop_no_mpc\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_stateflow_for_loop_no_mpc_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_stateflow_for_loop_no_mpcMachineNumber_,
           1,
           2,
           3,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_stateflow_for_loop_no_mpcMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_stateflow_for_loop_no_mpcMachineNumber_,chartInstance.chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_stateflow_for_loop_no_mpcMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_write_sequence_to_workspace",0,
                              (MexFcnForType)c1_sf_marshall);
          _SFD_SET_DATA_PROPS(1,0,0,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"cnt",0,
                              (MexFcnForType)c1_sf_marshall);
          _SFD_SET_DATA_PROPS(2,11,0,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"count",0,
                              (MexFcnForType)c1_sf_marshall);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          uint8_T *c1_call_write_sequence_to_workspace;
          c1_call_write_sequence_to_workspace = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_call_write_sequence_to_workspace);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c1_cnt);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance.c1_count_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_stateflow_for_loop_no_mpcMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_stateflow_for_loop_no_mpc();
  initialize_c1_stateflow_for_loop_no_mpc();
}

static void sf_opaque_enable_c1_stateflow_for_loop_no_mpc(void *chartInstanceVar)
{
  enable_c1_stateflow_for_loop_no_mpc();
}

static void sf_opaque_disable_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar)
{
  disable_c1_stateflow_for_loop_no_mpc();
}

static void sf_opaque_gateway_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar)
{
  sf_c1_stateflow_for_loop_no_mpc();
}

static mxArray* sf_opaque_get_sim_state_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_stateflow_for_loop_no_mpc();
  return st;
}

static void sf_opaque_set_sim_state_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c1_stateflow_for_loop_no_mpc(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_stateflow_for_loop_no_mpc(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_stateflow_for_loop_no_mpc();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_stateflow_for_loop_no_mpc(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_stateflow_for_loop_no_mpc();
  }
}

static void mdlSetWorkWidths_c1_stateflow_for_loop_no_mpc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("stateflow_for_loop_no_mpc",
      "stateflow_for_loop_no_mpc",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("stateflow_for_loop_no_mpc",
                "stateflow_for_loop_no_mpc",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "stateflow_for_loop_no_mpc","stateflow_for_loop_no_mpc",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"stateflow_for_loop_no_mpc",
        "stateflow_for_loop_no_mpc",1,1);
    }

    sf_set_rtw_dwork_info(S,"stateflow_for_loop_no_mpc",
                          "stateflow_for_loop_no_mpc",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(731689429U));
  ssSetChecksum1(S,(2140379322U));
  ssSetChecksum2(S,(1384943763U));
  ssSetChecksum3(S,(1833248769U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_stateflow_for_loop_no_mpc(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "stateflow_for_loop_no_mpc",
      "stateflow_for_loop_no_mpc",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_stateflow_for_loop_no_mpc(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_stateflow_for_loop_no_mpc;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c1_stateflow_for_loop_no_mpc_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_stateflow_for_loop_no_mpc(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_stateflow_for_loop_no_mpc(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_stateflow_for_loop_no_mpc(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_stateflow_for_loop_no_mpc_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/cnt", "cnt", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/Rest_Mode", "Rest_Mode", 0, 0, 0, 0, 0 },

  { 2, 0, "StateflowChart/STEP1", "STEP1", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    3                                  /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
