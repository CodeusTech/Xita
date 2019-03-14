/*
  operations.h (Constructors)
  Cody Fagley
  Authored on   March  8, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Backend Functionality for dealing with Constructor Identifiers

  Table of Contents
  =================
  1.) Structures
    1.a) Compiler Buffers
  2.) Operations
    2.a) Declare Constructor
    2.b) Constructor Expression
    2.c) Find Constructor
    2.d) Get Constructor Size
*/

#ifndef CONSTRUCT_OPERATIONS_H
#define CONSTRUCT_OPERATIONS_H

//  XCS Libraries
#include "../../memory/memory.h"
#include "../types/types.h"

//  Linux Libraries
#include "stdbool.h"

/*
  1.) Structures
*/

/*
  1.a) Compiler Buffers
*/
extern char** ident_construct;
extern unsigned int* size_construct;
extern unsigned int count_construct;


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


/* 2.c) Find Constructor

  Returns:
    0, if identifier is not a Constructor
    i, if identifier is a constructor, where 'i' is the index in buffer
*/
int construct_find (char* ident)
{
  printf("Found Constructor: %s\n", ident);

  for (int i = 0; i < count_construct; i++)
  {
    /*
      Search Buffer for Constructor Match with 'ident'

      If a match is found, report (i + 18) 
      
      NOTE: (1-17 are primitive codes)
    */
    if (true) return i + 18;
  }

  return 0;
}


/* 2.b) Constructor Expression

  Returns:
    0, if Successful
    1, if Constructor not Found
*/
int exp_constructor (char* ident)
{
  //  Check if Constructor is Declared
  int con_id = construct_find(ident);
  if (!con_id) return 1;


  return 0;
}


/* 2.d) Get Constructor Size

  Returns:
    0, if UNSUCCESSFUL
    s, if Successful, where 's' is size, in bytes, of Data Constructor
*/
unsigned int construct_size (char* ident)
{
  //  Find Key Number for Identifier
  unsigned int rtn = construct_find(ident);
  if (!rtn) return 0;

  //  Error Check

  return size_construct[rtn];
}




#endif
