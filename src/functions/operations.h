/*
  operations.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains Backend Function Operations

  Table of Contents
  =================
  1.) Declare Function
  2.) Invoke Function
  3.) Find Function
*/

#ifndef FUNCTIONS_OPERATIONS_H
#define FUNCTIONS_OPERATIONS_H


//  Global Variables
extern char** ident_functions;



/* 1.) Declare Function

  Returns:
    0, if Successful
*/
int declare_function (char* name)
{
  printf("Function %s Declared\n", name);
  return 0;
}


/* 2.) Invoke Function

  Returns:
    0, if Successful
*/
int invoke_function (char* name)
{
  printf("Function %s Invoked\n", name);

  return 0;
}


/* 3.) Find Function

  Returns:
    0, if identifier is not a Function
    i, if identifier is a function, where i is index in function buffer
*/
int find_function (char* ident)
{
  printf("Function Found: %s\n", ident);

  return 0;
}



#endif
