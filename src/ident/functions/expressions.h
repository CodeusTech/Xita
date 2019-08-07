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
  2.) Functional Expressions
    2.a) Execute Function
    2.b) Load Argument (Standard)
    2.c) Load Argument (Recursive)
  3.) Parameter Expressions
*/


#ifndef FUNCTIONS_EXPRESSIONS_H
#define FUNCTIONS_EXPRESSIONS_H


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
  ADR reg = rs_push();

  //  TODO: Copy contents of Parameter to 'reg'

  free (ident);

  return 0;
}




#endif
