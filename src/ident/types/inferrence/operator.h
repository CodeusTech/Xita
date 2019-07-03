/*
  operator.h (Type Inferrence)
  Cody Fagley
  Authored on   March 7, 2019
  Last Modified March 7, 2019
*/

/*
  Contains functionality for Operator Expression Type Inferrence

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
*/

#ifndef INFERRENCE_OPERATOR_H
#define INFERRENCE_OPERATOR_H

#include "../../../primitives/primitives.h"

/*
  1) Standard Operators
*/

/* 1.a) Addition

  Returns:
    0, if Successful
*/
int infer_addition()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_addition();

  return 0;
}

/* 1.b) Subtraction

  Returns:
    0, if Successful
*/
int infer_subtraction()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_subtraction();

  return 0;
}

/* 1.c) Multiplication

  Returns:
    0, if Successful
*/
int infer_multiplication()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_multiplication();

  return 0;
}

/* 1.d) Division

  Returns:
    0, if Successful
*/
int infer_division()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>1 && lhsT<11) && (rhsT>1 && rhsT<11)) return integer_division();

  return 0;
}

/* 1.e) Modulus

  Returns:
    0, if Successful
*/
int infer_modulus()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

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
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>0 && lhsT<11) && (rhsT>0 && rhsT<11)) return bitwise_and();

  return 0;
}

/* 2.b) Bitwise OR

  Returns:
    0, if Successful
*/
int infer_bit_or()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

  if ((lhsT>0 && lhsT<11) && (rhsT>0 && rhsT<11)) return bitwise_or();

  return 0;
}

/* 2.c) Bitwise XOR

  Returns:
    0, if Successful
*/
int infer_bit_xor()
{
  //  Pop from Register Stack
  rs_pop();

  //  Check LHS/RHS Types
  TypeID lhsT = rs_types[scope_curr][rs_second()];
  TypeID rhsT = rs_types[scope_curr][rs_top()];

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
  //  STUB STUB STUB
  printf("Perform Boolean AND\n");

  return 0;
}

/*
  2.g) Boolean OR

  Returns:
    0, if Successful
*/
int infer_bool_or()
{
  //  STUB STUB STUB
  printf("Perform Boolean Or\n");

  return 0;
}

/*
  2.h) Boolean XOR

  Returns:
    0, if Successful
*/
int infer_bool_xor()
{
  //  STUB STUB STUB
  printf("Perform Boolean XOR\n");

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
  //  STUB STUB STUB
  printf("Perform Less Than\n");

  return 0;
}

/* 3.b) Less Than or Equal To

  Returns:
    0, if Successful
*/
int infer_bool_lte()
{
  //  STUB STUB STUB
  printf("Perform Less Than or Equal To\n");

  return 0;
}

/* 3.c) Greater Than

  Returns:
    0, if Successful
*/
int infer_bool_gt()
{
  //  STUB STUB STUB
  printf("Perform Greater Than\n");

  return 0;
}

/* 3.d) Greater Than or Equal To

  Returns:
    0, if Successful
*/
int infer_bool_gte()
{
  //  STUB STUB STUB
  printf("Perform Greater Than or Equal To\n");

  return 0;
}

/* 3.e) Equal To

  Returns:
    0, if Successful
*/
int infer_bool_eq()
{
  //  STUB STUB STUB
  printf("Perform Equal To\n");

  return 0;
}

/* 3.f) Not Equal To

  Returns:
    0, if Successful
*/
int infer_bool_neq()
{
  //  STUB STUB STUB
  printf("Perform Not Equal To\n");

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

#endif
