/*
 * File: minimalist0.c
 *
 * Real-Time Workshop code generated for Simulink model minimalist0.
 *
 * Model version                        : 1.179
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Oct 29 16:53:48 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Oct 29 16:53:51 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "minimalist0.h"
#include "minimalist0_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define minimalist0_IN_S01             (1)
#define minimalist0_IN_S05             (2)

/* Block signals (auto storage) */
BlockIO_minimalist0 minimalist0_B;

/* Block states (auto storage) */
D_Work_minimalist0 minimalist0_DWork;

/* Real-time model */
RT_MODEL_minimalist0 minimalist0_M_;
RT_MODEL_minimalist0 *minimalist0_M = &minimalist0_M_;

/* Model step function */
void minimalist0_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[3];
  uint8_T rtb_IndexVector;
  uint8_T rtb_VectorConcatenate1[7];

  {
    uint8_T rtb_call_write_com3_buffer_C;
    uint8_T rtb_call_write_com3_buffer_O;
    uint8_T rtb_VectorConcatenate[5];
    int32_T i;

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: minimalist/Chart */
    /* During: minimalist/Chart */
    if (minimalist0_DWork.is_active_c2_minimalist0 == 0) {
      /* Entry: minimalist/Chart */
      minimalist0_DWork.is_active_c2_minimalist0 = 1U;

      /* Transition: '<S2>:16' */
      /* Entry 'S01': '<S2>:3' */
      minimalist0_DWork.is_c2_minimalist0 = (uint8_T)minimalist0_IN_S01;
      rtb_call_write_com3_buffer_C = 0U;
      rtb_call_write_com3_buffer_O = 1U;

      /* call_write_3_bytes_to_pc_com3=0; */
    } else {
      switch (minimalist0_DWork.is_c2_minimalist0) {
       case minimalist0_IN_S01:
        /* During 'S01': '<S2>:3' */
        /* Transition: '<S2>:40' */
        /* Exit 'S01': '<S2>:3' */
        /* Entry 'S05': '<S2>:23' */
        minimalist0_DWork.is_c2_minimalist0 = (uint8_T)minimalist0_IN_S05;
        rtb_call_write_com3_buffer_O = 0U;
        rtb_call_write_com3_buffer_C = 1U;

        /* call_write_3_bytes_to_pc_com3=0; */
        break;

       case minimalist0_IN_S05:
        /* During 'S05': '<S2>:23' */
        /* Transition: '<S2>:41' */
        /* Exit 'S05': '<S2>:23' */
        /* Entry 'S01': '<S2>:3' */
        minimalist0_DWork.is_c2_minimalist0 = (uint8_T)minimalist0_IN_S01;
        rtb_call_write_com3_buffer_C = 0U;
        rtb_call_write_com3_buffer_O = 1U;

        /* call_write_3_bytes_to_pc_com3=0; */
        break;

       default:
        /* Transition: '<S2>:16' */
        /* Entry 'S01': '<S2>:3' */
        minimalist0_DWork.is_c2_minimalist0 = (uint8_T)minimalist0_IN_S01;
        rtb_call_write_com3_buffer_C = 0U;
        rtb_call_write_com3_buffer_O = 1U;

        /* call_write_3_bytes_to_pc_com3=0; */
        break;
      }
    }

    /* Outputs for enable SubSystem: '<S1>/Request NAV Packet' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (minimalist0_B.call_request_nav_packet > 0) {
      /* DataStoreWrite: '<S4>/Data Store Write' */
      minimalist0_DWork.sz_buffer_transmit = 7U;

      /* Constant: '<S10>/Constant' */
      rtb_VectorConcatenate[0] = 85U;
      rtb_VectorConcatenate[1] = 85U;
      rtb_VectorConcatenate[2] = 71U;
      rtb_VectorConcatenate[3] = 80U;

      /* DataStoreRead: '<S10>/Data Store Read' */
      rtb_VectorConcatenate[4] = minimalist0_DWork.packet_cfg;

      /* SignalConversion: '<S10>/ConcatBufferAtVector Concatenate1In1' */
      for (i = 0; i < 5; i++) {
        rtb_VectorConcatenate1[i] = rtb_VectorConcatenate[i];
      }

      /* Sum: '<S10>/Sum of Elements1' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion3'
       */
      i = 151 + rtb_VectorConcatenate[4];

      /* DataTypeConversion: '<S10>/Data Type Conversion4' incorporates:
       *  ArithShift: '<S11>/shift'
       *  S-Function (sfix_bitop): '<S10>/Bitwise Operator2'
       */
      rtb_VectorConcatenate1[5] = (uint8_T)((int32_T)((uint32_T)i >> 8) & 255);

      /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
       *  S-Function (sfix_bitop): '<S10>/Bitwise Operator3'
       */
      rtb_VectorConcatenate1[6] = (uint8_T)(uint32_T)(i & 255);

      /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn1' */
      for (i = 0; i < 7; i++) {
        minimalist0_B.VectorConcatenate_p[i] = rtb_VectorConcatenate1[i];
      }

      /* DataStoreWrite: '<S4>/Data Store Write1' */
      for (i = 0; i < 11; i++) {
        minimalist0_DWork.buffer_transmit[i] =
          minimalist0_B.VectorConcatenate_p[i];
      }

      /* SwitchCase: '<S10>/Switch Case' incorporates:
       *  ActionPort: '<S12>/Action Port'
       *  ActionPort: '<S13>/Action Port'
       *  ActionPort: '<S14>/Action Port'
       *  Constant: '<S4>/Constant'
       *  SubSystem: '<S10>/Switch Case Action Subsystem'
       *  SubSystem: '<S10>/Switch Case Action Subsystem1'
       *  SubSystem: '<S10>/Switch Case Action Subsystem2'
       */

      /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
       *  Constant: '<S13>/Constant'
       */
      minimalist0_DWork.packet_cfg = 78U;
    }

    /* end of Outputs for SubSystem: '<S1>/Request NAV Packet' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", "C"' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (rtb_call_write_com3_buffer_C > 0) {
      /* DataStoreWrite: '<S6>/Data Store Write' */
      minimalist0_DWork.buffer_transmit_com3[0] =
        minimalist0_ConstB.VectorConcatenate_d[0];
      minimalist0_DWork.buffer_transmit_com3[1] =
        minimalist0_ConstB.VectorConcatenate_d[1];
      minimalist0_DWork.buffer_transmit_com3[2] =
        minimalist0_ConstB.VectorConcatenate_d[2];
    }

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", "C"' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", "O"' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (rtb_call_write_com3_buffer_O > 0) {
      /* DataStoreWrite: '<S7>/Data Store Write' */
      minimalist0_DWork.buffer_transmit_com3[0] =
        minimalist0_ConstB.VectorConcatenate[0];
      minimalist0_DWork.buffer_transmit_com3[1] =
        minimalist0_ConstB.VectorConcatenate[1];
      minimalist0_DWork.buffer_transmit_com3[2] =
        minimalist0_ConstB.VectorConcatenate[2];
    }

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", "O"' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (minimalist0_B.call_write_com3_buffer_third_by > 0) {
      /* Embedded MATLAB: '<S8>/Embedded MATLAB Function' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read'
       */
      /* Embedded MATLAB Function 'minimalist/Write to PC COM3 \"BUFFER\", 3rd byte/Embedded MATLAB Function': '<S15>:1' */
      /* '<S15>:1:6' */
      minimalist0_B.VectorConcatenate[0] =
        minimalist0_DWork.buffer_receive_nav_mode[2];

      /* DataStoreWrite: '<S8>/Data Store Write' */
      minimalist0_DWork.buffer_transmit_com3[0] =
        minimalist0_B.VectorConcatenate[0];
      minimalist0_DWork.buffer_transmit_com3[1] =
        minimalist0_B.VectorConcatenate[1];
      minimalist0_DWork.buffer_transmit_com3[2] =
        minimalist0_B.VectorConcatenate[2];
    }

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3, 3 bytes' incorporates:
     *  EnablePort: '<S9>/Enable'
     */

    /* DataStoreWrite: '<S9>/Data Store Write' */
    minimalist0_DWork.nElems = 3U;

    /* DataStoreRead: '<S9>/Data Store Read' */
    rtb_DataStoreRead[0] = minimalist0_DWork.buffer_transmit_com3[0];
    rtb_DataStoreRead[1] = minimalist0_DWork.buffer_transmit_com3[1];
    rtb_DataStoreRead[2] = minimalist0_DWork.buffer_transmit_com3[2];

    /* Outputs for iterator SubSystem: '<S9>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S16>/For Iterator'
     */

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  Constant: '<S16>/Constant'
     *  DataStoreRead: '<S16>/Data Store Read'
     *  Sum: '<S16>/Add'
     */
    minimalist0_DWork.nIters = minimalist0_DWork.nIters + 1U;

    /* MultiPortSwitch: '<S16>/Index Vector' */
    rtb_IndexVector = rtb_DataStoreRead[0];

    /* If: '<S16>/If' incorporates:
     *  ActionPort: '<S17>/Action Port'
     *  ActionPort: '<S18>/Action Port'
     *  DataStoreRead: '<S16>/Data Store Read1'
     *  DataStoreRead: '<S16>/Data Store Read2'
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  SubSystem: '<S16>/If Action Subsystem'
     *  SubSystem: '<S16>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist0_DWork.nIters <= minimalist0_DWork.nElems) == 1U)
    {
      /* S-Function (qsmcm_sci_tx): '<S17>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    } else {
      /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
       *  Constant: '<S18>/Constant'
       */
      minimalist0_DWork.nIters = 0U;
    }

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  Constant: '<S16>/Constant'
     *  DataStoreRead: '<S16>/Data Store Read'
     *  Sum: '<S16>/Add'
     */
    minimalist0_DWork.nIters = minimalist0_DWork.nIters + 1U;

    /* MultiPortSwitch: '<S16>/Index Vector' */
    rtb_IndexVector = rtb_DataStoreRead[1];

    /* If: '<S16>/If' incorporates:
     *  ActionPort: '<S17>/Action Port'
     *  ActionPort: '<S18>/Action Port'
     *  DataStoreRead: '<S16>/Data Store Read1'
     *  DataStoreRead: '<S16>/Data Store Read2'
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  SubSystem: '<S16>/If Action Subsystem'
     *  SubSystem: '<S16>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist0_DWork.nIters <= minimalist0_DWork.nElems) == 1U)
    {
      /* S-Function (qsmcm_sci_tx): '<S17>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    } else {
      /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
       *  Constant: '<S18>/Constant'
       */
      minimalist0_DWork.nIters = 0U;
    }

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  Constant: '<S16>/Constant'
     *  DataStoreRead: '<S16>/Data Store Read'
     *  Sum: '<S16>/Add'
     */
    minimalist0_DWork.nIters = minimalist0_DWork.nIters + 1U;

    /* MultiPortSwitch: '<S16>/Index Vector' */
    rtb_IndexVector = rtb_DataStoreRead[2];

    /* If: '<S16>/If' incorporates:
     *  ActionPort: '<S17>/Action Port'
     *  ActionPort: '<S18>/Action Port'
     *  DataStoreRead: '<S16>/Data Store Read1'
     *  DataStoreRead: '<S16>/Data Store Read2'
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  SubSystem: '<S16>/If Action Subsystem'
     *  SubSystem: '<S16>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist0_DWork.nIters <= minimalist0_DWork.nElems) == 1U)
    {
      /* S-Function (qsmcm_sci_tx): '<S17>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    } else {
      /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
       *  Constant: '<S18>/Constant'
       */
      minimalist0_DWork.nIters = 0U;
    }

    /* end of Outputs for SubSystem: '<S9>/For Iterator Subsystem' */

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3, 3 bytes' */
  }
}

