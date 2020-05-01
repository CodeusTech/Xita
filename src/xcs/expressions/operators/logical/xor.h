/*
  xor.h (Logical)
  Codeus Tech
  Authored on   April 29, 2020
  Last Modified April 29, 2020
*/

/*
  Contains structures/implementations for Logical OR Operator (||)
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class LogicalXOROperator : public Operator
{

public:
  LogicalXOROperator()
  {
    
  }

  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf (str, "  cmp   %s, %s   // Fix Logical Exclusive Or", sec, top);

    l.log('D', "Operators", "Resolved Logical Exclusive OR Operation");

    free(top);
    free(sec);

    return str;
  }

};
