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

//  Linux Libraries
#include "math.h"
#include "time.h"

//  XCS Libraries
#include <xcs/std/typedefs.h>

/*
  1.) Static Operations
*/

/* 1.a) Create New Register Stack

*/
ErrorCode rs_new()
{
  regstack new_rs;

  //  Random Order Variables
  unsigned long long activeRegs = 0;
  curr_reg = 0;
  unsigned long chk;

  mangle += rand();
  unsigned long seed = time(NULL) + mangle;
  srand(seed);

  // TODO: Make More Efficient
  for (int i = 0; i < 25; i++)
  {
    chk = rand() % 25;
    if (activeRegs & (int) (pow(2,chk))) i--;
    else
    {
      new_rs.rs_code.push_back(chk);
      activeRegs |= (int) pow(2,chk);
    }
  }

  rs.push_back(new_rs);

  //  Return Success
  return 0;
}

/* 1.b) Push to Register Stack

*/
ADR rs_push()
{

  printf("check\n");
  // TODO:  Error Check
  return curr_reg++;
}

/* 1.c) Pop from Register Stack

*/
ADR rs_pop()
{
  //  TODO: Error Check
  return --curr_reg;
}


/*
  2.) Accessor Operations
*/

/* 2.a) Access Top Element

*/
ADR rs_top()
{ 
  //  TODO: Error Check
  
  return rs[scope_curr].rs_code[curr_reg]; 
}

/* 2.b) Access Second Element (from Top)

*/
ADR rs_sec()
{
  //  TODO: Error Check
  return rs[scope_curr].rs_code[curr_reg-1];
}


TypeID rs_top_type() { return rs[scope_curr].rs_type[curr_reg]; }
TypeID rs_sec_type() { return rs[scope_curr].rs_type[curr_reg-1]; }


ConstructorID rs_top_struct() { return rs[scope_curr].rs_struct[curr_reg]; }
ConstructorID rs_sec_struct() { return rs[scope_curr].rs_struct[curr_reg-1]; }



#endif
