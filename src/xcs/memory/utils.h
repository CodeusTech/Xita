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

#include "structs.h"

ErrorCode decl_memory_variable(Identifier ident)
{
  //  Make Room on Register Stack for new entry
  rs_push(last_type);

  if (memory_variables == NULL)
    memory_variables = new MemoryVariableNode(ident, rs_top(), NULL);
  else
    memory_variables->add_variable(ident, rs_top());

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "ldr %s,[%s,0]", top, sec);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}

/*
  Returns:
   -1, if Node doesn't exist
    0, if Successful

*/
ErrorCode undecl_memory_variable(Identifier ident)
{
  if (memory_variables == NULL) return -1;

  MemoryVariableNode* node = memory_variables;

  return 0;
}


ADR find_memory_variable(Identifier ident)
{
  if (memory_variables == NULL) return 0;

  MemoryVariableNode* node = memory_variables->find(ident);

  if (node) return node->get_register();

  return 0;
}


#endif
