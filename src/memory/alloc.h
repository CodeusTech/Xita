/*
  alloc.h
  Cody Fagley
  Authored on   March 13, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Operations for XCS Internal Memory Allocator

  Table of Contents
  =================
  1.) Memory Allocation
    1.a) Check if Allocated
    1.b) Allocate Memory
    1.c) Free Memory
*/

#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H


/*
  1.) Memory Allocation
*/

/* 1.a) Check if Allocated

  Returns:
    0, if Successful
*/
ErrorCode xcs_is_alloc()
{
  /*
    TOP  holds memory address, addr
    NEXT holds size s (in bytes)
  */

  //  Error Check

  /*
    Top Register holds:
      0, if Address is Allocated
      addr, 
  */

  return 0;
}

/* 1.b) Allocate Memory

  'xcs_alloc' essentially performs AVL Insert on Active Memory Tree

  Returns:
    0, if Successful
*/
ErrorCode xcs_alloc()
{
  /*
    TOP holds size (in bytes) to Allocate
  */
  ADR reg = rs_pop();

  //  Error Check Size

  /*
    TODO:
     * Generate Random Number using GPIO
     * Check if Already Allocated
     * Perform Allocation
  */

  //  Generate Random Number Using GPIO

  //  Check if Already Allocated

  //  Perform Allocation 

  //  Place Memory Pointer on Top of Register Stack
  reg = rs_push();

  //  Return Success
  return reg;
}

/* 1.c) Free Memory

  Returns:
    0, if Successful
*/
ErrorCode xcs_free()
{
  
  // Top Register Holds an Allocated Memory Address
  ADR reg = rs_pop();

  /*
    TODO:
     * Error Check
     * Deallocate Pointer within 'reg'
  */

  /*
    End of Call:
      Deallocate TOP and Decrement Register Stack
  */
  return reg;
}


#endif
