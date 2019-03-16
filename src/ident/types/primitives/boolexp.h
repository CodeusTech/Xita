/*
  boolexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains boolean primitive expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) Boolean Literals
    1.a) True/False
    1.b) Boolean Negation
  2.) Boolean Comparisons
    2.a) Boolean And
    2.b) Boolean Or
    2.c) Boolean Exclusive Or
  3.) Ordered Comparisons
    3.a) Less Than
    3.b) Less Than or Equal To
    3.c) Greater Than
    3.d) Greater Than or Equal To
    3.e) Equivalent To
    3.e) Not Equivalent To
*/

#ifndef PRIMITIVES_BOOLEXP_H
#define PRIMITIVES_BOOLEXP_H

//  XCS Libraries
#include "../../../regstack/regstack.h"

/*
  1.) Boolean Literals
*/

/*
  1.a) True/False
*/

/* Push True to Register Stack

  Returns:
    0, if Successful
*/
int boolean_true()
{
  //  TODO: Error Check

  //  Get Next Register on Stack
  ADR reg = rs_push();

  //  Push 1 to Register Stack

  return 0;
}

/* Push False to Register Stack

  Returns:
    0, if Successful
*/
int boolean_false()
{
  //  TODO: Error Check

  //  Get Next Register on Stack
  ADR reg = rs_push();

  //  Push 0 to Register Stack

  return 0;
}

/*
  1.b) Boolean Negation
*/

/*
  2.) Boolean Comparisons
*/

/* 2.a) Boolean And
  Performs boolean and from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_and()
{
  printf("Boolean And\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_top();
  ADR sec = rs_second();

  //  Perform Boolean And Check

  //  Pop Right-hand Operand from Register Stack
  rs_pop();

  return 0;
}

/* 2.b) Boolean Or
  Performs boolean or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_or()
{
  printf("Boolean Or\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_top();
  ADR sec = rs_second();

  //  Perform Boolean And Check

  //  Pop Right-hand Operand from Register Stack
  rs_pop();

  return 0;
}

/* 2.c) Boolean Exclusive Or
  Performs boolean xor from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_xor()
{
  printf("Boolean Exclusive Or\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_top();
  ADR sec = rs_second();

  //  Perform Boolean XOR Check

  //  Pop Right-hand Operand from Register Stack
  rs_pop();

  return 0;
}


/*
  3.) Ordered Comparisons
*/

/* 3.a) Less Than
  Evaluates if NEXT is less than TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_lt()
{
  printf("Boolean Less Than\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform < Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

/* 3.b) Less Than or Equal To
  Evaluates if NEXT is less than or equal to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_lte()
{
  printf("Boolean Less Than or Equal To\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform <= Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

/* 3.c) Greater Than
  Evaluates if NEXT is greater than TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_gt()
{
  printf("Boolean Greater Than\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform > Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

/* 3.d) Greater Than or Equal To
  Evaluates if NEXT is greater than or equal to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_gte()
{
  printf("Boolean Greater Than or Equal To\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform >= Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

/* 3.e) Equivalent To
  Evaluates if NEXT is equivalent to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_eq()
{
  printf("Boolean Equivalence\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform == Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

/* 3.f) Not Equivalent To
  Evaluates if NEXT is not equivalent to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_neq()
{
  printf("Boolean Unequivalence\n");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Perform != Check

  //  Push Result onto Register Stack
  rs_push();

  return 0;
}

#endif
