/*
  manager.h (Operator)
  Codeus Tech
  Authored on   April 23, 2020
  Last Modified April 24, 2020
*/

/*
  Contains functions for managing operators and their operands/implementations
*/

#pragma once

#include <xcs/std/includes.h>

#include "arithmetic.h"
#include "logical.h"


class OperatorManager
{
  /*
    Private Data
  */

protected:

  //  Arithmetic Operators
  AdditionOperator addition;
  SubtractOperator subtract;
  MultiplyOperator multiply;
  DivisionOperator division;
  ModulusOperator  modulus;


public:

  /*
    Constructors
  */
  OperatorManager() { l.log('d', "Operators", "Initialized Operator Manager"); }

  ErrorCode solveOperator(OperatorID oid)
{ 
  switch (oid)
  {
    //  2.e.I) Arithmetic
    case OPERATOR_ADDITION:

      l.log('d', "Operators", "Resolved Addition Operation");
      return SUCCESS;

    case OPERATOR_SUBTRACT:

      l.log('d', "Operators", "Resolved Subtraction Operation");
      return SUCCESS;
    
    case OPERATOR_MULTIPLY:

      l.log('d', "Operators", "Resolved Multiplication Operation");
      return SUCCESS;
    
    case OPERATOR_DIVISION:

      l.log('d', "Operators", "Resolved Division Operation");
      return SUCCESS;

    case OPERATOR_MODULUS:

      l.log('d', "Operators", "Resolved Modulus Operation");
      return SUCCESS;

    //  2.e.II) Bitwise

    //  2.e.III) Logical

    default:
      //  Default Operator
      l.log('e', "Operators", "Unrecognized operator node resolved");  
      return 1; 
  }
}




};


