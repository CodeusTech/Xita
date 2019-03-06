/*
  int.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains primitive integer expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) Integer Literals
    1.a) Pop Integer
    1.b) Push Integer Literal
  2.) Integer Arithmetic
    2.a) Integer Addition
    2.b) Integer Subtraction
    2.c) Integer Multiplication
    2.d) Integer Division
    2.e) Integer Modulus
  3.) Bitwise Arithmetic
    3.a) Bitwise Shift Left
    3.b) Bitwise Shift Right
    

*/

#ifndef PRIMITIVES_INTEXP_H
#define PRIMITIVES_INTEXP_H

/*
  1.) Integer Literals
*/

/* 1.a) Pop Integer Literal

  Returns:
    0, if Successful
*/
int pop_int()
{
  //  STUB STUB STUB
  printf("Integer Popped from Register Stack\n");

  return 0;
}

/* 1.b) Push Integer Literal

  Returns:
    0, if Successful
*/
int push_int_lit(int literal)
{
  //  STUB STUB STUB
  printf("Integer Literal Pushed to Register Stack: %d\n", literal);

  return 0;
}

/* 1.c) Push Integer Identifier

  Returns:
    0, if Successful
*/
int push_int_ident(char* ident)
{
  //  STUB STUB STUB
  printf("Integer Identifier Pushed to Register Stack: %s\n", ident);

  return 0;
}


/*
  2.) Integer Arithmetic
*/

/* 2.a) Integer Addition
  Adds TOP to NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_addition()
{
  printf("Added top two registers on REGISTER STACK\n");

  return 0;
}

/* 2.b) Integer Subtraction
  Subtracts TOP from NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_subtraction()
{
  printf("Subtracted top two registers on REGISTER STACK\n");

  return 0;
}

/* 2.c) Integer Multiplication
  Multiplies TOP and NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_multiplication()
{
  printf("Multiplied top two registers on REGISTER STACK\n");

  return 0;
}

/* 2.d) Integer Division
  Divides TOP from NEXT register; NEXT holds quotient; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_division()
{
  printf("Divided top two registers on REGISTER STACK\n");

  return 0;
}

/* 2.e) Integer Modulus
  Divides TOP from NEXT register; NEXT holds remainder; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_modulus()
{
  printf("Modulus'd top two registers on REGISTER STACK\n");

  return 0;
}

/*
  3.) Bitwise Arithmetic
*/

/* 3.a) Bitwise Shift Left
  Shifts NEXT register's bits left by TOP places

  Returns:
    0, if Succcessful
*/
int bitwise_shl()
{
  printf("Bitwise Shift Left\n");

  return 0;
}

/* 3.b) Bitwise Shift Right
  Shifts NEXT register's bits right by TOP places

  Returns:
    0, if Succcessful
*/
int bitwise_shr()
{
  printf("Bitwise Shift Right\n");

  return 0;
}

/* 3.c) Bitwise And
  Performs bitwise and from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_and()
{
  printf("Bitwise And\n");

  return 0;
}

/* 3.d) Bitwise Or
  Performs bitwise or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_or()
{
  printf("Bitwise Or\n");

  return 0;
}

/* 3.e) Bitwise Xor
  Performs bitwise exclusive or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_xor()
{
  printf("Bitwise Exclusive Or\n");

  return 0;
}

#endif
