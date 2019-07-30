/*
  declarations.h
  Cody Fagley
  Authored on   July 11, 2019
  Last Modified July 29, 2019
*/

/*
  Contains implementations for Functional Declarations.  

  This includes:
    * Functions
    * Parameters


  TABLE OF CONTENTS
  =================
  2.) Declare Function
*/

#ifndef FUNCTIONS_DECLARATIONS_H
#define FUNCTIONS_DECLARATIONS_H

#include "../../primitives/typecodes.h"
#include "../../utils/scope.h"

extern Identifier* ident_constants;
extern unsigned long long* index_asm_text;
extern unsigned long long* count_asm_text;


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

  //  Generate Register Stack for New Scope
  rs_init(s);

  list<string> new_comms;
  asm_text.push_back(new_comms);
  
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
