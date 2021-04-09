/*
  gt.h (Logical)
  Codeus Tech
  Authored on   April 29, 2020
  Last Modified April 29, 2020
*/

/*
  Contains structure/definitions for 'Greater Than', 'Greater Than or Equal To' Operations 
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class GreaterThanOperator : public Operator
{


public:

  GreaterThanOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


class GreaterThanOrEqOperator : public Operator
{


public:

  GreaterThanOrEqOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


