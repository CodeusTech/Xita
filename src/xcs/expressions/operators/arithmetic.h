/*
  arithmetic.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structure/implementations for using arithmetic operators

  Table of Contents
  =================
  1.) Initialize Arithmetic Operators
  2.) Operator Definitions
    2.a) Addition Operator
    2.b) Subtract Operator
    2.c) Multiply Operator
    2.d) Division Operator
    2.e) Modulus Operator
*/

#pragma once

#include <xcs/std/includes.h>

#include "structs.h"


/*
  1.) Operator Definitions
*/

/*
  1.a) Addition Operator  --  (+)
*/
class AdditionOperator : public OperatorNode
{
private:
  typedef OperatorNode super;
public:
  AdditionOperator();
  ErrorCode resolve() override;
};

/*
  1.b) Subtraction Operator  --  (+)
*/
class SubtractOperator : public OperatorNode
{
private:
  typedef OperatorNode super;
public:
  SubtractOperator();
  ErrorCode resolve() override;
};

/*
  1.c) Multiplication Operator  --  (+)
*/
class MultiplyOperator : public OperatorNode
{
private:
  typedef OperatorNode super;
public:
  MultiplyOperator();
  ErrorCode resolve() override;
};

/*
  1.d) Division Operator  --  (+)
*/
class DivisionOperator : public OperatorNode
{
private:
  typedef OperatorNode super;
public:
  DivisionOperator();
  ErrorCode resolve() override;
};

/*
  1.e) Modulus Operator  --  (+)
*/
class ModulusOperator : public OperatorNode
{
private:
  typedef OperatorNode super;
public:
  ModulusOperator();
  ErrorCode resolve() override;
};


#include "arithmetic.cpp"
