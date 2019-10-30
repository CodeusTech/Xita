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


/*
  _xcs_get_size ()

  This function returns the size (in bytes) of a given Type ID.

  Returns:
    0, if Error
*/
unsigned long _xcs_get_size(TypeID tid)
{
  switch (tid)
  {
    case TYPE_ARBITRARY:  //  VOID POINTER
      return 8;
    case TYPE_INTEGER:
      return 2;
    case TYPE_U8:
      return 1;
    case TYPE_I8:
      return 1;
    case TYPE_U16:
      return 2;
    case TYPE_I16:
      return 2;
    case TYPE_U32:
      return 4;
    case TYPE_I32:
      return 4;
    case TYPE_U64:
      return 8;
    case TYPE_I64:
      return 8;
    case TYPE_REAL:
      return 10;
    case TYPE_FLOAT:
      return 10;
    case TYPE_DOUBLE:
      return 16;
    case TYPE_BOOLEAN:
      return 1;
    case TYPE_CHAR:
      return 1;
    case TYPE_STRING:   //  POINTER
      return 8;      
    case TYPE_LIST:     //  POINTER
      return 8;
    default:
      /*
        TODO:
          * if tid > 17
            - if tid > (17 + count_types)  OR  if tid == 0
              + Report Error (tid Out of Bounds)
            - else
              + Find Type Size using Buffer
      */
      return 0; //  REPORT ERROR
  }
}

#endif
