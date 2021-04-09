/*
  or.h (Logical)
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


class LogicalOROperator : public Operator
{

public:
  LogicalOROperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf (str, "  cmp   %s, %s  //  FIX LOGICAL OR", sec, top);
    l.log('D', "Operators", "Resolved Logical OR Operation");

    free(top);
    free(sec);

    return str;
  }

};


