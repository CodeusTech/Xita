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
  1.a) Send Message
  1.b) Receive Message
*/

#ifndef IPC_OPERATIONS
#define IPC_OPERATIONS


/* 1.a) Send Message

  Returns:
    0, if Successful
*/
ErrorCode exp_send(Identifier key)
{
  //  Identify Sending Process
  unsigned long pid = 0;

  //  Send Data to Process
  printf("Data Sent to Process %lu using Key %s\n", pid, key);

  /*
    TODO: 
     * Error Check
     * Perform IPC System Call
      + Transfer Message to Process Output Channel
  */

  //  Return Success
  return 0;
}

/* 1.b) Receive Message

  Returns:
    0, if Successful
*/
ErrorCode exp_receive(Identifier key)
{
  //  Identify Receiving Process
  unsigned long pid = 0;

  //  Receive Data from Process
  printf("Data Received from Process %lu using Key %s\n", pid, key);

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

