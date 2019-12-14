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
    2.a) Find Function w/o Parameters
    2.b) Find Function w/ Parameters
    2.c) Load Argument (Standard)
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

#include <xcs/asm/text.h>

#include "structs.h"


/*  
  1.) Find Constant
    * Returns ConstantID of the matched constant identifier
*/
ConstantID find_constant(Identifier ident)
{
  for (vector<ConstantNode>::iterator it = context.get_constants().begin(); it != context.get_constants().end(); it++)
  
  for (unsigned int i = 0; i < context.count_constants(); i++)
    if (strcmp(context.get_constant(i).get_identifier(), ident) == 0) 
    {
      found = true;
      free(ident);

      return context.get_constant(i).get_ID();
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
  sprintf(str, "ldr   %s, %s", rtop, context.get_constants().at(_const-1).get_identifier());
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


/* 2.c) Load Argument (Standard)

  Returns:
    0, if Successful
*/
ErrorCode load_argument(Scope scope)
{
  char* str = (char*) malloc(50);

  ADR adr = context.get_param_reg(scope, argt.size()-1);
  argt.pop_back();
  
  char* tgt = get_reg(adr, 32);
  char* src = get_reg(context.get_top(get_scope_curr()), 32);

  context.pop(get_scope_curr());
  sprintf(str, "mov   %s, %s", tgt, src);
  add_command(str);
      
  //  Deallocate Strings
  free(tgt); free(src);
  free(str);
  return 0;
}


/* 2.a) Find Function w/o Parameters

  Returns:
    0, if ident is not a Declared Function
    s, where 's' is the matching function's Context Scope ID
*/
FunctionID find_function (Identifier ident)
{
  for (unsigned long i = 0; i < context.count_functions(); i++)
    if (strcmp(context.get_function_identifier(i), ident) == 0) 
    {
      if (context.count_param(i) == argt.size())
      {
        found = true;
        free(ident);

        return i;
      }
    }


  return (FunctionID) NULL;
}


ErrorCode resolve_function (FunctionID fid)
{

  printf("Resolving Function: %s\n", context.get_function_identifier(fid));

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);

  //  If Arguments are waited to be loaded,
  //    Load into the called function
  while (argt.size() > 0) { load_argument(fid); }

  //  Add to Queue for File Printing
  sprintf(str, "bl __%lu_%s", fid, context.get_function_identifier(fid));
  add_command(str);

  //  Handle Return Registers after function call
  for (unsigned int i = 0; i < context.count_rtn(fid); i++)
  {
    if (context.is_active(get_scope_curr(), context.get_rtn(fid, i)))
    {
      rs_push(context.get_rtn_type(fid, i));

      char* top = get_reg(rs_top(), 32);
      char* rtn = get_reg(context.get_rtn(fid, i), 32);

      sprintf(str, "mov   %s, %s", top, rtn);
      add_command(str);

      free (top);
      free (rtn);
    }
    rs_push_reg(context.get_rtn_type(fid, i), context.get_rtn(fid, i));
  }
  
  //  Deallocate Strings
  free(str);

  args = 0;

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
  if (context.count_functions() < 2) { return 0; }

  char* str = (char*) malloc(50);

  FunctionNode fnode = context.get_last_function();

  for (unsigned int i = 0; i < fnode.count_param(); i++)
  {
    if (strcmp(fnode.get_param(i).get_identifier(), ident) == 0)
    { 
      printf("Resolving Parameter: %s\n", ident);
      rs_push(fnode.get_param_type(i));
      last_type = fnode.get_param_type(i);

      char* src = get_reg(fnode.get_param_reg(i), 32);
      char* rtop = get_reg(rs_top(), 32);

      sprintf(str, "mov   %s, %s", rtop, src);
      add_command(str);

      free(str);
      free (src);
      free(rtop);
      
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



#endif
