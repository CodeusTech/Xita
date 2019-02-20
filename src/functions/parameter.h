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
    1.b) Invoke Parameter
    1.c) Find Parameter
  2.) Argument Operations
    2.a) Load Argument (Standard)
    2.b) Load Argument (Recursive)
*/

#ifndef FUNCTIONS_PARAMETER_H
#define FUNCTIONS_PARAMETER_H

//  Global Variables
extern char** ident_parameters;


/*
  1.) Parameter Operations
*/

/* 1.a) Declare Parameter

  Returns:
    0, if Successful
*/
int declare_parameter (char* name)
{
  printf("Parameter %s Declared\n", name);

  return 0;
}

/* 1.b) Invoke Parameter

  Returns:
    0, if Successful
*/
int invoke_parameter(char* name)
{
  printf("Parameter %s Invoked\n", name);

  return 0;
}

/* 1.c) Find Parameter

  Returns:
    0, if identifier is not a Parameter
    i, if identifier is Parameter, where 'i' is index in Parameter Buffer
*/
int find_parameter()
{
  printf("Parameter Found: %s\n");

  return 0;
}


/*
  2.) Argument Operations
*/

/* 2.a) Load Argument (Standard)

  Returns:
    0, if Successful
*/
int load_argument()
{
  printf("Argument Loaded\n");

  return 0;
}

/* 2.b) Load Argument (Recursive)

  Returns:
    0, if Successful
*/
int load_argument_rec()
{
  printf("Recursive Argument Loaded\n");

  return 0;
}


#endif
