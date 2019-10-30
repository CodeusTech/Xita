/*
  esc_char.h
  Cody Fagley
  Authored on   March 17, 2019
  Last Modified March 17, 2019
*/

/*
  Contains Functionality for Handling Escaped Characters

  Table of Contents
  =================
  1.) Special Characters
  2.) Escaped Operators
*/

#ifndef REGEX_ESC_CHAR_H
#define REGEX_ESC_CHAR_H


/*
  1.) Special Characters
*/

const char regchar_newline[2]   = {'\\', 'n'};
const char regchar_tabchar[2]   = {'\\', 't'};
const char regchar_backspace[2] = {'\\', 'b'};


/*
  2.) Escaped Operators
*/

const char regchar_mulchar[2]   = {'\\', '*'};
const char regchar_addchar[2]   = {'\\', '+'};
const char regchar_leftpar[2]   = {'\\', '('};
const char regchar_rightpar[2]  = {'\\', ')'};
const char regchar_dashchar[2]  = {'\\', '-'};


#endif

