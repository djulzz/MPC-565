/* Include files */

#include "blascompat32.h"
#include "minimalist0_sfun.h"
#include "c3_minimalist0.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "minimalist0_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc3_minimalist0InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c3_minimalist0(void);
static void initialize_params_c3_minimalist0(void);
static void enable_c3_minimalist0(void);
static void disable_c3_minimalist0(void);
static void c3_update_debugger_state_c3_minimalist0(void);
static const mxArray *get_sim_state_c3_minimalist0(void);
static void set_sim_state_c3_minimalist0(const mxArray *c3_st);
static void finalize_c3_minimalist0(void);
static void sf_c3_minimalist0(void);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_d_sf_marshall(void *c3_chartInstance, void *c3_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c3_minimalist0(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c3_is_active_c3_minimalist0 = 0U;
}

static void initialize_params_c3_minimalist0(void)
{
}

static void enable_c3_minimalist0(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c3_minimalist0(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c3_update_debugger_state_c3_minimalist0(void)
{
}

static const mxArray *get_sim_state_c3_minimalist0(void)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T *c3_byte;
  c3_byte = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2));
  c3_u = *c3_byte;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_u = chartInstance.c3_is_active_c3_minimalist0;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_minimalist0(const mxArray *c3_st)
{
  const mxArray *c3_u;
  const mxArray *c3_byte;
  uint8_T c3_u0;
  uint8_T c3_y;
  const mxArray *c3_b_byte;
  uint8_T c3_u1;
  uint8_T c3_b_y;
  uint8_T *c3_c_byte;
  c3_c_byte = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_byte = sf_mex_dup(sf_mex_getcell(c3_u, 0));
  sf_mex_import("byte", sf_mex_dup(c3_byte), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_byte);
  *c3_c_byte = c3_y;
  c3_b_byte = sf_mex_dup(sf_mex_getcell(c3_u, 1));
  sf_mex_import("is_active_c3_minimalist0", sf_mex_dup(c3_b_byte), &c3_u1, 1, 3,
                0U, 0, 0U, 0);
  c3_b_y = c3_u1;
  sf_mex_destroy(&c3_b_byte);
  chartInstance.c3_is_active_c3_minimalist0 = c3_b_y;
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_minimalist0();
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_minimalist0(void)
{
}

static void sf_c3_minimalist0(void)
{
  int32_T c3_i0;
  int32_T c3_previousEvent;
  int32_T c3_i1;
  uint8_T c3_buffer[37];
  real_T c3_nargout = 1.0;
  real_T c3_nargin = 1.0;
  uint8_T c3_byte;
  uint8_T *c3_b_byte;
  uint8_T (*c3_b_buffer)[37];
  c3_b_buffer = (uint8_T (*)[37])ssGetInputPortSignal(chartInstance.S, 0);
  c3_b_byte = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c3_i0 = 0; c3_i0 < 37; c3_i0 = c3_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c3_b_buffer)[c3_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c3_b_byte, 1U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c3_i1 = 0; c3_i1 < 37; c3_i1 = c3_i1 + 1) {
    c3_buffer[c3_i1] = (*c3_b_buffer)[c3_i1];
  }

  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c3_nargout, c3_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c3_nargin, c3_c_sf_marshall);
  sf_debug_symbol_scope_add("byte", &c3_byte, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("buffer", &c3_buffer, c3_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,6);
  c3_byte = c3_buffer[2];
  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  *c3_b_byte = c3_byte;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_minimalist0MachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i2;
  uint8_T c3_b_u[37];
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  for (c3_i2 = 0; c3_i2 < 37; c3_i2 = c3_i2 + 1) {
    c3_b_u[c3_i2] = (*((uint8_T (*)[37])c3_u))[c3_i2];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 3, 0U, 1U, 0U, 1, 37));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  uint8_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((uint8_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_minimalist0_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c3_nameCaptureInfo;
}

static const mxArray *c3_d_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c3_minimalist0_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2251958243U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2418391744U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4146892977U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1808661944U);
}

mxArray *sf_c3_minimalist0_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2394422289U);
    pr[1] = (double)(2431630222U);
    pr[2] = (double)(3890368401U);
    pr[3] = (double)(3302175292U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(37);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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

static mxArray *sf_get_sim_state_info_c3_minimalist0(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[8],T\"byte\",},{M[8],M[0],T\"is_active_c3_minimalist0\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_minimalist0_get_check_sum(&mxChecksum);
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
          (_minimalist0MachineNumber_,
           3,
           1,
           1,
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
          init_script_number_translation(_minimalist0MachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_minimalist0MachineNumber_,
            chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_minimalist0MachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 37;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"buffer",0,(MexFcnForType)c3_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"byte",0,
                              (MexFcnForType)c3_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,72);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          uint8_T (*c3_buffer)[37];
          uint8_T *c3_byte;
          c3_buffer = (uint8_T (*)[37])ssGetInputPortSignal(chartInstance.S, 0);
          c3_byte = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_buffer);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_byte);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_minimalist0MachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_minimalist0(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c3_minimalist0();
  initialize_c3_minimalist0();
}

static void sf_opaque_enable_c3_minimalist0(void *chartInstanceVar)
{
  enable_c3_minimalist0();
}

static void sf_opaque_disable_c3_minimalist0(void *chartInstanceVar)
{
  disable_c3_minimalist0();
}

static void sf_opaque_gateway_c3_minimalist0(void *chartInstanceVar)
{
  sf_c3_minimalist0();
}

static mxArray* sf_opaque_get_sim_state_c3_minimalist0(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c3_minimalist0();
  return st;
}

static void sf_opaque_set_sim_state_c3_minimalist0(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c3_minimalist0(sf_mex_dup(st));
}

static void sf_opaque_terminate_c3_minimalist0(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c3_minimalist0();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_minimalist0(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_minimalist0();
  }
}

static void mdlSetWorkWidths_c3_minimalist0(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("minimalist0","minimalist0",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("minimalist0","minimalist0",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("minimalist0",
      "minimalist0",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"minimalist0","minimalist0",3,1);
      sf_mark_chart_reusable_outputs(S,"minimalist0","minimalist0",3,1);
    }

    sf_set_rtw_dwork_info(S,"minimalist0","minimalist0",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2296008829U));
  ssSetChecksum1(S,(76652171U));
  ssSetChecksum2(S,(2509764199U));
  ssSetChecksum3(S,(2951920499U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_minimalist0(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "minimalist0", "minimalist0",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_minimalist0(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c3_minimalist0;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c3_minimalist0;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c3_minimalist0;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c3_minimalist0;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c3_minimalist0;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c3_minimalist0;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c3_minimalist0;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_minimalist0;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c3_minimalist0;
  chartInstance.chartInfo.mdlStart = mdlStart_c3_minimalist0;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_minimalist0;
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

void c3_minimalist0_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_minimalist0(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_minimalist0(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_minimalist0(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_minimalist0_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
