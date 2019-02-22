/*
  stdproc.h
  Cody Fagley
  Authored on   February 22, 2019
  Last Modified February 22, 2019
*/

/*
  Contains Standard Definitions for use in Process-Related Headers

  Table of Contents
  =================
  1.) Structures
    1.a) Interprocess Message
    1.b) Process Structure
  2.) Standard Operations
*/

#ifndef PROCESS_STDPROC_H
#define PROCESS_STDPROC_H


/*
  1.) Structures
*/

/* 1.a) IPC Message

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
  2.) Standard Operations
*/


#endif
