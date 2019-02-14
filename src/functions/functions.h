/*
  functions.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Operations for Functions
*/

#ifndef XCS_FUNCTIONS_H
#define XCS_FUNCTIONS_H

extern char** ident_functions;

//  Function Headers
#include "constant.h"
#include "parameter.h"

//  Global Variables
extern char** ident_functions;


/*  Declares a Function
  Returns:
    0, if Successful
*/
int declare_function (char* name)
{
  printf("Function %s Declared\n", name);\
  return 0;
}



#endif
