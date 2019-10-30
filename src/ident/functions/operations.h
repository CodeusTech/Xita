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
#include "../../regstack/regstack.h"
#include "../../utils/scope.h"
#include "../../grammar/status.h"

#include "structs.h"


/*  
  1.) Find Constant
    * Returns ConstantID of the matched constant identifier
*/
ConstantID find_constant(Identifier ident)
{
  for (vector<ConstantNode>::iterator it = constants.begin(); it != constants.end(); it++)
    if (strcmp((*it).get_identifier(), ident) == 0) 
    {
      found = true;

      //  Create ARM Assembly Command
      char* str = (char*) malloc(50);
      char* rtop = get_reg(rs_top(), 32);

      //  Add to Queue for File Printing
      sprintf(str, "ldr   %s, %s", rtop, ident);
      add_command(str);

      //  Deallocate Strings
      free(str);
      free(rtop);
      free(ident);

      ADR reg = rs_push();

      rs[scope_curr].rs_struct.push_back(2);
      rs[scope_curr].rs_type.push_back(2);

      //  
      return (*it).get_ID();
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
FunctionID find_function (Identifier ident)
{
  //  STUB STUB STUB
  printf("Function Found: %s\n", ident);

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
  //found = true;
  //  STUB STUB STUB

  //  Temporary test
  //rs[scope_curr].rs_type.push_back(TYPE_INTEGER);
  //rs[scope_curr].rs_struct.push_back(TYPE_INTEGER);
  //push_int(32);

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

