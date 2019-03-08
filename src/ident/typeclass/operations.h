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
extern char** ident_typeclasses;


/* 1.) Declare Typeclass

  Returns:
    0, if Successful
*/
int declare_typeclass (char* ident)
{
  printf("Typeclass %s Declared\n", ident);\

  return 0;
}


/* 2.) Typeclass Expression

  Returns:
    0, if Successful
*/
int invoke_typeclass (char* ident)
{
  printf("Typeclass Invoked: %s\n", ident);

  return 0;
}


/* 3.) Find Typeclass

  Returns:
    0, if ident is not a Typeclass
    i, if ident is a Typeclass, where 'i' is the index in buffer
*/
int find_typeclass (char* ident)
{
  printf("Typeclass Found: %s\n", ident);

  return 0;
}


#endif
