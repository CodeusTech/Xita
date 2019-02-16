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
    1.a) RESERVED
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

/*
  1.) Boolean Literals
*/

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

  return 0;
}

#endif
