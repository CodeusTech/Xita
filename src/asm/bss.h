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


/*
  1.) Structure
*/

/* 1.a) Generate BSS

  Returns:
    0, if Successful
*/
ErrorCode generate_bss()
{
  //  STUB STUB STUB
  printf(".bss Section Generated\n");

  /*
    TODO:
     * Error Check
     * Produce Section Header and Write to Assembly File
     * Write Out Entire BSS Buffer
  */

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
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Store Data into .bss Section
  */

  // Return Success
  return 0;
}



#endif
