/*
  shorthand.h
  Cody Fagley
  Authored on   March 17, 2019
  Last Modified March 17, 2019
*/

/*
  Contains Functionality for Handling Regular Expression Shorthand Patterns
*/

#ifndef REGEXP_SHORTHAND_H
#define REGEXP_SHORTHAND_H


/*
  3.) Shorthand
*/

const char regex_any_char     = '.';  //  Does not Include New Line
const char regex_any_digit[2] = {'\\', 'd'};
const char regex_any_hex[2]   = {'\\', 'h'};
const char regex_any_word[2]  = {'\\', 'w'};


#endif

