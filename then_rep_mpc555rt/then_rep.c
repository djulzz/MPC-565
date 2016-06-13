/*
 * File: then_rep.c
 *
 * Real-Time Workshop code generated for Simulink model then_rep.
 *
 * Model version                        : 1.278
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu Nov 05 13:43:42 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu Nov 05 13:43:45 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "then_rep.h"
#include "then_rep_private.h"

/* Named constants for Stateflow: '<S1>/Chart' */
#define then_rep_IN_S01                (1)
#define then_rep_IN_S02                (2)

/* Block signals (auto storage) */
BlockIO_then_rep then_rep_B;

/* Block states (auto storage) */
D_Work_then_rep then_rep_DWork;

/* Real-time model */
RT_MODEL_then_rep then_rep_M_;
RT_MODEL_then_rep *then_rep_M = &then_rep_M_;

/* Model step function */
void then_rep_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_DataStoreRead[17];
  uint8_T rtb_IndexVector;

  {
    int32_T i;

    /* Outputs for atomic SubSystem: '<Root>/then_rep' */

    /* Stateflow: '<S1>/Chart' */
    /* Gateway: then_rep/Chart */
    /* During: then_rep/Chart */
    if (then_rep_DWork.is_active_c1_then_rep == 0) {
      /* Entry: then_rep/Chart */
      then_rep_DWork.is_active_c1_then_rep = 1U;

      /* Transition: '<S2>:3' */
      /* Entry 'S01': '<S2>:1' */
      then_rep_DWork.is_c1_then_rep = (uint8_T)then_rep_IN_S01;
      then_rep_B.call_process_write = 1U;
      then_rep_DWork.cnt = (uint8_T)(then_rep_DWork.cnt + 1);
    } else {
      switch (then_rep_DWork.is_c1_then_rep) {
       case then_rep_IN_S01:
        /* During 'S01': '<S2>:1' */
        if (then_rep_DWork.cnt < 10) {
          /* Transition: '<S2>:8' */
          /* Exit 'S01': '<S2>:1' */
          /* Entry 'S01': '<S2>:1' */
          then_rep_DWork.is_c1_then_rep = (uint8_T)then_rep_IN_S01;
          then_rep_B.call_process_write = 1U;
          then_rep_DWork.cnt = (uint8_T)(then_rep_DWork.cnt + 1);
        } else {
          if (then_rep_DWork.cnt >= 10) {
            /* Transition: '<S2>:7' */
            /* Exit 'S01': '<S2>:1' */
            /* Entry 'S02': '<S2>:2' */
            then_rep_DWork.is_c1_then_rep = (uint8_T)then_rep_IN_S02;
            then_rep_B.call_process_write = 0U;
          }
        }
        break;

       case then_rep_IN_S02:
        break;

       default:
        /* Transition: '<S2>:3' */
        /* Entry 'S01': '<S2>:1' */
        then_rep_DWork.is_c1_then_rep = (uint8_T)then_rep_IN_S01;
        then_rep_B.call_process_write = 1U;
        then_rep_DWork.cnt = (uint8_T)(then_rep_DWork.cnt + 1);
        break;
      }
    }

    /* Outputs for enable SubSystem: '<S1>/process_write' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (then_rep_B.call_process_write > 0) {
      /* DataStoreWrite: '<S5>/Data Store Write' */
      then_rep_DWork.nElems = 17U;

      /* DataStoreRead: '<S5>/Data Store Read' */
      for (i = 0; i < 17; i++) {
        rtb_DataStoreRead[i] = then_rep_DWork.buffer_transmit_com3[i];
      }

      /* Outputs for atomic SubSystem: '<S5>/For Iterator Subsystem' */

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
      if ((uint32_T)(then_rep_DWork.nIters < then_rep_DWork.nElems) == 1U) {
        /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
         *  Constant: '<S7>/Constant'
         *  DataStoreRead: '<S7>/Data Store Read'
         *  Sum: '<S7>/Add'
         */
        then_rep_DWork.nIters = then_rep_DWork.nIters + 1U;

        /* MultiPortSwitch: '<S7>/Index Vector' incorporates:
         *  DataStoreRead: '<S7>/Data Store Read3'
         */
        rtb_IndexVector = rtb_DataStoreRead[(int32_T)then_rep_DWork.nIters - 1];

        /* S-Function (qsmcm_sci_tx): '<S7>/Serial Transmit' */
        general_send_string_sci2(&rtb_IndexVector,1);
      } else {
        /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
         *  Constant: '<S8>/Constant'
         */
        then_rep_DWork.nIters = 0U;
      }

      /* end of Outputs for SubSystem: '<S5>/For Iterator Subsystem' */
    }

    /* end of Outputs for SubSystem: '<S1>/process_write' */

    /* end of Outputs for SubSystem: '<Root>/then_rep' */
  }
}

/* Model initialize function */
void then_rep_initialize(boolean_T firstTime)
{
  (void)firstTime;

  {
    int32_T i;

    /* Start for atomic SubSystem: '<Root>/then_rep' */
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
      then_rep_DWork.buffer_transmit_com3[i] =
        then_rep_ConstP.DataStoreMemory4_Ini[i];
    }

    /* end of Start for SubSystem: '<Root>/then_rep' */
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
