/*
  constant.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Operations for Constants

  Table of Contents
  =================
  1.) Declare Constant
  2.) Constant Expressions
  3.) Find Constant
*/

#ifndef FUNCTIONS_CONSTANTS_H
#define FUNCTIONS_CONSTANTS_H

extern char** ident_constants;


/* 1.) Declare Constant

  Returns:
    0, if Successful
*/
ErrorCode decl_constant(char* constant)
{
  //  STUB STUB STUB
  printf("Constant Declared: %s\n", constant);

  /*
    TODO:
     * Error Check
     * Statically Determine Constant Value
      + If cannot statically determine, Report Error
     * Record Constant into .bss Section
  */

  return 0;
}


/* 2.) Constant Expressions

  Returns:
    0, if Successful
*/
ErrorCode exp_constant(char* constant)
{
  //  STUB STUB STUB
  printf("Constant Invoked: %s\n", constant);

  /*
    TODO:
     * Error Check
  */

  //  Push to Register Stack
  ADR reg = rs_push();

  /*
    TODO:
      * Push Constant Type into Buffer Type Stack
      * Set Value of reg to Constant Value
  */

  return 0;
}


/* 3.) Find Constant

  Returns:
    0, if identifier is not constant
    i, if identifier is a constant, where 'i' is buffer index
*/
ConstantID find_constant(char* ident)
{
  //  STUB STUB STUB
  printf("Ident is (not) a constant: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Search Through Buffer of Constants for ident
      + If ident matches, return ID value
      + If No Ident matches, return 0
  */

  return 0;
}


#endif

