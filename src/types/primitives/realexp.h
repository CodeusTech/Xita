/*
  realexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains real number primitive expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) Real Literals
    1.a) Pop Real
    1.b) Push Real Literal
    1.c) Push Real Identifier
  2.) Real Arithmetic
    2.a) Real Addition
    2.b) Real Subtraction
    2.c) Real Multiplication
    2.d) Real Division
*/

#ifndef PRIMITIVES_REALEXP_H
#define PRIMITIVES_REALEXP_H

#include "typecodes.h"
#include "../types.h"

#include "../../grammar/status.h"
extern unsigned int grammar_status;

/*
  1.) Real Literals
*/

/* 1.a) Pop Real

  Returns:
    0, if Successful
*/
int pop_real()
{
  //  STUB STUB STUB
  printf("Real Number Popped\n");

  return 0;
}

/* 1.b) Push Real Literal

  Returns:
    0, if Successful
*/
int push_real_lit(double lit)
{
  //  STUB STUB STUB
  printf("Real Literal Pushed: %f\n", lit);

  return 0;
}

/* 1.c) Push Real Identifier

  Returns:
    0, if Successful
    1, if Identifier is not a Real Number
*/
int push_real_ident(char* ident)
{
  //  STUB STUB STUB
  printf("Real Identifier Pushed to Stack: %s\n", ident);

  switch(find_type(ident))
  {
    case TYPE_REAL:
      //  Push Real Number
      break;
    case TYPE_FLOAT:
      //  Push Floating Point
      break;
    case TYPE_DOUBLE:
      //  Push Double Precision
      break;
    default:
      //  Not a Real Number, Report Error
      grammar_status = GRAMMAR_ERROR_TYPECHECK;
      //  TODO: Return with yyerror() 
      return 1;
  }

  return 0;
}


/*
  2.) Real Arithmetic
*/

/* 2.a) Real Addition

  Returns:
    0, if Successful
*/
int real_addition()
{
  printf("Perform Real Addition\n");

  return 0;
}

/* 2.b) Real Subtraction

  Returns:
    0, if Successful
*/
int real_subtraction()
{
  printf("Perform Real Subtraction\n");

  return 0;
}

/* 2.c) Real Multiplication

  Returns:
    0, if Successful
*/
int real_multiplication()
{
  printf("Perform Real Multiplication\n");

  return 0;
}

/* 2.d) Real Division

  Returns:
    0, if Successful
*/
int real_division()
{
  printf("Perform Real Division\n");

  return 0;
}



#endif
