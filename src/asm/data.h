/*
  data.h
  Cody Fagley 
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  .data Section contains Initialized Data (Constants)

  Table of Contents
  =================
  1.) Structure
    1.a) Generate Data
  2.) Operations
    2.a) Add Integer to Data
    2.b) Add Real to Data
    2.c) Add Boolean to Data
    2.d) Add Character to Data
    2.e) Add String to Data
    2.f) Add List to Data
*/

#ifndef ASM_DATA_H
#define ASM_DATA_H

#include "stdbool.h"

/*
  1.) Structure
*/

/* 1.a) Generate Data

  Returns:
    0, if Successful
*/
ErrorCode generate_data()
{
  //  STUB STUB STUB

  /*
    TODO: 
     * Error Check
     * Print .data Section Header
     * Write Out Entire .data Section Buffer
  */

  //  Return Success
  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add Integer to Data
Adds Integer Constant to .data Section

  Returns:
    0, if Successful
*/
ErrorCode add_int_to_data(Identifier ident, int value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print Integer Constant to .data Section
  */

  // Return Success
  return 0;
}

/* 2.b) Add Real to Data
Adds Real Constant to .data Section

  Returns:
    0, if Successful
*/
ErrorCode add_real_to_data(Identifier ident, double value)
{
  //  STUB STUB STUB STUB
  
  /*
    TODO:
     * Error Check
     * Print Real Constant to .data Section
  */

  //  Return Success
  return 0;
}

/* 2.c) Add Boolean to Data

  Returns:
    0, if Successful
*/
ErrorCode add_bool_to_data(Identifier ident, bool value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print Boolean Constant to .data Section
  */

  //  Return Success
  return 0;
}

/* 2.d) Add Character to Data

  Returns:
    0, if Successful
*/
ErrorCode add_char_to_data(Identifier ident, bool value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print Character Constant to .data Section
  */

  //  Return Success

  return 0;
}

/* 2.e) Add String to Data

  Returns:
    0, if Successful
*/
ErrorCode add_string_to_data(Identifier ident, char* str)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print String Constant to .data Section
  */

  //  Return Success

  return 0;
}

/* 2.f) Add List to Data

NOTE: Constant Lists are only available in Linux-to-XCS Cross Compiler
  Returns:
    0, if Successful
*/
ErrorCode add_list_to_data(Identifier ident, long value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print List Constant to .data Section
  */

  //  Return Success

  return 0;
}

#endif
