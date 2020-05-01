/*
  lt.h (Logical)
  Codeus Tech
  Authored on   April 29, 2020
  Last Modified April 29, 2020
*/

/*
  Contains structure/definitions for 'Less Than', 'Less Than or Equal To' Operations 
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class LessThanOperator : public Operator
{


public:

  LessThanOperator()
  {
    
  }

  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    //  STUB:  Needs to be rebuilt using previous implementation.
    char* str = (char*) malloc(50);

    sprintf (str, "  cmp   %s, %s", sec, top);
    l.log('D', "Operators", "Resolved 'Less Than' Operation");

    free(top);
    free(sec);

    return str;
  }

};


class LessThanOrEqOperator : public Operator
{


public:

  LessThanOrEqOperator()
  {
    
  }

  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    //  STUB:  Needs to be rebuilt using previous implementation.
    char* str = (char*) malloc(50);

    sprintf (str, "  cmp   %s, %s", sec, top);
    l.log('D', "Operators", "Resolved 'Less Than or Equal To' Operation");

    free(top);
    free(sec);

    return str;
  }

};


