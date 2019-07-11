/*
  operations.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified    March 19, 2019
*/

/*
  Contains Backend Function Operations

  Table of Contents
  =================
  1.) Function Initialization
    1.a) Declare Function
    1.b) Undeclare Function
  2.) Function Expressions
  3.) Find Function ID
    3.a) Find Function /wo Parameters
    3.b) Find Function /w Parameters
*/

#ifndef FUNCTIONS_OPERATIONS_H
#define FUNCTIONS_OPERATIONS_H

//  XCS Libraries
#include "../../utils/scope.h"

//  Global Variables
extern Identifier* ident_functions;




/* 2.) Function Expressions

  Returns:
    0, if Successful
*/
ErrorCode exp_function (Identifier name)
{
  //  STUB STUB STUB
  printf("Function %s Invoked\n", name);

  /*
    TODO:
     * Error Check
     * If target function has parameters,
      + If parameter ADRs are active, copy data to Data Stack
      + Load Parameter Into Expected ADR
  */

  /*
    TODO:
     * Perform Contextual Type Check
  */

  return 0;
}

/*
  3.) Find Function ID
*/

/* 3.a) Find Function /wo Parameters

  Returns:
    0, if ident is not a Declared Function
    s, where 's' is the matching function's Context Scope ID
*/
Scope find_function (Identifier ident)
{
  //  STUB STUB STUB
  printf("Function Found: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Search Function Buffers for ident
      + Ensure ident has no expected parameters
  */

  return 0;
}

/* 3.) Find Function /w Parameters

  Returns:
    0, if ident is not a Declared Function
    i, if ident is a function, where i is index in function buffer
*/
Scope find_pfunction (Identifier ident, TypeID* ptypes)
{
  //  STUB STUB STUB
  printf("Function Found: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Search Function Buffers for ident
      + If ident is found, compare parameters types with ptypes
  */

  return 0;
}



#endif

