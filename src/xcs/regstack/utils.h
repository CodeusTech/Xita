/*
  utils.h (regstack)
  Codeus Tech
  Authored on   October 31, 2019
  Last Modified October 31, 2019
*/

/*
  Contains Convenience Utilities for manipulating the register stack
*/

#ifndef REGSTACK_UTILS_H
#define REGSTACK_UTILS_H


#include <xcs/std/typedefs.h>
#include <xcs/std/scope.h>
#include <xcs/std/buffers.h>
#include <xcs/std/error.h>

#include "structs.h"


//   Get Top/Second of Current Scope's Register Stack
ADR rs_top() { return context->get_top(get_scope_curr()); }
ADR rs_sec() { return context->get_sec(get_scope_curr()); }

TypeID rs_top_type() { return context->get_top_type(get_scope_curr()); }
TypeID rs_sec_type() { return context->get_sec_type(get_scope_curr()); }

ErrorCode rs_push(TypeID tid) { return context->push(get_scope_curr(), tid); }
ErrorCode rs_push_reg(TypeID tid, ADR reg) { return context->push_reg(get_scope_curr(), tid, reg); }
ErrorCode rs_pop() { return context->pop(get_scope_curr()); }

ErrorCode end_scope()
{
  //  TODO: FIX THIS
  scope_curr = 0;
  last_type = 2;

  for (unsigned int i = 0; i < context->count_ADRs(0); i++) context->pop(0);

  return SUCCESS;
}

ErrorCode add_function(Identifier ident) 
{
  list<string> tmp;
  asm_text.push_back(tmp);
  context->add_function(FunctionNode(ident));

  return SUCCESS;
}


#endif
