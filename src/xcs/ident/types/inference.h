/*
  Inference.h (Types)
  Cody Fagley
  Authored on   March 7, 2019
  Last Modified July 29, 2019
*/

/*
  Contains functionality for Expression Type Inferrence

  Table of Contents
  =================
  1.) Standard Operators
    1.a) Addition
    1.b) Subtraction
    1.c) Multiplication
    1.d) Division
    1.e) Modulus
  2.) Logical Operators
    2.a) Bitwise AND
    2.b) Bitwise OR
    2.c) Bitwise XOR
    2.d) Bitwise SHL
    2.e) Bitwise SHR
    2.f) Boolean AND
    2.g) Boolean OR
    2.h) Boolean XOR
  3.) Comparison Operators
    3.a) Less Than
    3.b) Less Than or Equal To
    3.c) Greater Than
    3.d) Greater Than or Equal To
    3.e) Equal To
    3.f) Not Equal To
  4.) List Operators
    4.a) Append
    4.b) List Constructor
  5.) Constructors
*/

#ifndef TYPES_INFERRENCE_H
#define TYPES_INFERRENCE_H

#include "../../primitives/primitives.h"
#include <xcs/regstack/utils.h>

/*
  1) Standard Operators
*/

/* 1.a) Addition

  Returns:
    0, if Successful
*/
int infer_addition()
{

  //  Check LHS/RHS Types
  TypeID rhsT = rs_top_type();
  TypeID lhsT = rs_sec_type();


  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_addition();

  return 0;
}

/* 1.b) Subtraction

  Returns:
    0, if Successful
*/
int infer_subtraction()
{
  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_subtraction();

  return 0;
}

/* 1.c) Multiplication

  Returns:
    0, if Successful
*/
int infer_multiplication()
{
  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_multiplication();

  return 0;
}

/* 1.d) Division

  Returns:
    0, if Successful
*/
int infer_division()
{

  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_division();

  return 0;
}

/* 1.e) Modulus

  Returns:
    0, if Successful
*/
int infer_modulus()
{

  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_modulo();

  return 0;
}


/*
  2.) Logical Operators
*/

/* 2.a) Bitwise AND

  Returns:
    0, if Successful
*/
int infer_bit_and()
{

  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>0 && lhsT<11) && (rhsT>0 && rhsT<11)) return bitwise_and();

  return 0;
}

/* 2.b) Bitwise OR

  Returns:
    0, if Successful
*/
int infer_bit_or()
{

  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>0 && lhsT<11) && (rhsT>0 && rhsT<11)) return bitwise_or();

  return 0;
}

/* 2.c) Bitwise XOR

  Returns:
    0, if Successful
*/
int infer_bit_xor()
{

  //  Check LHS/RHS Types
  TypeID lhsT = rs_sec_type();
  TypeID rhsT = rs_top_type();

  if ((lhsT>0 && lhsT<11) && (rhsT>0 && rhsT<11)) return bitwise_xor();

  return 0;
}

/* 2.d) Bitwise SHL

  Returns:
    0, if Successful
*/
int infer_bit_shl()
{
  //  STUB STUB STUB
  printf("Perform Bitwise SHL\n");

  return 0;
}

/* 2.e) Bitwise SHR

  Returns:
    0, if Successful
*/
int infer_bit_shr()
{
  //  STUB STUB STUB
  printf("Perform Bitwise SHR\n");

  return 0;
}

/*
  2.f) Boolean AND

  Returns:
    0, if Successful
*/
int infer_bool_and()
{
  boolean_and();

  return 0;
}

/*
  2.g) Boolean OR

  Returns:
    0, if Successful
*/
int infer_bool_or()
{
  boolean_or();

  return 0;
}

/*
  2.h) Boolean XOR

  Returns:
    0, if Successful
*/
int infer_bool_xor()
{
  boolean_xor();

  return 0;
}


/*
  3.) Comparison Operators
*/

/* 3.a) Less Than

  Returns:
    0, if Successful
*/
int infer_bool_lt()
{
  boolean_lt();

  return 0;
}

/* 3.b) Less Than or Equal To

  Returns:
    0, if Successful
*/
int infer_bool_lte()
{
  boolean_lte();

  return 0;
}

/* 3.c) Greater Than

  Returns:
    0, if Successful
*/
int infer_bool_gt()
{
  boolean_gt();

  return 0;
}

/* 3.d) Greater Than or Equal To

  Returns:
    0, if Successful
*/
int infer_bool_gte()
{
  boolean_gte();

  return 0;
}

/* 3.e) Equal To

  Returns:
    0, if Successful
*/
int infer_bool_eq()
{
  boolean_eq();

  return 0;
}

/* 3.f) Not Equal To

  Returns:
    0, if Successful
*/
int infer_bool_neq()
{
  boolean_neq();

  return 0;
}


/*
  4.) List Operators
*/

/* 4.a) Append

  Returns:
    0, if Successful
*/
int infer_append()
{
  //  STUB STUB STUB
  printf("Perform List Append\n");

  return 0;
}

/* 4.b) List Constructor

  Returns:
    0, if Successful
*/
int infer_list_con()
{
  //  STUB STUB STUB
  printf("Perform List Construction\n");

  return 0;
}

/*
  5.) Constructors
*/
ErrorCode infer_constructor(ConstructorID construct)
{
  /*
    STUB STUB STUB
  */

  //  Return Success
  return 0;
}

#endif