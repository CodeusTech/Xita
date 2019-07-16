/*
  declarations.h (Types)
  Cody Fagley
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*/

/*
  Declaration functionality for handling data type/structure backend

  Table of Contents
  =================
  1.) Type Declarations
    1.a) Declare Type
    1.b) Declare Type Parameter
*/

#ifndef TYPES_DECLARATIONS_H
#define TYPES_DECLARATIONS_H

#include "operations.h"

/*
  1.) Type Declarations
*/

/* 1.a) Declare Type

  Returns:
    0, if Successful
*/
ErrorCode decl_type (char* ident)
{
  //  Aquire TypeID
  TypeID tid = get_next_tid() - 18;

  /*
    TODO:
      * Error Check
      * Detect and Adjust for situations where tid >= 255
        - Allocate and link to next group of types
  */

  /*
    Set initial Values && Allocate Memory
  */
  //  Types
  ident_types[tid] = strdup(ident);
  pcount_types[tid] = 0;
  param_types[tid] = (Identifier*) malloc (10 * sizeof(Identifier));

  //  Constructors
  count_construct[tid] = 0;
  ident_construct[tid] = (Identifier*) malloc (40 * sizeof(unsigned int));
  ident_elements[tid] = (Identifier**) malloc(256 * sizeof(Identifier*));
  type_elements[tid]  = (TypeID**) malloc(40 * sizeof(TypeID*));
  count_elements[tid] = (unsigned int*) malloc(40 * sizeof(unsigned int));

  //  Free String Memory
  free(ident);

  //  Return Success
  return 0;
}

/* 1.b) Declare Type Parameter

  Returns:
    0, if Successful
*/
ErrorCode decl_type_param (Identifier ident)
{
  //  Retrieve Current TypeID
  TypeID tid = get_curr_tid() - 18;

  /*
    TODO:
      * Error Check
      * Detect and Adjust for situations where pcount_types[tid] >= 9
        - Allocate and link to next group of type parameters
  */
  param_types[tid][pcount_types[tid]] = strdup(ident);

  //  Increment Parameter Count for this type
  pcount_types[tid]++;

  //  Free String Buffer
  free(ident);

  //  Return Success
  return 0;
}


/* 2.a) Declare Constructor

  Returns:
    0, if Successful
*/
ErrorCode decl_constructor (Identifier ident)
{
  //  Retrieve Current TypeID
  TypeID tid = get_curr_tid() - 18;
  unsigned int cid = count_construct[tid];

  //  Add Constructor to Type
  ident_construct[tid][cid] = ident;

  /* 
    Initialize Element Properties
  */
  count_elements[tid][cid] = 0;
  type_elements[tid][cid] = (TypeID*) malloc(40 * sizeof(TypeID));
  ident_elements[tid][cid] = (Identifier*) malloc(40 * sizeof(Identifier));


  //  Increment Number of Constructors for Current Type
  count_construct[tid]++;

  //  Return Success
  return 0;
}

#endif
