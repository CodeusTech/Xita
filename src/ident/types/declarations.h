/*
  declarations.h (Types)
  Cody Fagley
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*/

/*
  Declaration functionality for handling data type/structure backend
*/

#ifndef TYPES_DECLARATIONS_H
#define TYPES_DECLARATIONS_H

#include "operations.h"

/* 1.) Declare Type

  Returns:
    0, if Successful
*/
int decl_type (char* ident)
{
  //  Aquire TypeID
  TypeID tid = get_next_tid() - 18;

  /*
    TODO:
      * Error Check
      * Detect and Adjust for situations where tid >= 255
        - Allocate and link to next group of types
  */

  printf("check\n");

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
  ident_elements[tid] = (Identifier*) malloc(256 * sizeof(unsigned int));
  type_elements[tid]  = (TypeID*) malloc(40 * sizeof(TypeID));
  count_elements[tid] = (unsigned int*) malloc(40 * sizeof(unsigned int));





  free(ident);

  return 0;
}

/* 2.a) Declare Constructor

  Returns:
    0, if Successful
*/
ErrorCode decl_constructor (Constructor ident)
{
  //  STUB STUB STUB
  printf("Constructor Declared: %s \n", ident);

  /*
    TODO:
     * Error Check
     * Add ident to Buffers
     * Add type to Buffers
  */

  //  Return Success
  return 0;
}

#endif
