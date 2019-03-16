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
  2.) Operator Structures
    2.a) Operand Pairs
  3.) Memory Allocator Structures
*/

#ifndef GLOBALS_STRUCTS_H
#define GLOBALS_STRUCTS_H

#include "../memory/memory.h"

/*
  1.) Register Stacks
*/

typedef unsigned char ADR;

typedef struct regstack_t
{
  ADR order[30];
} RegStack;

/*
  2.) Operator Structures
*/

/*
  2.a) Operand Pairs
*/
typedef struct operands_t
{
  unsigned int lhs; // Left-Hand Side  Type Code
  unsigned int rhs; // Right-Hand Side Type Code
} operands;


/*
  3.) Memory Allocator Structures
*/
MemoryBlock* ActiveMemory;

#endif
