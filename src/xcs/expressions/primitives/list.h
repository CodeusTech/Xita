/*
  list.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structures/implementations for XCS List primitives


  TABLE OF CONTENTS
  =================
  1.) Initialize List Primitives
  2.) Push List Primitive
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>

/*
  1.) Initialize ASCII Primitives
*/

ErrorCode initializeListPrimitives(ContextManager context)
{
  char* name = (char*) malloc(50);

  sprintf(name, "list"); context.declareType(name, 1);          
  sprintf(name, "a'"); context.declareTypeParameter(name);
  sprintf(name, "List"); context.declareTypeConstructor(name); 

  return SUCCESS;
}


