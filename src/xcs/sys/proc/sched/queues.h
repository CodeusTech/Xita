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
  1.) Process Queue Accessors
    1.a) Enqueue Process
*/

#ifndef SCHED_QUEUES_H
#define SCHED_QUEUES_H


/*
  1.) Process Queue Accessors
*/

/* 1.a) Enqueue Process

  Returns:
    0, if Successful
*/
ErrorCode proc_enqueue()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  //  Construct New Process Structure
  proc_new();

  /*
    TODO: 
     * TOP Contains Pointer to New Process Structure
     * Add Process to Queue
  */

  //  Return Success
  return 0;
}

/* 1.b) Dequeue Process

  Returns:
    0, if Successful
*/
ErrorCode proc_dequeue()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Remove Front Entry from Queue
  */

  //  Return Success
  return 0;
}


#endif

