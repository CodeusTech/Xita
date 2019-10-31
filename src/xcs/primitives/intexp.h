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
      1.b.1) Push Unsigned 8-Bit Integer
      1.b.2) Push Unsigned 16-Bit Integer
      1.b.3) Push Unsigned 32-Bit Integer
      1.b.4) Push Unsigned 64-Bit Integer
      1.b.5) Push Signed 8-Bit Integer
      1.b.6) Push Signed 16-Bit Integer
      1.b.7) Push Signed 32-Bit Integer
      1.b.8) Push Signed 64-Bit Integer
    1.c) Push Integer Identifier
  2.) Integer Arithmetic
    2.a) Integer Addition
    2.b) Integer Subtraction
    2.c) Integer Multiplication
    2.d) Integer Division
    2.e) Integer Modulus
  3.) Bitwise Arithmetic
    3.a) Bitwise Shift Left
    3.b) Bitwise Shift Right
    3.c) Bitwise And
    3.d) Bitwise Or
    3.e) Bitwise Xor
*/

#ifndef PRIMITIVES_INTEXP_H
#define PRIMITIVES_INTEXP_H

//  XCS Libraries
#include "../std/typecodes.h"
#include "../std/structs.h"

#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include <xcs/regstack/utils.h>


extern unsigned int grammar_status;

/*
  1.) Integer Literals
*/

/* 1.a) Pop Integer

  Returns:
    0, if Successful
*/
int pop_int()
{
  //  STUB STUB STUB
  printf("Integer Popped from Register Stack\n");
  rs_pop();

  return 0;
}

/* 1.b) Push Integer Literals

  Puts integer [lit] into current scope's register stack
  Puts integer TypeID into current scope's register stack

  Returns:
    0, if Successful
*/
int push_int(long long lit)
{
  //  Map Integer Literal Type to Top of Register Stack
  unsigned char bits;
  last_data = (void*) (long long) lit; 

  rs_push(last_type);

  switch(last_type)
  {
    case TYPE_U8:
    case TYPE_I8:
      bits = 8;
      break;
    case TYPE_U16:
    case TYPE_I16:
      bits = 16;
      break;
    case TYPE_U32:
    case TYPE_I32:
    case TYPE_INTEGER:
      bits = 32;
      break;
    case TYPE_U64:
    case TYPE_I64:
      bits = 64;
      break;
    default:
      bits = 32;
  }

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* reg_top = get_reg(rs_top(), bits);


  //  Add to Queue for File Printing
  sprintf(str, "mov   %s, #%llu", reg_top, lit);
  add_command(str);

  //  Free allocated memory and move to next register on stack

  free(str);
  free(reg_top);


  return 0;
}

/* 1.b.1) Push Unsigned 8-Bit Integer

*/



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

  printf("check\n");
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "add   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 2.b) Integer Subtraction
  Subtracts TOP from NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_subtraction()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();


  sprintf(str, "sub   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 2.c) Integer Multiplication
  Multiplies TOP and NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_multiplication()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "mul   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 2.d) Integer Division
  Divides TOP from NEXT register; NEXT holds quotient; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_division()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "sdiv  %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 2.e) Integer Modulus
  Divides TOP from NEXT register; NEXT holds remainder; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_modulo()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "mov   %s, %s mod %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/*
  3.) Bitwise Arithmetic
*/

/* 3.a) Bitwise Shift Left
  Shifts NEXT register's bits left by TOP places

  Returns:
    1, if Succcessful
*/
int bitwise_shl()
{
  // STUB STUB STUB
  printf("Bitwise Shift Left\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise Shift
  ADR rhs = rs_top();
  ADR lhs = rs_sec();

  //  After Bitwise Shift, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.b) Bitwise Shift Right
  Shifts NEXT register's bits right by TOP places

  Returns:
    0, if Successful
*/
int bitwise_shr()
{
  printf("Bitwise Shift Right\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise Shift
  ADR rhs = rs_top();
  ADR lhs = rs_sec();

  //  After Bitwise Shift, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.c) Bitwise And
  Performs bitwise and from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_and()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "and   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 3.d) Bitwise Or
  Performs bitwise or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_or()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "orr   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/* 3.e) Bitwise Xor
  Performs bitwise exclusive or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_xor()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "eor   %s, %s, %s", sec, sec, top);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(sec);
  free(top);

  return 0;
}

#endif
