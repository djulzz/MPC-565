/*
 * File: gimme.c
 *
 * Real-Time Workshop code generated for Simulink model gimme.
 *
 * Model version                        : 1.336
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 11:53:39 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 11:53:41 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gimme.h"
#include "gimme_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define gimme_IN_STEP01                (1)
#define gimme_IN_STEP02                (2)

/* Block signals (auto storage) */
BlockIO_gimme gimme_B;

/* Block states (auto storage) */
D_Work_gimme gimme_DWork;

/* Real-time model */
RT_MODEL_gimme gimme_M_;
RT_MODEL_gimme *gimme_M = &gimme_M_;

/* Model step function */
void gimme_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[12];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: gimme/Chart */
    /* During: gimme/Chart */
    if (gimme_DWork.is_active_c1_gimme == 0) {
      /* Entry: gimme/Chart */
      gimme_DWork.is_active_c1_gimme = 1U;

      /* Transition: '<S2>:11' */
      /* Entry 'STEP01': '<S2>:2' */
      gimme_DWork.is_c1_gimme = (uint8_T)gimme_IN_STEP01;
      gimme_B.call_write_on_com2 = 1U;
      gimme_DWork.step_iter = (uint8_T)(gimme_DWork.step_iter + 1);
    } else {
      switch (gimme_DWork.is_c1_gimme) {
       case gimme_IN_STEP01:
        /* During 'STEP01': '<S2>:2' */
        if (gimme_DWork.step_iter < 10) {
          /* Transition: '<S2>:9' */
          /* Exit 'STEP01': '<S2>:2' */
          /* Entry 'STEP01': '<S2>:2' */
          gimme_DWork.is_c1_gimme = (uint8_T)gimme_IN_STEP01;
          gimme_B.call_write_on_com2 = 1U;
          gimme_DWork.step_iter = (uint8_T)(gimme_DWork.step_iter + 1);
        } else {
          if (gimme_DWork.step_iter >= 10) {
            /* Transition: '<S2>:5' */
            /* Exit 'STEP01': '<S2>:2' */
            /* Entry 'STEP02': '<S2>:4' */
            gimme_DWork.is_c1_gimme = (uint8_T)gimme_IN_STEP02;
            gimme_B.call_write_on_com2 = 0U;
          }
        }
        break;

       case gimme_IN_STEP02:
        break;

       default:
        /* Transition: '<S2>:11' */
        /* Entry 'STEP01': '<S2>:2' */
        gimme_DWork.is_c1_gimme = (uint8_T)gimme_IN_STEP01;
        gimme_B.call_write_on_com2 = 1U;
        gimme_DWork.step_iter = (uint8_T)(gimme_DWork.step_iter + 1);
        break;
      }
    }

    /* Outputs for enable SubSystem: '<S1>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    if (gimme_B.call_write_on_com2 > 0) {
      /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
       *  Constant: '<S3>/Constant'
       *  DataStoreRead: '<S3>/Data Store Read1'
       *  Sum: '<S3>/Add'
       */
      gimme_DWork.step_iter = (uint8_T)(uint32_T)(gimme_DWork.step_iter + 1);

      /* DataStoreWrite: '<S3>/Data Store Write' */
      gimme_DWork.nElems = 12U;

      /* DataStoreRead: '<S3>/Data Store Read' */
      for (i = 0; i < 12; i++) {
        rtb_DataStoreRead[i] = gimme_DWork.buffer_transmit_com3[i];
      }

      /* Outputs for atomic SubSystem: '<S3>/For Iterator Subsystem' */

      /* If: '<S6>/If' incorporates:
       *  ActionPort: '<S7>/Action Port'
       *  ActionPort: '<S8>/Action Port'
       *  DataStoreRead: '<S6>/Data Store Read1'
       *  DataStoreRead: '<S6>/Data Store Read2'
       *  DataTypeConversion: '<S6>/Data Type Conversion'
       *  RelationalOperator: '<S6>/Relational Operator'
       *  SubSystem: '<S6>/If Action Subsystem'
       *  SubSystem: '<S6>/If Action Subsystem1'
       */
      if ((uint32_T)(gimme_DWork.nIters < gimme_DWork.nElems) == 1U) {
        /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
         *  Constant: '<S7>/Constant'
         *  DataStoreRead: '<S7>/Data Store Read'
         *  Sum: '<S7>/Add'
         */
        gimme_DWork.nIters = gimme_DWork.nIters + 1U;

        /* MultiPortSwitch: '<S7>/Index Vector' incorporates:
         *  DataStoreRead: '<S7>/Data Store Read3'
         */
        rtb_IndexVector = rtb_DataStoreRead[(int32_T)gimme_DWork.nIters - 1];

        /* S-Function (qsmcm_sci_tx): '<S7>/Serial Transmit' */
        general_send_string_sci2(&rtb_IndexVector,1);
      } else {
        /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
         *  Constant: '<S8>/Constant'
         */
        gimme_DWork.nIters = 0U;
      }

      /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
    }

    /* end of Outputs for SubSystem: '<S1>/Enabled Subsystem' */
  }
}

/* Model initialize function */
void gimme_initialize(boolean_T firstTime)
{
  (void)firstTime;

  {
    int32_T i;

    /* Start for S-Function (sfunRTWConfig): '<S4>/config' */

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
    for (i = 0; i < 12; i++) {
      gimme_DWork.buffer_transmit_com3[i] = gimme_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
