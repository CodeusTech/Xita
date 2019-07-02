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
    1.a) .text Buffers
    1.b) .bss Buffers
    1.c) Name Mangling
  2.) Register Stack
    2.a) Standard Register Stack
    2.b) Extended Register Stack
    2.c) Context Scopes
  3.) Function Buffers
    3.a) Functions
    3.b) Parameters
    3.c) Constants
  4.) Type Buffers
    4.a) Type Data
    4.b) Constructors
    4.c) Typeclasses
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

//  1.a) .text Buffers
char** start_asm_text;
char**  curr_asm_text;
unsigned int count_asm_text;
unsigned int index_asm_text;

//  1.b) .bss Buffers
char** start_asm_bss;
char**  curr_asm_bss;
unsigned int count_asm_bss;
unsigned int index_asm_bss;

//  1.c) .data Buffers
char** start_asm_data;
char**  curr_asm_data;
unsigned int count_asm_data;
unsigned int index_asm_data;

// 1.c) Name Mangling
unsigned int mangle = 0;


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

//  3.a) Functions
char** ident_funct;         //  Function Identifiers
unsigned int* type_funct;   //  Return Type of Functions
unsigned int* rtn_funct;    //  Number of Function Returns

//  3.b) Parameters
char*** param_funct;        //  Function Parameter Identifiers
unsigned int* pnum_funct;   //  Number of Parameters for Function
unsigned int** ptype_funct; //  Function Parameter Types

//  3.c) Constants
char** ident_const;       //  Constant Identifiers
unsigned int* type_const; //  Constant Type Codes



/*
  4.) Type Buffers
*/

//  4.a) Type Data
unsigned int* types;      //  Type Codes
unsigned int count_types; //  Number of Types
char** ident_types;       //  Type Identifiers
char*** param_types;      //  Type Parameters

//  4.b) Constructors
char** ident_construct;       //  Constructor Identifiers
unsigned int* count_construct;//  Number of Constructors for Function
char*** ident_elem;           //  Element Identifiers
char** etype_construct;       //  Types of Elements for Constructor
unsigned int* enum_construct; //  Number of Elements for Constructor

//  4.c) Typeclasses 
char** ident_typeclasses; //  Typeclass Identifiers

char** ident_prototypes;  //  Prototype Identifiers
char*** param_prototypes; //  Prototype Parameters


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
