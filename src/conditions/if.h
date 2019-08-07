/*
  if.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains Backend Functionality For if then else Statements

  Table of Contents
  =================
  1.) If...
    1.a) If Declaration
    1.b) If Boolean Expression
  2.) Then...
    2.a) Then Declaration
    2.b) Then Expression
  3.) Else...
    3.a) Else Declaration
    3.b) Else Expression
  4.) Conclude If Then Else
*/

#ifndef CONDITIONS_IF_H
#define CONDITIONS_IF_H

#include "../asm/asm.h"
#include "../regstack/regstack.h"

extern unsigned int mangle;


/*
  1.) If...
*/

/* 1.a) If Declaration

  Returns:
    0, if successful
*/
unsigned int decl_if()
{
  //  Create Mangle ID for if ... then ... else ... expression
  mangle += rand();

  //  Print Assembly Header to If Statement
  char* str = (char*) malloc(60); //  Supports 10-figures worth of if statements
  
  //  Add Mangle to Header
  sprintf(str, "if_%u:", mangle);
  add_command(str);

  free(str);

  return mangle;
}

/* 1.b) If Boolean Expression

  Returns:
    0, if Successful
*/
unsigned int exp_if(unsigned int mang)
{
  //  TODO:  Error Check
  //           * TOP

  //  Pop TOP
  rs_pop();

  //  Allocate Memory for String
  char* str = (char*) malloc (70);
  char* top = get_reg(rs_top(), 32);

  //  Compare Top of Register Stack to 
  sprintf(str, "cmp   %s, #1", top);
  add_command(str);

  //  If False, Jump to else Block
  sprintf(str, "blt   else_%u", mang);
  add_command(str);

  //  Free Memory
  free(top);
  free(str);

  return mang;
}


/*
  2.) Then...
*/

/* 2.b) Then Expression

  Returns:
    0, if Successful
*/
int exp_then(unsigned int mang)
{
  char* str = (char*) malloc (80);

  sprintf(str, "b     finish_%u", mang);
  add_command(str);

  free(str);
  rs_pop();

  return mang;
}


/*
  3.) Else...
*/

/* 3.a) Else Declaration

  Returns:
    0, if Successful
*/
unsigned int decl_else(unsigned int mang)
{
  char* str = (char*) malloc (80);

  sprintf(str, "else_%u:", mang);
  add_command(str);

  free(str);

  return mang;
}

/* 3.b) Else Expression

  Returns:
    0, if Succssful
*/
ErrorCode exp_else(unsigned int mang)
{
  char* str = (char*) malloc (80);

  sprintf(str, "finish_%u:", mang);
  add_command(str);

  free(str);

  //  Return Success
  return 0;
}



#endif
