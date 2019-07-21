/*
  declarations.h
  Cody Fagley
  Authored on   July 11, 2019
  Last Modified July 11, 2019
*/

/*
  Contains implementations for Functional Declarations.  

  This includes:
    * Constants
    * Functions
    * Parameters


  TABLE OF CONTENTS
  =================
  1.) Declare Constant
  2.) Declare Function
*/

#ifndef FUNCTIONS_DECLARATIONS_H
#define FUNCTIONS_DECLARATIONS_H

#include "../../primitives/typecodes.h"
#include "../../utils/scope.h"

extern Identifier* ident_constants;
extern unsigned long long* index_asm_text;
extern unsigned long long* count_asm_text;


/* 1.) Declare Constant

  Returns:
    0, if Successful
*/
ErrorCode decl_constant(Identifier ident)
{
  //  Retract last register stack push
  get_last_command();
  rs_pop();

  switch (last_type)
  {
    case TYPE_INTEGER:
      add_constant_int (ident, (int) last_data, 2);
      break;
    case TYPE_U8: 
      add_constant_int (ident, (unsigned char) last_data, 1);
      break;
    case TYPE_I8: 
      add_constant_int (ident, (char) last_data, 1);
      break;
    case TYPE_U16:
      add_constant_int (ident, (unsigned int) last_data, 2);
      break;
    case TYPE_I16:
      add_constant_int (ident, (int) last_data, 2);
      break;
    case TYPE_U32:
      add_constant_int (ident, (unsigned long) last_data, 4);
      break;
    case TYPE_I32:
      add_constant_int (ident, (long) last_data, 4);
      break;
    case TYPE_U64:
      add_constant_int (ident, (unsigned long long) last_data, 8);
      break;
    case TYPE_I64:
      add_constant_int (ident, (long long) last_data, 8);
      break;
    //  FLOAT, DOUBLE and REAL values go here
    case TYPE_BOOLEAN:
      add_constant_int (ident, (bool) last_data, 1);
      break;
    case TYPE_CHAR:
      add_constant_int (ident, (unsigned char) last_data, 1);
      break;
    case TYPE_STRING:
      add_constant_str (ident, (char*) last_data);
      break;
  }

  return 0;
}

/*
  1.) Function Initialization
*/

/* 1.a) Declare Function

  Returns:
    0, if Successful
*/
ErrorCode decl_function (Identifier ident)
{
  /*
    TODO:
     * Error Check
     * Store Parent Context Scope 
  */

  //  Get New Context Scope
  Scope s = get_scope_next();

  curr_asm_text = (Command*) malloc (256*sizeof(Command));
  start_asm_text[s] = (Command*) curr_asm_text;
  count_asm_text[s] = 0;

  //  Generate Register Stack for New Scope
  rs_init(s);
  
  //  Print Function Identifier to Assembly File
  char comm[300];
  sprintf(comm, "\n%s:\n", ident);
  add_command(comm);

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



#endif
