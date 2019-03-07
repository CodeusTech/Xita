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
  2.) Invoke Constant
  3.) Find Constant
*/

#ifndef FUNCTIONS_CONSTANTS_H
#define FUNCTIONS_CONSTANTS_H

extern char** ident_constants;


/* 1.) Declare Constant

  Returns:
    0, if Successful
*/
int declare_constant(char* constant)
{
  printf("Constant Declared: %s\n", constant);

  return 0;
}


/* 2.) Invoke Constant

  Returns:
    0, if Successful
*/
int invoke_constant(char* constant)
{
  printf("Constant Invoked: %s\n", constant);

  return 0;
}


/* 3.) Find Constant

  Returns:
    0, if identifier is not constant
    i, if identifier is a constant, where 'i' is buffer index
*/
int find_constant(char* ident)
{
  printf("Ident is (not) a constant: %s\n", ident);

  return 0;
}




#endif
