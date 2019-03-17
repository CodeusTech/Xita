/*
  timer.h
  Cody Fagley
  Authored on   March 16, 2019
  Last Modified March 16, 2019
*/

/*
  Contains functionality for BCM2835 System Timers

  Table of Contents
  =================
  1.) Timer Constants
    1.a) System Timer Base Address
  2.) System Timer Control/Status
  3.) Free-Running Counter
    3.a) Lower 32 Bits
    3.b) Upper 32 Bits
  4.) Event Timer Trigger Values
*/

#ifndef GPIO_TIMER_H
#define GPIO_TIMER_H

/*
  1.) Timer Constants
*/

//  1.a) System Timer Base Address
unsigned long sys_timers = 0x7E003000;


/*
  2.) System Timer Control/Status
*/

/* Event Timer Match

  Returns:
    True, if requested timer has activated
    False, if no event has occured since last read
*/
bool systimer_match_triggered(unsigned char timer)
{
  //  STUB STUB STUB

  /*
    Check for activation in requested event timer
  */
  switch (timer)
  {
    case 0:
      //  Check if Clock 0 Triggered
      break;
    case 1:
      //  Check if Clock 1 Triggered
      break;
    case 2:
      //  Check if Clock 2 Triggered
      break;
    case 3:
      //  Check if Clock 3 Triggered
      break;
    default:
      //  Report Error (Nonexistant Hardware Requested)
      yyerror("Nonexistant System Timer Requested\n");
      break;
  }

  return true;
}


/*
  3.) Free-Running Counter
*/

/* 3.a) Lower 32-Bits

  Returns:
    Lower 32-Bits of Free-Running System Clock
*/
unsigned long systimer_clow()
{
  //  STUB STUB STUB

  /*
    Read the Lower 32 Counter Register
  */

  return 0;
}

/* 3.b) Upper 32-Bits

  Returns:
    Upper 32-Bits of Free-Running System Clock
*/
unsigned long systimer_chigh()
{
  //  STUB STUB STUB

  /*
    Read the Upper 32 Counter Register
  */

  return 0;
}


/*
  4.) Event Timer Trigger Values
*/

/* 4.a) Set Timer Trigger Value

  Returns:
    0, if Successful
*/
int systimer_set_trigger(unsigned char timer)
{
  //  STUB STUB STUB

  /*
    Set the Timer Compare Value for 'timer'
  */

  return 0;
}

/* 4.b) Get Timer Trigger Value

  Returns:
    0, if Successful
*/
unsigned long systimer_get_trigger(unsigned char timer)
{
  //  STUB STUB STUB

  /*
    Get the Timer Compare Value for 'timer'
  */

  //  TODO: Return Timer Compare Value instead of 0.

  return 0;
}


#endif

