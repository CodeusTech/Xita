/*
  typeclass.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Backend Typeclass Operations

  Table of Contents
  =================
  1.) Declare Typeclass
  2.) Invoke Typeclass
  3.) Find Typeclass
*/

#ifndef TYPES_TYPECLASS_H
#define TYPES_TYPECLASS_H

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


/* 2.) Invoke Typeclass

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
