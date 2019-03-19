/*
  tether.h
  Cody Fagley
  Authored on   March 12, 2019
  Last Modified March 12, 2019
*/

/*
  Contains Protocols for External Tether Modules

  Table of Contents
  =================
  1.) External Modules
    1.a) open Tether Module
    1.b) close Tether Module
  2.) Tether Module Activation
    2.a) activate Tether Module
    2.b) deactivate Tether Module
*/

#ifndef MODULES_TETHER_H
#define MODULES_TETHER_H


//  Linux Libraries
#include "stdio.h"

extern FILE* yyin;

/*
  1.) Tether Modules
*/

/* 1.a) open Tether Module

  Returns:
    0, if Successful
*/
ErrorCode open_tether(Identifier mod)
{
  //  STUB STUB STUB
  printf("Tether Module Opened: %s\n", mod);

  /*
    TODO:
     * Error Check
     * Check if File Exists
     * Allow Use of Tether Module Declarations
      + Module Context Shift
  */

  //  Return Success
  return 0;
}

/* 1.b) close Tether Module

  Returns:
    0, if Successful
*/
ErrorCode close_tether()
{
  //  STUB STUB STUB
  printf("Tether Module Closed\n");

  /*
    TODO:
     * Error Check
     * Check if File Exists
     * Disable Tether Protocol (Coming Soon)
  */

  //  Return Success
  return 0;
}


/*
  2.) Tether Module Activation
*/

/* 2.a) activate Tether Module

  Returns:
    0, if Successful
*/
ErrorCode activate_tether(Identifier ident)
{
  //  STUB STUB STUB
  printf("Tether Module Activated: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Check if File Exists
     * Trigger XCSE Activation
      + More Coming Soon
  */

  //  Return Success
  return 0;
}

/* 2.b) deactivate Tether Module

  Returns:
    0, if Successful
*/
ErrorCode deactivate_tether(Identifier ident)
{
  //  STUB STUB STUB
  printf("Tether Module Deactivated: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Check if Module is Activated
     * Trigger XCSE Deactivation
      + More Comining Soon
  */

  // Return Success
  return 0;
}


#endif

