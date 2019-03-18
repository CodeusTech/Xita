/*
  operations.h (Modules)
  Cody Fagley
  Authored on   March 18, 2019
  Last Modified March 18, 2019
*/

/*
  Contains Backend Functionality for Module Manipulation

  Table of Contents
  =================
  1.) Module Context
    1.a) Store Current Context
    1.b) Restore Previous Context
*/

#ifndef MODULES_OPERATIONS_H
#define MODULES_OPERATIONS_H


/*
  1.) Module Context
*/

/* 1.a) Store Current Context

  Returns:
    0, if Successful
*/
ErrorCode mod_store_context()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Save Current Meta Data
      + Store Input Stream
      + Store Parser Line Number
      + Store any other data regarding Parser State
  */

  return 0;
}

/* 1.b) Restore Previous Module Context

  Returns:
    0, if Successful
*/
ErrorCode mod_restore_context()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * After Header Parse Finishes...
      + Restore Input Stream
      + Restore Line Number
      + Restore all other metadata
  */

  //  Return Success
  return 0;
}

#endif

