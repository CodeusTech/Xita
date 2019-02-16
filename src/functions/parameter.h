/*
  parameter.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Operations for Parameters
*/

#ifndef FUNCTIONS_PARAMETER_H
#define FUNCTIONS_PARAMETER_H

//  Global Variables
extern char** ident_parameters;


/*  Declares a Parameter
  Returns:
    0, if Successful
*/
int declare_parameter (char* name)
{
  printf("Parameter %s Declared\n", name);\
  return 0;
}


/*  Loads Argument into Function Call
  Returns:
    0, if Successful
*/
int load_argument()
{
  printf("Argument Loaded\n");

  return 0;
}


#endif
