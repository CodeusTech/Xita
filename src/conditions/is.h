/*
  is.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains backend functionality for explicit type checking
*/

#ifndef CONDITIONS_IS_H
#define CONDITIONS_IS_H

#include "../ident/types/types.h"

/*
  Returns:
    0, if Successful
*/
ErrorCode is_construct()
{
  //  Remove the last expression getting pushed to stack
  get_last_command();

  /*
    Compare TOP Type vs SECOND Type
  */
  ConstructorID cSec = rs_construct[scope_curr][rs_second()];

  push_int(cSec);
  push_int(last_constructor);

  rs_pop();

  //  Get Register Codes
  ADR topreg = rs[scope_curr][rs_top()];
  ADR secreg = rs[scope_curr][rs_second()];
  char* top = get_reg32(topreg);
  char* sec = get_reg32(secreg);

  char* str = (char*) malloc(50);

  //  Compare Type IDs
  sprintf(str, "cmp   %s, %s\n", sec, top);
  add_command(str);

  //  Create New Mangle Number
  for (int i = 0; i < 3; i++) mangle += rand();
  srand(time(NULL)+mangle);
  for (int i = 0; i < 4; i++) mangle += rand();
  unsigned long long mang = mangle;

  rs_pop();

  //  Branch if Equal to set
  sprintf(str, "beq   set_%llu\n", mang);
  add_command(str);

  sprintf(str, "mov   %s, #0\n", get_reg64(secreg);
  add_command(str);

  sprintf(str, "b     finish_%llu\n", mang);
  add_command(str);

  sprintf(str, "set_%llu:\n", mang);
  add_command(str);

  sprintf(str, "mov   %s, #1\n", sec);
  add_command(str);

  sprintf(str, "finish_%llu:\n", mang);
  add_command(str);

  rs_push();

  //  Free Memory Buffers
  free(str);
  free(top);
  free(sec);

  //  Return Success
  return 0;
}

/*
  Returns:
    0, if Successful
*/
ErrorCode is_type()
{
  //  Remove the last expression getting pushed to stack
  get_last_command();

  /*
    Compare TOP Type vs SECOND Type
  */
  TypeID tSec = infer_constructor(rs_construct[scope_curr][rs_second()]);

  push_int(tSec);
  push_int(last_type);

  rs_pop();

  //  Get Register Codes
  ADR top = rs[scope_curr][rs_top()];
  ADR sec = rs[scope_curr][rs_second()];

  char* str = (char*) malloc(50);

  //  Compare Type IDs
  sprintf(str, "cmp   %s, %s\n", get_reg32(sec), get_reg32(top));
  add_command(str);

  //  Create New Mangle Number
  for (int i = 0; i < 3; i++) mangle += rand();
  srand(time(NULL)+mangle);
  for (int i = 0; i < 4; i++) mangle += rand();
  unsigned long long mang = mangle;

  rs_pop();

  //  Branch if Equal to set
  sprintf(str, "beq   set_%llu\n", mang);
  add_command(str);

  sprintf(str, "mov   %s, #0\n", get_reg64(sec));
  add_command(str);

  sprintf(str, "b     finish_%llu\n", mang);
  add_command(str);

  sprintf(str, "set_%llu:\n", mang);
  add_command(str);

  sprintf(str, "mov   %s, #1\n", get_reg32(sec));
  add_command(str);

  sprintf(str, "finish_%llu:\n", mang);
  add_command(str);

  rs_push();

  free(str);

  //  Return Success
  return 0;
}

#endif

