/*
 * File: simplest0.c
 *
 * Real-Time Workshop code generated for Simulink model simplest0.
 *
 * Model version                        : 1.268
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Mon Nov 16 18:29:06 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Mon Nov 16 18:29:08 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simplest0.h"
#include "simplest0_private.h"

/* Block states (auto storage) */
D_Work_simplest0 simplest0_DWork;

/* Real-time model */
RT_MODEL_simplest0 simplest0_M_;
RT_MODEL_simplest0 *simplest0_M = &simplest0_M_;

/* Model step function */
void simplest0_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[17];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* DataStoreWrite: '<S3>/Data Store Write' */
    simplest0_DWork.nElems = 17U;

    /* DataStoreRead: '<S3>/Data Store Read' */
    for (i = 0; i < 17; i++) {
      rtb_DataStoreRead[i] = simplest0_DWork.buffer_transmit_com3[i];
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
    if ((uint32_T)(simplest0_DWork.nIters < simplest0_DWork.nElems) == 1U) {
      /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
       *  Constant: '<S6>/Constant'
       *  DataStoreRead: '<S6>/Data Store Read'
       *  Sum: '<S6>/Add'
       */
      simplest0_DWork.nIters = simplest0_DWork.nIters + 1U;

      /* MultiPortSwitch: '<S6>/Index Vector' incorporates:
       *  DataStoreRead: '<S6>/Data Store Read3'
       */
      rtb_IndexVector = rtb_DataStoreRead[(int32_T)simplest0_DWork.nIters - 1];

      /* S-Function (qsmcm_sci_tx): '<S6>/Serial Transmit' */
      general_send_string_sci1(&rtb_IndexVector,1);
    } else {
      /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
       *  Constant: '<S7>/Constant'
       */
      simplest0_DWork.nIters = 0U;
    }

    /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
  }
}

/* Model initialize function */
void simplest0_initialize(boolean_T firstTime)
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
       * Ideal bit rate = 921600.0
       * Achieved bit rate = 1.25E+006
       * Calculation based on system clock = 4.0E+007
       * Loop mode = Standard transmit/receive
       */
      const uint16_T sc1br = 0x1U;

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
      simplest0_DWork.buffer_transmit_com3[i] =
        simplest0_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
