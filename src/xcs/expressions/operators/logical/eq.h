/*
  eq.h (Logical)
  Codeus Tech
  Authored on   April 29, 2020
  Last Modified April 29, 2020
*/

/*
  Contains structure/definitions for 'Equal To', 'Not Equal To' Operations 
*/

#pragma once

#include <xcs/std/includes.h>

#include "../structs.h"


class EqualToOperator : public Operator
{


public:

  EqualToOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;

};


class NotEqualOperator : public Operator
{

public:

  NotEqualOperator(OperatorManager* manager) : Operator(manager)
  { }

  char* resolve(RegisterStack* rs) override;
};

class LogicalNotOperator : public Operator
{

public:

  LogicalNotOperator(OperatorManager* manager) : Operator(manager) 
  { }

  char* resolve(RegisterStack* rs) override;
};

