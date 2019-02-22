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
  1.) Structures
    1.a) Compiler Buffers
  2.) Operations
    2.a) Declare Constructor
    2.b) Invoke Constructor
    2.c) Find Constructor
    2.d) Get Constructor Size
*/

#ifndef TYPES_CONSTRUCTOR_H
#define TYPES_CONSTRUCTOR_H

/*
  1.) Structures
*/

/*
  1.a) Compiler Buffers
*/
extern char** ident_constructors;
extern int* size_constructors;


/*
  2.) Operations
*/

/* 2.a) Declare Constructor

  Returns:
    0, if Successful
*/
int declare_constructor (char* name)
{
  printf("Constructor %s Declared\n", name);

  return 0;
}


/* 2.b) Invoke Constructor

  Returns:
    0, if Successful
*/
int invoke_constructor (char* name)
{
  printf("Constructor Invoked: %s\n", name);

  return 0;
}


/* 2.c) Find Constructor

  Returns:
    0, if identifier is not a Constructor
    i, if identifier is a constructor, where 'i' is the index in buffer
*/
int find_constructor (char* ident)
{
  printf("Found Constructor: %s\n", ident);

  return 0;
}


/* 2.d) Get Constructor Size

  Returns:
    0, if UNSUCCESSFUL
    s, if Successful, where 's' is size, in bytes, of Data Constructor
*/
int get_constructor_size()
{

  return 0;
}

#endif
