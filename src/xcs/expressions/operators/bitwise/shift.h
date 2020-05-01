/*
  shift.h
  Codeus Tech
  Authored on   April 30, 2020
  Last Modified April 30, 2020
*/

/*
  Contains backend functionality for Bitwise Shift Left Operator
*/

#pragma once

#include <xcs/std/includes.h>
#include "../structs.h"


class BitwiseShiftLeftOperator : public Operator
{


public: 

  BitwiseShiftLeftOperator() { }


  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf(str, "  mov   %s, %s  //  TODO: Replace with Bitwise Op", sec, top);
    l.log('D', "Operators", "Resolved Bitwise Shift Left Operation");

    free(top);
    free(sec);

    return str;
  }

};


class BitwiseShiftRightOperator : public Operator
{

public:

  BitwiseShiftRightOperator() { }


  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf(str, "  mov   %s, %s  //  TODO: Replace with Bitwise Op", sec, top);
    l.log('D', "Operators", "Resolved Bitwise Shift Right Operation");

    free(top);
    free(sec);

    return str;
  }

};


