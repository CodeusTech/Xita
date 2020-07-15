/*
  division.h
  Codeus Tech, LLC
  Authored on   July 15, 2020
  Last Modified July 15, 2020
*/

/*
  Contains structures/implementations for Division in XCS
*/

#pragma once

#include <xcs/std/includes.h>
#include "../structs.h"


class DivisionOperator : public Operator
{
public:
  DivisionOperator();
  char* resolve(RegisterStack* rs) override;
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  Constructors 
*/
DivisionOperator::DivisionOperator()
{
  op = strdup(string("(/)").c_str());
  is_communitive = false;
}


char* DivisionOperator::resolve(RegisterStack* rs)
{
  /*
    Get top 2 registers
    Add together (according to type sizes)
  */

  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);

  char* str = (char*) malloc(50);

  bool isSigned = false;
  sprintf(str, "  %cdiv   %s, %s, %s", (isSigned? 's':'u'), sec, sec, top);

  free(top);
  free(sec);

  return str;
}

ErrorCode DivisionOperator::override(TypeID rtn_type, TypeID left, TypeID right)
{
  TypeID* tids = (TypeID*) malloc(2*sizeof(TypeID));

  tids[0] = left;
  tids[1] = right;

  operands.push_back(Operand(rtn_type, tids));
  return SUCCESS;
}




class ModulusOperator : public Operator
{
public:
  ModulusOperator();
  char* resolve(RegisterStack* rs) override;
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  Constructors 
*/
ModulusOperator::ModulusOperator()
{
  op = strdup(string("(%)").c_str());
  is_communitive = false;
}


char* ModulusOperator::resolve(RegisterStack* rs)
{
  /*
    Get top 2 registers
    Add together (according to type sizes)
  */

  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);

  rs->push(1);
  char* quotient = get_reg(rs->top(), 32);

  //  Allocate Memory
  char** rtn = (char**) malloc(2*sizeof(char*));
  rtn[0] = (char*) malloc(50); rtn[1] = (char*) malloc(50);


  sprintf(rtn[0], "  udiv  %s, %s, %s", quotient, sec, top);
  sprintf(rtn[1], "  msub  %s, %s, %s, %s", sec, top, quotient, sec);
  printf("CHECK!!!\n");

  free(top);
  free(sec);

  return (char*)rtn;
}

ErrorCode ModulusOperator::override(TypeID rtn_type, TypeID left, TypeID right)
{
  TypeID* tids = (TypeID*) malloc(2*sizeof(TypeID));

  tids[0] = left;
  tids[1] = right;

  operands.push_back(Operand(rtn_type, tids));
  return SUCCESS;
}

