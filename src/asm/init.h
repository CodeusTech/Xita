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



extern char** start_asm_text;
extern char**  curr_asm_text;
extern int count_asm_text;
extern int index_asm_text;


/*
  1.) BSS Section
*/

/* 1.a) Initialize BSS Buffers

  Returns:
    0, if Successful
*/
ErrorCode init_asm_bss()
{
  //  STUB STUB STUB
  printf("BSS Buffers Initialized\n");

  /*
    TODO:
     * Error Check
     * Create Buffers
     * Allocate Memory
  */

  return 0;
}

/* 1.b) Clear BSS Buffers

  Returns:
    0, if Successful
*/
ErrorCode clear_asm_bss()
{
  // STUB STUB STUB
  printf("BSS Buffers Initialized\n");

  /*
    TODO:
     * Error Check
     * Deallocate Buffers 
      - Consider using Recursion
  */

  //  Return Success
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
  //  STUB STUB STUB
  
  /*
    TODO:
     * Error Check
     * Create Buffers
     * Allocate Memory
  */

  // Return Success
  return 0;
}

/* 2.b) Clear Data Buffers

  Returns:
    0, if Successful
*/
ErrorCode clear_asm_data()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Deallocate Buffers
      - Consider using Recursion
  */

  //  Return Success
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
  start_asm_text = (char**) malloc(256 * sizeof(char*));
  curr_asm_text  = start_asm_text;
  index_asm_text = 0;

  start_asm_text[255] = (char*) 0;
  curr_asm_text[255]  = (char*) 0;

  //  Return Success
  return 0;
}

/*  3.b) Clear Text Buffers

  Returns:
    0, if Successful
*/
ErrorCode clear_asm_text()
{
  curr_asm_text = start_asm_text;

  //  If not at end of list, recurse next buffer
  if ( start_asm_text[255] != (char*) 0)
  {
    start_asm_text = (char**) start_asm_text[255];
    clear_asm_text((char**) start_asm_text[255]);
  }

  //  Free Current Buffer
  free(curr_asm_text);

  return 0;
}


#endif

