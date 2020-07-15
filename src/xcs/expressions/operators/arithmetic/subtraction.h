/*
  subtraction.h
  Codeus Tech, LLC
  Authored on   July 15, 2020
  Last Modified July 15, 2020
*/

/*
  Contains structures and implementations for subtraction operator usage
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"

class SubtractOperator : public Operator
{
private: 

protected:

public: 
  SubtractOperator();
  char* resolve(RegisterStack* rs) override;
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};


/*
  Constructors
*/
SubtractOperator::SubtractOperator()
{
  op = strdup(string("(-)").c_str());
  is_communitive = false;
}


char* SubtractOperator::resolve(RegisterStack* rs)
{
  /*
    Get top 2 registers
    Add together (according to type sizes)
  */

  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);

  char* str = (char*) malloc(50);
  sprintf(str, "  sub   %s, %s, %s", sec, sec, top);

  free(top);
  free(sec);

  return str;
}

ErrorCode SubtractOperator::override(TypeID rtn_type, TypeID left, TypeID right)
{
  TypeID* tids = (TypeID*) malloc(2*sizeof(TypeID));

  tids[0] = left;
  tids[1] = right;

  operands.push_back(Operand(rtn_type, tids));
  return SUCCESS;
}


