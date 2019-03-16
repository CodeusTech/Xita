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
    2.a) Standard Register Stack
    2.b) Extended Register Stack
    2.c) Context Scopes
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

//  2.a) Standard Register Stack
ADR curr_reg;             //  Current Register pointer
ADR** rs;                 //  Register Stack Orders
unsigned int** rs_types;  //  Register Stack Types

//  2.b) Extended Register Stack
unsigned int rse_next = 1;  //  Next Extended Register Stack
unsigned long** rse_types;  //  Register Stack Types (Extended)

//  2.c) Context Scopes

Scope scope_curr = 0;  //  Function/Register Stack Scope
Scope scope_next = 1;  //  Next Function Scope
Scope* scope_parents;  //  Parent (Return) Scope 

/*
  3.) Function Buffers
*/

char** ident_functions;   //  Function Identifiers
char** ident_constants;   //  Constant Identifiers
char** ident_parameters;  //  Parameter Identifiers


/*
  4.) Type Buffers
*/

char** ident_types;       //  Type Identifiers
char** ident_typeclasses; //  Typeclass Identifiers


/*
  5.) Constructors
*/

char** ident_construct;         //  Constructor Identifiers
unsigned int* size_construct;   //  Constructor Data Sizes
unsigned int* count_construct;  //  Number of Constructors (for type)


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
