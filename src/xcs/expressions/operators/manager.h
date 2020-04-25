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
#include <xcs/regstack/structs.h>

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

  char* solveOperator(OperatorID oid, RegisterStack* rs)
{ 
  switch (oid)
  {
    //  2.e.I) Arithmetic
    case OPERATOR_ADDITION:
      return addition.resolve(rs);
      
    case OPERATOR_SUBTRACT:
      return subtract.resolve(rs);
    
    case OPERATOR_MULTIPLY:
      return multiply.resolve(rs);
    
    case OPERATOR_DIVISION:
      return division.resolve(rs);

    case OPERATOR_MODULUS:

      l.log('d', "Operators", "Resolved Modulus Operation");
      return SUCCESS;

    //  2.e.II) Bitwise

    //  2.e.III) Logical

    default:
      //  Default Operator
      l.log('e', "Operators", "Unrecognized operator node resolved");  
      return NULL; 
  }
}




};


