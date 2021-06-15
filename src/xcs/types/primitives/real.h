/*
  real.h (Primitives)
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains functionality for handling real numbers
*/

#pragma once

#include <xcs/std/includes.h>

#include <xcs/context/manager.h>
extern ContextManager context;


ErrorCode declarePrimitiveReals()
{
  char* str = (char*) malloc(10);

  sprintf(str, "real"); context.declareType(str);
  sprintf(str, "Real"); context.declareTypeConstructor(str);
  sprintf(str, "float"); context.declareType(str);
  sprintf(str, "Float"); context.declareTypeConstructor(str);
  sprintf(str, "double"); context.declareType(str);
  sprintf(str, "Double"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared primitive types: real");
  free(str);
  return SUCCESS;
}



