/*
  declarations.h
  Cody Fagley
  Authored on     July 11, 2019
  Last Modified August  7, 2019
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

#include "../../primitives/typecodes.h"
#include "../../utils/scope.h"

extern Identifier* ident_constants;
extern unsigned long long* index_asm_text;
extern unsigned long long* count_asm_text;



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

  node_constant cnst;
  cnst.const_ident = strdup(ident);
  cnst.const_type  = last_type;

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
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 2: //  2-Byte Alignment
      sprintf(size, "hword");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 4: //  4-Byte Alignment
      sprintf(size, "word");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 8: //  8-Byte Alignment
      sprintf(size, "dword");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    default:  
      //  Invalid Attempt
      return 1;
  }
    
  //  Commit to .data Section
  asm_data.push_back(strdup(str));
  constants.push_back(cnst);

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

  free(ident);

  return 0;
}

/* 2.b) Return Function

  Returns:
    0, if Successful
*/
ErrorCode ret_function ()
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

/* 2.c) Undeclare Function

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


/* 
  3.) Parameter Declarations
*/

/* 3.a) Declare Parameter

  Returns:
    0, if Successful
*/
ErrorCode decl_parameter (Identifier name)
{
  printf("Parameter %s Declared\n", name);
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  //  Push Parameter to Register Stack
  //ADR reg = rs_push();
  //pnum_funct[scope_curr]++;

  //  TODO: Add Parameter Type to Backend Buffers

  return 0;
}



#endif
