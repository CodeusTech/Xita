/*
  structs.h
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified July 29, 2019
*/

/*
  Contains data structure definitions for use in global buffers

  Table of Contents
  =================
  1.) Basic Infrastructure
  2.) Register Stacks

*/

#ifndef std_STRUCTS_H
#define std_STRUCTS_H

#include <vector>

//  XCS Libraries
#include "typedefs.h"


using namespace std;

using std::vector;


/*
  1.) Basic Infrastructure
*/


/*
  Debug Messages
*/

struct DebugMessageNode
{
  Identifier ident;
  char* msg;
};

vector<DebugMessageNode> debug;


enum IdentifierType
{
  CONSTANT,
  FUNCTION,
  FUNCTION_PARAMETER,
  TYPE,
  TYPE_PARAMETER,
  TYPECLASS,
  CONSTRUCTOR
};

/*
  2.) Register Stacks
*/

struct regstack
{
  //  UNSAFE:  Assumes stack size < 26
  vector<ADR> rs_code;
  vector<TypeID> rs_type;
  vector<ConstructorID> rs_struct;
};




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
  9.) Internal Process Scheduling
*/

/*
  9.a) Infrastructure
*/


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

#endif
