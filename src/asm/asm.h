/*
  asm.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Infrastructure for Procedurally Generating AArch64 Assembly Code
*/

#ifndef XCS_ASM_H
#define XCS_ASM_H

#include "header.h"

#include "stdlib.h"
#include "stdio.h"

/*
  Returns:
    0, if successful
    1, if assembly header fails
*/
int write_asm_file(char* filename)
{
  asm_file = fopen(filename, "w+");
  if (header_source(filename)) return 1;

  fclose(asm_file);

  return 0;
}

int delete_asm_file(char* filename)
{
  remove(filename);
}

#endif
