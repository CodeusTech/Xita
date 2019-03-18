/*
  operations.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains Backend Function Operations

  Table of Contents
  =================
  1.) Declare Function
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
extern char** ident_functions;



/* 1.) Declare Function

  Returns:
    0, if Successful
*/
int decl_function (char* ident)
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
  sprintf(comm, "%s:\n\0", ident);

  return 0;
}

/* End Declare Function

  Returns:
    0, if Successful
*/
int decl2_function ()
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
  sprintf(comm, "  bx lr\n\0");
  add_command(comm);

  return 0;
}


/* 2.) Function Expressions

  Returns:
    0, if Successful
*/
int exp_function (char* name)
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
    i, if ident is a function, where i is index in function buffer
*/
int find_function (char* ident)
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
int find_pfunction (char* ident, TypeID* ptypes)
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

