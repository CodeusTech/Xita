/*
  shorthand.h
  Cody Fagley
  Authored on   March 17, 2019
  Last Modified March 17, 2019
*/

/*
  Contains Functionality for Handling Regular Expression Shorthand Patterns

  Table of Contents
  =================
  1.) Shorthand Values
    1.a) Any Character (NOT New Line)
    1.b) Any Numerical Digit (Base 10)
    1.c) Any Hexadecimal Digit (Base 16)
    1.d) Any Word
  2.) Shorthand Ranges
*/

#ifndef REGEX_SHORTHAND_H
#define REGEX_SHORTHAND_H


/*
  1.) Shorthand Values
*/

/* 1.a) Any Character (NOT New Line)

  Returns:
    0, if Successful
*/
int regex_any_char()
{
  char any_char = '.';
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Read ONE Character
      - Accepts any Character but the New Line ('\n') Character
  */

  return 0;
}

/* 1.b) Any Numerical Digit (Base 10)

  Returns:
    0, if Successful
*/
int regex_any_digit()
{
  char any_digit[2] = {'\\', 'd'};
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Read ONE Digit
      - Accepts any Character, '0' - '9'
  */

  return 0;
}

/* 1.c) Any Hexadecimal Digit (Base 16)

  Returns:
    0, if Successful
*/
int regex_any_hex()
{
  char any_hex[2]   = {'\\', 'h'};
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Read ONE Character
      - Accepts any Character, '0'-'9', 'a'-'f', 'A'-'F'
  */

  return 0;
}

/* 1.d) Any Word

  Returns:
    0, if Successful
*/
int regex_any_word()
{
  const char regex_any_word[2]  = {'\\', 'w'};
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Reads Several Characters
      - Accepts any Characters, ended by some form of whitespace
      - Whitespace can be These Characters:
        + Space Character
        + Tab Character
        + New Line Character
  */

  return 0;
}


/*
  2.) Shorthand Ranges
*/

/* 2.a) ASCII Character Ranges

  Returns:
    0, if Successful
*/
int regex_char_range()
{
  //  x-y
  //  For Example, 0-9 includes one instance of any digit
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Read ONE Character
      - Accepts any Character, x to y
  */

  return 0;
}

#endif

