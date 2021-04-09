/*
  ascii.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structures/implementations for XCS ASCII primitives


  TABLE OF CONTENTS
  =================
  1.) Initialize ASCII Primitives
  2.) Push ASCII Primitive
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>

extern ContextManager context;


Index countStrings = 0;

/*
  1.) Initialize ASCII Primitives
*/

ErrorCode initializeASCIIPrimitives()
{
  char* name = (char*) malloc(50);

  sprintf(name, "char"); context.declareType(name, 1);          
  sprintf(name, "Char"); context.declareTypeConstructor(name); 
  sprintf(name, "string"); context.declareType(name, POINTERSIZE);
  sprintf(name, "String"); context.declareTypeConstructor(name);

  return SUCCESS;
}


ErrorCode pushString(char* str)
{
  context.addString(str);
  context.LastConstructor(TYPE_STRING);
  context.LastType(TYPE_STRING);

  ADR adr = context.rsPush(TYPE_STRING);
  char* top = get_reg(adr, 64);

  char* s = (char*) malloc(100);
  sprintf(s, "  ldr   %s, =_s_%lu", top, countStrings++);
  context.addInstruction(s);

  free(s);
  return SUCCESS;
}
