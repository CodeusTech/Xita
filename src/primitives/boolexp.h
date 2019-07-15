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
#include "typecodes.h"
#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include "../globals/structs.h"

/*
  1.) Boolean Literals
*/

/*
  1.a) True/False
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
ErrorCode boolean_and()
{
  rs_pop();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean And Check
  char* str = (char*) malloc(50);

  sprintf(str, "and   %s, %s, %s\n", 
    get_reg(sec, 32), get_reg(sec, 32), get_reg(top, 32));
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(str);

  //  Return Success
  return 0;
}

/* 2.b) Boolean Or
  Performs boolean or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_or()
{
  rs_pop();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean OR Check
  char* str = (char*) malloc(50);

  sprintf(str, "orr   %s, %s, %s\n", 
    get_reg(sec, 32), get_reg(sec, 32), get_reg(top, 32));
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(str);

  //  Return Success
  return 0;
}

/* 2.c) Boolean Exclusive Or
  Performs boolean xor from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_xor()
{
  rs_pop();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(50);

  sprintf(str, "eor   %s, %s, %s\n", 
    get_reg(sec, 32), get_reg(sec, 32), get_reg(top, 32));
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(str);

  //  Return Success
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
ErrorCode boolean_lt()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Less Than
  sprintf(str, "blt   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

/* 3.b) Less Than or Equal To
  Evaluates if NEXT is less than or equal to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_lte()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Less Than or Equal To
  sprintf(str, "ble   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

/* 3.c) Greater Than
  Evaluates if NEXT is greater than TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_gt()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Greater Than
  sprintf(str, "bgt   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

/* 3.d) Greater Than or Equal To
  Evaluates if NEXT is greater than or equal to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_gte()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Greater Than or Equal To
  sprintf(str, "bge   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

/* 3.e) Equivalent To
  Evaluates if NEXT is equivalent to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_eq()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Equal To
  sprintf(str, "beq   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

/* 3.f) Not Equivalent To
  Evaluates if NEXT is not equivalent to TOP; NEXT stores result

  Returns:
    0, if Successful
*/
int boolean_neq()
{
  rs_pop();

  mangle += rand();

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  rs_pop();

  //  Jump if Not Equal To
  sprintf(str, "bne   set_%u\n", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u\n", mangle);
  add_command(str);

  sprintf(str, "set_%u:\n", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:\n", mangle);
  add_command(str);


  free(str);

  //  Return Success
  return 0;
}

#endif