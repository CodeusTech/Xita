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
  2.) Serialize Function's Register Stack
  3.) Initialize Register Stack Backend Infrastructure
  4.) Finalize Register Stack
*/

#ifndef REGSTACK_CONTROL_H
#define REGSTACK_CONTROL_H

#include "operations.h"

extern ADR** rs;  //  Global Register Stack Orders
extern Scope scope_next;
extern TypeID** rs_types;
extern TypeID** rse_types;
extern ConstructorID** rs_construct;
extern unsigned int rse_next;
extern unsigned long** rse_construct;


/* 1.) Initialize Function's Register Stack

  Returns:
    0, if Successful
*/
int rs_init(Scope scope)
{

  /*
    TODO:
     * Error Check
     * Check for Scope == 255
  */
  //  Set Create Register Stack
  rs_new(scope);

  rs_types[scope]      = (TypeID*) malloc(25*sizeof(TypeID));
  rs_construct[scope]   = (ConstructorID*) malloc(25 * sizeof(unsigned int));

  if  (scope == 0)
  { 
    rse_types[scope] = NULL;
    rse_construct[scope]  = NULL;
  }
  else 
  {
    rse_types[scope] = (TypeID*) malloc(256* sizeof(TypeID));
    rse_construct[scope] = (ConstructorID*) malloc(256 * sizeof(unsigned long));
  }

  return 0;
}

/* 2.) Serialize Register Stack

  Returns:
    0, if Successful
*/
int rs_serialize()
{
  int active = curr_reg;
  unsigned long long reg1, reg2 = (unsigned long long) 0;

  //  Create Serial Integers
  for (unsigned long long i = 0; i < active; i++)
  {
    ADR reg = rs_pop();

    unsigned long long test = (unsigned long long) rs[scope_curr][rs_top()];
    unsigned long long test2 = ((((unsigned long long) 31) & test) << (i * 5));


    reg1 |= test2;
  }

  char* str = (char*) malloc(50);
  sprintf(str, "mov   W30, %llu\n", reg1);

  add_command(str);

  free(str);

  return 0;
}


/* 4.) Finalize Register Stack

  Returns:
    0, if Successful
*/
int rs_end()
{
  rs_serialize();

  /*
    FREE MEMORY BUFFERS
  */
  for (int i = 0; i < scope_next; i++)
  {
    //  Entry Function Context Scope
    if (rs[i][26] == (ADR) 0) 
    {
  printf("check\n");
      free(rs[i]);
      free(rs_types[i]);
      free(rs_construct[i]);
    }
    //  Subfunction Context Scopes
    else 
    {
      free (rs[i]);
      free (rs_types[i]);
      free (rs_construct[i]);
      free (rse_types[i]);
      free (rse_construct[i]);
    }
  }

  for (int i = 1; i < rse_next; i++)
  {
    free (rse_types[i]);
    free(rse_construct[i]);
  }

  free(rs);

  return 0;
}

#endif
