/*
 * File: Simplest_With_For_Iterator5.c
 *
 * Real-Time Workshop code generated for Simulink model Simplest_With_For_Iterator5.
 *
 * Model version                        : 1.361
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Wed Nov 04 00:04:11 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Wed Nov 04 00:04:14 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simplest_With_For_Iterator5.h"
#include "Simplest_With_For_Iterator5_private.h"

/* Block states (auto storage) */
D_Work_Simplest_With_For_Iterat Simplest_With_For_Iterato_DWork;

/* Real-time model */
RT_MODEL_Simplest_With_For_Iter Simplest_With_For_Iterator5_M_;
RT_MODEL_Simplest_With_For_Iter *Simplest_With_For_Iterator5_M =
  &Simplest_With_For_Iterator5_M_;

/* Model step function */
void Simplest_With_For_Iterator5_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[17];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* Outputs for atomic SubSystem: '<Root>/Simplest_With_For_Iterator5' */

    /* Outputs for atomic SubSystem: '<S1>/Subsystem' */

    /* DataStoreRead: '<S3>/Data Store Read' */
    for (i = 0; i < 17; i++) {
      rtb_DataStoreRead[i] =
        Simplest_With_For_Iterato_DWork.buffer_transmit_com3[i];
    }

    /* Outputs for iterator SubSystem: '<S3>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S5>/For Iterator'
     */
    for (i = 0; i < 17; i++) {
      /* MultiPortSwitch: '<S5>/Index Vector' */
      rtb_IndexVector = rtb_DataStoreRead[i];

      /* S-Function (qsmcm_sci_tx): '<S5>/Serial Transmit' */
      general_send_string_sci2(&rtb_IndexVector,1);
    }

    /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */

    /* end of Outputs for SubSystem: '<S1>/Subsystem' */

    /* end of Outputs for SubSystem: '<Root>/Simplest_With_For_Iterator5' */
  }
}

/* Model initialize function */
void Simplest_With_For_Iterator5_initialize(boolean_T firstTime)
{
  (void)firstTime;

  {
    int32_T i;

    /* Start for atomic SubSystem: '<Root>/Simplest_With_For_Iterator5' */
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
      Simplest_With_For_Iterato_DWork.buffer_transmit_com3[i] =
        Simplest_With_For_Iterat_ConstP.DataStoreMemory4_Ini[i];
    }

    /* end of Start for SubSystem: '<Root>/Simplest_With_For_Iterator5' */
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
