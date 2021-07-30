/*
  multiply.h
  Codeus Tech, LLC
  Authored on   July 15, 2020
  Last Modified July 30, 2021
*/

/*
  Contains structures/implementations for Muliplication Operator in XCS
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class MultiplyOperator : public Operator
{
public:
  MultiplyOperator();
  char* resolve(RegisterStack* rs) override;
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  Constructors 
*/
MultiplyOperator::MultiplyOperator()
{
  op = strdup(string("(*)").c_str());
  is_communitive = false;
}


char* MultiplyOperator::resolve(RegisterStack* rs)
{
  /*
    Get top 2 registers
    Add together (according to type sizes)
  */

  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);

  char* str = (char*) malloc(50);

  if (target_architecture == XitaArchitecture::Arm32 || 
      target_architecture == XitaArchitecture::Arm64)
  {
    char* rtn = get_reg(rs->push(rs->top_type()), 32);

    sprintf(str, "  mul   %s, %s, %s", rtn, sec, top);
    
    rs->remove(1);
    rs->remove(1);

    free(rtn);
  }
  else if (target_architecture == XitaArchitecture::x86_64)
  {
    sprintf(str, "  imul  %s, %s", top, sec);
    rs->pop();
  }

  free(top);
  free(sec);

  return str;
} 

ErrorCode MultiplyOperator::override(TypeID rtn_type, TypeID left, TypeID right)
{
  TypeID* tids = (TypeID*) malloc(2*sizeof(TypeID));

  tids[0] = left;
  tids[1] = right;

  operands.push_back(Operand(rtn_type, tids));
  return SUCCESS;
}

