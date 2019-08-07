/*
  operations.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified   August  7, 2019
*/

/*
  Contains Backend Function Operations

  Table of Contents
  =================
  1.) Find Constant
  2.) Find Function
    2.a) Find Function /wo Parameters
    2.b) Find Function /w Parameters
  3.) Find Functional Parameter
*/

#ifndef FUNCTIONS_OPERATIONS_H
#define FUNCTIONS_OPERATIONS_H

//  XCS Libraries
#include "../../utils/scope.h"

//  Global Variables
extern Identifier* ident_functions;



/*  1.) Find Constant


*/
void* find_constant(Identifier ident)
{
  for (vector<node_constant>::iterator it = constants.begin(); it != constants.end(); it++)
    if (strcmp(((*it).const_ident), ident) == 0) 
    {
      found = true;
      //  TODO:  Generalize cast to work on more than integers
      return (void*) (unsigned long long) (*it).value;
    }

  found = false;
  free(ident);

  return NULL;
}


/*
  2.) Find Function
*/

/* 2.a) Find Function /wo Parameters

  Returns:
    0, if ident is not a Declared Function
    s, where 's' is the matching function's Context Scope ID
*/
void* find_function (Identifier ident)
{
  //  STUB STUB STUB
  printf("Function Found: %s\n", ident);
  found = true;

  /*
    TODO:
     * Error Check
     * Search Function Buffers for ident
      + Ensure ident has no expected parameters
  */

  return NULL;
}

/* 2.b) Find Function /w Parameters

  Returns:
    0, if ident is not a Declared Function
    i, if ident is a function, where i is index in function buffer
*/
void* find_pfunction (Identifier ident, TypeID* ptypes)
{
  //  STUB STUB STUB
  printf("Function Found: %s\n", ident);
  found = true;

  /*
    TODO:
     * Error Check
     * Search Function Buffers for ident
      + If ident is found, compare parameters types with ptypes
  */

  return NULL;
}


/* 3.) Find Functional Parameter

  Returns:
    0, if identifier is not a Parameter
    i, if identifier is Parameter, where 'i' is index in Parameter Buffer
*/
ParameterID find_parameter(Identifier ident)
{
  printf("Parameter Found: %s\n", ident);
  found = true;
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru backend buffers
      - If Parameter is found, 
        + Return Buffer Index
      - If Not Found,
        + Return 0
  */

  return 0;
}



#endif

