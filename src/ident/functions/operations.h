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


/*
  1.) Function Initialization
*/

/* 1.a) Declare Function

  Returns:
    0, if Successful
*/
ErrorCode decl_function (Identifier ident)
{
  //  STUB STUB STUB
  printf("Function %s Declared\n", ident);

  /*
    TODO:
     * Error Check
     * Store Parent Context Scope 
  */

  //  Get New Context Scope
  Scope s = get_scope_next();

  //  Generate Register Stack for New Scope
  rs_stack_init(s);
  
  //  Print Function Identifier to Assembly File
  char comm[300];
  sprintf(comm, "%s:\n", ident);
  //  add_command(comm);

  return 0;
}

/* End Declare Function

  Returns:
    0, if Successful
*/
ErrorCode decl2_function ()
{
  // STUB STUB STUB

  /* 
    TODO:
     * Error Check
     * If Function had Parameters,
      + Move Return Values into bottom of register stack
     * Set Current Scope to Parent Context Scope
  */

  //  Return to Parent Context Scope
  char comm[9];
  sprintf(comm, "  bx lr\n");
  // add_command(comm);

  return 0;
}

/* 1.c) Undeclare Function

  Returns:
    0, if Successful
*/
ErrorCode undecl_function()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Reset Scope and Associated Metadata
      + Identifier Buffers
      + Type Buffers
      + etc.
  */

  //  Return Success
  return 0;
}


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

