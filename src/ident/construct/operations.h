/*
  operations.h (Constructors)
  Cody Fagley
  Authored on   March  8, 2019
  Last Modified  July 15, 2019
*/

/*
  Contains Backend Functionality for dealing with Constructor Identifiers

  Table of Contents
  =================
  1.) Structures
    1.a) Compiler Buffers
  2.) Operations
    2.b) Find Constructor
    2.c) Constructor Expression
*/

#ifndef CONSTRUCT_OPERATIONS_H
#define CONSTRUCT_OPERATIONS_H

//  XCS Libraries
#include "../types/types.h"

//  Linux Libraries
#include "stdbool.h"

/*
  1.) Structures
*/

/*
  1.a) Compiler Buffers
*/
extern Identifier** ident_construct;
extern unsigned int* size_construct;
extern unsigned int count_types;
extern unsigned int* count_construct;


/*
  2.) Operations
*/

/* 2.b) Find Constructor

  Returns:
    0, if identifier is not a Constructor
    else, returns Constructor ID
*/
ConstructorID construct_find (Constructor ident)
{
  printf("Found Constructor: %s\n", ident);

  for (int i = 0; i < (next_type - 18); i++)
  {
    for (int j = 0; j < count_construct[i]; j++)
    {
      /*
        Search Buffer for Constructor Match with 'ident'

        If a match is found, report (i + 18) 
        
        NOTE: (1-17 are primitive codes)
      */
      if (true) return j + 18;
    }
  }
  
  return 0;
}

/* 2.c) Constructor Expression

  Returns:
    0, if Successful
    1, if Constructor not Found
*/
ErrorCode exp_constructor (Constructor ident)
{
  //  STUB STUB STUB
  printf("Constructor Invoked: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Push Constructor Expression
      + Push TypeID 
  */

  //  Check if Constructor is Declared
  int con_id = construct_find(ident);
  if (!con_id) return 1;


  return 0;
}


#endif
