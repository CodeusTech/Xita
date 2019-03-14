/*
  structs.h (Processes)
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Standard Structures to be used in Process Scheduling
  
  Table of Contents
  =================
  1.) Interprocess Communication
    1.a) IPC Message
    1.b) Message Channel
  2.) Process Structure
  3.) Process Queue
  4.) Process Scheduler
*/

#ifndef PROC_STRUCTS_H
#define PROC_STRUCTS_H

/*
  1.) Interprocess Communication
*/

/* 1.a) IPC Message

  * Contains all metadata required for an interprocess message.
  * In other words, this is the format used when 
      process A sends a message to process B.
*/
typedef struct Message_t
{
  char* key;              // Key String
  unsigned int size;      // Data Size
  void* data;             // Data Payload
  int status;             // Message Status
  unsigned int from_pid;  // Sending Process ID
  unsigned int to_pid;    // Receiving Process ID
} Message;

/* 1.b) Message Channel

*/
typedef struct MessageChannel_t
{
  unsigned int front_len; //  Length of Front Queue
  unsigned int back_len;  //  Length of Back Queue
  Message* front; //  Front Message Queue
  Message* back;  //  Back Message Queue
} MessageChannel;


/* 2.) Process Structure

*/
typedef struct Process_t
{
  unsigned int pid;       //  Process ID
  int stat;               //  Process Status
  unsigned int* teth;     //  Active Process Tethers
  MessageChannel input;   //  Process Input Queue
  MessageChannel output;  //  Process Output Queue
  MessageChannel error;   //  Process Error Queue
} Process;


/* 3.) Process Queue

*/
typedef struct ProcessQueue_t
{
  unsigned long front_len;  //  Length of Front Queue
  unsigned long back_len;   //  Length of Back Queue
  Process* front; //  Front Process Queue
  Process* back;  //  Back Process Queue
} ProcessQueue;


/* 4.) Process Scheduler

*/
typedef struct ProcessScheduler_t
{
  ProcessQueue* queue0;  // First Priority  (System Interrupts) (Clocks/Event Timers)
  ProcessQueue* queue1;  // Second Priority (User Interrupts) (System - Instant of Execution)
  ProcessQueue* queue2;  // Third Priority  (Source - Instant of Execution)
  ProcessQueue* queue3;  // Fourth Priority
  ProcessQueue* queue4;  // Fifith Priority (Source - After x Seconds)
  int* blocked; // Inactive Processes (Blocked)
  int* t_mod;   // Active Tether Modules
} ProcessScheduler;



#endif
