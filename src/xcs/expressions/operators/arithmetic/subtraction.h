/*
  subtraction.h
  Codeus Tech
  Authored on   March  7, 2021
  Last Modified  July 30, 2021
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

    if (target_architecture == XitaArchitecture::Arm32 || 
        target_architecture == XitaArchitecture::Arm64)
    {
      char* rtn = get_reg(rs->push(rs->top_type()), 32);

      sprintf(str, "  sub   %s, %s, %s", rtn, sec, top);
      
      rs->remove(1);
      rs->remove(1);

      free(rtn);
    }
    else if (target_architecture == XitaArchitecture::x86_64)
    {
      sprintf(str, "  sub  %s, %s", top, sec);
      rs->pop();
    }

    free(top);
    free(sec);

    return str;
  } 

};
