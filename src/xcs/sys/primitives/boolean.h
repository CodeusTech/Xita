/*
  boolean.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains Functionality for backend handling of boolean values
*/

#pragma once

#include <xcs/std/includes.h>

#include <xcs/context/manager.h>
extern ContextManager context;


ErrorCode declarePrimitiveBoolean()
{
  char* str = (char*) malloc(10);

  sprintf(str, "bool"); context.declareType(str);
  sprintf(str, "True"); context.declareTypeConstructor(str);
  sprintf(str, "False"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared primitive types: char & string");
  free(str);
  return SUCCESS;
}

