/*
  control.h
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Control/Status Operations for Managing the Register Stack

  Table of Contents
  =================
  1.) Initialize Function's Register Stack
  2.) Initialize Register Stack Backend Infrastructure
  3.) Finalize Register Stack
*/

#ifndef REGSTACK_CONTROL_H
#define REGSTACK_CONTROL_H

#include "operations.h"

extern ADR** rs;  //  Global Register Stack Orders
extern Scope scope_next;
extern TypeID** rs_types;
extern unsigned int rse_next;
extern unsigned long** rse_types;


/* 1.) Initialize Function's Register Stack

  Returns:
    0, if Successful
*/
int rs_stack_init(Scope scope)
{
  /*
    TODO:
     * Error Check
  */

  //  Set Create Register Stack
  rs[scope]     = (ADR*) malloc(31 * sizeof(ADR));
  rs[scope][31] = (ADR) 0;  // Indicates Extended Space isn't used

  rs_types[scope]   = (TypeID*) malloc(30 * sizeof(unsigned int));

  if  (scope == 0) rse_types[scope]  = NULL;
  else rse_types[scope] = (unsigned long*) malloc(255 * sizeof(unsigned long));

  return 0;
}


/* 2.) Initialize Register Stack

  Returns:
    0, if Successful
*/
int rs_init()
{
  printf("rs_init() Called...\n");
  //   Initialize Register Stack Buffers, and 1st Reg Stack
  rs = (ADR**) malloc(4096 * sizeof(ADR*));
  rs[0] = rs_new();

  //  Initialize Register Stack Types Buffer
  rs_types = (TypeID**) malloc(4096 * sizeof(TypeID*));
  rs_types[0] = (TypeID*) malloc (30 * sizeof(TypeID));

  //  Initialize Register Stack Types Buffer (Extended)
  rse_types = (unsigned long**) malloc(4096 * sizeof(unsigned long*));
  rse_types[0] = NULL;  //  RESERVED

  return 0;
}


/* 3.) Finalize Register Stack

  Returns:
    0, if Successful
*/
int rs_end()
{
  printf("rs_finish() Called...\n");
  for (int i = 0; i < scope_next; i++)
  {
    //  Entry Function Context Scope
    if (rs[i][31] == (ADR) 0) 
    {
      free(rs[i]);
      free(rs_types[i]);
    }
    //  Subfunction Context Scopes
    else 
    {
      free (rs[i]);
      free (rs_types[i]);
      free (rse_types[i]);
    }
  }

  for (int i = 1; i < rse_next; i++)
  {
    free(rse_types[i]);
  }

  free(rs);
  free(rs_types);
  free(rse_types);


  return 0;
}

#endif
