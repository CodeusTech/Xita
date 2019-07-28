/*
  data.h
  Cody Fagley 
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  .data Section contains Initialized Data (Constants)

  Table of Contents
  =================
  1.) Structure
    1.a) Generate Data
  2.) Operations
    2.a) Add Integer to Data
    2.b) Add Real to Data
    2.c) Add Boolean to Data
    2.d) Add Character to Data
    2.e) Add String to Data
    2.f) Add List to Data
*/

#ifndef ASM_DATA_H
#define ASM_DATA_H

#include "stdbool.h"

/*
  1.) Structure
*/

/* 1.a) Generate Data

  Returns:
    0, if Successful
*/
ErrorCode generate_data(FILE* filename)
{
  //  Stub Stub Stub
  printf(".data Section Generated\n");

  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .data.xcs:\n");
  
  curr_asm_data = start_asm_data;

  /* Print TEXT Buffer Contents to File */
  for (int i = 0; i < count_asm_data; i++)
  {
    if (i == 255) 
    {
      curr_asm_data = (char**) start_asm_data[i];
      free(start_asm_data);
      i = 0;
      count_asm_data -= 255;
    }
    fprintf(filename, "  %s", curr_asm_data[i]);
    free(curr_asm_data[i]);
  }

  free(curr_asm_data);
  //  Pretty up file with new lines
  fprintf(filename, "\n\n");

  //  Return Success
  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add Integer to Data
Adds Integer Constant to .data Section

  Returns:
    0, if Successful
    1, if `bytes` is invalid
*/
ErrorCode add_constant_int(Identifier ident, int value, int bytes)
{
  if (index_asm_data == 255)
  {
    curr_asm_data[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_data = (Command*) curr_asm_data[255];

    index_asm_data = 0;
  }

  char* str = (char*) malloc(256);
  char* size = (char*) malloc(10);
  
  switch (bytes)
  {
    case 1:
      sprintf(size, "byte");
      break;
    case 2:
      sprintf(size, "hword");
      break;
    case 4:
      sprintf(size, "word");
      break;
    case 8:
      sprintf(size, "dword");
      break;
    default:
      return 1;
  }

  sprintf(str, "%s: .%s #%d", ident, size, value);
    
  curr_asm_data[index_asm_data] = strdup(str);
  index_asm_data++;
  count_asm_data++;

  free(str);
  free(size);

  // Return Success
  return 0;
}

/* 2.b) Add Real to Data
Adds Real Constant to .data Section

  Returns:
    0, if Successful
*/
ErrorCode add_real_to_data(Identifier ident, double value)
{
  //  STUB STUB STUB STUB
  
  /*
    TODO:
     * Error Check
     * Print Real Constant to .data Section
  */

  //  Return Success
  return 0;
}

/* 2.d) Add Character to Data

  Returns:
    0, if Successful
*/
ErrorCode add_char_to_data(Identifier ident, char value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print Character Constant to .data Section
  */

  //  Return Success

  return 0;
}

/* 2.e) Add String to Data

  Returns:
    0, if Successful
*/
ErrorCode add_constant_str(Identifier ident, char* string)
{
  if (index_asm_data == 255)
  {
    curr_asm_data[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_data = (Command*) curr_asm_data[255];

    index_asm_data = 0;
  }

  char* str = (char*) malloc(256);



  sprintf(str, "%s SETS \"%s\"", ident, string);
    
  curr_asm_data[index_asm_data] = strdup(str);
  index_asm_data++;
  count_asm_data++;

  free(str);

  //  Return Success
  return 0;
}

/* 2.f) Add List to Data

NOTE: Constant Lists are only available in Linux-to-XCS Cross Compiler
  Returns:
    0, if Successful
*/
ErrorCode add_list_to_data(Identifier ident, long value)
{
  //  STUB STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Print List Constant to .data Section
  */

  //  Return Success

  return 0;
}

#endif
