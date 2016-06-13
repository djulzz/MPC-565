/*
 * File: minimalist_sequence_arg.c
 *
 * Real-Time Workshop code generated for Simulink model minimalist_sequence_arg.
 *
 * Model version                        : 1.271
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 18:09:26 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 18:09:29 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "minimalist_sequence_arg.h"
#include "minimalist_sequence_arg_private.h"

/* Named constants for Stateflow: '<S3>/Chart' */
#define minimalist_sequence_arg_IN_STEP (1)

/* Named constants for Stateflow: '<S9>/Chart' */
#define minimalist_sequence_arg_IN_step (1)

/* Block signals (auto storage) */
BlockIO_minimalist_sequence_arg minimalist_sequence_arg_B;

/* Block states (auto storage) */
D_Work_minimalist_sequence_arg minimalist_sequence_arg_DWork;

/* Real-time model */
RT_MODEL_minimalist_sequence_ar minimalist_sequence_arg_M_;
RT_MODEL_minimalist_sequence_ar *minimalist_sequence_arg_M =
  &minimalist_sequence_arg_M_;

/*
 * Output and update for action system:
 *    '<S8>/If Action Subsystem1'
 *    '<S12>/If Action Subsystem1'
 */
void minimalist_s_IfActionSubsystem1(uint32_T *rtd_nIters)
{
  /* DataStoreWrite: '<S10>/Data Store Write' incorporates:
   *  Constant: '<S10>/Constant'
   */
  (*rtd_nIters) = 0U;
}

