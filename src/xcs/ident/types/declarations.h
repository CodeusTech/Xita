/*
  declarations.h (Types)
  Cody Fagley
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*/

/*
  Declaration functionality for handling data type/structure backend

  Table of Contents
  =================
  1.) Type Declarations
    1.a) Declare Type
    1.b) Declare Type Parameter
*/

#ifndef TYPES_DECLARATIONS_H
#define TYPES_DECLARATIONS_H


//  Linux headers
#include <string.h>
#include <cstdlib>

#include <xcs/std/structs.h>
#include <xcs/std/buffers.h>

#include "operations.h"

extern void yyerror(const char*);

/*
  1.) Type Declarations
*/

/* 1.a) Declare Type

  Returns:
    0, if Successful
*/
ErrorCode decl_type (char* ident)
{
  //  Aquire TypeID
  TypeID tid = get_next_tid() - 18;

  TypeNode new_type;

  new_type.type_ident = strdup(ident);
  new_type.type_id    = tid;  

  /*
    TODO:
      * Error Check
      * Detect and Adjust for situations where tid >= 255
        - Allocate and link to next group of types
  */

  /*
    Set initial Values && Allocate Memory
  */
  types.push_back(new_type);

  //  Free String Memory
  free(ident);

  //  Return Success
  return 0;
}

/* 1.b) Declare Type Parameter

  Returns:
    0, if Successful
*/
ErrorCode decl_type_param (Identifier ident)
{
  TypeID tid = get_curr_tid() - 18;
  types.back().param_type.push_back(strdup(ident));

  //  Free String Buffer
  free(ident);

  //  Return Success
  return 0;
}


/* 2.a) Declare Constructor

  Returns:
    0, if Successful
*/
ErrorCode decl_constructor (Identifier ident)
{
  TypeID tid = get_curr_tid() - 18;
  //  TODO: use sprintf or something to print ident to terminal
  if (find_constructor(ident)) yyerror("Constructor with that name already declared");


  ConstructorNode constructor;

  constructor.ident = strdup(ident);
  constructor.cid   = get_next_cid();

  types.back().constructors.push_back(constructor);

  //  Free Buffers
  free(ident);

  //  Return Success
  return 0;
}

#endif
