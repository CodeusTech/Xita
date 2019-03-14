/*
  ipc.h
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Structures/Functions for Interprocess Communication

  Table of Contents
  =================
  1.) IPC Messages
    1.a) Get Key String
    1.b) Get Data Size
    1.c) Get Data Payload
    1.d) Get Message Status
    1.e) Get Sender
    1.f) Get Recipient
  2.) Message Channels
    2.a) Front Queue Length
    2.b) Back Queue Length
    2.c) Get Front Queue
    2.d) Get Back Queue

*/

#ifndef PROC_IPC_H
#define PROC_IPC_H

#include "structs.h"


/*
  1.) IPC Messages
*/

/* 1.a) Get Key String

  Returns:
    Message Key String
*/
char* msg_get_key(Message* msg)
{
  //  Check Status for Errors

  return msg->key;
}

/* 1.b) Get Data Size

  Returns:
    Message Data Size
*/
unsigned int msg_get_size(Message* msg)
{
  //  Check Status for Errors

  return msg->size;
}

/* 1.c) Get Data Payload

  Returns:
    Message Data Payload
*/
void* msg_get_data(Message* msg)
{
  //  Check Status for Errors

  return msg->data;
}

/* 1.d) Get Message Status

  Returns:
    0, if msg is Ready
    1, if msg is NULL
*/
int msg_get_status(Message* msg)
{
  if (msg == NULL) return 1;
  return msg->status;
}

/* 1.e) Get Sender

  Returns:
    0, if msg is NULL/Errant
    pid, if msg is Ready
*/
unsigned int msg_get_send(Message* msg)
{
  if (msg == NULL) return 0;
  return msg->from_pid;
}

/* 1.f) Get Recipient

  Returns:
    0, if msg is NULL/Errant
    pid, if msg is Ready
*/
unsigned int msg_get_rec(Message* msg)
{
  if (msg == NULL) return 0;
  return msg->to_pid;
}


/*
  2.) Message Channels
*/

/* 2.a) New Message Channel

  Returns:
    p, Pointer to new Message Channel
*/
MessageChannel* mc_new(unsigned int s)
{
  //  Allocate XCS Memory
  MessageChannel* mc;

  mc->front = -1;
  mc->back  = -1;
  mc->size  =  s;
  mc->queue = NULL; //  TODO: Requires Dynamic Allocation

  return mc;
}

/* 2.b) Enqueue Message

  Returns:
    p, Pointer to new Message Channel with Message enqueued
*/
MessageChannel* mc_add(MessageChannel* mc, Message msg)
{


  return mc;
}

#endif
