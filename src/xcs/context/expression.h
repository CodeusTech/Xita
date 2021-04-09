/*
  expression.h (Context)
  Codeus Tech
  Authored on   April 26, 2020
  Last Modified April 26, 2020
*/

/*
  Contains functionality for managing expressions in a context
*/

#pragma once


enum ExpressionType
{
  EXP_LITERAL      = 1,
  EXP_CONDITION    = 2,
  EXP_TYPE         = 3,
  EXP_TYPECLASS    = 4,
  EXP_CONSTRUCTOR  = 5,
  EXP_CONSTANT     = 6,
  EXP_FUNCTION     = 7,
  EXP_PARAMETER    = 8,
  EXP_MODULE       = 9,
  EXP_MEMORY       = 10
};



