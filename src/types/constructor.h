/*
  constructor.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Backend Constructor Infrastructure
*/

#ifndef TYPES_CONSTRUCTOR_H
#define TYPES_CONSTRUCTOR_H

extern char** ident_constructors;


int declare_constructor (char* name)
{
  printf("Constructor %s Declared\n", name);
  return 0;
}


#endif
