/*
  charexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
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
  2.) Character From ASCII Integer
*/

#ifndef PRIMITIVES_CHAREXP_H
#define PRIMITIVES_CHAREXP_H


/*
  1.) Character Literals
*/

int literal_char(char c)
{
  // NOTE: CURRENTLY INCORRECT
  //        Does not correctly handle escaped characters
  printf("Character Literal: %c\n", c);

  return 0;
}

/*
  2.) Character From ASCII Integer
*/

int char_from_int(int i)
{
  printf("Character: %c, derived from int: %d.\n", (char) i, i);

  return 0;
}


#endif
