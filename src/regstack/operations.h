/*
  operations.h (Register Stacks)
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains standard operations for manipulating the register stack

  Table of Contents
  =================
  1.) Static Operations
    1.a) Create New Register Stack
    1.b) Push to Register Stack
    1.c) Pop from Register Stack
  2.) Accessor Operations
    2.a) Access Top Element
    2.b) Access Second Element (from Top)
*/

#ifndef REGSTACK_OPERATIONS_H
#define REGSTACK_OPERATIONS_H

#include "math.h"

extern unsigned char curr_reg;

/*
  1.) Static Operations
*/

/* 1.a) Create New Register Stack

*/
ADR* rs_new()
{
  //  Allocate Register Stack Memory
  ADR* rs = (ADR*) malloc(30);
  
  //  Random Order Variables
  unsigned long activeRegs = 0;
  curr_reg = 0;
  int chk;

  // TODO: Make More Efficient
  for (int i = 0; i < 30; i++)
  {
    chk = rand() % 30;
    if (activeRegs & (int) (pow(2,chk))) i--;
    else
    {
      rs[i] = chk;
      activeRegs |= (int) pow(2,chk);
    }
  }

  return rs;
}

/* 1.b) Push to Register Stack

*/
unsigned int rs_push()
{
  // TODO:  Error Check
  return curr_reg++;
}

/* 1.c) Pop from Register Stack

*/
unsigned int rs_pop()
{
  //  TODO: Error Check
  return --curr_reg;
}


/*
  2.) Accessor Operations
*/

/* 2.a) Access Top Element

*/
unsigned int rs_top()
{ 
  //  TODO: Error Check
  return curr_reg; 
}

/* 2.b) Access Second Element (from Top)

*/
unsigned int rs_second()
{
  //  TODO: Error Check
  return (curr_reg - 1);
}



#endif
