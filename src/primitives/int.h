/*
  int.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains primitive integer expressions
*/

#ifndef PRIMITIVES_INT_H
#define PRIMITIVES_INT_H


/* INTEGER ADDITION
  Adds TOP to SECOND register; TOP is deactivated
*/
int integer_addition()
{
  printf("Added top two registers on REGISTER STACK\n");

  return 0;
}

/* INTEGER SUBTRACTION
  Subtracts TOP from SECOND register; TOP is deactivated
*/
int integer_subtraction()
{
  printf("Subtracted top two registers on REGISTER STACK\n");

  return 0;
}

/* INTEGER MULTIPLICATION
  Multiplies TOP and SECOND register; TOP is deactivated
*/
int integer_multiplication()
{
  printf("Multiplied top two registers on REGISTER STACK\n");

  return 0;
}

/* INTEGER DIVISION
  Divides TOP from SECOND register; SECOND holds quotient; TOP is deactivated
*/
int integer_division()
{
  printf("Divided top two registers on REGISTER STACK\n");

  return 0;
}

/* INTEGER MODULUS
  Divides TOP from SECOND register; SECOND holds remainder; TOP is deactivated
*/
int integer_modulus()
{
  printf("Modulus'd top two registers on REGISTER STACK\n");

  return 0;
}

#endif
