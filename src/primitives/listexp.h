/*
  listexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains list primitive expressions

  Definitions
  ===========

  
  Table of Contents
  =================
  1.) List Literals
    1.a) List Constructor
    1.b) List Tail
  2.) List Arithmetic
    2.a) Append Lists
  3.) List Traversal
*/

#ifndef PRIMITIVES_LISTEXP_H
#define PRIMITIVES_LISTEXP_H

//  XCS Libraries
#include "typecodes.h"
#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include "../globals/structs.h"

/*
  1.) List Literals
*/

/* 1.a) List Constructor

  Returns:
    0, if Successful
*/
int list_construct(TypeID tid, Arbitrary data)
{
  /*
    TODO: 
      * Check Size of Type ID
      * Allocate Dynamic Memory
      * Construct Data Node
      * Repeat for Each Node in List
  */
  //  Calculate Node Size
  unsigned long nsize = _xcs_get_size(tid);
  nsize += 8; //  Add Pointer to Next Node

  //  Move Node Size to OSP for memory allocation
  char* str = (char*) malloc (50);

  //  Move Node Size to OSP for Memory Allocation
  sprintf(str, "  mov x28, #%lu", nsize);
  add_command(str);

  //  Serialize Pointer's register into x29
  sprintf(str, "  mov x29, #%d", rs_top());
  add_command(str);

  /*
    TODO:
      * Preserve lr (unless unnecessary, which is VERY preferable)
  */

  sprintf(str, "  bl __xcs_alloc");  //  TODO: REPLACE WITH SYSTEM INTERRUPT 
  add_command(str);

  /*
    Top of the register stack has an allocated address at this point

    TODO:
      * Construct Memory Node
      * Copy data into memory
        - Use double word store commands (e.g. str x0)
      * Create link to the list's Tail
  */

  //  Push List Pointer to Register Stack
  ADR reg = rs_push();

  return 0;
}

/* 1.b) List Tail

  Returns:
    0, if Successful
*/
int list_tail()
{
  printf("Returned Tail of List\n");

  //  TODO: Error Check

  //  Push Tail List Pointer to Register Stack
  ADR reg = rs_push();

  return 0;
}


/*
  2.) List Arithmetic
*/

/* 2.a) Append Lists

  Returns:
    0, if Successful
*/
int list_append()
{
  printf("Lists Appended");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Append Lists Together
  //  Push Final List onto Register Stack
  ADR reg = rs_push();

  return 0;
}


/*
  3.) List Traversal
*/



#endif
