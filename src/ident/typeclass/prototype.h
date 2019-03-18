/*
  prototype.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified    March  8, 2019
*/

/*
  Contains backend functionality for typeclass prototypes

  Table of Contents
  =================
  1.) Declare Prototype
  2.) Declare Prototype Parameter
*/

#ifndef TYPECLASS_PROTOTYPE_H
#define TYPECLASS_PROTOTYPE_H


/* 1.) Declare Prototype

  Returns:
    0, if Successful
*/
ErrorCode decl_proto(Identifier ident)
{
  //  STUB STUB STUB
  printf("Prototype %s Declared, and requires parameters: ", ident);

  /*
    TODO:
     * Error Check
     * Add ident to Prototype Buffer
  */

  //  Return Success
  return 0;
}


/* 2.) Declare Prototype Parameter

  Returns:
    0, if Successful

*/
ErrorCode param_proto(Identifier ident)
{
  //  STUB STUB STUB
  printf("%s ", ident);

  /*
    TODO:
     * Error Check
     * Add ident to Prototype Parameter Buffer
  */

  //  Return Success
  return 0;
}

/* 3.) Find Prototype

  Returns:
    0, if ident is not a Prototype
    i, if ident is a prototype, where 'i' is the index in buffer
*/
PrototypeID find_proto(Identifier ident)
{
  //  STUB STUB STUB
  printf("Found Prototype: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Get Implementation Typeclass
     * Find Prototype Identifier by Typeclass
      + If Found, Return ID Number
      + If Not Found, Return 0
  */

  //  Return Failure
  return 0;
}

#endif