/* Model initialize function */
void minimalist0_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Start for S-Function (sfunRTWConfig): '<S3>/config' */

  /* -- Resource Configuration : MPC555dkConfig::SYSTEM_CLOCKS : [START] --- */
  USIU.PLPRCR.B.MF = 9;

  /* Wait for PLL to Lock */
  while (USIU.PLPRCR.B.SPLS == 0) ;

  /* Assuming External Oscilator Frequency = 4000000 */

  /* The DIVF bits control the value of the pre-divider in the SPLL circuit. */
  USIU.PLPRCR.B.DIVF = 0;

  /* Division factor high frequency. */
  USIU.SCCR.B.DFNH = 0;

  /* Division factor low frequency. */
  USIU.SCCR.B.DFNL = 0;

  /* RTC (and PIT) clock diver. Divide by 256 */
  USIU.SCCR.B.RTDIV = 1;

  /* External bus division factor. */
  USIU.SCCR.B.EBDF = 0;

  /* MIOS14 Test and Pin Control Register configuration CCAN bit
   * 1 = TOUCAN_C function is selected (c_cntx0, c_cnrx0)
   * 0 = MIOS General Purpose I/O is selected (mpio32b13, mpio32b14)
   */
  MIOS14.MIOS14TPCR.B.VMUX2 = 0;

  /* -- Resource Configuration : MPC555dkConfig::SYSTEM_CLOCKS : [END] --- */

  /* -- Resource Configuration : MPC555dkConfig::QSMCM : [START] --- */
  {
    /* SCI1 control register 0
     * Ideal bit rate = 9600.0
     * Achieved bit rate = 9.6153846153846152E+003
     * Calculation based on system clock = 4.0E+007
     * Loop mode = Standard transmit/receive
     */
    const uint16_T sc1br = 0x82U;

    /* SCI1 control register 1
     * Using 8-bit data
     * Parity = N/A
     */
    const uint16_T scc1r1 = 0xcU;
    qsmcm_sci1_init(sc1br, scc1r1);
  }

  {
    /* SCI2 control register 0
     * Ideal bit rate = 9600.0
     * Achieved bit rate = 9.6153846153846152E+003
     * Calculation based on system clock = 4.0E+007
     * Loop mode = Standard transmit/receive
     */
    const uint16_T sc2br = 0x82U;

    /* SCI2 control register 1
     * Using 8-bit data
     * Parity = N/A
     */
    const uint16_T scc2r1 = 0xcU;
    qsmcm_sci2_init(sc2br, scc2r1);
  }

  /* -- Resource Configuration : MPC555dkConfig::QSMCM : [END] --- */

  /* Start for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' */

  /* Constant: '<S8>/Constant1' */
  minimalist0_B.VectorConcatenate[1] = 13U;
  minimalist0_B.VectorConcatenate[2] = 10U;

  /* end of Start for SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
