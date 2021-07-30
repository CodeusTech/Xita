/*
  multiplication.h
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

class MultiplyOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  MultiplyOperator()
  {
  
    op = strdup(string("(*)").c_str());
    is_communitive = true;
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
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};


