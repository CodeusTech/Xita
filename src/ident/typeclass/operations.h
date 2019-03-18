/*
  operations.h (Typeclasses)
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified March 8, 2019
*/

/*
  Contains functionality for typeclass identifiers

  Table of Contents
  =================
  1.) Declare Typeclass
  2.) Typeclass Expression
  3.) Find Typeclass
*/

#ifndef TYPECLASS_OPERATIONS_H
#define TYPECLASS_OPERATIONS_H

//  Global Variables
extern Identifier* ident_typeclasses;


/* 1.) Declare Typeclass

  Returns:
    0, if Successful
*/
ErrorCode decl_typeclass (Identifier ident)
{
  //  STUB STUB STUB
  printf("Typeclass %s Declared\n", ident);

  /*
    TODO:
     * Error Check
     * Add ident to Typeclass Buffers
     * Add Prototype Metadata to Buffers
  */

  //  Return Success
  return 0;
}


/* 2.) Typeclass Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_typeclass (Identifier ident)
{
  //  STUB STUB STUB
  printf("Typeclass Invoked: %s\n", ident);

  /*
    TODO:
     * Error Check
     * PLANNING/ARCHITECTURE REQUIRED
     * DO NOT PROCEED
  */

  //  Return Success
  return 0;
}


/* 3.) Find Typeclass

  Returns:
    0, if ident is not a Typeclass
    i, if ident is a Typeclass, where 'i' is the index in buffer
*/
TypeclassID find_typeclass (Identifier ident)
{
  //  STUB STUB STUB
  printf("Typeclass Found: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Search through Typeclass Buffers
      + If match is found, return ID
      + If no match found, return 0
  */

  //  Return Success
  return 0;
}


#endif

