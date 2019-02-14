/*
  operations.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains Backend Function Operations
*/

#ifndef FUNCTIONS_OPERATIONS_H
#define FUNCTIONS_OPERATIONS_H


//  Global Variables
extern char** ident_functions;



/*  Declares a Function
  Returns:
    0, if Successful
*/
int declare_function (char* name)
{
  printf("Function %s Declared\n", name);
  return 0;
}


int invoke_function (char* name)
{
  printf("Function %s Invoked\n", name);

  return 0;
}



#endif
