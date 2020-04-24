/*
  arithmetic.cpp
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains extended implementations for Arithmetic Operators in XCS

  Table of Contents
  =================
  1.) Initialize Arithmetic Operators
  2.) Operator Definitions
    2.a) Addition Operator
*/

#include "arithmetic.h"



/*
  1.) Operator Definitions
*/

  /*
    1.a) Addition Operator
  */

  AdditionOperator::AdditionOperator()
  {
    super();
    op = strdup(string("(+)").c_str());
    is_communitive = true;
  }

  ErrorCode AdditionOperator::resolve()
  {
    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    l.log('d', "Operators", "Addition operation has been resolved");

    return SUCCESS;
  }

  /*
    1.b) Subtraction Operator
  */

  SubtractOperator::SubtractOperator()
  {
    super();
    op = strdup(string("(-)").c_str());
  }

  ErrorCode SubtractOperator::resolve()
  {
    /*
      Type Check Operands
    */
    if (super::resolve()) return 1; //  Type Check Failed

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    l.log('d', "Operators", "Subtraction operation has been resolved");

    return SUCCESS;
  }

  /*
    1.c) Multiplication Operator
  */

  MultiplyOperator::MultiplyOperator()
  {
    super();
    op = strdup(string("(*)").c_str());
    is_communitive = true;
  }

  ErrorCode MultiplyOperator::resolve()
  {
    /*
      Type Check Operands
    */
    if (super::resolve()) return 1; //  Type Check Failed

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    l.log('d', "Operators", "Multiplication operation has been resolved");

    return SUCCESS;
  }

  /*
    1.d) Division Operator
  */

  DivisionOperator::DivisionOperator()
  {
    super();
    op = strdup(string("(/)").c_str());
  }

  ErrorCode DivisionOperator::resolve()
  {
    /*
      Type Check Operands
    */
    if (super::resolve()) return 1; //  Type Check Failed

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    l.log('d', "Operators", "Division operation has been resolved");

    return SUCCESS;
  }

  /*
    1.c) Modulus Operator
  */

  ModulusOperator::ModulusOperator()
  {
    super();
    op = strdup(string("(%)").c_str());
  }

  ErrorCode ModulusOperator::resolve()
  {
    /*
      Type Check Operands
    */
    if (super::resolve()) return 1; //  Type Check Failed

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    l.log('d', "Operators", "Modulus operation has been resolved");

    return SUCCESS;
  }