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
*/

#ifndef PRIMITIVES_CHAREXP_H
#define PRIMITIVES_CHAREXP_H

#include "typecodes.h"
#include "../types/types.h"

/*
  1.) Character Literals
*/

/* 1.a) Pop Character

  Returns:
    1, if Successful
*/
int pop_char()
{
  // STUB STUB STUB
  printf("Character Popped");

  return 1;
}

/* 1.b) Push Character Literal

  Returns:
    1, if Successful
*/
int push_char_lit(char lit)
{
  //  STUB STUB STUB
  printf("Character Literal Pushed: %c\n", lit);

  return 1;
}

/* 1.c) Push Character Integer

  Returns:
    1, if Successful
*/
int push_char_int(unsigned int lit)
{
  //  STUB STUB STUB
  printf("Character Integer Pushed: %d\n", lit);

  return 1;
}

/* 1.d) Push Character Identifier

  Returns:
    1, if Successful
*/
int push_char_ident(char* ident)
{
  //  STUB STUB STUB
  printf("Character Identifier Pushed: %s\n", ident);

  if (find_type(ident) == TYPE_CHAR) {/* Handle Character */ }
  else {/* Not a Character, Throw Error */}

  return 1;
}


/*
  2.) Character Expressions
*/

int char_from_int(int i)
{
  printf("Character: %c, derived from int: %d.\n", (char) i, i);

  return 1;
}


#endif
