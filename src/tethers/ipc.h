/*
  ipc.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains backend functionality for interprocess communication

  Table of Contents
  =================
  1.) Asynchronous Interprocess Communication
    1.a) Invoke Send
    1.b) Invoke Receive
  2.) Persistent Interprocess Communication
    2.a) Invoke Ask
    2.b) Declare Offer
    3.c) Find Offer
*/

#ifndef TETHERS_IPC_H
#define TETHERS_IPC_H

/*
  1.) Asynchronous Interprocess Communication
*/

/* 1.a) Invoke Send

  Returns:
    0, if Successful
*/
int ipc_send(char* key)
{
  printf("Sending data through Channel, %s\n", key);

  return 0;
}

/* 1.b) Invoke Receive

  Returns:
    0, if Successful
*/
int ipc_receive(char* key)
{
  printf("Receiving data through Channel, %s\n", key);

  return 0;
}


/*
  2.) Persistent Interprocess Communication
*/

/* 2.a) Invoke Ask

  Returns:
    0, if Successful
*/
int ipc_ask(char* module, char* ident)
{
  printf("%s requested from module: %s\n", ident, module);

  return 0;
}

/* 2.b) Declare Offer

  Returns:
    0, if Successful
*/
int ipc_offer(char* ident)
{
  printf("Service Offered: %s\n", ident);

  return 0;
}

/* 2.c) Find Offer

  Returns:
    0, if ident is not an Offer
    i, if ident is an Offer, where 'i' is Index in Buffer
*/
int find_offer(char* ident)
{
  printf("Offer Found: %s\n");

  return 0;
}



#endif
