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
  1.) Parse Header Module
  2.) Import Header (Submodule)
*/

#ifndef MODULES_HEADER_H
#define MODULES_HEADER_H

#include "operations.h"


/* 1.) Parse Header Module

  Returns:
    0, if Successful
*/
ErrorCode mod_parse_header()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
  */

  /*
    TODO:
     * Shift to New Header Context
      + Change Input Stream
      + Reset Line Number to 0
      + Change Parser/Module States
  */

  return 0;
}


/* 2.) Import Header (Submodule)

  Returns:
   0, if Successful
*/
ErrorCode open_header(Identifier ident)
{
  //  STUB STUB STUB
  printf("Header Opened: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Ensure Target File Exists
  */

  //  Store Current Metadata
  mod_store_context();

  //  Parse New Header Module
  mod_parse_header();

  //  Restore Current Context
  mod_restore_context();

  //  Return Success
  return 0;
}


#endif

