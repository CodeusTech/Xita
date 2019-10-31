/*
  expressions.h
  Cody Fagley
  Authored on   August 7, 2019
  Last Modified August 7, 2019
*/

/*
  Contains backend libraries for handling functional expressions


  TABLE OF CONTENTS
  =================
  1.) Constant Expressions
    1.a) Find Constant
    1.b) Resolve Constant
  2.) Functional Expressions
    2.a) Execute Function
    2.b) Load Argument (Standard)
    2.c) Load Argument (Recursive)
  3.) Parameter Expressions
*/


#ifndef FUNCTIONS_EXPRESSIONS_H
#define FUNCTIONS_EXPRESSIONS_H


//  XCS Libraries
#include <xcs/std/buffers.h>
#include <xcs/std/scope.h>
#include <xcs/grammar/status.h>

#include <xcs/regstack/regstack.h>
#include <xcs/regstack/utils.h>

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
      free(ident);

      return (*it).get_ID();
    }

  return (ConstantID) NULL;
}

/*

*/
ErrorCode resolve_constant(ConstantID _const)
{
  //  Push Constant 
  rs_push(TYPE_ARBITRARY);


  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* rtop = get_reg(rs_top(), 32);

  //  Add to Queue for File Printing
  sprintf(str, "ldr   %s, %s", rtop, constants.at(_const-1).get_identifier());
  add_command(str);

  //  Deallocate Strings
  free(str);
  free(rtop);

  //  Return Success
  return 0;
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
  for (vector<FunctionNode>::iterator iter = functions.begin(); iter != functions.end(); ++iter )
    if (strcmp((*iter).get_identifier(), ident) == 0) 
    {
      found = true;
      free(ident);

      return (*iter).get_ID();
    }

  return (FunctionID) NULL;
}

ErrorCode resolve_function (FunctionID _funct)
{

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  
  /*
    TODO: Function Call Precursor Actions HERE

      * Prepare the current scope for a context shift
      * Load Arguments if necessary
  */

  //  Add to Queue for File Printing
  sprintf(str, "bl __%lu_%s", functions[_funct-1].get_ID(), functions[_funct-1].get_identifier());
  add_command(str);
  
  //  Deallocate Strings
  free(str);

  //  Return Success
  return 0;
}


/* 3.) Find Functional Parameter

  Returns:
    0, if identifier is not a Parameter
    i, if identifier is Parameter, where 'i' is index in Parameter Buffer
*/
bool resolve_parameter(Identifier ident)
{
  /*
    FunctionNodes are checked for qualified parameter in the following order:
      * Current Function Scope
      * Parent Function Scope
      * Recursive Parent Checks until Scope 0 (Root) is hit
  */
  if (functions.size() == 0) { return 0; }

  char* str = (char*) malloc(50);

  //  Check Current Function Scope
  for (vector<FunctionParameterNode>::iterator iter = functions.back().get_param().begin(); iter != functions.back().get_param().end(); ++iter)
    if (strcmp((*iter).get_identifier(), ident) == 0) 
    { 
      printf("Found Parameter: %s\n", (*iter).get_identifier());
      return true;
    }

  /*
    TODO:
     * Error Check
     * Search thru backend buffers
      - If Parameter is found, 
        + Return Buffer Index
      - If Not Found,
        + Return 0
  */

  free(str);

  return false;
}



/*
  2.) Functional Expressions
*/

/* 2.a) Execute Function

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


/* 2.b) Load Argument (Standard)

  Returns:
    0, if Successful
*/
ErrorCode load_argument(Scope scope)
{
  printf("Argument Loaded\n");
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  /*
    TODO:
     * If not immediately found,
      + Recursively search through parent context scopes
     * If reg is already currently active,
      + Push current contents of reg onto data stack
      + UNLESS, reg contents are getting moved to reg for function call
     * Load Expression into reg
  */

  return 0;
}

/* 2.c) Load Argument (Recursive)

  Returns:
    0, if Successful
*/
ErrorCode load_argument_rec()
{
  printf("Recursive Argument Loaded\n");

  /*
    TODO:
     * Error Check
  */

  /*
    TODO:
     * PLANNING/ARCHITECTURE REQUIRED
     * DO NOT PROCEEED
  */

  return 0;
}



/* 3.) Parameter Expression

  'Parameters' are arbitrary, named expressions used in function declarations

  Returns:
    0, if Successful
*/
ErrorCode exp_parameter(Identifier ident)
{
  printf("Parameter %s Invoked\n", ident);
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  //  Push Parameter to Register Stack
  ADR reg = rs_push(TYPE_ARBITRARY);

  //  TODO: Copy contents of Parameter to 'reg'

  free (ident);

  return 0;
}




#endif
