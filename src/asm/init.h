/*
  init.h (Assembly)
  Cody Fagley
  Authored on   March  8, 2019
  Last Modified March 25, 2019
*/

/*
  Contains Initialization Functionality for Generating Assembly

  Table of Contents
  =================
  1.) BSS Section
    1.a) Initialize BSS Buffers
    1.b) Clear BSS Buffers
  2.) Data Section
    2.a) Initialize Data Buffers
    2.b) Clear Data Buffers
  3.) Text Section
    3.a) Initialize Text Buffers
    3.b) Clear Text Buffers
*/

#ifndef ASM_INIT_H
#define ASM_INIT_H

#include "../globals/structs.h"

/*
  Global Assembly Data
*/

//  .bss metadata
extern Variable* start_asm_bss;
extern Variable* curr_asm_bss;
extern unsigned int count_asm_bss;
extern unsigned int index_asm_bss;

//  .data metadata
extern Constant* start_asm_data;
extern Constant* curr_asm_data;
extern unsigned int count_asm_data;
extern unsigned int index_asm_data;

//  .text metadata
extern Command** start_asm_text;
extern Command*  curr_asm_text;
extern unsigned int* count_asm_text;
extern unsigned int* index_asm_text;


/*
  1.) BSS Section
*/

/* 1.a) Initialize BSS Buffers

  Returns:
    0, if Successful
*/
ErrorCode init_asm_bss()
{
  start_asm_bss = (char**) malloc(256 * sizeof(char*));
  curr_asm_bss = start_asm_bss;
  count_asm_bss = 0;
  index_asm_bss = 0;

  start_asm_bss[255] = (char*) 0;
  curr_asm_bss[255]  = (char*) 0;

  // Return Success
  return 0;
}


/*
  2.) Data Section
*/

/* 2.a) Initialize Data Buffers

  Returns:
    0, if Successful
*/
ErrorCode init_asm_data()
{
  start_asm_data = (char**) malloc(256 * sizeof(char*));
  curr_asm_data = start_asm_data;
  count_asm_data = 0;
  index_asm_data = 0;

  start_asm_data[255] = (char*) 0;
  curr_asm_data[255]  = (char*) 0;

  // Return Success
  return 0;
}


/*
  3.) Text Section
*/

/*  3.a) Initialize Text Buffers

  Returns:
    0, if Successful
*/
ErrorCode init_asm_text()
{
  //  Allocate Memory
  start_asm_text = (Command**) malloc(256 * sizeof(Command*));
  start_asm_text[0] = (Command*) malloc(256 * sizeof(Command));
  curr_asm_text  = start_asm_text[0];
  count_asm_text = (unsigned int*) malloc(256*sizeof(unsigned int));
  index_asm_text = (unsigned int*) malloc(256*sizeof(unsigned int));

  start_asm_text[255] = (char**) 0;
  curr_asm_text[255]  = (char*) 0;

  //  Return Success
  return 0;
}



#endif

