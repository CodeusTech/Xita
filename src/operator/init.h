/*
  init.h (Operators)
  Cody Fagley
  Authored on   March 7, 2019
  Last Modified March 7, 2019
*/

/*
  Operator Initialization

  Table of Contents
  =================
  1.) Definitions/Structures
    1.a) Operand Pairs
  2.) Standard Operands
    2.a) Addition
    2.b) Subtraction
    2.c) Multiplication
    2.d) Division
    2.e) Modulus
  3.) Logical Operands
    3.a) Bitwise AND
    3.b) Bitwise OR
    3.c) Bitwise XOR
    3.d) Bitwise SHL
    3.e) Bitwise SHR
    3.f) Boolean AND
    3.g) Boolean OR
    3.h) Boolean XOR
  4.) Comparison Operands
    4.a) Less Than
    4.b) Less Than or Equal To
    4.c) Greater Than
    4.d) Greater Than or Equal To
    4.e) Equal To
    4.f) Not Equal To
  5.) List Operands
    5.a) Append
    5.b) List Constructor
  9.) Initialize XCS Operator LHS/RHS Operands
*/

#ifndef OPERATOR_VALIDATION_H
#define OPERATOR_VALIDATION_H

/*
  1.) Definitions/Structures
*/
#include "../globals/structs.h"

/*
  2.) Standard Operands
*/

/*
  2.a) Addition
*/

extern operands* operands_add;

/*  Initialize Addition Operands
  
  Returns:
    0, if Successful
*/
int init_operands_add()
{
  // STUB STUB STUB

  return 0;
}

/*
  2.b) Subtraction
*/

extern operands* operands_sub;

/*  Initialize Subtraction Operands
  
  Returns:
    0, if Successful
*/
int init_operands_sub()
{
  // STUB STUB STUB

  return 0;
}

/*
  2.c) Multiplication
*/

extern operands* operands_mul;

/*  Initialize Multiplication Operands
  
  Returns:
    0, if Successful
*/
int init_operands_mul()
{
  // STUB STUB STUB

  return 0;
}

/*
  2.d) Division
*/

extern operands* operands_div;

/*  Initialize Division Operands
  
  Returns:
    0, if Successful
*/
int init_operands_div()
{
  // STUB STUB STUB

  return 0;
}

/*
  2.e) Modulus
*/

extern operands* operands_mod;

/*  Initialize Modulus Operands
  
  Returns:
    0, if Successful
*/
int init_operands_mod()
{
  // STUB STUB STUB

  return 0;
}


/*
  3.) Logical Operands
*/

/*
  3.a) Bitwise AND
*/

extern operands* operands_bit_and;

/*  Initialize Bitwise AND Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bit_and()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.b) Bitwise OR
*/

extern operands* operands_bit_or;

/*  Initialize Bitwise OR Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bit_or()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.c) Bitwise XOR
*/

extern operands* operands_bit_xor;

/*  Initialize Bitwise XOR Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bit_xor()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.d) Bitwise SHL
*/

extern operands* operands_bit_shl;

/*  Initialize Bitwise SHL Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bit_shl()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.e) Bitwise SHR
*/

extern operands* operands_bit_shr;

/*  Initialize Bitwise SHR Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bit_shr()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.f) Boolean AND
*/

extern operands* operands_bool_and;

/*  Initialize Boolean AND Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bool_and()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.g) Boolean OR
*/

extern operands* operands_bool_or;

/*  Initialize Boolean OR Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bool_or()
{
  // STUB STUB STUB

  return 0;
}

/*
  3.h) Boolean XOR
*/

extern operands* operands_bool_xor;

/*  Initialize Boolean XOR Operands
  
  Returns:
    0, if Successful
*/
int init_operands_bool_xor()
{
  // STUB STUB STUB

  return 0;
}


/*
  4.) Comparison Operands
*/

/*
  4.a) Less Than
*/

extern operands* operands_lt;

/* Initialize Less Than Operands

  Returns:
    0, if Successful
*/
int init_operands_lt()
{
  // STUB STUB STUB

  return 0;
}

/*
  4.b) Less Than or Equal To
*/

extern operands* operands_lte;

/* Initialize Less Than or Equal To Operands

  Returns:
    0, if Successful
*/
int init_operands_lte()
{
  // STUB STUB STUB

  return 0;
}

/*
  4.c) Greater Than
*/

extern operands* operands_gt;

/* Initialize Greater Than Operands

  Returns:
    0, if Successful
*/
int init_operands_gt()
{
  // STUB STUB STUB

  return 0;
}

/*
  4.d) Greater Than or Equal To
*/

extern operands* operands_gte;

/* Initialize Greater Than or Equal To Operands

  Returns:
    0, if Successful
*/
int init_operands_gte()
{
  // STUB STUB STUB

  return 0;
}

/*
  4.e) Equal To
*/

extern operands* operands_eq;

/* Initialize Equal To Operands

  Returns:
    0, if Successful
*/
int init_operands_eq()
{
  // STUB STUB STUB

  return 0;
}

/*
  4.f) Not Equal To
*/

extern operands* operands_neq;

/* Initialize Not Equal To Operands

  Returns:
    0, if Successful
*/
int init_operands_neq()
{
  // STUB STUB STUB

  return 0;
}


/*
  5.) List Operands
*/

/*
  5.a) Append
*/

extern operands* operands_append;

/* Initialize Append Operands

  Returns:
    0, if Successful
*/
int init_operands_append()
{
  // STUB STUB STUB

  return 0;
}

/*
  5.b) List Constructor
*/

extern operands* operands_list_con;

/* Initialize Append Operands

  Returns:
    0, if Successful
*/
int init_operands_list_con()
{
  // STUB STUB STUB

  return 0;
}


/*
  9.) Initialize XCS Operator LHS/RHS Operands
*/

int init_operands()
{
  // Standard Operands
  init_operands_add();
  init_operands_sub();
  init_operands_mul();
  init_operands_div();
  init_operands_mod();

  // Logical Operands
  init_operands_bit_and();
  init_operands_bit_or();
  init_operands_bit_xor();
  init_operands_bit_shl();
  init_operands_bit_shr();
  init_operands_bool_and();
  init_operands_bool_or();
  init_operands_bool_xor();

  // Comparison Operands
  init_operands_lt();
  init_operands_lte();
  init_operands_gt();
  init_operands_gte();
  init_operands_eq();
  init_operands_neq();

  // List Operands
  init_operands_append();
  init_operands_list_con();
}


#endif
