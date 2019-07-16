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
  A.) Free Global Buffers
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

/*
  2.) Assembly Buffers
*/

//  2.a) .text Buffers
Command** start_asm_text;
Command*  curr_asm_text;
unsigned int* count_asm_text;
unsigned int* index_asm_text;

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

TypeID last_type = 0;

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
TypeID next_type = 18;    //  Number of Types
Identifier*  ident_types; //  Type Identifiers
unsigned int* pcount_types; //  Type Parameter Count
Identifier** param_types; //  Type Parameters

//  5.b) Constructors
unsigned int*  count_construct; //  Number of Constructors for Function
Identifier**   ident_construct; //  Constructor Identifiers
unsigned int** count_elements;  //  Number of Elements for Constructor
Identifier***  ident_elements;  //  Element Identifiers
TypeID***      type_elements;   //  Types of Elements for Constructor

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



/*  A.) Free Global Buffers

      This is one of the last functions that is executed upon each run of the
    XCSL-AArch Cross Compiler.  It's responsibility is to free all buffers that
    do not get freed naturally upon conclusion/assembly generation.

    TODO:
      * Many, many if ... else ... statements needed
        - Need to recursively check for extended lists

    Returns:
      0, if Successful
*/
ErrorCode free_buffers()
{

  //  Return Scope

  //  Register Stacks

  //  Functions

  /*
    TYPES
  */
  
  //  For Each Type
  for (TypeID tid = 0; tid < (next_type-18); tid++)
  { 
    //  For Each Parameter
    for (unsigned int pid = 0; pid < pcount_types[tid]; pid++)
    {
      free(param_types[tid][pid]);
    }

    //  For Each Constructor
    for (unsigned int cid = 0; cid < count_construct[tid]; cid++)
    {
      //  For Each Element
      for (unsigned int eid = 0; eid < count_elements[tid][cid]; eid++)
      {
        free(ident_elements[tid][cid][eid]);
      }

      free(ident_construct[tid][cid]);
      free(ident_elements[tid][cid]);
      free(type_elements[tid][cid]);
    }

    free(ident_types[tid]);
    free(param_types[tid]);

    free(ident_construct[tid]);
    free(ident_elements[tid]);
    free(type_elements[tid]);
    free(count_elements[tid]);
  }

  free (ident_types);
  free (pcount_types);
  free (param_types);
  free (count_construct);
  
  free (ident_construct);
  free (ident_elements);
  free (type_elements);
  free (count_elements);


  //  Return Success
  return 0;
}








#endif
