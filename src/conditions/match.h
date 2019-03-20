/*
  match.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Includes Backend Functionality For match ... with ... Statements

  Table of Contents
  =================
  1.) Match ...
    1.a) Declare Match Statement
    1.b) Match Expression
  2.) With ...
    2.a) Declare With Statement
    2.b) With Expression
  3.) Case Statements
    3.a) Declare Case Statement
  4.) Finalize match ... with ...
*/

#ifndef CONDITIONS_MATCH_H
#define CONDITIONS_MATCH_H

extern unsigned int mangle;

/*
  1.) Match ...
*/

/* 1.a) Declare Match Statement

  Returns:
    0, if Successful
*/
int decl_match()
{
  //  STUB STUB STUB
  printf("match ... \n");
  
  //  Mangled match in Assembly File
  char* str = (char*) malloc(20);
  sprintf(str, "match_%d:", mangle);

  //  Print str to Assembly File
  add_command(str);

  return 0;
}

/* 1.b) Match Expression

  Returns:
    0, if Successful
*/
int exp_match()
{
  // STUB STUB STUB

  //  TODO:  Error Check

  //  Prepare parameter metadata

  return 0;
}


/*
  2.) With ...
*/

/* 2.a) Declare With Statement

  Returns:
    0, if Successful
*/
int decl_with()
{
  printf("with ... ");
  
  /*
    TODO:
     * Error Check
  */

  return 0;
}

/* 2.b) With Expression

  Returns:
    0, if Successful
*/
int exp_with()
{
  //  STUB STUB STUB

  //  TODO:  Error Check

/*
   * Reset match Buffers
   * Prepare to Accept Arbitrary # of Case Arguments
*/

  return 0;
}


/*
  3.) Case Statements
*/

/* 3.a) Declare Case Statement

  Returns:
    0, if Successful
*/
int decl_case()
{
  //  STUB STUB STUB

  /*
    For Each Case Argument:
      * Check Type
      * Check Constructor/Literal
  */

  return 0;
}


/* 4.) Finalize match ... with ...

*/
int exp_match_with()
{
  printf("Statement Invoked\n");
  
  /*
    TODO:
     * Error Check
     * 
  */

  mangle++;

  return 0;
}


#endif

