/*
  asm.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified    April 24, 2020
*/

/*
  Infrastructure for Procedurally Generating AArch64 Assembly Code
*/

#ifndef XCS_ASM_H
#define XCS_ASM_H

//  Linux Libraries
#include "stdlib.h"
#include "stdio.h"

//  XCS Libraries
#include "header.h"

/*
  Returns:
    0, if Successful
    1, if File Remove Fails
*/
int delete_asm_file(char* filename)
{
  remove(filename);

  return SUCCESS;
}

#endif
