/*
  ipc.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified    March 19, 2019
*/

/*
  Contains backend functionality for interprocess communication

  Table of Contents
  =================
  1.) Asynchronous Interprocess Communication
    1.a) Send Expression
    1.b) Receive Expression
  2.) Persistent Interprocess Communication
    2.a) Declare Offer
    2.b) Request Expression
    3.c) Find Offer
*/

#ifndef TETHERS_IPC_H
#define TETHERS_IPC_H

/*
  1.) Asynchronous Interprocess Communication
*/

/* 1.a) Send Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_send(Identifier key)
{
  //  STUB STUB STUB
  printf("Sending data through Channel, %s\n", key);

  /*
    TODO:
     * Error Check
  */

  //  Return Success
  return 0;
}

/* 1.b) Receive Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_receive(Identifier key)
{
  //  STUB STUB STUB
  printf("Receiving data through Channel, %s\n", key);

  /*
    TODO:
     * Error Check
  */

  //  Return Success
  return 0;
}


/*
  2.) Persistent Interprocess Communication
*/

/* 2.a) Declare Offer

  Returns:
    0, if Successful
*/
ErrorCode decl_offer(Identifier ident)
{
  //  STUB STUB STUB
  printf("Service Offered: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Create new Scope Context
     * Add ident/data to Buffers
     * Check for Parameters
      + Add parameters to Buffers
  */

  //  Return Success
  return 0;
}

/* 2.b) Request Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_request(Identifier ident)
{
  //  STUB STUB STUB
  printf("IPC Message Requested: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Push Request to Register Stack
  */

  //  Return Success
  return 0;
}

/* 2.c) Find Offer

  Returns:
    0, if ident is not an Offer
    i, if ident is an Offer, where 'i' is Index in Buffer
*/
OfferID find_offer(Identifier ident)
{
  //  STUB STUB STUB
  printf("Offer Found: %s\n");

  /*
    TODO:
     * Error Check
     * Search Offer Buffers
     * If Match is Found,
      + Return Offer ID Number
  */

  //  Return Failure
  return 0;
}



#endif
