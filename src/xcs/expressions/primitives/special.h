/*
  special.h (primitives)
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains Type definitions for special primitive types
*/

#pragma once


#include <xcs/std/includes.h>
#include <xcs/context/manager.h>

extern ContextManager context;


/*
  Initialize Special Primitives
*/

ErrorCode initializeSpecialPrimitives()
{
  char* name = (char*) malloc(50);

  sprintf(name, "null"); context.declareType(name);
  sprintf(name, "NULL"); context.declareTypeConstructor(name);

  sprintf(name, "a'"); context.declareType(name, 4);
  sprintf(name, "A'"); context.declareTypeConstructor(name);

  free(name);
  return SUCCESS;
}
