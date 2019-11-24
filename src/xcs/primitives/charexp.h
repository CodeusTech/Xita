/*
  charexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified    March  6, 2019
*/

/*
  Contains primitive character expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) Character Literals
    1.a) Pop Character
    1.b) Push Character Literal
    1.c) Push Character Integer
    1.d) Push Character Identifier
  2.) Character Expressions
  3.) Character Codes
*/

#ifndef PRIMITIVES_CHAREXP_H
#define PRIMITIVES_CHAREXP_H

#include "../std/typecodes.h"
#include "../std/structs.h"

#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include <xcs/regstack/utils.h>
#include <xcs/asm/text.h>

extern unsigned int grammar_status;

/*
  1.) Character Literals
*/

/* 1.a) Pop Character

  Returns:
    0, if Successful
*/
int pop_char()
{
  // STUB STUB STUB
  printf("Character Popped");

  //  TODO:  Error Check

  //  Pop from Register Stack
  rs_pop();

  return 0;
}

/* 1.b) Push Character Literal

  Returns:
    0, if Successful
*/
int push_char_lit(unsigned char lit)
{
  ADR reg = rs_push(TYPE_CHAR);
  char* str = (char*) malloc(50);

  char* reg_top = get_reg(rs_top(), 32);

  if (rs_top() > 27) 
  {
    sprintf(str, "mov  w16, #%llu", lit);
    add_command(str);
    sprintf(str, "mov   %s, w16", reg_top);
    add_command(str);
  } else
  {
    //  Add to Queue for File Printing
    sprintf(str, "mov   %s, #%llu", reg_top, lit);
    add_command(str);
  }

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(reg_top);

  return 0;
}

/* 1.c) Push Character Integer

  Returns:
    0, if Successful
*/
int push_char_int(unsigned int lit)
{
  //  STUB STUB STUB
  printf("Character Integer Pushed: %d\n", lit);

  //  TODO: Error Check

  //  Push to Register Stack
  ADR reg = rs_push(TYPE_CHAR);

  return 0;
}


/*
  2.) Character Expressions
*/

int char_from_int(int i)
{
  printf("Character: %c, derived from int: %d.\n", (char) i, i);

  //  TODO: Error Check

  //  Push to Register Stack
  ADR reg = rs_push(TYPE_CHAR);

  return 0;
}

/*
  3.) Character Codes

  Returns:
    * 0-255, Valid ASCII Character Code
    * -1, if invalid ASCII character
*/
int get_char_code(char* str)
{
  if (strlen(str) == 0) return 0;
  if (strlen(str) == 2)
  {
    if (str[0] != '\\') return -1;  //  REPORT ERROR
    switch (str[1])
    {
      case '0':
        return 0;
      case 'a':
        return 7;
      case 'b':
        return 8;
      case 't':
        return 9;
      case 'n':
        return 10;
      case 'v':
        return 11;
      case 'f':
        return 12;
      case 'r':
        return 13;
      case '\"':
        return 34;
      case '\'':
        return 39;
      case '\\':
        return 92;
    }
  }
  if (strlen(str) == 1) return str[0];

  //  REPORT ERROR, all valid options should be caught by now
  return -1;
}


#endif
