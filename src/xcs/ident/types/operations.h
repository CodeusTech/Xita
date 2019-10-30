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
  1.) Utility Operations
    1.a) Get Next TypeID
    1.b) Get Current TypeID
  2.) Type Operations
    2.a) Find Type

*/

#ifndef TYPES_OPERATIONS_H
#define TYPES_OPERATIONS_H

#include "../../std/typecodes.h"

/*
  1.) Utility Operations
*/

//  2.a) Get Next TypeID
TypeID get_next_tid(){ return next_type++; }
//  2.b) Get Current TypeID
TypeID get_curr_tid(){ return next_type - 1; }

ConstructorID get_next_cid() { return next_cid++; }


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
ConstructorID find_constructor (Identifier ident)
{ 

  /*
    First, handle primitive constructors
  */
  if (strcmp(ident, "Int") == 0) {
    last_type = TYPE_INTEGER;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 2; } else
  if (strcmp(ident, "U8") == 0) {
    last_type = TYPE_U8;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 3; } else
  if (strcmp(ident, "I8") == 0) {
    last_type = TYPE_I8;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 4; } else
  if (strcmp(ident, "U16") == 0) {
    last_type = TYPE_U16;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 5; } else
  if (strcmp(ident, "I16") == 0) {
    last_type = TYPE_I16;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 6; } else
  if (strcmp(ident, "U32") == 0) {
    last_type = TYPE_U32;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 7; } else
  if (strcmp(ident, "I32") == 0) {
    last_type = TYPE_I32;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 8; } else
  if (strcmp(ident, "U64") == 0) {
    last_type = TYPE_U64;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 9; } else
  if (strcmp(ident, "I64") == 0) {
    last_type = TYPE_I64;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 10; } else
  if (strcmp(ident, "Real") == 0) {
    last_type = TYPE_REAL;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 11; } else
  if (strcmp(ident, "Float") == 0) {
    last_type = TYPE_FLOAT;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 12; } else
  if (strcmp(ident, "Double") == 0) {
    last_type = TYPE_DOUBLE;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 13; } else
  if (strcmp(ident, "Boolean") == 0) {
    last_type = TYPE_BOOLEAN;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 14; } else
  if (strcmp(ident, "Char") == 0) {
    last_type = TYPE_CHAR;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 15; } else
  if (strcmp(ident, "String") == 0) {
    last_type = TYPE_STRING;
    (rs[scope_curr].rs_type).push_back(last_type);
    return 16; } 
  else 
  {
    for (vector<TypeNode>::iterator t = types.begin(); t != types.end(); t++)
    {
      for (vector<ConstructorNode>::iterator c = (*t).constructors.begin(); c != (*t).constructors.end(); c++)
      {
        if (strcmp(ident, (*c).ident) == 0) return (*c).cid;
      }
    }
  }


  //  Report: Constructor not Found
  return 0;
}


ErrorCode impl_typeclass(Identifier ident)
{
  //  STUB STUB STUB
  

  //  Free Buffers
  free(ident);

  //  Return Success
  return 0;
}


#endif
