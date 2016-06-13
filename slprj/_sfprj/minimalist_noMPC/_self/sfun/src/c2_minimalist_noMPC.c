/* Include files */

#include "blascompat32.h"
#include "minimalist_noMPC_sfun.h"
#include "c2_minimalist_noMPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "minimalist_noMPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)
#define c2_IN_S01                      (1)
#define c2_IN_S02                      (2)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_minimalist_noMPCInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_minimalist_noMPC(void);
static void initialize_params_c2_minimalist_noMPC(void);
static void enable_c2_minimalist_noMPC(void);
static void disable_c2_minimalist_noMPC(void);
static void c2_update_debugger_state_c2_minimalist_noMPC(void);
static const mxArray *get_sim_state_c2_minimalist_noMPC(void);
static void set_sim_state_c2_minimalist_noMPC(const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_minimalist_noMPC(void);
static void finalize_c2_minimalist_noMPC(void);
static void sf_c2_minimalist_noMPC(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static uint8_T c2_get_count(int32_T c2_b);
static void c2_set_count(int32_T c2_b, uint8_T c2_c);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_minimalist_noMPC(void)
{
  uint8_T *c2_call_write_to_nav;
  uint8_T *c2_call_request_nav_packet;
  uint8_T *c2_call_read_nav_pkt_from_nav420;
  uint8_T *c2_call_write_com3_buffer_O;
  uint8_T *c2_call_write_com3_buffer_C;
  uint8_T *c2_call_write_com3_buffer_third_byte;
  c2_call_read_nav_pkt_from_nav420 = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 3);
  c2_call_write_to_nav = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_call_write_com3_buffer_O = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    4);
  c2_call_write_com3_buffer_third_byte = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 6);
  c2_call_request_nav_packet = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    2);
  c2_call_write_com3_buffer_C = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    5);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_doSetSimStateSideEffects = 0U;
  chartInstance.c2_setSimStateSideEffectsInfo = NULL;
  chartInstance.c2_tp_S01 = 0U;
  chartInstance.c2_tp_S02 = 0U;
  chartInstance.c2_is_active_c2_minimalist_noMPC = 0U;
  chartInstance.c2_is_c2_minimalist_noMPC = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c2_call_write_to_nav = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c2_call_request_nav_packet = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 3) != 0)) {
    *c2_call_read_nav_pkt_from_nav420 = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 4) != 0)) {
    *c2_call_write_com3_buffer_O = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 5) != 0)) {
    *c2_call_write_com3_buffer_C = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 6) != 0)) {
    *c2_call_write_com3_buffer_third_byte = 0U;
  }
}

static void initialize_params_c2_minimalist_noMPC(void)
{
}

