/*
 * File: julien0.c
 *
 * Real-Time Workshop code generated for Simulink model julien0.
 *
 * Model version                        : 1.153
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Wed Oct 28 16:43:48 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Wed Oct 28 16:43:50 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "julien0.h"
#include "julien0_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define julien0_IN_End                 (1)

/* Block signals (auto storage) */
BlockIO_julien0 julien0_B;

/* Block states (auto storage) */
D_Work_julien0 julien0_DWork;

/* Real-time model */
RT_MODEL_julien0 julien0_M_;
RT_MODEL_julien0 *julien0_M = &julien0_M_;

/* Model step function */
void julien0_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_VectorConcatenate1[7];
  uint8_T rtb_DataStoreRead_lv[3];
  uint8_T rtb_IndexVector1;

  {
    int32_T s13_iter;
    uint8_T rtb_VectorConcatenate[5];

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: julien/Chart */
    /* During: julien/Chart */
    if (julien0_DWork.is_active_c2_julien0 == 0) {
      /* Entry: julien/Chart */
      julien0_DWork.is_active_c2_julien0 = 1U;

      /* Transition: '<S2>:16' */
      /* Entry 'End': '<S2>:3' */
      julien0_DWork.is_c2_julien0 = (uint8_T)julien0_IN_End;
    } else {
      /* During 'End': '<S2>:3' */
      /* Transition: '<S2>:15' */
      /* Exit 'End': '<S2>:3' */
      /* Entry 'End': '<S2>:3' */
      julien0_DWork.is_c2_julien0 = (uint8_T)julien0_IN_End;
    }

    /* Outputs for enable SubSystem: '<S1>/Read From NAV420' incorporates:
     *  EnablePort: '<S4>/Enable'
     */

    /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
     *  Constant: '<S4>/Constant'
     */
    julien0_DWork.count = 3U;

    /* Outputs for iterator SubSystem: '<S4>/For Iterator Subsystem1' incorporates:
     *  Constant: '<S4>/NAV420 NAV Mode  Packet Size'
     *  ForIterator: '<S13>/For Iterator'
     */
    for (s13_iter = 0; s13_iter < 37; s13_iter++) {
      /* S-Function (qsmcm_sci_rx): '<S13>/Serial Receive' */
      {
        uint32_T tmpVar = (1 <= 1U) ? 1 : 1U;
        general_get_string_sci2( &julien0_B.SerialReceive,tmpVar);
      }
    }

    /* end of Outputs for SubSystem: '<S4>/For Iterator Subsystem1' */

    /* end of Outputs for SubSystem: '<S1>/Read From NAV420' */

    /* Outputs for enable SubSystem: '<S1>/Request NAV Packet' incorporates:
     *  EnablePort: '<S5>/Enable'
     */

    /* DataStoreWrite: '<S5>/Data Store Write' */
    julien0_DWork.sz_buffer_transmit = 7U;

    /* Constant: '<S14>/Constant' */
    rtb_VectorConcatenate[0] = 85U;
    rtb_VectorConcatenate[1] = 85U;
    rtb_VectorConcatenate[2] = 71U;
    rtb_VectorConcatenate[3] = 80U;

    /* DataStoreRead: '<S14>/Data Store Read' */
    rtb_VectorConcatenate[4] = julien0_DWork.packet_cfg;

    /* SignalConversion: '<S14>/ConcatBufferAtVector Concatenate1In1' */
    for (s13_iter = 0; s13_iter < 5; s13_iter++) {
      rtb_VectorConcatenate1[s13_iter] = rtb_VectorConcatenate[s13_iter];
    }

    /* Sum: '<S14>/Sum of Elements1' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion3'
     */
    s13_iter = 151 + rtb_VectorConcatenate[4];

    /* DataTypeConversion: '<S14>/Data Type Conversion4' incorporates:
     *  ArithShift: '<S15>/shift'
     *  S-Function (sfix_bitop): '<S14>/Bitwise Operator2'
     */
    rtb_VectorConcatenate1[5] = (uint8_T)((int32_T)((uint32_T)s13_iter >> 8) &
      255);

    /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
     *  S-Function (sfix_bitop): '<S14>/Bitwise Operator3'
     */
    rtb_VectorConcatenate1[6] = (uint8_T)(uint32_T)(s13_iter & 255);

    /* SignalConversion: '<S5>/ConcatBufferAtVector ConcatenateIn1' */
    for (s13_iter = 0; s13_iter < 7; s13_iter++) {
      julien0_B.VectorConcatenate_l[s13_iter] = rtb_VectorConcatenate1[s13_iter];
    }

    /* DataStoreWrite: '<S5>/Data Store Write1' */
    for (s13_iter = 0; s13_iter < 11; s13_iter++) {
      julien0_DWork.buffer_transmit[s13_iter] =
        julien0_B.VectorConcatenate_l[s13_iter];
    }

    /* SwitchCase: '<S14>/Switch Case' incorporates:
     *  ActionPort: '<S16>/Action Port'
     *  ActionPort: '<S17>/Action Port'
     *  ActionPort: '<S18>/Action Port'
     *  Constant: '<S5>/Constant'
     *  SubSystem: '<S14>/Switch Case Action Subsystem'
     *  SubSystem: '<S14>/Switch Case Action Subsystem1'
     *  SubSystem: '<S14>/Switch Case Action Subsystem2'
     */

    /* DataStoreWrite: '<S17>/Data Store Write' incorporates:
     *  Constant: '<S17>/Constant'
     */
    julien0_DWork.packet_cfg = 78U;

    /* end of Outputs for SubSystem: '<S1>/Request NAV Packet' */

    /* Outputs for enable SubSystem: '<S1>/Write to NAV420' incorporates:
     *  EnablePort: '<S7>/Enable'
     */

    /* Outputs for iterator SubSystem: '<S7>/For Iterator Subsystem1' incorporates:
     *  DataStoreRead: '<S7>/Data Store Read3'
     *  ForIterator: '<S19>/For Iterator'
     */
    for (s13_iter = 1; (uint32_T)s13_iter <= julien0_DWork.sz_buffer_transmit;
         s13_iter++) {
      julien0_B.ForIterator = s13_iter;
    }

    /* end of Outputs for SubSystem: '<S7>/For Iterator Subsystem1' */

    /* MultiPortSwitch: '<S7>/Index Vector1' incorporates:
     *  DataStoreRead: '<S7>/Data Store Read2'
     */
    rtb_IndexVector1 = julien0_DWork.buffer_transmit[julien0_B.ForIterator - 1];

    /* S-Function (qsmcm_sci_tx): '<S7>/Serial Transmit1' */
    general_send_string_sci2(&rtb_IndexVector1,1);

    /* end of Outputs for SubSystem: '<S1>/Write to NAV420' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", "C"' incorporates:
     *  EnablePort: '<S8>/Enable'
     */

    /* DataStoreWrite: '<S8>/Data Store Write' */
    julien0_DWork.buffer_transmit_com3[0] = julien0_ConstB.VectorConcatenate_f[0];
    julien0_DWork.buffer_transmit_com3[1] = julien0_ConstB.VectorConcatenate_f[1];
    julien0_DWork.buffer_transmit_com3[2] = julien0_ConstB.VectorConcatenate_f[2];

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", "C"' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", "O"' incorporates:
     *  EnablePort: '<S9>/Enable'
     */

    /* DataStoreWrite: '<S9>/Data Store Write' */
    julien0_DWork.buffer_transmit_com3[0] = julien0_ConstB.VectorConcatenate[0];
    julien0_DWork.buffer_transmit_com3[1] = julien0_ConstB.VectorConcatenate[1];
    julien0_DWork.buffer_transmit_com3[2] = julien0_ConstB.VectorConcatenate[2];

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", "O"' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' incorporates:
     *  EnablePort: '<S10>/Enable'
     */

    /* Embedded MATLAB: '<S10>/Embedded MATLAB Function' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read'
     */
    /* Embedded MATLAB Function 'julien/Write to PC COM3 \"BUFFER\", 3rd byte/Embedded MATLAB Function': '<S20>:1' */
    /* '<S20>:1:6' */
    julien0_B.VectorConcatenate[0] = julien0_DWork.buffer_receive_nav_mode[2];

    /* DataStoreWrite: '<S10>/Data Store Write' */
    julien0_DWork.buffer_transmit_com3[0] = julien0_B.VectorConcatenate[0];
    julien0_DWork.buffer_transmit_com3[1] = julien0_B.VectorConcatenate[1];
    julien0_DWork.buffer_transmit_com3[2] = julien0_B.VectorConcatenate[2];

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' */

    /* Outputs for enable SubSystem: '<S1>/Write to PC COM3, 3 bytes' incorporates:
     *  EnablePort: '<S11>/Enable'
     */

    /* DataStoreRead: '<S11>/Data Store Read' */
    rtb_DataStoreRead_lv[0] = julien0_DWork.buffer_transmit_com3[0];
    rtb_DataStoreRead_lv[1] = julien0_DWork.buffer_transmit_com3[1];
    rtb_DataStoreRead_lv[2] = julien0_DWork.buffer_transmit_com3[2];

    /* S-Function (qsmcm_sci_tx): '<S11>/Serial Transmit' */
    general_send_string_sci1(rtb_DataStoreRead_lv,3U);

    /* end of Outputs for SubSystem: '<S1>/Write to PC COM3, 3 bytes' */
  }
}

/* Model initialize function */
void julien0_initialize(boolean_T firstTime)
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

  /* Constant: '<S10>/Constant1' */
  julien0_B.VectorConcatenate[1] = 13U;
  julien0_B.VectorConcatenate[2] = 10U;

  /* end of Start for SubSystem: '<S1>/Write to PC COM3 "BUFFER", 3rd byte' */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
