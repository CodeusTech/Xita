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



/* 2.) Constant Expressions

  Returns:
    0, if Successful
*/
ErrorCode exp_constant(Identifier constant)
{
  //  STUB STUB STUB
  printf("Constant Invoked: %s\n", constant);

  /*
    TODO:
     * Error Check
  */

  //  Push to Register Stack
  //ADR reg = rs_push();

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
ConstantID find_constant(Identifier ident)
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

