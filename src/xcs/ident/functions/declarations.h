/*
  declarations.h
  Cody Fagley
  Authored on       July 11, 2019
  Last Modified December 13, 2019
*/

/*
  Contains implementations for Functional Declarations.  

  This includes:
    * Constants
    * Functions
    * Parameters


  TABLE OF CONTENTS
  =================
  1.) Function Declarations
    1.a) Declare Function
    1.b) Return Function
    1.c) Undeclare Function
  2.) Parameter Declarations
    2.a) Declare Parameter
*/

#ifndef FUNCTIONS_DECLARATIONS_H
#define FUNCTIONS_DECLARATIONS_H

#include <xcs/std/typedefs.h>
#include <xcs/std/scope.h>
#include <xcs/std/buffers.h>

#include "structs.h"
#include <xcs/modules/structs.h>

/*
  1.) Constant Declarations
*/

/* 1.a) Declare Constant

  Returns:
    0, if Successful
*/

ErrorCode decl_constant(Identifier ident)
{
  //  Allocate Command Buffers
  char* str = (char*) malloc(256);
  char* size = (char*) malloc(10);

  ConstantNode cnst = ConstantNode(ident, last_type, last_data);

  //  'bytes' indicates the assembly size directive to be used
  int bytes;

  //  Determine bytes via data type
  if ((last_type > 2 && last_type < 5) || (last_type > 13 && last_type < 16)) bytes = 1;
  else if (last_type > 4 && last_type < 7) bytes = 2;
  else if (last_type > 6 && last_type < 9) bytes = 4;
  else if (last_type == 2 || (last_type > 8 && last_type < 11)) bytes = 8;
  

  //  Determine Size of Constant (Bytes)
  switch (bytes)
  {
    case 1: //  1-Byte Alignment
      sprintf(size, "byte");
      sprintf(str, "%s: .%s %lu", ident, size, (unsigned long) last_data);
      cnst.set_value((Arbitrary) (unsigned long) last_data);
      break;
    case 2: //  2-Byte Alignment
      sprintf(size, "hword");
      sprintf(str, "%s: .%s %lu", ident, size, (unsigned long) last_data);
      cnst.set_value((Arbitrary) (unsigned long) last_data);
      break;
    case 4: //  4-Byte Alignment
      sprintf(size, "word");
      sprintf(str, "%s: .%s %lu", ident, size, (unsigned long) last_data);
      cnst.set_value((Arbitrary) (unsigned long) last_data);
      break;
    case 8: //  8-Byte Alignment
      sprintf(size, "dword");
      sprintf(str, "%s: .%s %llu", ident, size, (unsigned long long) last_data);
      cnst.set_value((Arbitrary) (unsigned long long) last_data);
      break;
    default:  
      //  Invalid Attempt
      return 1;
  }
    
  //  Commit to .data Section
  asm_data.push_back(strdup(str));
  context->add_constant(cnst);

  /*
    TODO:
      * Initialize ConstantNode, as according to XCS Tech Spec
      * Ensure all data that needs to be pushed to data stack is so
  */
  //sprintf(str, "bl    __decl_const");
  //add_command(str);

  //  Free Local String Buffers
  free(str);
  free(size);
  free(ident);

  // Return Success
  return 0;
}


/*
  2.) Function Declarations
*/

/* 2.a) Declare Function

  Returns:
    0, if Successful
*/
ErrorCode decl_function (Identifier ident)
{
  std:: string funName ="Declared Function ";

  funName += ident;
  l.log("Debug","Debug", funName);
  
  //printf("Declared Function: %s\n", ident);

  FunctionNode fnode = FunctionNode(ident);

  fnode.set_parent(get_scope_curr());
  fnode.set_scope(get_scope_next());
  
  context->add_function(fnode);
  
  asm_text.push_back(list<string>());
  
  //  Print Function Identifier to Assembly File
  char* str = (char*) malloc(50);
  char reg[] = "x30";
  char stp[] = "[sp, #-16]!";
 
  char* str1 = (char*) malloc(50);
  sprintf(str, "\n__%u_%s:", context->count_functions()-1, context->get_function_identifier(context->count_functions()-1));
  add_command(str);

  sprintf(str1, "str %s, %s", reg, stp);
  add_command(str1);

  /*
    TODO:
      * Initialize ConstantNode, as according to XCS Tech Spec
      * Ensure all data that needs to be pushed to data stack is so
  
  sprintf(str, "bl    __decl_funct");
  add_command(str);*/

  free(str);
  free(str1);

  return 0;
}

/* 2.b) Return Function

  Returns:
    0, if Successful
*/
ErrorCode ret_function ()
{
  /* 
    TODO:
     * Error Check
     * If Function had Parameters,
      + Move Return Values into bottom of register stack
     * Set Current Scope to Parent Context Scope
  */

std:: string funName ="Declared Function ";

 
  l.log("Debug","Debug", "End of Function Reached");
   
 //printf("End of Function Reached\n");

  //printf("End of Function Declaration\n");

  for (unsigned int i = 0; i < ( context->count_ADRs(get_scope_curr()) - context->count_param(get_scope_curr()) ); i++)
  {
    ADR reg = context->get_from_top(get_scope_curr(), i);
    TypeID tid = context->get_from_top_type(get_scope_curr(), i);

    context->push_rtn(get_scope_curr(), tid, reg);
  }

  //  Return to Parent Context Scope
  char comm[9];
  char reg[] = "x30";
   // ldr x30, [sp], #4
  char stp[] = "[sp], #16";
  char* str1 = (char*) malloc(50);
  sprintf(str1, "ldr %s, %s", reg, stp);
  add_command(str1);
  sprintf(comm, "ret");
  add_command(comm);

  set_scope_curr( context->get_parent(get_scope_curr()) );

  free(str1);
  return 0;
}

/* 2.c) Undeclare Function

  Returns:
    0, if Successful
*/
ErrorCode undecl_function()
{
  /*
    TODO:+
     * Error Check
     * Reset Scope and Associated Metadata
      + Identifier Buffers
      + Type Buffers
      + etc.
  */
  scope_curr = context->get_parent(get_scope_curr());

  context->remove_last_function();

  //  Return Success
  return 0;
}




#endif
