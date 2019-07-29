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
#include "../globals/buffers.h"
#include "../globals/structs.h"

#include "stdbool.h"
#include "../regstack/operations.h"

/*
  1.) Structure
*/

/* 1.a) Generate Data

  Returns:
    0, if Successful
*/
ErrorCode generate_data(FILE* filename)
{
  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .data.xcs:\n");

    /* Print TEXT Buffer Contents to File */
    for (list<string>::iterator it = asm_data.begin(); it != asm_data.end(); it++)
      fprintf(filename, "  %s\n", (*it).c_str());

  //  Pretty up file with new lines
  fprintf(filename, "\n\n");

  //  Stub Stub Stub
  printf(".data Section Generated\n");

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
  //  Allocate Command Buffers
  char* str = (char*) malloc(256);
  char* size = (char*) malloc(10);

  node_constant cnst;
  cnst.const_ident = strdup(ident);
  cnst.const_type  = last_type;

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
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 2: //  2-Byte Alignment
      sprintf(size, "hword");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 4: //  4-Byte Alignment
      sprintf(size, "word");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    case 8: //  8-Byte Alignment
      sprintf(size, "dword");
      sprintf(str, "%s: .%s #%llu\n", ident, size, (unsigned long long) last_data);
      cnst.value = (void*) (unsigned long long) last_data;
      break;
    default:  
      //  Invalid Attempt
      return 1;
  }
    
  //  Increment to prepare for next constant
  asm_data.push_back(strdup(str));
  constants.push_back(cnst);

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
  for (vector<node_constant>::iterator it = constants.begin(); it != constants.end(); it++)
    if (strcmp(((*it).const_ident), ident) == 0) return (*it).value;

  return 0;
}


#endif
