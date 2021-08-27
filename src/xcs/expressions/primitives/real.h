/*
  real.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structures/implementations for XCS real primitives


  TABLE OF CONTENTS
  =================
  1.) Initialize Real Primitives
  2.) Push Real Primitive
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>


/*
  1.) Initialize Real Primitives
*/

ErrorCode initializeRealPrimitives(ContextManager context)
{
  char* name = (char*) malloc(50);

  sprintf(name, "real"); context.declareType(name, 0);          //  NOTE THE SIZE PARAMETERS!!!
  sprintf(name, "Real"); context.declareTypeConstructor(name);  //  Implemented by identifier ONLY

  sprintf(name, "float"); context.declareType(name, 0);
  sprintf(name, "Float"); context.declareTypeConstructor(name);
  sprintf(name, "double"); context.declareType(name, 0);
  sprintf(name, "Double"); context.declareTypeConstructor(name);

  return SUCCESS;
}


