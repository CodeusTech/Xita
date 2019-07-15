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

/* 1.) Declare Type

  Returns:
    0, if Successful
*/
int decl_type (char* ident)
{
  printf("Type %s Declared\n", ident);

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
