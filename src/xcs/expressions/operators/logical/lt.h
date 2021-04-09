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

  LessThanOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


class LessThanOrEqOperator : public Operator
{


public:

  LessThanOrEqOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


