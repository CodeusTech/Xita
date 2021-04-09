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

  LogicalANDOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


