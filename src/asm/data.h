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


#include "text.h"

#include "stdbool.h"
#include "../regstack/operations.h"

extern void** values_const;

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
  free(values_const);
  //  Pretty up file with new lines
  fprintf(filename, "\n\n");

  //  Return Success
  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add Constant to Data
Adds Constant to .data Section

  Returns:
    0, if Successful
*/
ErrorCode decl_constant(Identifier ident)
{
  //  If at final link in list, create a new tail list
  if (index_asm_data == 255)
  {
    curr_asm_data[255] = (Command*) malloc(256 * sizeof(Command));
    values_const[255] = (void**) malloc(256 * sizeof(void*));
    ident_const[255] = (Identifier*) malloc(256 * sizeof(Identifier));

    curr_asm_data = (Command*) curr_asm_data[255];
    values_const  = (void**)  values_const[255];
    ident_const   = (Identifier*) ident_const[255];

    index_asm_data = 0;
  }

  //  Allocate Command Buffers
  char* str = (char*) malloc(256);
  char* size = (char*) malloc(10);

  //  'bytes' indicates the assembly size directive to be used
  int bytes;

  //  Determine bytes via data type
  if ((last_type > 2 && last_type < 5) || (last_type > 13 && last_type < 16)) bytes = 1;
  else if (last_type > 4 && last_type < 7) bytes = 2;
  else if (last_type > 6 && last_type < 9) bytes = 4;
  else if (last_type == 2 || (last_type > 8 && last_type < 11)) bytes = 8;
  
  /*
    Commit constant to assembly file
  */
  switch (bytes)
  {
    case 1: //  1-Byte Alignment
      sprintf(size, "byte");
      sprintf(str, "%s: .%s #%u\n", ident, size, (unsigned int) last_data);
      values_const[index_asm_data] = (unsigned int) last_data;
      break;
    case 2: //  2-Byte Alignment
      sprintf(size, "hword");
      sprintf(str, "%s: .%s #%u\n", ident, size, (unsigned int) last_data);
      values_const[index_asm_data] = (unsigned int) last_data;
      break;
    case 4: //  4-Byte Alignment
      sprintf(size, "word");
      sprintf(str, "%s: .%s #%lu\n", ident, size, (unsigned long) last_data);
      values_const[index_asm_data] = (unsigned long) last_data;
      break;
    case 8: //  8-Byte Alignment
      sprintf(size, "dword");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      values_const[index_asm_data] = (unsigned long long) last_data;
      break;
    default:  
      //  Invalid Attempt
      return 1;
  }

  //  Set Identifier
  ident_const[index_asm_data] = strdup(ident);
    
  //  Increment to prepare for next constant
  curr_asm_data[index_asm_data] = strdup(str);
  index_asm_data++;
  count_asm_data++;

  //  Free Local String Buffers
  free(str);
  free(size);
  free(ident);

  // Return Success
  return 0;
}


/*
  3.) Get Constant Value
*/
void* get_const(Identifier ident)
{
  for (int i = 0; i < count_asm_data; i++)
  {
    if (strcmp(ident, ident_const[i]) == 0) return (values_const[i]);
  }

  return 0;
}


#endif
