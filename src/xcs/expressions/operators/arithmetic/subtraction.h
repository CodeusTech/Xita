/*
  subtraction.h
  Codeus Tech
  Authored on   March 7, 2021
  Last Modified March 7, 2021
*/

/*
  Contains structure/definitions for handling subtraction operator in XCS
*/

#include <string>
#include <cstdio>

#include "xcs/std/includes.h"
#include "xcs/std/structs.h"
#include "../structs.h"

using namespace std;

#pragma once


class SubtractOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  SubtractOperator()
  {
  
    op = strdup(string("(-)").c_str());
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
    sprintf(str, "  sub   %s, %s, %s", sec, sec, top);

    free(top);
    free(sec);

    return str;
  }
};
