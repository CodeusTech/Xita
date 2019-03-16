/*
  struct.h
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Structures used with XCS Register Stack
*/

#ifndef REGSTACK_STRUCT_H
#define REGSTACK_STRUCT_H

typedef unsigned char ADR;

typedef struct regstack_t
{
  ADR order[30];
} RegStack;


#endif
