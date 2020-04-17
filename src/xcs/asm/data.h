/*
  data.h
  Cody Fagley 
  Authored on   February 16, 2019
  Last Modified   August  7, 2019
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


//  Linux Libraries
#include "stdbool.h"

//  XCS Libraries
#include "text.h"

#include <xcs/std/buffers.h>
#include <xcs/std/typedefs.h>
#include <xcs/regstack/regstack.h>


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
  l.log("Debug","Debug",".data Section Generated");
  //printf(".data Section Generated\n");

  //  Return Success
  return 0;
}





#endif
