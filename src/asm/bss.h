/*
  bss.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified March 25, 2019
*/

/*
  .bss Section Contains Uninitialized Data (Variables)

  Table of Contents
  =================
  1.) Structure
    1.a) Generate BSS
  2.) Operations
    2.a) Add to BSS
*/

#ifndef ASM_BSS_H
#define ASM_BSS_H


//  Linux Libraries
#include <string>
#include <list>

using namespace std;

using std::list;
using std::vector;
using std::string;


/*
  1.) Structure
*/

/* 1.a) Generate BSS

  Returns:
    0, if Successful
*/
ErrorCode generate_bss(FILE* filename)
{
  //  STUB STUB STUB
  printf(".bss Section Generated\n");

  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .bss.xcs:\n");

  /* Print TEXT Buffer Contents to File */
  for (list<string>::iterator it = asm_bss.begin(); it != asm_bss.end(); it++)
    fprintf(filename, "  %s\n", (*it).c_str());

  //  Pretty up file with new lines
  fprintf(filename, "\n\n");

  //  Return Success
  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add to BSS
  Adds BSS Command to .bss Section of Assembly File

  Returns:
    0, if Successful
*/
ErrorCode add_to_bss(Identifier ident, TypeID tid)
{
  /*
    STUB STUB STUB
  */

  // Return Success
  return 0;
}



#endif
