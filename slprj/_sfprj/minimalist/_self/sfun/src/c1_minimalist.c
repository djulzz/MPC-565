/* Include files */

#include "blascompat32.h"
#include "minimalist_sfun.h"
#include "c1_minimalist.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "minimalist_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_minimalistInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_minimalist(void);
static void initialize_params_c1_minimalist(void);
static void enable_c1_minimalist(void);
static void disable_c1_minimalist(void);
static void c1_update_debugger_state_c1_minimalist(void);
static const mxArray *get_sim_state_c1_minimalist(void);
static void set_sim_state_c1_minimalist(const mxArray *c1_st);
static void finalize_c1_minimalist(void);
static void sf_c1_minimalist(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_minimalist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_is_active_c1_minimalist = 0U;
}

static void initialize_params_c1_minimalist(void)
{
}

static void enable_c1_minimalist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_minimalist(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c1_update_debugger_state_c1_minimalist(void)
{
}

static const mxArray *get_sim_state_c1_minimalist(void)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1));
  c1_u = chartInstance.c1_is_active_c1_minimalist;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_minimalist(const mxArray *c1_st)
{
  const mxArray *c1_u;
  const mxArray *c1_b_is_active_c1_minimalist;
  uint8_T c1_u0;
  uint8_T c1_y;
  chartInstance.c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_b_is_active_c1_minimalist = sf_mex_dup(sf_mex_getcell(c1_u, 0));
  sf_mex_import("is_active_c1_minimalist", sf_mex_dup
                (c1_b_is_active_c1_minimalist), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_minimalist);
  chartInstance.c1_is_active_c1_minimalist = c1_y;
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_minimalist();
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_minimalist(void)
{
}

static void sf_c1_minimalist(void)
{
  int32_T c1_i0;
  int32_T c1_previousEvent;
  int32_T c1_current_index;
  uint8_T c1_current_byte;
  int32_T c1_i1;
  uint8_T c1_buffer[37];
  real_T c1_nargout = 0.0;
  real_T c1_nargin = 3.0;
  int32_T *c1_b_current_index;
  uint8_T *c1_b_current_byte;
  uint8_T (*c1_b_buffer)[37];
  c1_b_buffer = (uint8_T (*)[37])ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_current_byte = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_b_current_index = (int32_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_current_index, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_current_byte, 1U);
  for (c1_i0 = 0; c1_i0 < 37; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_buffer)[c1_i0], 2U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_current_index = *c1_b_current_index;
  c1_current_byte = *c1_b_current_byte;
  for (c1_i1 = 0; c1_i1 < 37; c1_i1 = c1_i1 + 1) {
    c1_buffer[c1_i1] = (*c1_b_buffer)[c1_i1];
  }

  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("buffer", &c1_buffer, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("current_byte", &c1_current_byte, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("current_index", &c1_current_index, c1_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,6);
  c1_buffer[_SFD_EML_ARRAY_BOUNDS_CHECK("buffer", (int32_T)_SFD_INTEGER_CHECK(
    "current_index", (real_T)c1_current_index), 1, 37, 1, 0)
    - 1] = c1_current_byte;
  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_minimalistMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((int32_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
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

static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i2;
  uint8_T c1_b_u[37];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for (c1_i2 = 0; c1_i2 < 37; c1_i2 = c1_i2 + 1) {
    c1_b_u[c1_i2] = (*((uint8_T (*)[37])c1_u))[c1_i2];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 3, 0U, 1U, 0U, 1, 37));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_minimalist_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u)
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

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_minimalist_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1465990719U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2472424492U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4005428107U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2853204674U);
}

mxArray *sf_c1_minimalist_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1318488556U);
    pr[1] = (double)(299779901U);
    pr[2] = (double)(251055162U);
    pr[3] = (double)(3211735785U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(37);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_minimalist(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_minimalist\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_minimalist_get_check_sum(&mxChecksum);
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
          (_minimalistMachineNumber_,
           1,
           1,
           1,
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
          init_script_number_translation(_minimalistMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_minimalistMachineNumber_,
            chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_minimalistMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,
                              "current_index",0,(MexFcnForType)c1_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "current_byte",0,(MexFcnForType)c1_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 37;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"buffer",0,(MexFcnForType)c1_c_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,108);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          int32_T *c1_current_index;
          uint8_T *c1_current_byte;
          uint8_T (*c1_buffer)[37];
          c1_buffer = (uint8_T (*)[37])ssGetInputPortSignal(chartInstance.S, 2);
          c1_current_byte = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c1_current_index = (int32_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_current_index);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_current_byte);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_buffer);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_minimalistMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_minimalist(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_minimalist();
  initialize_c1_minimalist();
}

static void sf_opaque_enable_c1_minimalist(void *chartInstanceVar)
{
  enable_c1_minimalist();
}

static void sf_opaque_disable_c1_minimalist(void *chartInstanceVar)
{
  disable_c1_minimalist();
}

static void sf_opaque_gateway_c1_minimalist(void *chartInstanceVar)
{
  sf_c1_minimalist();
}

static mxArray* sf_opaque_get_sim_state_c1_minimalist(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_minimalist();
  return st;
}

static void sf_opaque_set_sim_state_c1_minimalist(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c1_minimalist(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_minimalist(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_minimalist();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_minimalist(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_minimalist();
  }
}

static void mdlSetWorkWidths_c1_minimalist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("minimalist","minimalist",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("minimalist","minimalist",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("minimalist","minimalist",
      1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"minimalist","minimalist",1,3);
    }

    sf_set_rtw_dwork_info(S,"minimalist","minimalist",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1568023918U));
  ssSetChecksum1(S,(3368819320U));
  ssSetChecksum2(S,(3945233859U));
  ssSetChecksum3(S,(1384577097U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_minimalist(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "minimalist", "minimalist",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_minimalist(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_minimalist;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_minimalist;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_minimalist;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_minimalist;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_minimalist;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c1_minimalist;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c1_minimalist;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_minimalist;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_minimalist;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_minimalist;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_minimalist;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c1_minimalist_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_minimalist(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_minimalist(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_minimalist(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_minimalist_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
