/*
  buffers.h
  Cody Fagley
  Authored on   March 9, 2019
  Last Modified July 29, 2019
*/

/*
  Contains Global 'C' Buffers for XCSL Cross Compiler

  Table of Contents
  =================
  1.) Compiler Utilities
    1.a) Name Mangling
    1.b) Last Encountered Value
    1.c) Last Encountered Type
    1.d) Found Identifier
  2.) Assembly Buffers
    2.a) .text Section
    2.b) .bss Section
    2.c) .data Section
  3.) Register Stack
    3.a) Standard Register Stack
    3.b) Extended Register Stack
    3.c) Context Scopes
  4.) Function Buffers
    4.a) Functions
    4.b) Parameters
    4.c) Constants
  5.) Type Buffers
    5.a) Type Data
    5.b) Constructors
    5.c) Typeclasses
  6.) Operator Buffers
    6.a) Operand Pairs
  A.) Free Global Buffers
*/

#ifndef XCS_BUFFERS_H
#define XCS_BUFFERS_H

//  Linux Libraries
#include <iostream>
#include <string>
#include <vector>
#include <list>

//  XCS Libraries
#include "typedefs.h"
#include "structs.h"
#include "logger.h"


using namespace std;

using std::list;
using std::vector;
using std::string;

/*
  1.) Compiler Utilities
*/
 Logger l;

/*
  2.) Assembly Buffers
*/

//  2.a) .text Buffers
vector<list<string> > asm_text;

//  2.b) .bss Buffers
list<string> asm_bss;

//  2.c) .data Buffers
list<string> asm_data;




#endif