static void enable_c2_minimalist_noMPC(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_minimalist_noMPC(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_minimalist_noMPC(void)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance.c2_is_active_c2_minimalist_noMPC == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG,0);
  }

  if ((int16_T)chartInstance.c2_is_c2_minimalist_noMPC == c2_IN_S01) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if ((int16_T)chartInstance.c2_is_c2_minimalist_noMPC == c2_IN_S02) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  sf_debug_set_animation(c2_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_minimalist_noMPC(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  uint8_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  uint8_T *c2_call_read_nav_pkt_from_nav420;
  uint8_T *c2_call_request_nav_packet;
  uint8_T *c2_call_write_com3_buffer_C;
  uint8_T *c2_call_write_com3_buffer_O;
  uint8_T *c2_call_write_com3_buffer_third_byte;
  uint8_T *c2_call_write_to_nav;
  c2_call_read_nav_pkt_from_nav420 = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 3);
  c2_call_write_to_nav = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_call_write_com3_buffer_O = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    4);
  c2_call_write_com3_buffer_third_byte = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 6);
  c2_call_request_nav_packet = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    2);
  c2_call_write_com3_buffer_C = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    5);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(8));
  c2_u = *c2_call_read_nav_pkt_from_nav420;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = *c2_call_request_nav_packet;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_u = *c2_call_write_com3_buffer_C;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_u = *c2_call_write_com3_buffer_O;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_u = *c2_call_write_com3_buffer_third_byte;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_u = *c2_call_write_to_nav;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_u = chartInstance.c2_is_active_c2_minimalist_noMPC;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_u = chartInstance.c2_is_c2_minimalist_noMPC;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 7, c2_i_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_minimalist_noMPC(const mxArray *c2_st)
{
  const mxArray *c2_u;
  const mxArray *c2_call_read_nav_pkt_from_nav420;
  uint8_T c2_u0;
  uint8_T c2_y;
  const mxArray *c2_b_call_read_nav_pkt_from_nav420;
  uint8_T c2_u1;
  uint8_T c2_b_y;
  const mxArray *c2_c_call_read_nav_pkt_from_nav420;
  uint8_T c2_u2;
  uint8_T c2_c_y;
  const mxArray *c2_d_call_read_nav_pkt_from_nav420;
  uint8_T c2_u3;
  uint8_T c2_d_y;
  const mxArray *c2_e_call_read_nav_pkt_from_nav420;
  uint8_T c2_u4;
  uint8_T c2_e_y;
  const mxArray *c2_f_call_read_nav_pkt_from_nav420;
  uint8_T c2_u5;
  uint8_T c2_f_y;
  const mxArray *c2_g_call_read_nav_pkt_from_nav420;
  uint8_T c2_u6;
  uint8_T c2_g_y;
  const mxArray *c2_h_call_read_nav_pkt_from_nav420;
  uint8_T c2_u7;
  uint8_T c2_h_y;
  const mxArray *c2_b_setSimStateSideEffectsInfo;
  const mxArray *c2_i_y = NULL;
  uint8_T *c2_i_call_read_nav_pkt_from_nav420;
  uint8_T *c2_call_request_nav_packet;
  uint8_T *c2_call_write_com3_buffer_C;
  uint8_T *c2_call_write_com3_buffer_O;
  uint8_T *c2_call_write_com3_buffer_third_byte;
  uint8_T *c2_call_write_to_nav;
  c2_i_call_read_nav_pkt_from_nav420 = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 3);
  c2_call_write_to_nav = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_call_write_com3_buffer_O = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    4);
  c2_call_write_com3_buffer_third_byte = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 6);
  c2_call_request_nav_packet = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    2);
  c2_call_write_com3_buffer_C = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    5);
  c2_u = sf_mex_dup(c2_st);
  c2_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 0));
  sf_mex_import("call_read_nav_pkt_from_nav420", sf_mex_dup
                (c2_call_read_nav_pkt_from_nav420), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_call_read_nav_pkt_from_nav420);
  *c2_i_call_read_nav_pkt_from_nav420 = c2_y;
  c2_b_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 1));
  sf_mex_import("call_request_nav_packet", sf_mex_dup
                (c2_b_call_read_nav_pkt_from_nav420), &c2_u1, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u1;
  sf_mex_destroy(&c2_b_call_read_nav_pkt_from_nav420);
  *c2_call_request_nav_packet = c2_b_y;
  c2_c_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 2));
  sf_mex_import("call_write_com3_buffer_C", sf_mex_dup
                (c2_c_call_read_nav_pkt_from_nav420), &c2_u2, 1, 3, 0U, 0, 0U, 0);
  c2_c_y = c2_u2;
  sf_mex_destroy(&c2_c_call_read_nav_pkt_from_nav420);
  *c2_call_write_com3_buffer_C = c2_c_y;
  c2_d_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 3));
  sf_mex_import("call_write_com3_buffer_O", sf_mex_dup
                (c2_d_call_read_nav_pkt_from_nav420), &c2_u3, 1, 3, 0U, 0, 0U, 0);
  c2_d_y = c2_u3;
  sf_mex_destroy(&c2_d_call_read_nav_pkt_from_nav420);
  *c2_call_write_com3_buffer_O = c2_d_y;
  c2_e_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 4));
  sf_mex_import("call_write_com3_buffer_third_byte", sf_mex_dup
                (c2_e_call_read_nav_pkt_from_nav420), &c2_u4, 1, 3, 0U, 0, 0U, 0);
  c2_e_y = c2_u4;
  sf_mex_destroy(&c2_e_call_read_nav_pkt_from_nav420);
  *c2_call_write_com3_buffer_third_byte = c2_e_y;
  c2_f_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 5));
  sf_mex_import("call_write_to_nav", sf_mex_dup
                (c2_f_call_read_nav_pkt_from_nav420), &c2_u5, 1, 3, 0U, 0, 0U, 0);
  c2_f_y = c2_u5;
  sf_mex_destroy(&c2_f_call_read_nav_pkt_from_nav420);
  *c2_call_write_to_nav = c2_f_y;
  c2_g_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 6));
  sf_mex_import("is_active_c2_minimalist_noMPC", sf_mex_dup
                (c2_g_call_read_nav_pkt_from_nav420), &c2_u6, 1, 3, 0U, 0, 0U, 0);
  c2_g_y = c2_u6;
  sf_mex_destroy(&c2_g_call_read_nav_pkt_from_nav420);
  chartInstance.c2_is_active_c2_minimalist_noMPC = c2_g_y;
  c2_h_call_read_nav_pkt_from_nav420 = sf_mex_dup(sf_mex_getcell(c2_u, 7));
  sf_mex_import("is_c2_minimalist_noMPC", sf_mex_dup
                (c2_h_call_read_nav_pkt_from_nav420), &c2_u7, 1, 3, 0U, 0, 0U, 0);
  c2_h_y = c2_u7;
  sf_mex_destroy(&c2_h_call_read_nav_pkt_from_nav420);
  chartInstance.c2_is_c2_minimalist_noMPC = c2_h_y;
  c2_b_setSimStateSideEffectsInfo = sf_mex_dup(sf_mex_getcell(c2_u, 8));
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_duplicatearraysafe
                (&c2_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  sf_mex_assign(&chartInstance.c2_setSimStateSideEffectsInfo, c2_i_y);
  sf_mex_destroy(&c2_u);
  chartInstance.c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_minimalist_noMPC();
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_minimalist_noMPC(void)
{
  if (chartInstance.c2_doSetSimStateSideEffects != 0) {
    if ((int16_T)chartInstance.c2_is_c2_minimalist_noMPC == c2_IN_S01) {
      chartInstance.c2_tp_S01 = 1U;
    } else {
      chartInstance.c2_tp_S01 = 0U;
    }

    if ((int16_T)chartInstance.c2_is_c2_minimalist_noMPC == c2_IN_S02) {
      chartInstance.c2_tp_S02 = 1U;
    } else {
      chartInstance.c2_tp_S02 = 0U;
    }

    chartInstance.c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_minimalist_noMPC(void)
{
  sf_mex_destroy(&chartInstance.c2_setSimStateSideEffectsInfo);
}

static void sf_c2_minimalist_noMPC(void)
{
  int32_T c2_previousEvent;
  uint8_T *c2_call_write_to_nav;
  uint8_T *c2_call_request_nav_packet;
  uint8_T *c2_call_read_nav_pkt_from_nav420;
  uint8_T *c2_call_write_com3_buffer_O;
  uint8_T *c2_call_write_com3_buffer_C;
  uint8_T *c2_call_write_com3_buffer_third_byte;
  c2_call_read_nav_pkt_from_nav420 = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 3);
  c2_call_write_to_nav = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_call_write_com3_buffer_O = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    4);
  c2_call_write_com3_buffer_third_byte = (uint8_T *)ssGetOutputPortSignal
    (chartInstance.S, 6);
  c2_call_request_nav_packet = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    2);
  c2_call_write_com3_buffer_C = (uint8_T *)ssGetOutputPortSignal(chartInstance.S,
    5);
  c2_set_sim_state_side_effects_c2_minimalist_noMPC();
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_to_nav, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_request_nav_packet, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_read_nav_pkt_from_nav420, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_O, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_C, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_third_byte, 6U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  if ((int16_T)chartInstance.c2_is_active_c2_minimalist_noMPC == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
    chartInstance.c2_is_active_c2_minimalist_noMPC = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c2_is_c2_minimalist_noMPC = (uint8_T)c2_IN_S01;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c2_tp_S01 = 1U;
    *c2_call_write_com3_buffer_C = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_C, 5U);
    *c2_call_write_com3_buffer_O = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_O, 4U);
  } else {
    switch (chartInstance.c2_is_c2_minimalist_noMPC) {
     case c2_IN_S01:
      CV_CHART_EVAL(0,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
      chartInstance.c2_tp_S01 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      chartInstance.c2_is_c2_minimalist_noMPC = (uint8_T)c2_IN_S02;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
      chartInstance.c2_tp_S02 = 1U;
      *c2_call_write_com3_buffer_O = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_O, 4U);
      *c2_call_write_com3_buffer_C = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_C, 5U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      break;

     case c2_IN_S02:
      CV_CHART_EVAL(0,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
      chartInstance.c2_tp_S02 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      chartInstance.c2_is_c2_minimalist_noMPC = (uint8_T)c2_IN_S01;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
      chartInstance.c2_tp_S01 = 1U;
      *c2_call_write_com3_buffer_C = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_C, 5U);
      *c2_call_write_com3_buffer_O = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c2_call_write_com3_buffer_O, 4U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      break;

     default:
      CV_CHART_EVAL(0,0,0);
      chartInstance.c2_is_c2_minimalist_noMPC = (uint8_T)c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_minimalist_noMPCMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_minimalist_noMPC_get_eml_resolved_functions_info(void)
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

static void init_test_point_addr_map(void)
{
  chartInstance.c2_testPointAddrMap[0] = &chartInstance.c2_tp_S01;
  chartInstance.c2_testPointAddrMap[1] = &chartInstance.c2_tp_S02;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c2_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c2_testPointMappingInfo;
}

static uint8_T c2_get_count(int32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance.S, 0, NULL, c2_b);
  return chartInstance.c2_count_address[c2_b];
}

static void c2_set_count(int32_T c2_b, uint8_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance.S, 0, NULL, c2_b);
  chartInstance.c2_count_address[c2_b] = c2_c;
}

