/*
  memory.cpp
  Codeus Tech
  Authored on   October 28, 2020
  Last Modified October 28, 2020
*/

/*
  Contains extended implementations for MemoryVariableManager operations
*/

#include "memory.h"


ErrorCode MemoryVariableManager::addMemoryVariable(Identifier ident)
{
  if (!getMemoryVariable(ident))
    active_variables.push_back(MemoryVariable(ident));
  else
  {
    l.log("E", "MemoryVariables", "Multiple memory variables with unique identifier");
    return 1;
  }

  return SUCCESS;
}


ErrorCode MemoryVariableManager::rmMemoryVariable(Identifier ident)
{
  for (Index i = 0; i < active_variables.size(); ++i)
    if (strcmp(ident, active_variables[i].Ident()) == 0)
      active_variables.erase(active_variables.begin() + i);

  return SUCCESS;
}


MemoryVariable* MemoryVariableManager::getMemoryVariable(Identifier ident)
{
  for (Index i = 0; i < active_variables.size(); ++i)
    if (strcmp(ident, active_variables[i].Ident()) == 0)
      return &active_variables[i];

  //  No Match
  return NULL;
}

TypeID MemoryVariableManager::getVariableType(Identifier ident)
{
  MemoryVariable* mem;
  if ((mem = getMemoryVariable(ident)))
    return mem->Type();

  return NULL;
}
