/*
  types.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Public Interface for Types Backend Infrastructure
*/

#ifndef XCS_TYPES_H
#define XCS_TYPES_H

//  Type Headers
#include "constructor.h"
#include "lists.h"
#include "tuples.h"
#include "typeclass.h"

//  Global Variables
extern char** ident_types;


int declare_type (char* name)
{
  printf("Type %s Declared\n", name);
}



#endif
