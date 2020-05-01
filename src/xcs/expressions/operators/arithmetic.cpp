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

#include <xcs/regstack/structs.h>



/*
  1.) Operator Definitions
*/


/*
  1.b) Subtraction Operator
*/

  SubtractOperator::SubtractOperator()
  {
  
    op = strdup(string("(-)").c_str());
  }

  char* SubtractOperator::resolve(RegisterStack* rs)
  {
    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);
    sprintf(str, "  subs  %s, %s, %s", sec, sec, top);

    free(top);
    free(sec);

    return str;
  }

  /*
    1.c) Multiplication Operator
  */

  MultiplyOperator::MultiplyOperator()
  {
  
    op = strdup(string("(*)").c_str());
    is_communitive = true;
  }

  char* MultiplyOperator::resolve(RegisterStack* rs)
  {
    /*
      Type Check Operands
    */

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);
    sprintf(str, "  mul   %s, %s, %s", sec, sec, top);

    free(top);
    free(sec);

    return str;
  }

  /*
    1.d) Division Operator
  */

  DivisionOperator::DivisionOperator()
  {
  
    op = strdup(string("(/)").c_str());
  }

  char* DivisionOperator::resolve(RegisterStack* rs)
  {
    /*
      Type Check Operands
    */

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    char* top = get_reg(rs->top(), 32);
    char* sec = get_reg(rs->sec(), 32);

    char* str = (char*) malloc(50);
    sprintf(str, "  div   %s, %s, %s", sec, sec, top);

    free(top);
    free(sec);

    return str;
  }

  /*
    1.c) Modulus Operator
  */

  ModulusOperator::ModulusOperator()
  {
  
    op = strdup(string("(%)").c_str());
  }

  char* ModulusOperator::resolve(RegisterStack* rs)
  {
    /*
      Type Check Operands
    */

    /*
      Get top 2 registers
      Add together (according to type sizes)
    */

    //  TODO: This one is weird

    l.log('d', "Operators", "Modulus operation has been resolved");

    return SUCCESS;
  }