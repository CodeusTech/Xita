/*
  instance.h (data)
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  DataInstance are building blocks in the XCS compiler.  
  Each holds data for exactly 1 return expression.
*/

#pragma once

#include <xcs/std/includes.h>


struct DataInstance
{
  TypeID tid;
  Arbitrary value;
  
};


