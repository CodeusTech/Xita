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

extern void yyerror(const char*);

/*
  1.) Type Declarations
*/

/* 1.a) Declare Type

  Returns:
    0, if Successful
*/
ErrorCode decl_type (Identifier ident)
{
  //  Create new TypeNode
  TypeNode node = TypeNode(ident);

  //  Add to Buffers
  types.push_back(node);

  //  Return Success
  return 0;
}

ErrorCode decl_type_param(Identifier ident)
{
  types.back().add_parameter(ident);
}

ErrorCode decl_constructor(Identifier ident)
{
  types.back().add_constructor(ident);
}

#endif
