/*
  typecodes.h
  Cody Fagley
  Authored on   March 6, 2019
  Last Modified March 6, 2019
*/

/*
  Contains Primitive Identifier Codes for Type Inferrence

  Table of Contents
  =================
  1.) Total Number of Primitive Types
  2.) Integer Primitives
  3.) Real Primitives
  4.) Boolean Primitives
  5.) Character Primitives
  6.) String Primitives
  7.) List Primitives
*/

#ifndef PRIMITIVES_TYPECODES_H
#define PRIMITIVES_TYPECODES_H


/*
  1.) Total Number of Primitive Types
*/
#define NUM_PRIMITIVES 17

#define TYPE_ARBITRARY 1

/*
  2.) Integer Primitives
*/
#define TYPE_INTEGER   2
#define TYPE_U8        3
#define TYPE_I8        4
#define TYPE_U16       5
#define TYPE_I16       6
#define TYPE_U32       7
#define TYPE_I32       8
#define TYPE_U64       9
#define TYPE_I64      10


/*
  3.) Real Primitives
*/
#define TYPE_REAL     11
#define TYPE_FLOAT    12
#define TYPE_DOUBLE   13


/*
  4.) Boolean Primitives
*/
#define TYPE_BOOLEAN  14


/*
  5.) Character Primitives
*/
#define TYPE_CHAR     15


/*
  6.) String Primitives
*/
#define TYPE_STRING   16


/*
  7.) List Primitives
*/
#define TYPE_LIST     17


#endif