static void init_dsm_address_info(void)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance.S, sf_get_mapped_dsm_name
    (chartInstance.S, "count"), (void **)&chartInstance.
    c2_count_address, &chartInstance.c2_count_index);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c2_minimalist_noMPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(938524187U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4146941637U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1920521731U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2621110748U);
}

mxArray *sf_c2_minimalist_noMPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4205575979U);
    pr[1] = (double)(2616738514U);
    pr[2] = (double)(3034695533U);
    pr[3] = (double)(287483474U);
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

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_minimalist_noMPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[13],T\"call_read_nav_pkt_from_nav420\",},{M[1],M[12],T\"call_request_nav_packet\",},{M[1],M[18],T\"call_write_com3_buffer_C\",},{M[1],M[17],T\"call_write_com3_buffer_O\",},{M[1],M[19],T\"call_write_com3_buffer_third_byte\",},{M[1],M[11],T\"call_write_to_nav\",},{M[8],M[0],T\"is_active_c2_minimalist_noMPC\",},{M[9],M[0],T\"is_c2_minimalist_noMPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_minimalist_noMPC_get_check_sum(&mxChecksum);
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
          (_minimalist_noMPCMachineNumber_,
           2,
           2,
           3,
           7,
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
          init_script_number_translation(_minimalist_noMPCMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_minimalist_noMPCMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_minimalist_noMPCMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,11,0,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"count",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_write_to_nav",0,(MexFcnForType)
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_request_nav_packet",0,(MexFcnForType)
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_read_nav_pkt_from_nav420",0,(MexFcnForType)
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_write_com3_buffer_O",0,(MexFcnForType)
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_write_com3_buffer_C",0,(MexFcnForType)
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,
                              "call_write_com3_buffer_third_byte",0,
                              (MexFcnForType)c2_sf_marshall);
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
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          uint8_T *c2_call_write_to_nav;
          uint8_T *c2_call_request_nav_packet;
          uint8_T *c2_call_read_nav_pkt_from_nav420;
          uint8_T *c2_call_write_com3_buffer_O;
          uint8_T *c2_call_write_com3_buffer_C;
          uint8_T *c2_call_write_com3_buffer_third_byte;
          c2_call_read_nav_pkt_from_nav420 = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 3);
          c2_call_write_to_nav = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 1);
          c2_call_write_com3_buffer_O = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 4);
          c2_call_write_com3_buffer_third_byte = (uint8_T *)
            ssGetOutputPortSignal(chartInstance.S, 6);
          c2_call_request_nav_packet = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 2);
          c2_call_write_com3_buffer_C = (uint8_T *)ssGetOutputPortSignal
            (chartInstance.S, 5);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance.c2_count_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_call_write_to_nav);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_call_request_nav_packet);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_call_read_nav_pkt_from_nav420);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_call_write_com3_buffer_O);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_call_write_com3_buffer_C);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_call_write_com3_buffer_third_byte);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_minimalist_noMPCMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_minimalist_noMPC(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_minimalist_noMPC();
  initialize_c2_minimalist_noMPC();
}

