/*
  strexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains primitive string expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) String Literals
    1.a) Pop String
    1.b) Push String Literal
    1.c) Push String Identifier
  2.) String Arithmetic
    2.a) Append Strings
    

*/

#ifndef PRIMITIVES_STREXP_H
#define PRIMITIVES_STREXP_H

#include "../std/typecodes.h"
#include "../std/structs.h"

#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include <xcs/regstack/utils.h>

extern unsigned int grammar_status;

/*
  1.) String Literals
*/

/* 1.a) Pop String

  Returns:
    0, if Successful
*/
int pop_string()
{
  //  STUB STUB STUB
  printf("String Popped from Register Stack\n");

  //  TODO:  Error Check

  //  Pop String From Register Stack
  rs_pop();

  return 0;
}

/* 1.b) Push String Literal

  Returns:
    0, if Successful
*/
int push_string_lit(char* str)
{
  //  STUB STUB STUB
  printf("String Literal Pushed onto Register Stack: %s\n", str);

  //  TODO:  Error Check

  //  Push String to Register Stack
  ADR reg = rs_push(TYPE_STRING);

  return 0;
}


/*
  2.) String Arithmetic
*/

/* 2.a) Append Strings

  Returns:
    0, if Successful
*/
int string_append()
{

  //  TODO:  Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();


  //  Push New String to Register Stack
  ADR reg = rs_push(TYPE_STRING);
  

  return 0;
}




#endif
