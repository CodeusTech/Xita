/*
  process.h
  Cody Fagley 
  Authored on   February 22, 2019
  Last Modified February 22, 2019
*/

/*
  Contains Public Interface for XCS Process Definitions/Operations

  Table of Contents
  =================
  1.) Structures
    1.a) Interprocess Message
    1.b) Process Structure
    1.c) Process Queue
    1.d) Process Scheduler
  2.) Process Functions
    2.a) Get Process ID
    2.b) Get Process Status
    2.c) Get Active Process Tethers
    2.d) Get Input Queue
    2.e) Get Output Queue
    2.f) Get Error Queue
*/

#ifndef PROC_PROCESS_H
#define PROC_PROCESS_H


/*
  1.) Structures
*/

/* 1.a) IPC Message

  * Contains all metadata required for an interprocess message.
  * In other words, this is the format used when 
      process A sends a message to process B.
*/
typedef struct Message_t
{
  char* key;    // Key String
  long data;    // Data Payload
  int status;   // Message Status
  int from_pid; // Sending Process ID
  int to_pid;   // Receiving Process ID
} Message;

/* 1.b) Process Structure

*/
typedef struct Process_t
{
  int pid;          //  Process ID
  int stat;         //  Process Status
  int* teth;        //  Active Process Tethers
  Message* input;   //  Process Input Queue
  Message* output;  //  Process Output Queue
  Message* Error;   //  Process Error Queue
} Process;


/*
  2.) Process Functions
*/


#endif
