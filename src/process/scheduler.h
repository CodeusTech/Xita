/*
  scheduler.h
  Cody Fagley
  Authored on   February 22, 2019
  Last Modified February 22, 2019
*/

/*
  Contains Structures/Operations for XCS Process Scheduler

  Table of Contents
  =================
  1.) Structures
    1.a) Process Scheduler
  2.) Operations
    2.a) Add (Queue) Process
    2.b) Kill Process
    2.a) Block Process
    2.b) Unblock Process
*/

#ifndef PROCESS_SCHEDULER_H
#define PROCESS_SCHEDULER_H

#include "stdproc.h"

/*
  1.) Structures
*/

/* 1.a) Process Scheduler

*/
typedef struct scheduler_t
{
  Process* queue0;  // First Priority  (System Interrupts) (Clocks/Event Timers)
  Process* queue1;  // Second Priority (User Interrupts) (System - Instant of Execution)
  Process* queue2;  // Third Priority  (Source - Instant of Execution)
  Process* queue3;  // Fourth Priority
  Process* queue4;  // Fifith Priority (Source - After x Seconds)
  int* blocked; // Inactive Processes (Blocked)
  int* t_mod;   // Active Tether Modules
} ProcessScheduler;

/*
  2.) Operations
*/

/* 2.a) Block Process

  Returns:
    0, if Successful
*/
int block_process()
{

  return 0;
}

/* 2.b) Unblock Process

  Returns:
    0, if Successful
*/
int unblock_process()
{

  return 0;
}

#endif
