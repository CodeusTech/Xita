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
int decl_list()
{
  /*
    TODO: 
      * Check Size of Type ID
      * Allocate Dynamic Memory
      * Construct Data Node
      * Repeat for Each Node in List
  */

  //  Calculate Node Size
  unsigned long nsize = _xcs_get_size(last_type);
  nsize += 8; //  Add Pointer to Next Node

  //  Move Node Size to OSP for memory allocation
  char* str = (char*) malloc (50);
  char* top = get_reg(rs[scope_curr][rs_top()], 32);
  char* top64 = get_reg(rs[scope_curr][rs_top()], 64);
  char* sec64 = get_reg(rs[scope_curr][rs_second()], 64);

  /*
    TODO:
      * Error Check for situations with extended register stacks
  */
  sprintf(str, "mov   %s, %s\n", sec64, top64);
  add_command(str);

  //  Move Node Size to OSP for Memory Allocation
  sprintf(str, "mov   x28, #%lu\n", nsize);
  add_command(str);

  //  Serialize Pointer's register into x29
  sprintf(str, "mov   x29, #%d\n", rs[scope_curr][rs_second()]);
  add_command(str);

  /*
    TODO:
      * Preserve lr (unless unnecessary, which is VERY preferable)
  */

  sprintf(str, "bl    __xcs_alloc\n");  //  TODO: REPLACE WITH SYSTEM INTERRUPT 
  add_command(str);

  /*
    Top of the register stack has an allocated address at this point

    TODO:
      * Construct Memory Node
      * Copy data into memory
        - Use double word store commands (e.g. str x0)
      * Create link to the list's Tail
  */

  sprintf(str, "str   %s, [%s]\n", top, sec64);
  add_command(str);

  rs_pop();

  //  Free Memory
  free(str);
  free(top);
  free(top64);
  free(sec64);

  //  Return Success
  return 0;
}

/* 1.b) List Tail

  Returns:
    0, if Successful
*/
int list_tail()
{
  /*
    Assume top of register stack holds pointer to list
  */

  //  Acquire List Type Size
  unsigned long offset = _xcs_get_size(last_type); // Shift to pointer

  //  Allocate Space for Command
  char* str = (char*) malloc(50);
  char* top64 = get_reg(rs[scope_curr][rs_top()], 64);

  //  Replace Pointer to List with Pointer to List's Tail
  sprintf(str, "ldr   %s, [%s,#%lu]\n", top64, top64, offset);

  //  Push Command to Generated Assembly Queue
  add_command(str);

  /*
    TODO:
      * Deallocate memory node storing the previous head of the list
      * For now, use __dealloc
        - Eventually, replace with standard interrupt
  */

  free(str);
  free(top64);

  //  Return Success
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
  /*
    Assume TOP list is getting appended to SECOND list
  */

  /*
    TODO:
      * Error Check TOP and SECOND are valid lists
  */

  //  Allocate Command String
  char* str = (char*) malloc(50);
  char* top64 = get_reg(rs[scope_curr][rs_top()], 64);
  char* sec64 = get_reg(rs[scope_curr][rs_second()], 64);
  unsigned long offset = _xcs_get_size(last_type); //  Shift to 

  //  Temporarily store pointer in OSP
  sprintf(str, "  mov x28, %s\n", sec64);
  add_command(str);

  //  Navigate to Last Node
  sprintf(str, 
    "  ldr %s, [%s,#%lu]\n", sec64, sec64, offset);
  add_command(str);

  //  Append to end of list
  sprintf(str, "  str %s, %s, #%lu\n", top64, sec64, offset+8);
  add_command(str);
  rs_pop();

  //  Restore pointer on register stack
  sprintf(str, "  mov %s, x28\n", sec64);
  add_command(str);

  //  Free Command String Memory
  free(str);
  free(top64);
  free(sec64);

  return 0;
}




#endif
