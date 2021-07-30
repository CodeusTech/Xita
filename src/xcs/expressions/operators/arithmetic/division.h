/*
  division.h
  Codeus Tech
  Authored on   March  7, 2021
  Last Modified  July 30, 2021
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

      sprintf(str, "  udiv   %s, %s, %s", rtn, sec, top);
      
      rs->remove(1);
      rs->remove(1);

      free(rtn);
    }
    else if (target_architecture == XitaArchitecture::x86_64)
    {
      sprintf(str, "  mov  %s, rax\n", sec);
      sprintf(str, "  div  %s", top);

      //  NOTE !!! This is more involved than what is shown here.  
      //           As done this way, this will NOT work.  
      //           RAX and RDI need to be prepped for quotient/remainder
      rs->pop();
      rs->pop();
    }

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
