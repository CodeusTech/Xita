/*
  division.h
  Codeus Tech
  Authored on   March 7, 2021
  Last Modified March 7, 2021
*/

/*

*/

#pragma once

#include <string>
#include <cstdio>

#include "xcs/std/includes.h"
#include "xcs/std/structs.h"
#include "../structs.h"

class DivisionOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  DivisionOperator()
  {
  
    op = strdup(string("(/)").c_str());
  }

  char* resolve(RegisterStack* rs)
  {
    /*
      Type Check Operands
    */

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);
    sprintf(str, "  div   %s, %s, %s", sec, sec, top);

    free(top);
    free(sec);

    return str;
  }

  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  1.e) Modulus Operator  --  (+)
*/
class ModulusOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  ModulusOperator()
  {
  
    op = strdup(string("(%)").c_str());
  }

  char* resolve(RegisterStack* rs)
  {
    /*
      Type Check Operands
    */

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    //  TODO: This one is weird

    l.log('d', "Operators", "Modulus operation has been resolved");

    return SUCCESS;
  }
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};
