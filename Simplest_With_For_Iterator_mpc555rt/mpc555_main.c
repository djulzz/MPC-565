/*
 * File: mpc555_main.c
 *
 * Real-Time Workshop code generated for Simulink model Simplest_With_For_Iterator.
 *
 * Model version                        : 1.353
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Tue Nov 03 23:09:19 2009
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Tue Nov 03 23:09:21 2009
 *
 * Target selection: mpc555rt.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>                    /* Defines NULL */
#include "mpc5xx.h"
#include "rtwtypes.h"
#include "pit.h"                       /* MPC5xx Programmable Interrupt Timer Header */
#include "Simplest_With_For_Iterator.h" /* Model's header file */
#include "profile.h"

/* Control the behaviour of the model when overruns occur */
#define BASE_RATE_MAX_OVERRUNS         5

/* Watchdog timer */
#define SERVICE_WATCHDOG_TIMER \
 USIU.SWSR.R = 0x556C; \
 USIU.SWSR.R = 0xAA39;

/* Model sample period */
#define TIMER_TICK_PERIOD              0.2

static uint_T OverrunFlags[1];         /* ISR overrun flags */

/* rt_OneStep is called from a timer interrupt service routine. It is called at
 * the base-rate of the model.
 */
void rt_OneStep(MPC555_IRQ_LEVEL level)
{
  /* Clear the interrupt that triggered this function */
  ClearPitIRQ;

  /***********************************************
   * Check if base-rate step time is too fast    *
   ***********************************************/
  if (OverrunFlags[0] > BASE_RATE_MAX_OVERRUNS) {
    rtmSetErrorStatus(Simplest_With_For_Iterator_M, "Overrun");
  }

  /*************************************************
   * Check if an error status has been set *
   * by an overrun or by the generated code.       *
   *************************************************/
  if (rtmGetErrorStatus(Simplest_With_For_Iterator_M) != NULL) {
    return;
  }

  /***********************************************
   * Increment the overruns flag
   ***********************************************/
  if (OverrunFlags[0]++) {
    return;
  }

  while (OverrunFlags[0] > 0 ) {
    /* Re-enable interrupts here */
    EIE();

    /* Set model inputs here */

    /**************
     * Step model *
     **************/
    Simplest_With_For_Iterator_step();

    /* Get model outputs here */

    /* Get model outputs here */

    /* Service Watchdog Timer */
    SERVICE_WATCHDOG_TIMER;

    /* Disable interrupts */
    EID();

    /**************************
     * Decrement overrun flag *
     **************************/
    OverrunFlags[0]--;
  }
}

/* The "main" function initializes and executes the generated code.
 */
int_T main(int_T argc, const char_T *argv[])
{
  /************************
   * initialize the model *
   ************************/
#define LATCH_0_31_IMB_INTERRUPT_LEVELS 3                        /* Enable all IRQ levels on the UIMB */

  initIrqModule(LATCH_0_31_IMB_INTERRUPT_LEVELS);

  /* Initialize model */
  Simplest_With_For_Iterator_initialize(1);

  {
    float period ;

    /* Set the timeout period of the Programmable Interrupt Timer
     * which will driver rtOneStep */
    setPitModuleIrqLevel(RT_ONE_STEP_IRQ);
    period = setPitPeriod(TIMER_TICK_PERIOD, OSCILLATOR_FREQ);
    if (period < 0) {
      /* Unable to achive this period */
      exit(1);
    }
  }

#if INTEGER_CODE==0

  registerIRQ_Handler( RT_ONE_STEP_IRQ, rt_OneStep , NULL , FLOAT_USED_IN_ISR);

#else

  registerIRQ_Handler( RT_ONE_STEP_IRQ, rt_OneStep , NULL ,
                      FLOAT_NOT_USED_IN_ISR);

#endif

  EnablePitFreeze;                     /* Make sure we can stop the ISR during debug */
  EnablePitInterrupt;                  /* Enable the timer interrupt */
  EnablePit;                           /* Start the timer counting */

  /* Enable External Interrupts */
  EIE();
  while (rtmGetErrorStatus(Simplest_With_For_Iterator_M) == NULL) {
    boolean_T rtmStopReq = false;

    /* Optionally call an extern Background Task */
#ifdef __BACKGROUNDTASK__

    BACKGROUNDTASK();

#endif

  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
