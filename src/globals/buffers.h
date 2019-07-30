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
  A.) Free Global Buffers
*/

#ifndef GLOBALS_BUFFERS_H
#define GLOBALS_BUFFERS_H

//  XCS Libraries
#include "structs.h"

//  Linux Libraries
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

using std::list;
using std::vector;
using std::string;

/*
  1.) Compiler Buffers
*/

// 1.a) Name Mangling
unsigned int mangle = 0;

// 1.b) Last Encountered Value
void* last_data;

/*
  2.) Assembly Buffers
*/

//  2.a) .text Buffers
vector<list<string>> asm_text;

//  2.b) .bss Buffers
list<string> asm_bss;

//  2.c) .data Buffers
list<string> asm_data;


/*
  3.) Register Stack
*/

//  3.a) Standard Register Stack
ADR curr_reg;       //  Current Register pointer
vector<regstack> rs;

//  3.b) Extended Register Stack
unsigned int rse_next = 1;  //  Next Extended Register Stack
ConstructorID** rse_construct;  //  Register Stack Types (Extended)

//  3.c) Context Scopes
Scope scope_curr = 0;  //  Function/Register Stack Scope
Scope scope_next = 1;  //  Next Function Scope
Scope* scope_parents;  //  Parent (Return) Scope 

TypeID last_type = 0;
ConstructorID last_constructor = 0;

/*
  4.) Function Buffers
*/

//  4.a) Functions
Identifier* ident_funct;         //  Function Identifiers
unsigned int* type_funct;   //  Return Type of Functions
unsigned int* rtn_funct;    //  Number of Function Returns

//  4.b) Parameters
Identifier** param_funct;        //  Function Parameter Identifiers
unsigned int* pnum_funct;   //  Number of Parameters for Function
TypeID** ptype_funct; //  Function Parameter Types

vector<node_constant> constants;


/*
  5.) Type Buffers
*/

//  5.a) Type Data
TypeID next_type = 18;    //  Number of Types
ConstructorID next_cid = 18;

vector<node_type> types;


//  5.c) Typeclasses 
Identifier* ident_typeclasses; //  Typeclass Identifiers

Identifier* ident_prototypes;  //  Prototype Identifiers
Identifier** param_prototypes; //  Prototype Parameters


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

//  Comparison Operations
operands* operands_bool_and;
operands* operands_bool_or;
operands* operands_bool_xor;
operands* operands_lt;
operands* operands_lte;
operands* operands_gt;
operands* operands_gte;
operands* operands_eq;
operands* operands_neq;

//  List Operations
operands* operands_append;
operands* operands_list_con;



/*
  Initialize Buffers
*/
ErrorCode init_buffers()
{

  return 0;
}



#endif
