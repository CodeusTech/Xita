/*
  source.h
  Cody Fagley
  Authored on   March 16, 2019
  Last Modified March 18, 2019
*/

/*
  Contains Functionality for Source Files

  Table of Contents
  =================
  1.) External Source Modules
    1.a) Open External Source Module
  2.) Finish Parsing Source
*/

#ifndef MODULES_SOURCE_H
#define MODULES_SOURCE_H

#include "../regstack/regstack.h"


/*
  1.) Externals Source Modules
*/

/* 1.a) Open External Source Module

  Returns:
    0, if Successful
*/
ErrorCode open_source(Identifier ident)
{
  //  STUB STUB STUB
  printf("Opened Source Module: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Change Module Context
      + Store Current Context
      + Set Parsing Mode to Source
     * Parse Module
     * Return Current Module Context 
  */

  //  Return Success
  return 0;
}


/* 2.) Finish Parsing Source

  Returns:
    0, if Successful
*/
ErrorCode source_end()
{
  printf("Finished Parsing Source Module.\n"); 

  /*
    TODO: 
      This should only deallocate all buffers if this module is
      the 'driver' module.  In other words, it is outermost module.
  */
  //rs_end();

  /*
    If it is a nested header module of driver module,
    it should return to parent module without resetting buffers
  */

  return 0;
}



#endif

