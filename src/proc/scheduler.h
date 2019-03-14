/*
  scheduler.h
  Cody Fagley
  Authored on   February 22, 2019
  Last Modified    March 14, 2019
*/

/*
  Contains Backend Functionality for XCS Process Scheduler
*/

#ifndef PROC_SCHEDULER_H
#define PROC_SCHEDULER_H



/* 1.d) Process Scheduler

*/
typedef struct Scheduler_t
{
  ProcessQueue* queue0;  // First Priority  (System Interrupts) (Clocks/Event Timers)
  ProcessQueue* queue1;  // Second Priority (User Interrupts) (System - Instant of Execution)
  ProcessQueue* queue2;  // Third Priority  (Source - Instant of Execution)
  ProcessQueue* queue3;  // Fourth Priority
  ProcessQueue* queue4;  // Fifith Priority (Source - After x Seconds)
  int* blocked; // Inactive Processes (Blocked)
  int* t_mod;   // Active Tether Modules
} Scheduler;

#endif
