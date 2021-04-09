/*
  special.h (Primitives)
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains definitions for "Special" Primitives
*/

#pragma once


#include <xcs/std/includes.h>

#include <xcs/context/manager.h>


extern ContextManager context;


ErrorCode declarePrimitiveNull()
{
  char* str = (char*) malloc(6);

  sprintf(str, "null"); context.declareType(str);
  sprintf(str, "NULL"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared Primitive Type: null");
  free(str);

  return SUCCESS;
}

ErrorCode declarePrimitiveArbitrary()
{
  char* str = (char*) malloc(6);

  sprintf(str, "a"); context.declareType(str);
  sprintf(str, "A"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared Primitive Type: a");
  free(str);

  return SUCCESS;
}
