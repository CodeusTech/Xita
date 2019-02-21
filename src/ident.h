/*
  ident.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains Backend Functionality for Identifier Resolution

  Order of Resolution
  ===================
  * Parameter
  * Function
  * Constant


  Table of Contents
  =================
  1.) Resolve Identifier
    1.a) Check for Parameter
    1.b) Check for Function
    1.c) Check for Constant
*/

#ifndef XCS_IDENT_H
#define XCS_IDENT_H

#include "functions/functions.h"

#include "stdbool.h"

/*
  1.) Resolve Identifier

  Returns:
    0, if unable to resolve ident
    1, if ident is a Parameter
    2, if ident is a Function
    3, if ident is a Constant
*/
int resolve_identifier(char* ident)
{
  int rtn;

  //  1.a) Check for Parameter
  rtn = find_parameter(ident);
  if (rtn) { printf("Identifier is Parameter\n"); return 1; }


  //  1.b) Check for Function
  rtn = find_function(ident);
  if (rtn) { printf("Identifier is Function\n"); return 2; }

  
  //  1.c) Check for Constant
  rtn = find_constant(ident);
  if (rtn) { printf("Identifier is Constant\n"); return 3; }


  printf("Unable to resolve Identifier: %s\n", ident);
  return 0;
}



#endif
