/*
  structs.h
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified March 8, 2019
*/

/*
  Contains data structure definitions for use in global buffers

  Table of Contents
  =================
  1.) Infrastructure
    1.a) Assembly Infrastructure
  2.) Register Stacks
  3.) Functions
  4.) Data Types
  7.) Operator Structures
    7.a) Operand Pairs
  8.) Internal Memory Allocation
  9.) Internal Process Scheduling
    9.a) Infrastructure
    9.b) Interprocess Communication
      9.b.1) IPC Message
      9.b.2) Message Channel
    9.c) Process Structure
    9.d) Process Scheduling
      9.d.1) Process Queues
      9.d.2) Process Scheduler
  10.) Tether Modules
*/

#ifndef GLOBALS_STRUCTS_H
#define GLOBALS_STRUCTS_H

/*
  1.) Infrastructure
*/

typedef int ErrorCode;

typedef char* Identifier;
typedef char* Constructor;

/*
  1.a) Assembly Infrastructure
*/

typedef char* Command;
typedef char* Constant;
typedef char* Variable;

/*
  2.) Register Stacks
*/

typedef unsigned char ADR;
typedef unsigned int Scope;

typedef struct regstack_t
{
  ADR order[30];
} RegStack;


/*
  3.) Functions
*/

typedef unsigned long ConstantID;
typedef unsigned long FunctionID;
typedef unsigned int ParameterID;


/*
  4.) Data Types
*/

//  4.a) Types
typedef unsigned long TypeID;
typedef unsigned long ConstructorID;
typedef unsigned int ElementID;

//  4.b) Typeclasses
typedef unsigned long TypeclassID;
typedef unsigned int PrototypeID;

//  4.c) Primitives
typedef void* Arbitrary;

/*
  7.) Operator Structures
*/

/*
  7.a) Operand Pairs
*/
typedef struct operands_t
{
  TypeID lhs; // Left-Hand Side  Type Code
  TypeID rhs; // Right-Hand Side Type Code
} operands;


/*
  8.) Internal Memory Allocation
*/

/*
  8.a) Infrastructure
*/

typedef unsigned long Address;

/*
  8.b) Memory Blocks
*/

/* 8.b.1) Memory Node

*/
typedef struct mem_node
{
  struct mem_node* left;
  struct mem_node* right;
  unsigned int height;
  Address addr;
  unsigned long size;
  void* data;
} MemoryNode;

MemoryNode* ActiveMemory;


/*
  9.) Internal Process Scheduling
*/

/*
  9.a) Infrastructure
*/

typedef unsigned long ProcessID;

/*
  9.b) Interprocess Communication
*/

/* 9.b.1) IPC Message

 * Contains all metadata required for an interprocess message.
 * In other words, this is the format used when 
    process A sends a message to process B.
*/
typedef struct Message_t
{
  char* key;          // Key String
  unsigned int size;  // Data Size
  void* data;         // Data Payload
  int status;         // Message Status
  ProcessID src;      // Sending Process ID
  ProcessID dest;     // Receiving Process ID
} Message;

/* 9.b.2) Message Channel

*/
typedef struct MessageChannel_t
{
  int front, back;    // Queue Indices
  unsigned int size;  // Total Size
  Message* queue;     // Front Message Queue
} MessageChannel;

/* 9.c) Process Structure

*/
typedef struct Process_t
{
  ProcessID pid;          //  Process ID
  Identifier name;        //  Process Name
  ErrorCode stat;         //  Process Status
  ProcessID* teth;        //  Active Process Tethers
  MessageChannel* input;  //  Process Input Queue
  MessageChannel* output; //  Process Output Queue
  MessageChannel* error;  //  Process Error Queue
} Process;

/*
  9.d) Process Scheduling
*/

/* 9.d.1) Process Queue

*/
typedef struct ProcessQueue_t
{
  long front, back;
  unsigned int size;
  Process* queue;
} ProcessQueue;


/* 9.d.2) Process Scheduler

*/
typedef struct ProcessScheduler_t
{
  ProcessQueue* queue0; // First Priority  (System Interrupts) (Clocks/Event Timers)
  ProcessQueue* queue1; // Second Priority (User Interrupts) (System - Instant of Execution)
  ProcessQueue* queue2; // Third Priority  (Source - Instant of Execution)
  ProcessQueue* queue3; // Fourth Priority
  ProcessQueue* queue4; // Fifith Priority (Source - After x Seconds)
  ProcessID* blocked;   // Inactive Processes (Blocked)
  ProcessID* t_mod;     // Active Tether Modules
} ProcessScheduler;


/*
  10.) Tether Modules
*/

typedef unsigned long OfferID;

#endif
