/*
  alloc.h
  Cody Fagley
  Authored on   July 2, 2019
  Last Modified July 2, 2019
*/

/*
  Contains functionality for actually allocating and freeing memory
*/ 

#ifndef FLAT_ALLOC_H
#define FLAT_ALLOC_H

#include "constants.h"
#include "globals.h"

//  Allocate Next Slot of Memory
ErrorCode xcs_alloc()
{
  /*
    TODO:
      * Check hardware for next available memory slot
      * Move next available slot into top of register stack
      * Allocate address, pointed by top of register stack
      * Return to previous control sequence
  */

  return 0;
}


ErrorCode xcs_dealloc()
{
  /*
    TODO:
      * Check that address pointed by top of register stack is allocated
      * If allocated, deallocate the address
      * Pop value from top of register stack
      * Return to previous control sequence
  */

  return 0;
}


#endif
