/*
  integer.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains Function Listings for Handling XCS Integer Primitives


  Table of Contents
  =================
  1.) Declare Integer Types/Constructors (XCS Context)
  2.) Integer Operations
    2.a) Push Integer Literal
*/

#pragma once

#include <xcs/std/includes.h>

#include <xcs/context/manager.h>

extern ContextManager context;


/*
  1.) Declare Integer Types/Constructors (XCS Context)
*/

ErrorCode declarePrimitiveIntegers()
{
  char* str = (char*) malloc(10);

  sprintf(str, "int");  context.declareType(str, 4);          //  TID: 2
  sprintf(str, "Int");  context.declareTypeConstructor(str);

  sprintf(str, "u8");  context.declareType(str, 1);           //  TID: 3
  sprintf(str, "U8");  context.declareTypeConstructor(str);
  sprintf(str, "i8");  context.declareType(str, 1);           //  TID: 4
  sprintf(str, "I8");  context.declareTypeConstructor(str);
  sprintf(str, "u16"); context.declareType(str, 2);           //  TID: 5
  sprintf(str, "U16"); context.declareTypeConstructor(str);
  sprintf(str, "i16"); context.declareType(str, 2);           //  TID: 6
  sprintf(str, "I16"); context.declareTypeConstructor(str);
  sprintf(str, "u32"); context.declareType(str, 4);           //  TID: 7
  sprintf(str, "U32"); context.declareTypeConstructor(str);
  sprintf(str, "i32"); context.declareType(str, 4);           //  TID: 8
  sprintf(str, "I32"); context.declareTypeConstructor(str);
  sprintf(str, "u64"); context.declareType(str, 8);           //  TID: 9
  sprintf(str, "U64"); context.declareTypeConstructor(str);
  sprintf(str, "i64"); context.declareType(str, 8);           //  TID: 10
  sprintf(str, "I64"); context.declareTypeConstructor(str);

  l.log('D', "Primitives", "Declared Primitive Type: int");
  free(str);
  return SUCCESS;
}




/*
  2.) Integer Operations
*/








