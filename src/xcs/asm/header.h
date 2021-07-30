/*
  header.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Prints the approriate header for an AArch64 assembly file
*/

#ifndef ASM_HEADER_H
#define ASM_HEADER_H

#include "stdio.h"
#include <xcs/std/includes.h>

FILE* asm_file;

// Generate Assembly Header for Source Module
int header_source(char* mod_name)
{
  fprintf(asm_file, "//  %s\n", mod_name);
  fprintf(asm_file, "//  Cross-Compiled using Xita Control System: v%s\n\n", XCSL_VERSION);
  
  //  Return 0, if Successful
  return SUCCESS;
}




#endif
