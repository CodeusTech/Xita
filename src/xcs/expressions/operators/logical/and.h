/*
  and.h (Logical)
  Codeus Tech
  Authored on   April 29, 2020
  Last Modified April 29, 2020
*/

/*
  Contains structure/definitions for logical AND operator (&&)  
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class LogicalANDOperator : public Operator
{


public:

  LogicalANDOperator()
  {
    
  }

  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf(str, "  mov  %s, %s  // TODO: FIX LOGICAL AND", sec, top);

    l.log('D', "Operators", "Resolved Logical AND Operation");

    free(top);
    free(sec);

    return str;
  }

};


