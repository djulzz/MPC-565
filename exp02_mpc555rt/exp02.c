/*
 * File: exp02.c
 *
 * Real-Time Workshop code generated for Simulink model exp02.
 *
 * Model version                        : 1.301
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Nov 05 17:08:27 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Nov 05 17:08:29 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "exp02.h"
#include "exp02_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define exp02_IN_S                     (1)

/* Block signals (auto storage) */
BlockIO_exp02 exp02_B;

/* Block states (auto storage) */
D_Work_exp02 exp02_DWork;

/* Real-time model */
RT_MODEL_exp02 exp02_M_;
RT_MODEL_exp02 *exp02_M = &exp02_M_;

/* Model step function */
void exp02_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[17];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: exp02/Chart */
    /* During: exp02/Chart */
    if (exp02_DWork.is_active_c1_exp02 == 0) {
      /* Entry: exp02/Chart */
      exp02_DWork.is_active_c1_exp02 = 1U;

      /* Transition: '<S2>:2' */
      /* Entry 'S': '<S2>:1' */
      exp02_DWork.is_c1_exp02 = (uint8_T)exp02_IN_S;
      exp02_B.syscall = 1U;
    }

    /* Outputs for enable SubSystem: '<S1>/Subsystem' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (exp02_B.syscall > 0) {
      /* Outputs for atomic SubSystem: '<S4>/Subsystem' */

      /* DataStoreWrite: '<S6>/Data Store Write' */
      exp02_DWork.nElems = 17U;

      /* DataStoreRead: '<S6>/Data Store Read' */
      for (i = 0; i < 17; i++) {
        rtb_DataStoreRead[i] = exp02_DWork.buffer_transmit_com3[i];
      }

      /* Outputs for atomic SubSystem: '<S6>/Subsystem (Used to be a modified for subsystem)' */

      /* If: '<S7>/If' incorporates:
       *  ActionPort: '<S8>/Action Port'
       *  ActionPort: '<S9>/Action Port'
       *  DataStoreRead: '<S7>/Data Store Read1'
       *  DataStoreRead: '<S7>/Data Store Read2'
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       *  RelationalOperator: '<S7>/Relational Operator'
       *  SubSystem: '<S7>/If Action Subsystem'
       *  SubSystem: '<S7>/If Action Subsystem1'
       */
      if ((uint32_T)(exp02_DWork.nIters < exp02_DWork.nElems) == 1U) {
        /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
         *  Constant: '<S8>/Constant'
         *  DataStoreRead: '<S8>/Data Store Read'
         *  Sum: '<S8>/Add'
         */
        exp02_DWork.nIters = exp02_DWork.nIters + 1U;

        /* MultiPortSwitch: '<S8>/Index Vector' incorporates:
         *  DataStoreRead: '<S8>/Data Store Read3'
         */
        rtb_IndexVector = rtb_DataStoreRead[(int32_T)exp02_DWork.nIters - 1];

        /* S-Function (qsmcm_sci_tx): '<S8>/Serial Transmit' */
        general_send_string_sci2(&rtb_IndexVector,1);
      } else {
        /* DataStoreWrite: '<S9>/Data Store Write' incorporates:
         *  Constant: '<S9>/Constant'
         */
        exp02_DWork.nIters = 0U;
      }

      /* end of Outputs for SubSystem: '<S6>/Subsystem (Used to be a modified for subsystem)' */

      /* end of Outputs for SubSystem: '<S4>/Subsystem' */
    }

    /* end of Outputs for SubSystem: '<S1>/Subsystem' */
  }
}

/* Model initialize function */
void exp02_initialize(boolean_T firstTime)
{
  (void)firstTime;

  {
    int32_T i;

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

    /* Start for DataStoreMemory: '<S1>/Data Store Memory4' */
    for (i = 0; i < 17; i++) {
      exp02_DWork.buffer_transmit_com3[i] = exp02_ConstP.DataStoreMemory4_Ini[i];
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
