/*
  operations.h (Process Scheduler)
  Cody Fagley
  Authored on   March 7, 2019
  Last Modified March 7, 2019
*/

/*
  Contains Standard Backend Functionality for Process Scheduling

  Table of Contents
  =================
  1.) Process Scheduling
    1.a) Start Process
    1.b) Kill Process
    1.c) Block Process
    1.d) Unblock Process
  2.) Interprocess Communication
    2.a) Send Message
    2.b) Receive Message
*/

#ifndef SCHED_OPERATIONS_H
#define SCHED_OPERATIONS_H

/*
  1.) Process Scheduling
*/

/* 1.a) Start Process
  
  Returns:
    0, if Successful
*/
int proc_start()
{
  //  Process Started
  printf("Execuing Process...\n");

  return 0;
}

/* 1.b) Kill Process

  Returns:
    0, if Successful
*/
int proc_kill(unsigned int pid)
{
  //  Process Killed
  printf("Killing Process: %d\n", pid);

  return 0;
}

/* 1.c) Block Process

  Returns:
    0, if Successful
*/
int proc_block(unsigned int pid)
{
  //  Process Blocked
  printf("Blocking Process: %d\n", pid);

  return 0;
}

/* 1.d) Unblock Process

  Returns:
    0, if Successful
*/
int proc_unblock(unsigned int pid)
{
  //  Process Unblocked
  printf("Unblocking Process: %d\n", pid);

  return 0;
}


#endif
