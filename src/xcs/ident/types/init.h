/*
  init.h
  Codeus Tech
  Authored on   December 18, 2019
  Last Modified December 18, 2019
*/

/*
  Contains code for initializing the XCSL Types Interface
*/

#ifndef TYPES_INIT_H
#define TYPES_INIT_H

#include <xcs/std/typedefs.h>
#include <xcs/std/typecodes.h>
#include <xcs/std/error.h>

#include <xcs/std/buffers.h>

#include "structs.h"

ErrorCode initialize_types()
{
  char* str = (char*) malloc(50);

  sprintf(str, "arbitrary"); context->add_type(TypeNode(str)); str = (char*) malloc(50);

  //  Add Integers
  sprintf(str, "int"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "Int"); context->add_constructor(str); str = (char*) malloc(50);

  sprintf(str, "i8"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "I8"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "u8"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "U8"); context->add_constructor(str); str = (char*) malloc(50);

  sprintf(str, "i16"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "I16"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "u16"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "U16"); context->add_constructor(str); str = (char*) malloc(50);

  sprintf(str, "i32"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "I32"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "u32"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "U32"); context->add_constructor(str); str = (char*) malloc(50);

  sprintf(str, "i64"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "I64"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "u64"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "U64"); context->add_constructor(str); str = (char*) malloc(50);


  // Add Real Numbers
  sprintf(str, "real"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "Real"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "float"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "Float"); context->add_constructor(str); str = (char*) malloc(50);
  sprintf(str, "double"); context->add_type(TypeNode(str)); str = (char*) malloc(50);
  sprintf(str, "Double"); context->add_constructor(str);  str = (char*) malloc(50);

  // Add Boolean Values
  sprintf(str, "boolean"); context->add_type(TypeNode(str));  str = (char*) malloc(50);
  sprintf(str, "Boolean"); context->add_constructor(str);  str = (char*) malloc(50);

  // Add Characters/Strings
  sprintf(str, "char"); context->add_type(TypeNode(str));  str = (char*) malloc(50);
  sprintf(str, "Char"); context->add_constructor(str);  str = (char*) malloc(50);
  sprintf(str, "string"); context->add_type(TypeNode(str));  str = (char*) malloc(50);
  sprintf(str, "String"); context->add_constructor(str);  str = (char*) malloc(50);

  printf("Check!\n");

  return SUCCESS;
}

#endif