/* Model step function */
void minimalist_sequence_arg_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_VectorConcatenate1[7];
  uint8_T rtb_SerialReceive;
  uint8_T rtb_IndexVector;

  {
    uint8_T rtb_VectorConcatenate[5];
    uint32_T rtb_DataStoreRead1;
    int32_T i;

    /* DataStoreWrite: '<S5>/Data Store Write' */
    minimalist_sequence_arg_DWork.nElems = 37U;

    /* Outputs for atomic SubSystem: '<S5>/For Iterator Subsystem' */

    /* If: '<S8>/If' incorporates:
     *  ActionPort: '<S10>/Action Port'
     *  ActionPort: '<S9>/Action Port'
     *  DataStoreRead: '<S8>/Data Store Read1'
     *  DataStoreRead: '<S8>/Data Store Read2'
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  RelationalOperator: '<S8>/Relational Operator'
     *  SubSystem: '<S8>/If Action Subsystem'
     *  SubSystem: '<S8>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist_sequence_arg_DWork.nIters <
                   minimalist_sequence_arg_DWork.nElems) == 1U) {
      /* DataStoreWrite: '<S9>/Data Store Write' incorporates:
       *  Constant: '<S9>/Constant'
       *  DataStoreRead: '<S9>/Data Store Read'
       *  Sum: '<S9>/Add'
       */
      minimalist_sequence_arg_DWork.nIters =
        minimalist_sequence_arg_DWork.nIters + 1U;

      /* DataStoreRead: '<S9>/Data Store Read1' */
      rtb_DataStoreRead1 = minimalist_sequence_arg_DWork.nIters;

      /* S-Function (qsmcm_sci_rx): '<S9>/Serial Receive' */
      {
        uint32_T tmpVar = (1U <= 1U) ? 1U : 1U;
        general_get_string_sci2( &rtb_SerialReceive,tmpVar);
      }

      /* Stateflow: '<S9>/Chart' */
      /* Gateway: minimalist_sequence_arg/rcvNAV/For Iterator
         Subsystem/If Action
         Subsystem/Chart */
      /* During: minimalist_sequence_arg/rcvNAV/For Iterator
         Subsystem/If Action
         Subsystem/Chart */
      if (minimalist_sequence_arg_DWork.is_active_c1_minimalist_sequenc == 0) {
        /* Entry: minimalist_sequence_arg/rcvNAV/For Iterator
           Subsystem/If Action
           Subsystem/Chart */
        minimalist_sequence_arg_DWork.is_active_c1_minimalist_sequenc = 1U;

        /* Transition: '<S11>:5' */
        /* Entry 'step': '<S11>:4' */
        minimalist_sequence_arg_DWork.is_c1_minimalist_sequence_arg = (uint8_T)
          minimalist_sequence_arg_IN_step;
        minimalist_sequence_arg_DWork.buffer_receive_nav_mode[rtb_DataStoreRead1]
          = rtb_SerialReceive;
      }
    } else {
      minimalist_s_IfActionSubsystem1(&minimalist_sequence_arg_DWork.nIters);
    }

    /* end of Outputs for SubSystem: '<S5>/For Iterator Subsystem' */

    /* DataStoreWrite: '<S6>/Data Store Write' */
    minimalist_sequence_arg_DWork.nElems_b = 7U;

    /* Constant: '<S13>/Constant' */
    rtb_VectorConcatenate[0] = 85U;
    rtb_VectorConcatenate[1] = 85U;
    rtb_VectorConcatenate[2] = 71U;
    rtb_VectorConcatenate[3] = 80U;

    /* DataStoreRead: '<S13>/Data Store Read' */
    rtb_VectorConcatenate[4] = minimalist_sequence_arg_DWork.packet_cfg;

    /* SignalConversion: '<S13>/ConcatBufferAtVector Concatenate1In1' */
    for (i = 0; i < 5; i++) {
      rtb_VectorConcatenate1[i] = rtb_VectorConcatenate[i];
    }

    /* Sum: '<S13>/Sum of Elements1' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion3'
     */
    i = 151 + rtb_VectorConcatenate[4];

    /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
     *  ArithShift: '<S16>/shift'
     *  S-Function (sfix_bitop): '<S13>/Bitwise Operator2'
     */
    rtb_VectorConcatenate1[5] = (uint8_T)((int32_T)((uint32_T)i >> 8) & 255);

    /* DataTypeConversion: '<S13>/Data Type Conversion5' incorporates:
     *  S-Function (sfix_bitop): '<S13>/Bitwise Operator3'
     */
    rtb_VectorConcatenate1[6] = (uint8_T)(uint32_T)(i & 255);

    /* Outputs for atomic SubSystem: '<S6>/For Iterator Subsystem' */

    /* If: '<S12>/If' incorporates:
     *  ActionPort: '<S14>/Action Port'
     *  ActionPort: '<S15>/Action Port'
     *  DataStoreRead: '<S12>/Data Store Read1'
     *  DataStoreRead: '<S12>/Data Store Read2'
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     *  RelationalOperator: '<S12>/Relational Operator'
     *  SubSystem: '<S12>/If Action Subsystem'
     *  SubSystem: '<S12>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist_sequence_arg_DWork.nIters_p <
                   minimalist_sequence_arg_DWork.nElems_b) == 1U) {
      /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
       *  Constant: '<S14>/Constant'
       *  DataStoreRead: '<S14>/Data Store Read'
       *  Sum: '<S14>/Add'
       */
      minimalist_sequence_arg_DWork.nIters_p =
        minimalist_sequence_arg_DWork.nIters_p + 1U;

      /* MultiPortSwitch: '<S14>/Index Vector' incorporates:
       *  DataStoreRead: '<S14>/Data Store Read3'
       */
      rtb_IndexVector = rtb_VectorConcatenate1[(int32_T)
        minimalist_sequence_arg_DWork.nIters_p - 1];

      /* S-Function (qsmcm_sci_tx): '<S14>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    } else {
      minimalist_s_IfActionSubsystem1(&minimalist_sequence_arg_DWork.nIters_p);
    }

    /* end of Outputs for SubSystem: '<S6>/For Iterator Subsystem' */

    /* SwitchCase: '<S13>/Switch Case' incorporates:
     *  ActionPort: '<S17>/Action Port'
     *  ActionPort: '<S18>/Action Port'
     *  ActionPort: '<S19>/Action Port'
     *  Constant: '<S6>/Constant'
     *  SubSystem: '<S13>/Switch Case Action Subsystem'
     *  SubSystem: '<S13>/Switch Case Action Subsystem1'
     *  SubSystem: '<S13>/Switch Case Action Subsystem2'
     */

    /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
     *  Constant: '<S18>/Constant'
     */
    minimalist_sequence_arg_DWork.packet_cfg = 78U;

    /* Stateflow: '<S3>/Chart' */
    /* Gateway: minimalist_sequence_arg/Print/Chart */
    /* During: minimalist_sequence_arg/Print/Chart */
    if (minimalist_sequence_arg_DWork.is_active_c2_minimalist_sequenc == 0) {
      /* Entry: minimalist_sequence_arg/Print/Chart */
      minimalist_sequence_arg_DWork.is_active_c2_minimalist_sequenc = 1U;

      /* Entry 'STEP': '<S7>:3' */
      minimalist_sequence_arg_DWork.is_c2_minimalist_sequence_arg = (uint8_T)
        minimalist_sequence_arg_IN_STEP;
      minimalist_sequence_arg_B.out =
        minimalist_sequence_arg_DWork.buffer_receive_nav_mode[1];
    }

    /* S-Function (qsmcm_sci_tx): '<S3>/Serial Transmit' */
    general_send_string_sci1(&minimalist_sequence_arg_B.out,1U);
  }
}

/* Model initialize function */
void minimalist_sequence_arg_initialize(boolean_T firstTime)
{
  (void)firstTime;

  {
    int32_T i;

    /* Start for S-Function (sfunRTWConfig): '<S2>/config' */

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

    /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
    for (i = 0; i < 17; i++) {
      minimalist_sequence_arg_DWork.buffer_transmit_com3[i] =
        minimalist_sequence_arg_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
