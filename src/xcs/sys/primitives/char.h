/*
  char.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains structural definitions for XCS backend handling for ASCII Characters and Strings
*/

#pragma once

#include <xcs/std/includes.h>

#include <xcs/context/manager.h>
extern ContextManager context;


ErrorCode declarePrimitiveAscii()
{
  char* str = (char*) malloc(10);

  sprintf(str, "char"); context.declareType(str, 1);
  sprintf(str, "Char"); context.declareTypeConstructor(str);
  sprintf(str, "string"); context.declareType(str, POINTERSIZE);
  sprintf(str, "String"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared primitive types: char & string");
  free(str);
  return SUCCESS;
}




