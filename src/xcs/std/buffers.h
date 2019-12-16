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


using namespace std;

using std::list;
using std::vector;
using std::string;

/*
  1.) Compiler Utilities
*/


// 1.b) Last Encountered Value
void* last_data;

// 1.d) Found Identifier
bool found = false;

/*
  2.) Assembly Buffers
*/

//  2.a) .text Buffers
vector<list<string> > asm_text;

//  2.b) .bss Buffers
list<string> asm_bss;

//  2.c) .data Buffers
list<string> asm_data;


/*
  3.) Register Stack
*/


//  3.b) Extended Register Stack
unsigned int rse_next = 1;  //  Next Extended Register Stack
ConstructorID** rse_construct;  //  Register Stack Types (Extended)


Scope* scope_parents;  //  Parent (Return) Scope 

//  Context Buffers
TypeID last_type = 0;
ConstructorID last_constructor = 0;


bool pfunct = false;  //  DEPRECATED
vector<TypeID> argt;
Scope args = 0;

vector<MemoryVariableNode> memory_variables;

vector<ModuleNode> modules;
ModuleNode* context;
ModuleID current_context = 0;
ModuleID next_context = 1;

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
