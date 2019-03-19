/*
  operations.h (Interprocess Communication)
  Cody Fagley
  Authored on   March 18, 2019
  Last Modified March 18, 2019
*/

/*
  Contains Generic Operations for Interprocess Communication

  Table of Contents
  =================
  1.) Send Message
  2.) Receive Message
*/

#ifndef IPC_OPERATIONS
#define IPC_OPERATIONS


/* 1.) Send Message

  Returns:
    0, if Successful
*/
ErrorCode ipc_send(ProcessID pid)
{
  //  Send Data to Process
  printf("Data Sent to Process: %d\n", pid);

  /*
    TODO: 
     * Error Check
     * Perform IPC System Call
      + Transfer Message to Process Output Channel
  */

  //  Return Success
  return 0;
}

/* 2.) Receive Message

  Returns:
    0, if Successful
*/
ErrorCode ipc_receive(ProcessID pid)
{
  //  Receive Data from Process
  printf("Data Received from Process: %d\n", pid);

  //  Return Success
  return 0;
}

#endif

