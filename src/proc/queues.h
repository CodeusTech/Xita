/*
  queues.h
  Cody Fagley
  Authored on   February 22, 2019
  Last Modified    March 14, 2019
*/

/*
  Contains Standard Definitions for use in Process-Related Headers

  Table of Contents
  =================
  3.) Queue Functions
  4.) Scheduling Functions
  5.) Interprocess Communication
*/

#ifndef PROC_QUEUES_H
#define PROC_QUEUES_H



/* 1.c) Process Queue

*/
typedef struct ProcessQueue_t
{
  Process* front;
  Process* back;
  unsigned long front_len;
  unsigned long back_len;
} ProcessQueue;





#endif
