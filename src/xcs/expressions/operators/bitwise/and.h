/*
  and.h (Bitwise)
  Codeus Tech 
  Authored on   April 30, 2020
  Last Modified April 30, 2020
*/

/*
  Contains functionality for handling Bitwise AND operations
*/

#pragma

#include <xcs/std/includes.h>
#include "../structs.h"


class BitwiseAndOperator : public Operator
{


public:
  BitwiseAndOperator() { }

  
  char* resolve(RegisterStack* rs) override
  {
    //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);

    sprintf(str, "  mov   %s, %s  //  TODO: Replace with Bitwise Op", sec, top);

    l.log('D', "Operators", "Resolved Bitwise AND Operation");

    free(top);
    free(sec);

    return str;
  }

};