static void sf_opaque_enable_c2_minimalist_noMPC(void *chartInstanceVar)
{
  enable_c2_minimalist_noMPC();
}

static void sf_opaque_disable_c2_minimalist_noMPC(void *chartInstanceVar)
{
  disable_c2_minimalist_noMPC();
}

static void sf_opaque_gateway_c2_minimalist_noMPC(void *chartInstanceVar)
{
  sf_c2_minimalist_noMPC();
}

static mxArray* sf_opaque_get_sim_state_c2_minimalist_noMPC(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_minimalist_noMPC();
  return st;
}

static void sf_opaque_set_sim_state_c2_minimalist_noMPC(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c2_minimalist_noMPC(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_minimalist_noMPC(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_minimalist_noMPC();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_minimalist_noMPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_minimalist_noMPC();
  }
}

static void mdlSetWorkWidths_c2_minimalist_noMPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("minimalist_noMPC","minimalist_noMPC",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("minimalist_noMPC","minimalist_noMPC",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("minimalist_noMPC",
      "minimalist_noMPC",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"minimalist_noMPC","minimalist_noMPC",2,6);
    }

    sf_set_rtw_dwork_info(S,"minimalist_noMPC","minimalist_noMPC",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1456333887U));
  ssSetChecksum1(S,(326271081U));
  ssSetChecksum2(S,(4041972365U));
  ssSetChecksum3(S,(2435905910U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_minimalist_noMPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "minimalist_noMPC", "minimalist_noMPC",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_minimalist_noMPC(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_minimalist_noMPC;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_minimalist_noMPC;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_minimalist_noMPC;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_minimalist_noMPC;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_minimalist_noMPC;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_minimalist_noMPC;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_minimalist_noMPC;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_minimalist_noMPC;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_minimalist_noMPC;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_minimalist_noMPC;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_minimalist_noMPC;
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

void c2_minimalist_noMPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_minimalist_noMPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_minimalist_noMPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_minimalist_noMPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_minimalist_noMPC_method_dispatcher.\n"
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
  { 0, 0, "StateflowChart/S01", "S01", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/S02", "S02", 0, 0, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    2                                  /* Num Block IO signals */
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
