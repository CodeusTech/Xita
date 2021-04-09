/*
  memory.h
  Codeus Tech
  Authored on   October 28, 2020
  Last Modified October 28, 2020
*/

/*
  Contains backend functionality for memory get/set operators
*/

#pragma once

#include <vector>
#include <string>

#include <xcs/std/includes.h>
#include "variable.h"


class MemoryVariableManager
{
  /*
    Private Access
  */
  std::vector<MemoryVariable> active_variables;

public:
  MemoryVariableManager() {}

  ErrorCode addMemoryVariable(Identifier);
  ErrorCode rmMemoryVariable(Identifier);

  MemoryVariable* getMemoryVariable(Identifier);
  TypeID getVariableType(Identifier);


};
