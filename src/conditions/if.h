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
int decl_if()
{
  //  Create Mangle ID for if ... then ... else ... expression
  mangle += rand();

  //  Print Assembly Header to If Statement
  char* str = malloc(40); //  Supports 10-figures worth of if statements
  
  //  Add Mangle to Header
  sprintf(str, "if_%d:\n", mangle);
  add_command(str);

  free(str);

  return 0;
}

/* 1.b) If Boolean Expression

  Returns:
    0, if Successful
*/
int exp_if()
{
  //  TODO:  Error Check
  //           * TOP

  //  Allocate Memory for String
  char* str = (char*) malloc (50);

  //  Compare Top of Register Stack to 
  sprintf(str, "cmp %s, #1\n", get_reg32(rs[scope_curr][rs_top()]));
  add_command(str);

  //  If False, Jump to else Block
  sprintf(str, "jl false_%u\n", mangle);
  add_command(str);

  free(str);

  //  Pop TOP
  rs_pop();

  return 0;
}


/*
  2.) Then...
*/

/* 2.a) Then Declaration

  Returns:
    0, if Successful
*/
int decl_then()
{
  printf("then ...\n");
  /*

  //  Print Assembly Header to If Statement
  char* str = malloc(15); //  Supports 10-figures worth of if statements
  
  //  Add Mangle to Header
  sprintf(str, "then_%d:\n", mangle);
  add_command(str);  
  */

  return 0;
}

/* 2.b) Then Expression

  Returns:
    0, if Successful
*/
int exp_then()
{
  /*
  //  STUB STUB STUB
  
  //  TODO: Error Check

  //  Jump Beyond else Block
 
  // Reset Register Stack for Else Statement
  rs_pop();
  */ 

  return 0;
}


/*
  3.) Else...
*/

/* 3.a) Else Declaration

  Returns:
    0, if Successful
*/
int decl_else()
{
  printf("else ...\n");
  /*

  //  Print Assembly Header to If Statement
  char* str = malloc(15); //  Supports 10-figures worth of if statements
  
  //  Add Mangle to Header
  sprintf(str, "else_%d:\n", mangle);
  add_command(str);  
*/

  return 0;
}

/* 3.b) Else Expression

  Returns:
    0, if Succssful
*/
int exp_else()
{
  //  STUB STUB STUB
  
  //  TODO: Error Check

  //  Type Check: ELSE EXP against THEN EXP

  return 0;
}


/* 4.) Conclude If Then Else

*/
int exp_if_then_else()
{
  /*
  //  Print Assembly Header to If Statement
  char* str = malloc(15); //  Supports 10-figures worth of if statements
  
  //  Add Mangle to Header
  sprintf(str, "done_%d:\n", mangle);
  add_command(str);  

  mangle++;
*/

  return 0;
}


#endif
