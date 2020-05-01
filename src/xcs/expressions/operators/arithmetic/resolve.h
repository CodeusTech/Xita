/*
  resolve.h (Arithmetic Operators)
  Codeus Tech
  Authored on   April 28, 2020
  Last Modified April 28, 2020
*/

/*
  Contains definitions for resolving arithmetic operators (w/ given parameter types)
*/

#pragma once

#include <xcs/std/includes.h>
#include "arithmetic.h"
#include <xcs/context/manager.h>

extern ContextManager context;


ErrorCode resolveAddition()
{
  /*
    Collect Data Types
  */
  TypeID tid_left  = context.rsSecType();
  TypeID tid_right = context.rsType();

  if (tid_left >= NUMBER_TYPES || tid_right >= NUMBER_TYPES)
  {
    /*
      LHS or RHS has a user-defined type
    */
    printf("User Defined Type used in Addition\n");
    return SUCCESS;
  }

  /*
    At this point, both sides are using Primitive Literals
  */

  char* top = get_reg(context.rsTop(), 32);
  char* sec = get_reg(context.rsSec(), 32);

  char* str = (char*) malloc(50);
  sprintf(str, "  adds  %s, %s, %s", sec, sec, top);

  context.addInstruction(str);

  free(top);
  free(sec);

  return SUCCESS;
}



