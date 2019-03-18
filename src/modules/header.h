/*
  header.h
  Cody Fagley
  Authored on   March 18, 2019
  Last Modified March 18, 2019
*/

/*
  Contains backend functionality for importing Header Modules

  Table of Contents
  =================
  1.) Store Current Module Metadata
  2.) Parse Header Module
  3.) Restore Module Context
  4.) Import Header (Submodule)
*/

#ifndef MODULES_HEADER_H
#define MODULES_HEADER_H



/* 1.) Store Current Module Metadata

  Returns:
    0, if Successful
*/
ErrorCode mod_store_metadata()
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


/* 2.) Parse Header Module

  Returns:
    0, if Successful
*/
ErrorCode mod_parse_header()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Shift to New Header Context
      + Change Input Stream
      + Reset Line Number to 0
      + Change Parser/Module States
  */

  return 0;
}


/* 3.) Restore Module Context

  Returns:
    0, if Successful
*/
ErrorCode mod_restore_module()
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


/* 4.) Import Header (Submodule)

  Returns:
   0, if Successful
*/
ErrorCode mod_header()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Ensure Target File Exists
  */

  //  Store Current Metadata
  mod_store_metadata();

  //  Parse New Header Module
  mod_parse_header();

  //  Restore Current Context
  mod_restore_module();

  //  Return Success
  return 0;
}


#endif

