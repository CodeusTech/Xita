/*
  operations.h (Types)
  Cody Fagley
  Authored on   February 19, 2019
  Last Modified February 19, 2019
*/

/*
  Contains structures/operations for types

  Table of Contents
  =================
  1.) Declare Type
  2.) Type Expression
  3.) Find Type
*/

#ifndef TYPES_OPERATIONS_H
#define TYPES_OPERATIONS_H

//  Global Variables
extern char** ident_types;





/* 3.) Find Type

  Returns:
    0, if ident is not a Type
    1, if ident is of Arbitrary Type
    i, if ident is a Type, where 'i' is index in Types Buffer
*/
int find_type (char* ident)
{
  printf("Type Found: %s\n", ident);

  return 0;
}



#endif
