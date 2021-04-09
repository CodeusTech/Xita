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
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf(str, "  eor   %s, %s", sec, top);
    l.log('D', "Operators", "Resolved Bitwise Exclusive OR Operation");

    free(top);
    free(sec);

    return str;
  }
};

