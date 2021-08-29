/*
  error.h
  Codeus Tech
  Authored on   December 14, 2019
  Last Modified     July 23, 2021
*/

/*
  Contains standard XCS Error Codes
*/

#pragma once

ErrorCode active_error_code = 1;  //  Unhandled Exception Code

/*
  ERROR CODE LISTING
*/
#define SUCCESS 0

//  Register Stack Errors
/* NOTE: These return negative values, because a positive value indicates success in this case */
#define ERR_REGSTACK_POP_EMPTY  -101
#define ERR_REGSTACK_UNDEF_ARCH -100  //  Register Stack encountered Unsupported Target Architecture

//  Preprocess Errors
#define ERR_UNSUPPORTED_ARCH    100   //  Unsupported Target Architecture in .chip file
#define ERR_MEMORY_OVERLAP      101   //  Two Firmware interfaces in the .chip file have overlapping memory regions
#define ERR_UNDEFINED_FIRM      102   //  A firmware driver was loaded for an undefined firmware interface
#define ERR_REDEFINED_FIRM      103   //  A firmware driver was loaded for a previously defined firmware interface 

//  Memory Errors
#define ERR_MEMORY_ACCESS       500   //  Illegal Attempt to Directly Access Memory

//  Type Checking Errors
#define ERR_TYPE_UNDEFINED      1000
#define ERR_TYPE_UNSUPPORTED    1001
#define ERR_TYPE_ALREADY_DECL   1002



