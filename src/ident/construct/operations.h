/*
  operations.h (Constructors)
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified March 8, 2019
*/

/*
  Contains Backend Functionality for dealing with Constructor Identifiers

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

#ifndef CONSTRUCT_OPERATIONS_H
#define CONSTRUCT_OPERATIONS_H

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
int decl_constructor (char* ident)
{
  printf("Constructor Declared: %s \n", ident);

  return 0;
}


/* 2.b) Constructor Expression

  Returns:
    0, if Successful
*/
int exp_constructor (char* ident)
{
  printf("Constructor Evaluated: %s\n", ident);

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
