/*
  boolean.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structures/implementations for XCS boolean primitives


  TABLE OF CONTENTS
  =================
  1.) Initialize Boolean Primitives
  2.) Primitive Operations
  teelers
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>


/*
  1.) Initialize Boolean Primitives
*/

ErrorCode initializeBooleanPrimitives(ContextManager context)
{
  char* name = (char*) malloc(50);

  sprintf(name, "boolean"); context.declareType(name, 1);     
  sprintf(name, "True"); context.declareTypeConstructor(name); 
  sprintf(name, "False"); context.declareTypeConstructor(name); 
  
  free(name);
  return SUCCESS;
}



/*
  2.) Primitive Operations
*/

