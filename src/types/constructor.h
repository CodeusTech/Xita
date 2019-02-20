/*
  constructor.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Backend Constructor Infrastructure

  Table of Contents
  =================
  1.) Declare Constructor
  2.) Invoke Constructor
  3.) Find Constructor
*/

#ifndef TYPES_CONSTRUCTOR_H
#define TYPES_CONSTRUCTOR_H

extern char** ident_constructors;

/* 1.) Declare Constructor

  Returns:
    0, if Successful
*/
int declare_constructor (char* name)
{
  printf("Constructor %s Declared\n", name);

  return 0;
}


/* 2.) Invoke Constructor

  Returns:
    0, if Successful
*/
int invoke_constructor (char* name)
{
  printf("Constructor Invoked: %s\n", name);

  return 0;
}


/* 3.) Find Constructor

  Returns:
    0, if identifier is not a Constructor
    i, if identifier is a constructor, where 'i' is the index in buffer
*/
int find_constructor (char* ident)
{
  printf("Found Constructor: %s\n", ident);

  return 0;
}


#endif
