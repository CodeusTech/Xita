/*
  xor.h (Bitwise)
  Codeus Tech
  Authored on   April 30, 2020
  Last Modified April 30, 2020
*/

/*
  Contains functionality for Bitwise Exclusive OR Operator
*/

#pragma once

#include <xcs/std/includes.h>
#include "../structs.h"


class BitwiseXorOperator : public Operator
{

public:
  BitwiseXorOperator(OperatorManager* manager) : Operator(manager) 
  { }


  char* resolve(RegisterStack* rs) override
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

      sprintf(str, "  eor   %s, %s, %s", rtn, sec, top);
      
      rs->remove(1);
      rs->remove(1);

      free(rtn);
    }
    else if (target_architecture == XitaArchitecture::x86_64)
    {
      sprintf(str, "  xor  %s, %s", top, sec);
      rs->pop();
    }

    free(top);
    free(sec);

    return str;
  } 
};

