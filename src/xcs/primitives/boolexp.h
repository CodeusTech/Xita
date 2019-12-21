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
#include "../std/typecodes.h"
#include "../std/structs.h"

#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include <xcs/regstack/utils.h>

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
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean And Check
  char* str = (char*) malloc(50);

  sprintf(str, "and   %s, %s, %s", sec, sec, top);
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(top);
  free(sec);

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
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean OR Check
  char* str = (char*) malloc(50);

  sprintf(str, "orr   %s, %s, %s", sec, sec, top);
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(50);

  sprintf(str, "eor   %s, %s, %s", sec, sec, top);
  add_command(str);

  //  Pop Right-hand Operand from Register Stack
  rs_pop();
  free(top);
  free(sec);

  //  Return Success
  return 0;
}

ErrorCode boolean_not()
{
  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mang = get_mangle();

  //  Compare against false
  sprintf(str, "cmp   %s, #0", top); add_command(str);
  sprintf(str, "bgt   not__%llu", mang); add_command(str);

  sprintf(str, "mov   %s, #1", top); add_command(str);

  sprintf(str, "b     finish__%llu", mang); add_command(str);
  sprintf(str, "not__%llu:", mang); add_command(str);

  sprintf(str, "mov   %s, #0", top); add_command(str);

  sprintf(str, "finish__%llu:", mang); add_command(str);

  free(str);
  free(top);

  return SUCCESS;
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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Less Than
  sprintf(str, "blt   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  //  Free Buffers
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  char* str = (char*) malloc (60);

  //  Perform Boolean Exclusive OR Check

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Less Than or Equal To
  sprintf(str, "ble   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);


  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  free(str);

  //  Free Buffers
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Greater Than
  sprintf(str, "bgt   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  free(str);
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Greater Than or Equal To
  sprintf(str, "bge   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  //  Free Buffers
  free(str);
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Equal To
  sprintf(str, "beq   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  //  Free Buffers
  free(str);
  free(top);
  free(sec);

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
  unsigned int mangle = (unsigned int) get_mangle();

  //  TODO: Error Check

  //  Get Register Codes
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);

  //  Perform Boolean Exclusive OR Check
  char* str = (char*) malloc(100);

  //  Perform Comparison
  sprintf(str, "cmp   %s, %s", sec, top);
  add_command(str);

  rs_pop();

  //  Jump if Not Equal To
  sprintf(str, "bne   set_%u", mangle);
  add_command(str);

  
  push_int(0);
  rs_pop();

  sprintf(str, "b     finish_%u", mangle);
  add_command(str);

  sprintf(str, "set_%u:", mangle);
  add_command(str);

  push_int(1);

  sprintf(str, "finish_%u:", mangle);
  add_command(str);


  //  Free Buffers
  free(str);
  free(top);
  free(sec);

  //  Return Success
  return 0;
}

#endif
