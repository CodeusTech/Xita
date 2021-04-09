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

  char* resolve(RegisterStack* rs) override;

};


