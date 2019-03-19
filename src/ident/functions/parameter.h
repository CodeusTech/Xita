/*
  parameter.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Operations for Parameters/Arguments

  Definitions
  ===========
  A PARAMETER is an arbitrary identifier for use in function declarations
  An ARGUMENT is a specific expression for use in functional expressions


  Table of Contents
  =================
  1.) Parameter Operations
    1.a) Declare Parameter
    1.b) Parameter Expression
    1.c) Find Parameter
  2.) Argument Operations
    2.a) Load Argument (Standard)
    2.b) Load Argument (Recursive)
*/

#ifndef FUNCTIONS_PARAMETER_H
#define FUNCTIONS_PARAMETER_H

//  Global Variables
extern char*** param_funct;


/*
  1.) Parameter Operations
*/

/* 1.a) Declare Parameter

  Returns:
    0, if Successful
*/
ErrorCode decl_parameter (char* name)
{
  printf("Parameter %s Declared\n", name);
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  //  Push Parameter to Register Stack
  ADR reg = rs_push();
  //pnum_funct[scope_curr]++;

  //  TODO: Add Parameter Type to Backend Buffers

  return 0;
}

/* 1.b) Parameter Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_parameter(char* name)
{
  printf("Parameter %s Invoked\n", name);
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  //  Push Parameter to Register Stack
  ADR reg = rs_push();

  //  TODO: Copy contents of Parameter to 'reg'

  return 0;
}

/* 1.c) Find Parameter

  Returns:
    0, if identifier is not a Parameter
    i, if identifier is Parameter, where 'i' is index in Parameter Buffer
*/
ADR find_parameter(char* ident)
{
  printf("Parameter Found: %s\n", ident);
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search thru backend buffers
      - If Parameter is found, 
        + Return Buffer Index
      - If Not Found,
        + Return 0
  */

  return 0;
}


/*
  2.) Argument Operations
*/

/* 2.a) Load Argument (Standard)

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

/* 2.b) Load Argument (Recursive)

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


#endif
