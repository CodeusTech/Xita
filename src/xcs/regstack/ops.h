/*
  ops.h (regstack)
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Interface Functions for handling the active context's register stack
*/

#pragma once

#include <xcs/std/includes.h>

#include <xcs/context/manager.h>
extern ContextManager context;




//  2.a) Push Integer Literal
ErrorCode pushData(TypeID tid, Arbitrary value)
{
  context.rsPush(tid);
  context.LastType(tid);
  context.LastData(value);
  

  return SUCCESS;
}




