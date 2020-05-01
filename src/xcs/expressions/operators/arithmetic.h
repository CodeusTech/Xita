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

#include "arithmetic/addition.h"

/*
  1.) Operator Definitions
*/


/*
  1.b) Subtraction Operator  --  (+)
*/
class SubtractOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  SubtractOperator();
  char* resolve(RegisterStack* rs);
};

/*
  1.c) Multiplication Operator  --  (+)
*/
class MultiplyOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  MultiplyOperator();
  char* resolve(RegisterStack* rs);
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  1.d) Division Operator  --  (+)
*/
class DivisionOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  DivisionOperator();
  char* resolve(RegisterStack* rs);
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};

/*
  1.e) Modulus Operator  --  (+)
*/
class ModulusOperator
{
private:
  char* op;
  bool is_communitive = true;
public:
  ModulusOperator();
  char* resolve(RegisterStack* rs);
  ErrorCode override(TypeID rtn_type, TypeID left, TypeID right);
};


#include "arithmetic.cpp"
