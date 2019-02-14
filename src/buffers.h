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
*/

#ifndef XCS_BUFFERS_H
#define XCS_BUFFERS_H

/*
  1.) Assembly Buffers
*/

char** buf_asm_text;


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
  buf_asm_text = (char**) malloc(256 * sizeof(char*));

  buf_asm_text[255] = (char*) 0;

  return 0;
}

/*  Frees All Memory Associated with AArch64 Text Buffer
  Returns:
    0, if Successful
*/
int clear_buffer(char** buffer)
{

  //  If not at end of list, recurse next buffer
  if ( buf_asm_text[255] != (char*) 0)
    clear_buffer((char**) buf_asm_text[255]);

  //  Free Current Buffer
  free(buffer);

  return 0;
}


#endif
