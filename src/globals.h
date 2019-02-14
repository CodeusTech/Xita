/*
  buffers.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains shared buffers between Flex/Bison && XCS Driver

  Table of Contents
  =================
  1.) Assembly Buffers
  2.) Function Buffers
  3.) Type Buffers
*/

#ifndef XCS_BUFFERS_H
#define XCS_BUFFERS_H

/*
  1.) Assembly Buffers
*/

char** start_asm_text;
char**  curr_asm_text;
int count_asm_text;
int index_asm_text;

char** start_asm_bss;
char**  curr_asm_bss;
int count_asm_bss;
int index_asm_bss;


/*
  TODO:  
    MAKE init_buffer AND clear_buffer ARBITRARY FOR ANY BUFFER
*/

/*  Initialize AArch64 Text Buffer
  Returns:
    0, if Successful
*/
int init_buffer(char** buffer)
{
  //  Allocate Memory
  start_asm_text = (char**) malloc(256 * sizeof(char*));
  curr_asm_text  = start_asm_text;
  index_asm_text = 0;

  start_asm_text[255] = (char*) 0;
  curr_asm_text[255]  = (char*) 0;

  return 0;
}

/*  Frees All Memory Associated with AArch64 Text Buffer
  Returns:
    0, if Successful
*/
int clear_buffer(char** buffer)
{

  //  If not at end of list, recurse next buffer
  if ( start_asm_text[255] != (char*) 0)
    clear_buffer((char**) start_asm_text[255]);

  //  Free Current Buffer
  free(buffer);

  return 0;
}

/*
  2.) Function Buffers
*/

char** ident_functions;
char** ident_constants;

/*
  3.) Type Buffers
*/

char** ident_types;
char** ident_constructors;
char** ident_typeclasses;

#endif
