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




/* 2.b) Load Argument (Standard)

  Returns:
    0, if Successful
*/
ErrorCode load_argument(Scope scope)
{
  char* str = (char*) malloc(50);

  ADR adr = functions[scope-1].get_param()[--xcs_argc].get_reg();
  char* tgt = get_reg(adr, 32);
  char* src;

  
  printf("woot\n");

  switch (get_scope_curr())
  {
    case 0:
      //  Move from current scope's stack to function argument registers 'tgt'
      src = get_reg(rs_root.top(), 32);
      rs_root.pop();
      sprintf(str, "mov   %s, %s", tgt, src);
      add_command(str);
      break;
    default:
      src = get_reg(functions[get_scope_curr()-1].get_top(), 32);
      functions[get_scope_curr()-1].pop();
  }
      
  //  Deallocate Strings
  free(tgt); free(src);
  free(str);
  return 0;
}


ErrorCode resolve_function (FunctionID _funct)
{

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);

  while (xcs_argc > 0) { load_argument(_funct); }

  //  Add to Queue for File Printing
  sprintf(str, "bl __%lu_%s", functions[_funct-1].get_ID(), functions[_funct-1].get_identifier());
  add_command(str);
  
  //  Deallocate Strings
  free(str);

  xcs_args = 0;

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
  for (vector<FunctionParameterNode>::iterator iter = functions.back().get_param().begin(); iter != functions.back().get_param().end(); iter++)
  {
    if (strcmp((*iter).get_identifier(), ident) == 0) 
    { 
      printf("Found Parameter: %s\n", (*iter).get_identifier());
      free(str);
      return true;
    }
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
