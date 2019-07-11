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
  1.) Compiler Buffers
    1.a) Name Mangling
    1.b) Last Encountered Value
    1.c) Last Encountered Type
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
*/

#ifndef GLOBALS_BUFFERS_H
#define GLOBALS_BUFFERS_H

#include "structs.h"



/*
  1.) Compiler Buffers
*/

// 1.a) Name Mangling
unsigned int mangle = 0;

// 1.b) Last Encountered Value
void* last_data;

// 1.c) Last Encountered Type
TypeID last_type = 0;

/*
  2.) Assembly Buffers
*/

//  2.a) .text Buffers
char** start_asm_text;
char**  curr_asm_text;
unsigned int count_asm_text;
unsigned int index_asm_text;

//  2.b) .bss Buffers
char** start_asm_bss;
char**  curr_asm_bss;
unsigned int count_asm_bss;
unsigned int index_asm_bss;

//  2.c) .data Buffers
char** start_asm_data;
char**  curr_asm_data;
unsigned int count_asm_data;
unsigned int index_asm_data;


/*
  3.) Register Stack
*/

//  3.a) Standard Register Stack
ADR curr_reg;       //  Current Register pointer
ADR** rs;           //  Register Stack Orders
TypeID** rs_types;  //  Register Stack Types

//  3.b) Extended Register Stack
unsigned int rse_next = 1;  //  Next Extended Register Stack
TypeID** rse_types;  //  Register Stack Types (Extended)

//  3.c) Context Scopes
Scope scope_curr = 0;  //  Function/Register Stack Scope
Scope scope_next = 1;  //  Next Function Scope
Scope* scope_parents;  //  Parent (Return) Scope 



/*
  4.) Function Buffers
*/

//  4.a) Functions
char** ident_funct;         //  Function Identifiers
unsigned int* type_funct;   //  Return Type of Functions
unsigned int* rtn_funct;    //  Number of Function Returns

//  4.b) Parameters
char*** param_funct;        //  Function Parameter Identifiers
unsigned int* pnum_funct;   //  Number of Parameters for Function
unsigned int** ptype_funct; //  Function Parameter Types

//  4.c) Constants
char** ident_const;       //  Constant Identifiers
unsigned int* type_const; //  Constant Type Codes
unsigned int count_const; //  Number of Constants



/*
  5.) Type Buffers
*/

//  5.a) Type Data
unsigned int* types;      //  Type Codes
unsigned int count_types; //  Number of Types
char** ident_types;       //  Type Identifiers
char*** param_types;      //  Type Parameters

//  5.b) Constructors
char** ident_construct;       //  Constructor Identifiers
unsigned int* count_construct;//  Number of Constructors for Function
char*** ident_elem;           //  Element Identifiers
char** etype_construct;       //  Types of Elements for Constructor
unsigned int* enum_construct; //  Number of Elements for Constructor

//  5.c) Typeclasses 
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
