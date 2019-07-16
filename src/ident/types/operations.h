/*
  operations.h (Types)
  Cody Fagley
  Authored on   February 19, 2019
  Last Modified     July 15, 2019
*/

/*
  Contains structures/operations for types

  Table of Contents
  =================
  1.) Compiler Buffers
    1.a) Types
    1.b) Constructors
    1.c) Initialize Type Buffers
  1.) Utility Operations
    1.a) Get Next TypeID
    1.b) Get Current TypeID
  2.) Type Operations
    2.a) Find Type

*/

#ifndef TYPES_OPERATIONS_H
#define TYPES_OPERATIONS_H

/*
  1.) Compiler Buffers
*/

//  1.a) Types
extern TypeID  next_type;
extern Identifier*  ident_types;
extern Identifier** param_types;
extern unsigned int* pcount_types;

//  1.b) Constructors
extern Identifier**   ident_construct;
extern unsigned int*  count_construct;
extern Identifier***  ident_elements;
extern TypeID***      type_elements;
extern unsigned int** count_elements;

/* 1.c) Initialize Type Buffers

  Allocates necessary memory to begin declaring types
*/
ErrorCode type_init()
{
  /*
    Allocate memory for buffers
  */
  //  Types
  ident_types = (Identifier*) malloc(256 * sizeof(Identifier));
  param_types = (Identifier**) malloc(256 * sizeof(Identifier));
  pcount_types = (unsigned int*) malloc(256 * sizeof(unsigned int));
  
  //  Constructors
  ident_construct = (Identifier**) malloc(256 * sizeof(Identifier*));
  count_construct = (unsigned int*) malloc(256 * sizeof(unsigned int));
  ident_elements = (Identifier***) malloc(256 * sizeof(Identifier**));
  type_elements = (TypeID***) malloc(256 * sizeof(TypeID**));
  count_elements = (unsigned int**) malloc(256 * sizeof(unsigned int*));


  //  Return Success
  return 0;
}

/*
  2.) Utility Operations
*/

//  2.a) Get Next TypeID
TypeID get_next_tid(){ return next_type++; }
//  2.b) Get Current TypeID
TypeID get_curr_tid(){ return next_type - 1; }


/*
  3.) Type Operations
*/

/* 3.a) Find Type

  Returns:
    0, if ident is not a Type
    1, if ident is of Arbitrary Type
    i, if ident is a Type, where 'i' is index in Types Buffer
*/
TypeID find_type (Identifier ident)
{
  printf("Type Found: %s\n", ident);

  return 0;
}

/* 3.b) Find Constructor

  Returns:
    0, if ident is not a Constructor
    tid, if ident is a declared constructor
      - tid is the declaring type's ID number
*/
TypeID find_constructor (Identifier ident)
{ 
  /*
    First, handle primitive constructors
  */
  if (strcmp(ident, "Int") == 0) {
    last_type = TYPE_INTEGER;
    rs_types[scope_curr][rs_top()] = TYPE_INTEGER;
    return 2; } else
  if (strcmp(ident, "U8") == 0) {
    last_type = TYPE_U8;
    rs_types[scope_curr][rs_top()] = TYPE_U8;
    return 3; } else
  if (strcmp(ident, "I8") == 0) {
    last_type = TYPE_I8;
    rs_types[scope_curr][rs_top()] = TYPE_I8;
    return 4; } else
  if (strcmp(ident, "U16") == 0) {
    last_type = TYPE_U16;
    rs_types[scope_curr][rs_top()] = TYPE_U16;
    return 5; } else
  if (strcmp(ident, "I16") == 0) {
    last_type = TYPE_I16;
    rs_types[scope_curr][rs_top()] = TYPE_I16;
    return 6; } else
  if (strcmp(ident, "U32") == 0) {
    last_type = TYPE_U32;
    rs_types[scope_curr][rs_top()] = TYPE_U32;
    return 7; } else
  if (strcmp(ident, "I32") == 0) {
    last_type = TYPE_I32;
    rs_types[scope_curr][rs_top()] = TYPE_I32;
    return 8; } else
  if (strcmp(ident, "U64") == 0) {
    last_type = TYPE_U64;
    rs_types[scope_curr][rs_top()] = TYPE_U64;
    return 9; } else
  if (strcmp(ident, "I64") == 0) {
    last_type = TYPE_I64;
    rs_types[scope_curr][rs_top()] = TYPE_I64;
    return 10; } else
  if (strcmp(ident, "Real") == 0) {
    last_type = TYPE_REAL;
    rs_types[scope_curr][rs_top()] = TYPE_REAL;
    return 11; } else
  if (strcmp(ident, "Float") == 0) {
    last_type = TYPE_FLOAT;
    rs_types[scope_curr][rs_top()] = TYPE_FLOAT;
    return 12; } else
  if (strcmp(ident, "Double") == 0) {
    last_type = TYPE_DOUBLE;
    rs_types[scope_curr][rs_top()] = TYPE_DOUBLE;
    return 13; } else
  if (strcmp(ident, "Boolean") == 0) {
    last_type = TYPE_BOOLEAN;
    rs_types[scope_curr][rs_top()] = TYPE_BOOLEAN;
    return 14; } else
  if (strcmp(ident, "Char") == 0) {
    last_type = TYPE_CHAR;
    rs_types[scope_curr][rs_top()] = TYPE_CHAR;
    return 15; } else
  if (strcmp(ident, "String") == 0) {
    last_type = TYPE_STRING;
    rs_types[scope_curr][rs_top()] = TYPE_STRING;
    return 16; } 


  //  Report: Constructor not Found
  return 0;
}

#endif
