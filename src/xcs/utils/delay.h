/*
  delay.h
  Codeus Tech
  Authored on   December 19, 2019
  Last Modified December 19, 2019
*/

/*
  Contains definition for XCS 'delay' keyword
*/

#ifndef UTILS_DELAY_H
#define UTILS_DELAY_H

//  Linux Imports
#include <stdlib.h>
#include <stdio.h>

//  XCS Imports
#include <xcs/std/typedefs.h>
#include <xcs/std/error.h>

#include "mangle.h"
#include <xcs/asm/text.h>
#include <xcs/regstack/utils.h>

ErrorCode exp_delay()
{
  char* str = (char*) malloc(50);
  unsigned long long mang = get_mangle();

  char* reg = get_reg(rs_top(), 32);

  sprintf(str, "__delay_%llu:", mang);
  add_command(str);

  sprintf(str, "subs  %s, %s, #1", reg, reg);
  add_command(str);

  sprintf(str, "cmp   %s, #1", reg);
  add_command(str);

  //  Jump if Less Than
  sprintf(str, "blt   finish_%llu", mang);
  add_command(str);

  sprintf(str, "b    __delay_%llu", mang);
  add_command(str);

  sprintf(str, "finish_%llu:", mang);
  add_command(str);

  return SUCCESS;
}


#endif
