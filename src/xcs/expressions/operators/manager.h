/*
  manager.h (Operator)
  Codeus Tech
  Authored on   April 23, 2020
  Last Modified April 30, 2020
*/

/*
  Contains functions for managing operators and their operands/implementations
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/regstack/structs.h>

#include "arithmetic/arithmetic.h"
#include "logical/logical.h"
#include "bitwise/bitwise.h"
#include "memory/memops.h"

class ContextManager;

class OperatorManager
{
  /*
    Private Data
  */

protected:

  //  Arithmetic Operators
  AdditionOperator addition = AdditionOperator(this);
  SubtractOperator subtract;
  MultiplyOperator multiply;
  DivisionOperator division;
  ModulusOperator  modulus;

  //  Bitwise Operators
  BitwiseAndOperator bitwise_and        = BitwiseAndOperator(this);
  BitwiseOrOperator bitwise_or          = BitwiseOrOperator(this);
  BitwiseXorOperator bitwise_xor        = BitwiseXorOperator(this);
  BitwiseShiftLeftOperator bitwise_shl  = BitwiseShiftLeftOperator(this);
  BitwiseShiftRightOperator bitwise_shr = BitwiseShiftRightOperator(this);

  //  Logical Operators
  LogicalANDOperator  logical_and     = LogicalANDOperator(this);
  LogicalOROperator   logical_or      = LogicalOROperator(this);
  LogicalXOROperator  logical_xor     = LogicalXOROperator(this);
  GreaterThanOperator logical_gt      = GreaterThanOperator(this);
  GreaterThanOrEqOperator logical_gte = GreaterThanOrEqOperator(this);
  LessThanOperator    logical_lt      = LessThanOperator(this);
  LessThanOrEqOperator logical_lte    = LessThanOrEqOperator(this);
  EqualToOperator     logical_eq      = EqualToOperator(this);
  NotEqualOperator    logical_neq     = NotEqualOperator(this);
  LogicalNotOperator  logical_not     = LogicalNotOperator(this);


public:
  //  Public for Operator Access
  ContextManager* context;

  /*
    Constructors
  */
  OperatorManager(ContextManager* context) 
    : context(context)
  { l.log('d', "Operators", "Initialized Operator Manager"); }


  char* solveOperator(OperatorID oid, RegisterStack* rs);


};


