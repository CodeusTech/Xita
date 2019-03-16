/*
  buffers.h
  Cody Fagley
  Authored on   March 9, 2019
  Last Modified March 9, 2019
*/

/*
  Contains Global 'C' Buffers for XCSL Cross Compiler

  Table of Contents
  =================
  1.) Assembly Buffers
  2.) Register Stack
  3.) Function Buffers
  4.) Type Buffers
  5.) Constructors
  6.) Operator Buffers
    6.a) Operand Pairs
*/

#ifndef GLOBALS_BUFFERS_H
#define GLOBALS_BUFFERS_H

#include "structs.h"


/*
  1.) Assembly Buffers
*/

char** start_asm_text;
char**  curr_asm_text;
int count_asm_text;
int index_asm_text;

char** start_asm_bss;
char**  curr_asm_bss;
int count_asm_bss;
int index_asm_bss;


/*
  2.) Register Stack
*/

ADR curr_reg; //  Current Register pointer



/*
  3.) Function Buffers
*/

char** ident_functions;   //  Function Identifiers
char** ident_constants;   //  Constant Identifiers
char** ident_parameters;  //  Parameter Identifiers


/*
  4.) Type Buffers
*/

char** ident_types;
char** ident_typeclasses;


/*
  5.) Constructors
*/

char** ident_construct;
unsigned int* size_construct;
unsigned int count_construct;


/*
  6.) Operator Buffers
*/

//  Standard Operations
operands* operands_add;
operands* operands_sub;
operands* operands_mul;
operands* operands_div;
operands* operands_mod;

//  Logical Operations
operands* operands_bit_and;
operands* operands_bit_or;
operands* operands_bit_xor;
operands* operands_bit_shl;
operands* operands_bit_shr;
operands* operands_bool_and;
operands* operands_bool_or;
operands* operands_bool_xor;

//  Comparison Operations
operands* operands_lt;
operands* operands_lte;
operands* operands_gt;
operands* operands_gte;
operands* operands_eq;
operands* operands_neq;

//  List Operations
operands* operands_append;
operands* operands_list_con;


#endif
