/*
  error.h
  Codeus Tech
  Authored on   December 14, 2019
  Last Modified December  7, 2022
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

//  Preprocess Errors
#define ERR_UNSUPPORTED_ARCH    100   //  Unsupported Target Architecture in .chip file
#define ERR_MEMORY_OVERLAP      101   //  Two Firmware interfaces in the .chip file have overlapping memory regions
#define ERR_UNDEFINED_FIRM      102   //  A firmware driver was loaded for an undefined firmware interface
#define ERR_REDEFINED_FIRM      103   //  A firmware driver was loaded for a previously defined firmware interface 

//  Register Stack Errors
#define ERR_REGSTACK_UNDEF_ARCH -100  //  Register Stack encountered Unsupported Target Architecture
#define ERR_REGSTACK_POP_EMPTY  -101

//  Memory Errors
#define ERR_MEMORY_ACCESS       500   //  Illegal Attempt to Directly Access Memory



/*
  CRITICAL EXCEPTIONS
*/

class ExceptionUnsupportedArchitecture: public exception {
  virtual const char* what() const throw() {
    return "Xita Compiler ran with unsupported architecture.\n  Please use one of the following: 'Arm64', 'Arm32'";
  }
} ExceptionUnsupportedArchitecture;

class ExceptionMissingChipFile : public exception {
  virtual const char* what() const throw() {
    return "A chip file must be specified with `--chip [path/to/file.chip]`";
  }
} ExceptionMissingChipFile;


