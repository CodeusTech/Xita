/*
  is.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified      May  1, 2020
*/

/*
  Contains backend functionality for explicit type checking
*/

#ifndef CONDITIONS_IS_H
#define CONDITIONS_IS_H

#include <xcs/types/types.h>
#include <xcs/std/operations.h>

/*
  Returns:
    0, if Successful
ErrorCode is_construct()
{
  //  Remove the last expression getting pushed to stack
  get_last_command();

  *
    Compare TOP Type vs SECOND Type
  *
  ConstructorID cSec = rs_sec_struct();

  push_int(cSec);
  push_int(last_constructor);

  rs_pop();

  //  Get Register Codes
  ADR topreg = rs_top();
  ADR secreg = rs_sec();
  char* top = get_reg(topreg, 32);
  char* sec = get_reg(secreg, 32);
  char* sec64 = get_reg(secreg, 64);

  char* str = (char*) malloc(50);

  //  Compare Type IDs
  sprintf(str, "cmp   %s, %s\n", sec, top);
  context.addInstruction(str);

  //  Create New Mangle Number
  for (int i = 0; i < 3; i++) mangle += rand();
  srand(time(NULL)+mangle);
  for (int i = 0; i < 4; i++) mangle += rand();
  unsigned long long mang = mangle;

  rs_pop();

  //  Branch if Equal to set
  sprintf(str, "beq   set_%llu\n", mang);
  context.addInstruction(str);

  sprintf(str, "mov   %s, #0\n", sec64);
  context.addInstruction(str);

  sprintf(str, "b     finish_%llu\n", mang);
  context.addInstruction(str);

  sprintf(str, "set_%llu:\n", mang);
  context.addInstruction(str);

  sprintf(str, "mov   %s, #1\n", sec);
  context.addInstruction(str);

  sprintf(str, "finish_%llu:\n", mang);
  context.addInstruction(str);

  rs_push(TYPE_BOOLEAN);

  //  Free Memory Buffers
  free(str);
  free(top);
  free(sec);
  free(sec64);

  //  Return Success
  return 0;
}
*/

/*
  Returns:
    0, if Successful
*/
ErrorCode isType()
{
  //  Remove the last expression getting pushed to stack
  context.popLastInstruction();

  pushData(context.LastType(), (Arbitrary) context.LastType());

  /*
    Compare TOP Type vs SECOND Type
  */

  //  If Possible, Type-Check statically
  if (context.TypeCheck())
  {
    l.log('d', "TypeCheck", "Invoked Type Check Successful");
  } else
  {
    l.log('e', "TypeCheck", "Invoked Type Check Failed");
  }

  //  TODO: Add Type Check Function
  pushData(TYPE_BOOLEAN, (Arbitrary) 1); //  True


  //  Get Register Codes
  ADR topreg = context.rsTop();
  ADR secreg = context.rsSec();
  char* top = get_reg(topreg, 32);
  char* sec = get_reg(secreg, 32);
  char* sec64 = get_reg(secreg, 64);

  char* str = (char*) malloc(50);

  //  Compare Type IDs
  sprintf(str, "cmp   %s, %s\n", sec, top);
  context.addInstruction(str);

  //  Create New Mangle Number
  for (int i = 0; i < 3; i++) mangle += rand();
  srand(time(NULL)+mangle);
  for (int i = 0; i < 4; i++) mangle += rand();
  unsigned long long mang = mangle;

  context.rsPop();

  //  Branch if Equal to set
  sprintf(str, "beq   set_%llu\n", mang);
  context.addInstruction(str);

  sprintf(str, "mov   %s, #0\n", sec64);
  context.addInstruction(str);

  sprintf(str, "b     finish_%llu\n", mang);
  context.addInstruction(str);

  sprintf(str, "set_%llu:\n", mang);
  context.addInstruction(str);

  sprintf(str, "mov   %s, #1\n", sec);
  context.addInstruction(str);

  sprintf(str, "finish_%llu:\n", mang);
  context.addInstruction(str);

  context.rsPush(TYPE_BOOLEAN);

  free(str);

  //  Return Success
  return 0;
}

#endif

