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

//  XCS Libraries
#include "bss.h"
#include "data.h"
#include "header.h"
#include "text.h"
#include "init.h"

//  Linux Libraries
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

  generate_bss(asm_file);
  generate_data(asm_file);
  generate_text(asm_file);

  fclose(asm_file);

  return 0;
}

/*
  Returns:
    0, if Successful
    1, if File Remove Fails
*/
int delete_asm_file(char* filename)
{
  remove(filename);

  return 0;
}

#endif
