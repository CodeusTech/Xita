/*
  utils.h (memory)
  Codeus Tech
  Authored on   December 13, 2019
  Last Modified December 13, 2019
*/

/*
  Contains convenience utilities for manipulating memory variable nodes
*/

#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <xcs/std/typedefs.h>
#include <xcs/std/buffers.h>

#include <xcs/asm/text.h>
#include <xcs/regstack/utils.h>

#include "structs.h"

ErrorCode decl_memory_variable(Identifier ident)
{
  char* top = get_reg(rs_top(), 32);

  rs_pop();

  rs_push(2);

  MemoryVariableNode mvnode = MemoryVariableNode(ident, rs_top());

  memory_variables.push_back(mvnode);

  char* memreg = get_reg(memory_variables.back().get_register(), 32);

  char* str = (char*) malloc (50);
  sprintf(str, "ldr   %s, [%s]", memreg, top);
  add_command(str);

  free(str);
  free(top);
  free(memreg);

  //  Return Success
  return 0;
}

ErrorCode decl_memory_variable_this() 
{
  char* str = (char*) malloc(6);
  sprintf(str, "this");

  return decl_memory_variable(str);
}

/*
  Returns:
   -1, if Node doesn't exist
    0, if Successful

*/
ErrorCode undecl_memory_variable()
{
  if (memory_variables.size() == 0) return -1;

  memory_variables.pop_back();
  rs_pop();

  return 0;
}


MemoryVariableID find_memory_variable(Identifier ident)
{
  /*
    TODO: Error Check Inputs
  */

  for (unsigned int i = 0; i < memory_variables.size(); i++)
    if (strcmp(ident, memory_variables[i].get_identifier()) == 0)
      { free(ident); return (i + 1); }

  return 0;
}

ADR memory_variable_register(MemoryVariableID mvid)
{
  /*
    TODO: Error Check Inputs
  */

  return memory_variables[mvid-1].get_register();
}

TypeID memory_variable_type(MemoryVariableID mvid)
{
  /*
    TODO: Error Check Inputs
  */

  return memory_variables[mvid-1].get_type();
}

ErrorCode resolve_memory_variable(MemoryVariableID mvid)
{
  printf("Resolving Memory Variable: %s\n", memory_variables[mvid-1].get_identifier());
  
  context.push_reg(get_scope_curr(), memory_variable_type(mvid), memory_variable_register(mvid));


  //  Return Success
  return 0;
}


#endif
