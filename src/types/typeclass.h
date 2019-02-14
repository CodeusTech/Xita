/*
  typeclass.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Backend Typeclass Operations
*/

#ifndef TYPES_TYPECLASS_H
#define TYPES_TYPECLASS_H

//  Global Variables
extern char** ident_typeclasses;


/*  Declares a Typeclass
  Returns:
    0, if Successful
*/
int declare_typeclass (char* name)
{
  printf("Typeclass %s Declared\n", name);\
  return 0;
}


#endif
