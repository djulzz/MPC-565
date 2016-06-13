/*
 * File: minimalist_sequence_ref.c
 *
 * Real-Time Workshop code generated for Simulink model minimalist_sequence_ref.
 *
 * Model version                        : 1.263
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Fri Oct 30 12:17:32 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Fri Oct 30 12:17:34 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "minimalist_sequence_ref.h"
#include "minimalist_sequence_ref_private.h"

/* Block states (auto storage) */
D_Work_minimalist_sequence_ref minimalist_sequence_ref_DWork;

/* Real-time model */
RT_MODEL_minimalist_sequence_re minimalist_sequence_ref_M_;
RT_MODEL_minimalist_sequence_re *minimalist_sequence_ref_M =
  &minimalist_sequence_ref_M_;

/* Model step function */
void minimalist_sequence_ref_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[10];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* DataStoreWrite: '<S3>/Data Store Write' */
    minimalist_sequence_ref_DWork.nElems = 10U;

    /* DataStoreRead: '<S3>/Data Store Read' */
    for (i = 0; i < 10; i++) {
      rtb_DataStoreRead[i] =
        minimalist_sequence_ref_DWork.buffer_transmit_com3[i];
    }

    /* Outputs for atomic SubSystem: '<S3>/For Iterator Subsystem' */

    /* If: '<S5>/If' incorporates:
     *  ActionPort: '<S6>/Action Port'
     *  ActionPort: '<S7>/Action Port'
     *  DataStoreRead: '<S5>/Data Store Read1'
     *  DataStoreRead: '<S5>/Data Store Read2'
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     *  RelationalOperator: '<S5>/Relational Operator'
     *  SubSystem: '<S5>/If Action Subsystem'
     *  SubSystem: '<S5>/If Action Subsystem1'
     */
    if ((uint32_T)(minimalist_sequence_ref_DWork.nIters <
                   minimalist_sequence_ref_DWork.nElems) == 1U) {
      /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
       *  Constant: '<S6>/Constant'
       *  DataStoreRead: '<S6>/Data Store Read'
       *  Sum: '<S6>/Add'
       */
      minimalist_sequence_ref_DWork.nIters =
        minimalist_sequence_ref_DWork.nIters + 1U;

      /* MultiPortSwitch: '<S6>/Index Vector' incorporates:
       *  DataStoreRead: '<S6>/Data Store Read3'
       */
      rtb_IndexVector = rtb_DataStoreRead[(int32_T)
        minimalist_sequence_ref_DWork.nIters - 1];

      /* S-Function (qsmcm_sci_tx): '<S6>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    } else {
      /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
       *  Constant: '<S7>/Constant'
       */
      minimalist_sequence_ref_DWork.nIters = 0U;
    }

    /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
  }
}

/* Model initialize function */
void minimalist_sequence_ref_initialize(boolean_T firstTime)
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
    for (i = 0; i < 10; i++) {
      minimalist_sequence_ref_DWork.buffer_transmit_com3[i] =
        minimalist_sequence_ref_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
