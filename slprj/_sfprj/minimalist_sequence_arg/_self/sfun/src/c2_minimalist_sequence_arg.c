/* Include files */

#include "blascompat32.h"
#include "minimalist_sequence_arg_sfun.h"
#include "c2_minimalist_sequence_arg.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "minimalist_sequence_arg_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)
#define c2_IN_STEP                     (1)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_minimalist_sequence_argInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_minimalist_sequence_arg(void);
static void initialize_params_c2_minimalist_sequence_arg(void);
static void enable_c2_minimalist_sequence_arg(void);
static void disable_c2_minimalist_sequence_arg(void);
static void c2_update_debugger_state_c2_minimalist_sequence_arg(void);
static const mxArray *get_sim_state_c2_minimalist_sequence_arg(void);
static void set_sim_state_c2_minimalist_sequence_arg(const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_minimalist_sequence_arg(void);
static void finalize_c2_minimalist_sequence_arg(void);
static void sf_c2_minimalist_sequence_arg(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static uint8_T c2_get_buffer_receive_nav_mode(int32_T c2_b);
static void c2_set_buffer_receive_nav_mode(int32_T c2_b, uint8_T c2_c);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_minimalist_sequence_arg(void)
{
  uint8_T *c2_out;
  c2_out = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_doSetSimStateSideEffects = 0U;
  chartInstance.c2_setSimStateSideEffectsInfo = NULL;
  chartInstance.c2_tp_STEP = 0U;
  chartInstance.c2_is_active_c2_minimalist_sequence_arg = 0U;
  chartInstance.c2_is_c2_minimalist_sequence_arg = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c2_out = 0U;
  }
}

static void initialize_params_c2_minimalist_sequence_arg(void)
{
}

static void enable_c2_minimalist_sequence_arg(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_minimalist_sequence_arg(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_minimalist_sequence_arg(void)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance.c2_is_active_c2_minimalist_sequence_arg == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG,1);
  }

  if ((int16_T)chartInstance.c2_is_c2_minimalist_sequence_arg == c2_IN_STEP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  sf_debug_set_animation(c2_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_minimalist_sequence_arg(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T *c2_out;
  c2_out = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  c2_u = *c2_out;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = chartInstance.c2_is_active_c2_minimalist_sequence_arg;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_u = chartInstance.c2_is_c2_minimalist_sequence_arg;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_minimalist_sequence_arg(const mxArray *c2_st)
{
  const mxArray *c2_u;
  const mxArray *c2_out;
  uint8_T c2_u0;
  uint8_T c2_y;
  const mxArray *c2_b_out;
  uint8_T c2_u1;
  uint8_T c2_b_y;
  const mxArray *c2_c_out;
  uint8_T c2_u2;
  uint8_T c2_c_y;
  const mxArray *c2_b_setSimStateSideEffectsInfo;
  const mxArray *c2_d_y = NULL;
  uint8_T *c2_d_out;
  c2_d_out = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_u = sf_mex_dup(c2_st);
  c2_out = sf_mex_dup(sf_mex_getcell(c2_u, 0));
  sf_mex_import("out", sf_mex_dup(c2_out), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_out);
  *c2_d_out = c2_y;
  c2_b_out = sf_mex_dup(sf_mex_getcell(c2_u, 1));
  sf_mex_import("is_active_c2_minimalist_sequence_arg", sf_mex_dup(c2_b_out),
                &c2_u1, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u1;
  sf_mex_destroy(&c2_b_out);
  chartInstance.c2_is_active_c2_minimalist_sequence_arg = c2_b_y;
  c2_c_out = sf_mex_dup(sf_mex_getcell(c2_u, 2));
  sf_mex_import("is_c2_minimalist_sequence_arg", sf_mex_dup(c2_c_out), &c2_u2, 1,
                3, 0U, 0, 0U, 0);
  c2_c_y = c2_u2;
  sf_mex_destroy(&c2_c_out);
  chartInstance.c2_is_c2_minimalist_sequence_arg = c2_c_y;
  c2_b_setSimStateSideEffectsInfo = sf_mex_dup(sf_mex_getcell(c2_u, 3));
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_duplicatearraysafe
                (&c2_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  sf_mex_assign(&chartInstance.c2_setSimStateSideEffectsInfo, c2_d_y);
  sf_mex_destroy(&c2_u);
  chartInstance.c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_minimalist_sequence_arg();
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_minimalist_sequence_arg(void)
{
  if (chartInstance.c2_doSetSimStateSideEffects != 0) {
    if ((int16_T)chartInstance.c2_is_c2_minimalist_sequence_arg == c2_IN_STEP) {
      chartInstance.c2_tp_STEP = 1U;
    } else {
      chartInstance.c2_tp_STEP = 0U;
    }

    chartInstance.c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_minimalist_sequence_arg(void)
{
  sf_mex_destroy(&chartInstance.c2_setSimStateSideEffectsInfo);
}

static void sf_c2_minimalist_sequence_arg(void)
{
  int32_T c2_previousEvent;
  uint8_T *c2_out;
  c2_out = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_set_sim_state_side_effects_c2_minimalist_sequence_arg();
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_out, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  if ((int16_T)chartInstance.c2_is_active_c2_minimalist_sequence_arg == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,1);
    chartInstance.c2_is_active_c2_minimalist_sequence_arg = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
    chartInstance.c2_is_c2_minimalist_sequence_arg = (uint8_T)c2_IN_STEP;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c2_tp_STEP = 1U;
    *c2_out = c2_get_buffer_receive_nav_mode(1);
    _SFD_DATA_RANGE_CHECK((real_T)*c2_out, 1U);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_minimalist_sequence_argMachineNumber_,
    chartInstance.chartNumber, chartInstance.
    instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_minimalist_sequence_arg_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint8_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  uint8_T c2_b_u[37];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i0 = 0; c2_i0 < 37; c2_i0 = c2_i0 + 1) {
    c2_b_u[c2_i0] = (*((uint8_T (*)[37])c2_u))[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 1U, 0U, 1, 37));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c2_testPointAddrMap[0] = &chartInstance.c2_tp_STEP;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c2_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c2_testPointMappingInfo;
}

static uint8_T c2_get_buffer_receive_nav_mode(int32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance.S, 0, NULL, c2_b);
  return (*chartInstance.c2_buffer_receive_nav_mode_address)[c2_b];
}

static void c2_set_buffer_receive_nav_mode(int32_T c2_b, uint8_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance.S, 0, NULL, c2_b);
  (*chartInstance.c2_buffer_receive_nav_mode_address)[c2_b] = c2_c;
}

static void init_dsm_address_info(void)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance.S, sf_get_mapped_dsm_name
    (chartInstance.S, "buffer_receive_nav_mode"), (void **)&
    chartInstance.c2_buffer_receive_nav_mode_address,
    &chartInstance.c2_buffer_receive_nav_mode_index);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c2_minimalist_sequence_arg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(932180581U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3638454349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3716676629U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(624650901U);
}

mxArray *sf_c2_minimalist_sequence_arg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2227802213U);
    pr[1] = (double)(3408450152U);
    pr[2] = (double)(3207317314U);
    pr[3] = (double)(374778842U);
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

static mxArray *sf_get_sim_state_info_c2_minimalist_sequence_arg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[2],T\"out\",},{M[8],M[0],T\"is_active_c2_minimalist_sequence_arg\",},{M[9],M[0],T\"is_c2_minimalist_sequence_arg\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_minimalist_sequence_arg_get_check_sum(&mxChecksum);
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
          (_minimalist_sequence_argMachineNumber_,
           2,
           1,
           0,
           2,
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
          init_script_number_translation(_minimalist_sequence_argMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_minimalist_sequence_argMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_minimalist_sequence_argMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 37;
            _SFD_SET_DATA_PROPS(0,11,0,0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"buffer_receive_nav_mode",0,(MexFcnForType)
                                c2_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"out",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          uint8_T *c2_out;
          c2_out = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U,
            chartInstance.c2_buffer_receive_nav_mode_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_minimalist_sequence_argMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_minimalist_sequence_arg(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_minimalist_sequence_arg();
  initialize_c2_minimalist_sequence_arg();
}

static void sf_opaque_enable_c2_minimalist_sequence_arg(void *chartInstanceVar)
{
  enable_c2_minimalist_sequence_arg();
}

static void sf_opaque_disable_c2_minimalist_sequence_arg(void *chartInstanceVar)
{
  disable_c2_minimalist_sequence_arg();
}

static void sf_opaque_gateway_c2_minimalist_sequence_arg(void *chartInstanceVar)
{
  sf_c2_minimalist_sequence_arg();
}

static mxArray* sf_opaque_get_sim_state_c2_minimalist_sequence_arg(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_minimalist_sequence_arg();
  return st;
}

static void sf_opaque_set_sim_state_c2_minimalist_sequence_arg(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_minimalist_sequence_arg(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_minimalist_sequence_arg(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_minimalist_sequence_arg();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_minimalist_sequence_arg(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_minimalist_sequence_arg();
  }
}

static void mdlSetWorkWidths_c2_minimalist_sequence_arg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("minimalist_sequence_arg",
      "minimalist_sequence_arg",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("minimalist_sequence_arg",
                "minimalist_sequence_arg",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("minimalist_sequence_arg",
      "minimalist_sequence_arg",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"minimalist_sequence_arg",
        "minimalist_sequence_arg",2,1);
    }

    sf_set_rtw_dwork_info(S,"minimalist_sequence_arg","minimalist_sequence_arg",
                          2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(194670447U));
  ssSetChecksum1(S,(1723008846U));
  ssSetChecksum2(S,(2583065692U));
  ssSetChecksum3(S,(545158752U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_minimalist_sequence_arg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "minimalist_sequence_arg",
      "minimalist_sequence_arg",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_minimalist_sequence_arg(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_minimalist_sequence_arg;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_minimalist_sequence_arg;
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

void c2_minimalist_sequence_arg_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_minimalist_sequence_arg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_minimalist_sequence_arg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_minimalist_sequence_arg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_minimalist_sequence_arg_method_dispatcher.\n"
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
  { 0, 0, "StateflowChart/STEP", "STEP", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1                                  /* Num Block IO signals */
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
