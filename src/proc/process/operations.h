/*
  operations.h (Processes)
  Cody Fagley
  Authored on   March 18, 2019
  Last Modified March 18, 2019
*/

/*
  Contains Operations for Process Manipulation

  Table of Contents
  =================
  1.) Process Accessors
    1.a) Get Process ID
    1.b) Get Process Status
    1.c) Get Active Tethers
    1.d) Input Queue
    1.e) Output Queue
    1.f) Error Queue
*/

#ifndef PROCESS_OPERATIONS_H
#define PROCESS_OPERATIONS_H


/*
  1.) Process Accessors
*/

/* 1.a) Get Process ID

  Returns:
    0, if Process Name is not Found
    pid, otherwise
*/
ProcessID proc_get_pid(Identifier pname)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru Process Scheduler for pname
     * Return Process ID if match is found
      + If no match is found, return 0
  */

  //  Return Failure (No Match)
  return 0;
}

/* 1.b) Get Process Status

  Returns:
    Process Status Code
*/
ErrorCode proc_get_status(ProcessID pid)
{
  //  STUB STUB STUB
  
  /*
    TODO:
     * Error Check
     * Search thru Scheduler for pid
     * Return Status for Process, pid
      + If no match is found, return 0
  */

  //  Return Failure (No Match)
  return 0;
}

/* 1.c) Get Active Tethers

  Returns:
    0, if Process has no active Tethers
    else, linked list of ProcessID
*/
ProcessID* proc_get_teth(ProcessID pid)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru Scheduler for pid
     * Return Linked Lists to Tethered Processes
  */

  //  Return No Active Tethers
  return 0;
}

/* 1.d) Input Queue

  Returns:
    0, if No Messages in Input Queue
    else, linked list of Messages to be received
*/
MessageChannel* proc_get_input(ProcessID pid)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru Scheduler for pid
     * Return Pointer to Input Queue
      + If Empty, return 0
  */

  return 0;
}

/* 1.e) Output Queue

  Returns:
    0, if No Messages in Output Queue
    else, linked list of Messages to be Sent
*/
MessageChannel* proc_get_output(ProcessID pid)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru Scheduler for pid
     * Return Pointer to Output Queue
      + If Empty, return 0
  */

  return 0;
}

/* 1.f) Error Queue

  Returns:
    0, if No Messages in Error Queue
    else, linked list of Error Messages
*/
MessageChannel* proc_get_output(ProcessID pid)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru Scheduler for pid
     * Return Pointer to Error Queue
      + If Empty, return 0
  */

  return 0;
}



#endif

