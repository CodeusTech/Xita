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

#include "expressions.h"

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
  context.add_type(node);

  char* str = (char*) malloc(270);
  sprintf(str, "bl    __decl_type");
  add_command(str);

  //  Return Success
  return 0;
}


/*
  decl_type_alias(tid)
    tid: Type ID #

    Allows type expression, referenced by 'tid', as valid constructor of type declaration

    Returns:
      0, if Successful
*/
ErrorCode decl_type_alias(TypeID tid)
{
  /*
    TODO: ERROR CHECK
  */
  context.get_last_type().add_alias(tid);
			printf("Check!!!\n");

  //  Return Success
  return 0;
}


/*
  decl_type_param(ident)
    ident: Identifier, representative of an arbitrary type expression

    Adds a type parameter of name 'ident' to the current type declaration

    returns:
      0, if Successful
*/
ErrorCode decl_type_param(Identifier ident)
{
  /*
    TODO: ERROR CHECK
  */
  context.get_last_type().add_parameter(ident);

  return 0;
}

/*
  decl_constructor(ident)
    ident: Capitalized Identifier, representative of type constructor

    Declares a constructor as part of the current type declaration

    returns:
      0, if Successful
*/
ErrorCode decl_constructor(Identifier ident)
{
  /*
    TODO: ERROR CHECK
  */
  context.add_constructor(ident);
  
  //  Return Success
  return 0;
}

/*
  decl_record(ident)
    ident: Identifier, representitive of a data structure's element name

    returns:
      0, if Successful
*/
ErrorCode decl_record(Identifier ident)
{
  //printf("Added Record: %s\n", ident);
  
  context.add_record(ident, last_type);

  //  Return Success
  return 0;
}


#endif
