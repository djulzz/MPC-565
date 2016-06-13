/*
 * File: Subsystem.c
 *
 * Real-Time Workshop code generated for Simulink model Subsystem.
 *
 * Model version                        : 1.326
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Mon Nov 02 23:16:02 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Mon Nov 02 23:16:04 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define Subsystem_IN_STEP01            (1)
#define Subsystem_IN_STEP02            (2)

/* Block signals (auto storage) */
BlockIO_Subsystem Subsystem_B;

/* Block states (auto storage) */
D_Work_Subsystem Subsystem_DWork;

/* Real-time model */
RT_MODEL_Subsystem Subsystem_M_;
RT_MODEL_Subsystem *Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead;

  /* Stateflow: '<S1>/Chart' */
  /* Gateway: Subsystem/Chart */
  /* During: Subsystem/Chart */
  if (Subsystem_DWork.is_active_c1_Subsystem == 0) {
    /* Entry: Subsystem/Chart */
    Subsystem_DWork.is_active_c1_Subsystem = 1U;

    /* Transition: '<S2>:11' */
    /* Entry 'STEP01': '<S2>:2' */
    Subsystem_DWork.is_c1_Subsystem = (uint8_T)Subsystem_IN_STEP01;
    Subsystem_B.call_write_on_com2 = 1U;
    Subsystem_DWork.step_iter = (uint8_T)(Subsystem_DWork.step_iter + 1);
  } else {
    switch (Subsystem_DWork.is_c1_Subsystem) {
     case Subsystem_IN_STEP01:
      /* During 'STEP01': '<S2>:2' */
      if (Subsystem_DWork.step_iter < 250) {
        /* Transition: '<S2>:9' */
        /* Exit 'STEP01': '<S2>:2' */
        /* Entry 'STEP01': '<S2>:2' */
        Subsystem_DWork.is_c1_Subsystem = (uint8_T)Subsystem_IN_STEP01;
        Subsystem_B.call_write_on_com2 = 1U;
        Subsystem_DWork.step_iter = (uint8_T)(Subsystem_DWork.step_iter + 1);
      } else {
        if (Subsystem_DWork.step_iter >= 250) {
          /* Transition: '<S2>:5' */
          /* Exit 'STEP01': '<S2>:2' */
          /* Entry 'STEP02': '<S2>:4' */
          Subsystem_DWork.is_c1_Subsystem = (uint8_T)Subsystem_IN_STEP02;
          Subsystem_B.call_write_on_com2 = 0U;
        }
      }
      break;

     case Subsystem_IN_STEP02:
      break;

     default:
      /* Transition: '<S2>:11' */
      /* Entry 'STEP01': '<S2>:2' */
      Subsystem_DWork.is_c1_Subsystem = (uint8_T)Subsystem_IN_STEP01;
      Subsystem_B.call_write_on_com2 = 1U;
      Subsystem_DWork.step_iter = (uint8_T)(Subsystem_DWork.step_iter + 1);
      break;
    }
  }

  /* Outputs for enable SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (Subsystem_B.call_write_on_com2 > 0) {
    /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<S3>/Data Store Read1'
     *  Sum: '<S3>/Add'
     */
    Subsystem_DWork.step_iter = (uint8_T)(uint32_T)(Subsystem_DWork.step_iter +
      1);

    /* DataStoreWrite: '<S3>/Data Store Write' */
    Subsystem_DWork.nElems = 1U;

    /* DataStoreRead: '<S3>/Data Store Read' */
    rtb_DataStoreRead = Subsystem_DWork.buffer_transmit_com3;

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
    if ((uint32_T)(Subsystem_DWork.nIters < Subsystem_DWork.nElems) == 1U) {
      /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
       *  Constant: '<S7>/Constant'
       *  DataStoreRead: '<S7>/Data Store Read'
       *  Sum: '<S7>/Add'
       */
      Subsystem_DWork.nIters = Subsystem_DWork.nIters + 1U;

      /* S-Function (qsmcm_sci_tx): '<S7>/Serial Transmit' */
      general_send_string_sci2(&rtb_DataStoreRead,1);
    } else {
      /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
       *  Constant: '<S8>/Constant'
       */
      Subsystem_DWork.nIters = 0U;
    }

    /* end of Outputs for SubSystem: '<S3>/For Iterator Subsystem' */
  }

  /* end of Outputs for SubSystem: '<S1>/Enabled Subsystem' */
}

/* Model initialize function */
void Subsystem_initialize(boolean_T firstTime)
{
  (void)firstTime;

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
  Subsystem_DWork.buffer_transmit_com3 = 1U;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
