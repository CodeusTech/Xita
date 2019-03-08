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
*/

#ifndef GLOBALS_STRUCTS_H
#define GLOBALS_STRUCTS_H


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

#endif
