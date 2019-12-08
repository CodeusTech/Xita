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

#include "structs.h"

ADR rs_top()
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.top(); }
  return functions[s-1].get_top();
}

ADR rs_sec()
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.sec(); }
  return functions[s-1].get_sec();
}

TypeID rs_top_type()
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.top_type(); }
  return functions[s-1].get_top_type();
}

TypeID rs_sec_type()
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.sec_type(); }
  return functions[s-1].get_sec_type();
}

ErrorCode rs_push(TypeID tid)
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.push(tid); }
  return functions[s-1].push(tid);
}

ErrorCode rs_push_reg(TypeID tid, ADR reg)
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.push_reg(tid, reg); }
  return functions[s-1].push_reg(tid, reg);
}

ErrorCode rs_pop()
{
  Scope s = get_scope_curr();

  if (s == 0) { return rs_root.pop(); }
  return functions[s-1].pop();
}

ErrorCode end_scope()
{
  //  TODO: FIX THIS
  scope_curr = 0;
  last_type = 2;

  for (unsigned int i = 0; i < rs_root.size(); i++)
  {
    rs_root.pop();
  }

  return 0;
}


#endif
