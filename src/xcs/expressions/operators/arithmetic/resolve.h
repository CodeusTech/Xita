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

  TypeID tid_left  = context.rsSecType();
  TypeID tid_right = context.rsType();

  for (Index i = 0; i < operands.size(); ++i)
    if ((operands[i].OpearandTypes()[0] == tid_left) && (operands[i].OpearandTypes()[1] == tid_right))
    {
      printf("Operand Match!!\n");
    }
}



