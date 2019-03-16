/*
  source.h
  Cody Fagley
  Authored on   March 16, 2019
  Last Modified March 16, 2019
*/

/*
  Contains Functionality for Source Files
*/

#ifndef MODULES_SOURCE_H
#define MODULES_SOURCE_H

#include "../regstack/regstack.h"


/* 1.) Finish Source Module

  Returns:
    0, if Successful
*/
int source_end()
{
  printf("Finished Parsing Source Module.\n"); 

  /*
    TODO: 
      This should only deallocate all buffers if this module is
      the 'driver' module.  In other words, it is outermost module.
  */
  rs_end();

  /*
    If it is a nested header module of driver module,
    it should return to parent module without resetting buffers
  */

  return 0;
}



#endif

