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
  3.) Find Function
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
int decl_function (char* name)
{
  printf("Function %s Declared\n", name);

  //  Store Current Context Scope as Parent
  //  TODO: ...

  //  Get New Function Context Scope
  //Scope s = get_scope_next();

  //  Generate Register Stack for Scope
  

  return 0;
}

/* End Declare Function

  Returns:
    0, if Successful
*/
int decl2_function ()
{
  /* TODO:
    If Function has Parameters,
      Move Return Values into bottom of register stack
  */


  //  Return to Parent Context Scope

  return 0;
}


/* 2.) Function Expressions

  Returns:
    0, if Successful
*/
int exp_function (char* name)
{
  printf("Function %s Invoked\n", name);

  return 0;
}


/* 3.) Find Function

  Returns:
    0, if identifier is not a Function
    i, if identifier is a function, where i is index in function buffer
*/
int find_function (char* ident)
{
  printf("Function Found: %s\n", ident);

  return 0;
}



#endif
