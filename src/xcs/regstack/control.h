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

#include <xcs/std/typedefs.h>
#include "operations.h"


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
  rs_new();


  return 0;
}

/* 2.) Serialize Register Stack

  Returns:
    0, if Successful
*/
int rs_serialize()
{
  printf("Current Register is: %d\n", curr_reg);

  int active = curr_reg;
  unsigned long long reg1 = (unsigned long long) 0;

  //  Create Serial Integers
  for (int i = 0; i < active; i++)
  {
    unsigned long long test = (unsigned long long) rs[scope_curr].rs_code[rs_sec()];
    unsigned long long test2 = ((31 & test) << (i * 5));

    reg1 |= test2;

    ADR reg = rs_pop();
  }

  char* str = (char*) malloc(50);
  sprintf(str, "mov   W30, %llu\n", reg1);

  add_command(str);

  return 0;
}


/* 4.) Finalize Register Stack

  Returns:
    0, if Successful
*/
int rs_end()
{
  rs_serialize();

  return 0;
}

#endif
