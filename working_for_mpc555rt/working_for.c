/*
 * File: working_for.c
 *
 * Real-Time Workshop code generated for Simulink model working_for.
 *
 * Model version                        : 1.370
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 16:22:23 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 16:22:25 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "working_for.h"
#include "working_for_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define working_for_IN_STEP01          (1)
#define working_for_IN_STEP02          (2)

/* Block signals (auto storage) */
BlockIO_working_for working_for_B;

/* Block states (auto storage) */
D_Work_working_for working_for_DWork;

/* Real-time model */
RT_MODEL_working_for working_for_M_;
RT_MODEL_working_for *working_for_M = &working_for_M_;

/* Model step function */
void working_for_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[10];
  uint8_T rtb_IndexVector;

  {
    int32_T s6_iter;
    int32_T i;

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: working_for/Chart */
    /* During: working_for/Chart */
    if (working_for_DWork.is_active_c1_working_for == 0) {
      /* Entry: working_for/Chart */
      working_for_DWork.is_active_c1_working_for = 1U;

      /* Transition: '<S2>:11' */
      /* Entry 'STEP01': '<S2>:2' */
      working_for_DWork.is_c1_working_for = (uint8_T)working_for_IN_STEP01;
      working_for_B.call_write_on_com2 = 1U;
      working_for_DWork.step_iter = (uint8_T)(working_for_DWork.step_iter + 1);
    } else {
      switch (working_for_DWork.is_c1_working_for) {
       case working_for_IN_STEP01:
        /* During 'STEP01': '<S2>:2' */
        if (working_for_DWork.step_iter < 10) {
          /* Transition: '<S2>:9' */
          /* Exit 'STEP01': '<S2>:2' */
          /* Entry 'STEP01': '<S2>:2' */
          working_for_DWork.is_c1_working_for = (uint8_T)working_for_IN_STEP01;
          working_for_B.call_write_on_com2 = 1U;
          working_for_DWork.step_iter = (uint8_T)(working_for_DWork.step_iter +
            1);
        } else {
          if (working_for_DWork.step_iter >= 10) {
            /* Transition: '<S2>:5' */
            /* Exit 'STEP01': '<S2>:2' */
            /* Entry 'STEP02': '<S2>:4' */
            working_for_DWork.is_c1_working_for = (uint8_T)working_for_IN_STEP02;
            working_for_B.call_write_on_com2 = 0U;
          }
        }
        break;

       case working_for_IN_STEP02:
        break;

       default:
        /* Transition: '<S2>:11' */
        /* Entry 'STEP01': '<S2>:2' */
        working_for_DWork.is_c1_working_for = (uint8_T)working_for_IN_STEP01;
        working_for_B.call_write_on_com2 = 1U;
        working_for_DWork.step_iter = (uint8_T)(working_for_DWork.step_iter + 1);
        break;
      }
    }

    /* Outputs for enable SubSystem: '<S1>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    if (working_for_B.call_write_on_com2 > 0) {
      /* Outputs for iterator SubSystem: '<S3>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S6>/For Iterator'
       */
      for (s6_iter = 0; s6_iter < 10; s6_iter++) {
        /* DataStoreRead: '<S6>/Data Store Read' */
        for (i = 0; i < 10; i++) {
          rtb_DataStoreRead[i] = working_for_DWork.buffer_transmit[i];
        }

        /* MultiPortSwitch: '<S6>/Index Vector' */
        rtb_IndexVector = rtb_DataStoreRead[s6_iter];

        /* S-Function (qsmcm_sci_tx): '<S6>/Serial Transmit' */
        general_send_string_sci1(&rtb_IndexVector,1U);
      }

      /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
    }

    /* end of Outputs for SubSystem: '<S1>/Enabled Subsystem' */
  }
}

/* Model initialize function */
void working_for_initialize(boolean_T firstTime)
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
       * Loop mode = Loopback mode enabled
       */
      const uint16_T sc1br = 0x82U;

      /* SCI1 control register 1
       * Using 8-bit data
       * Parity = N/A
       */
      const uint16_T scc1r1 = 0x400cU;
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
      working_for_DWork.buffer_transmit[i] =
        working_for_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
