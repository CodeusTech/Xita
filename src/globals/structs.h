/*
  structs.h
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified March 8, 2019
*/

/*
  Contains data structure definitions for use in global buffers

  Table of Contents
  =================
  1.) Register Stacks
  4.) Data Types
  6.) Memory Allocator Structures
  7.) Operator Structures
    7.a) Operand Pairs
*/

#ifndef GLOBALS_STRUCTS_H
#define GLOBALS_STRUCTS_H

#include "../memory/memory.h"

/*
  1.) Register Stacks
*/

typedef unsigned char ADR;
typedef unsigned int Scope;

typedef struct regstack_t
{
  ADR order[30];
} RegStack;


/*
  3.) Functions
*/

typedef unsigned long ConstantID;


/*
  4.) Data Types
*/

typedef unsigned long TypeID;

/*
  6.) Memory Allocator Structures
*/
MemoryBlock* ActiveMemory;



/*
  7.) Operator Structures
*/

/*
  7.a) Operand Pairs
*/
typedef struct operands_t
{
  unsigned int lhs; // Left-Hand Side  Type Code
  unsigned int rhs; // Right-Hand Side Type Code
} operands;

#endif
