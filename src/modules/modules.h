/*
  modules.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 21, 2019
*/

/*
  Contains Public Interface for Handling External Modules

  Table of Contents
  =================
  1.) Resolve Module Type
  2.) Source Modules
    2.a) Open Source Module
    2.b) Close Source Module
  3.) Header Modules (Submodules)
    3.a) Open Submodule
    3.b) Close Submodule
  4.) Tether Modules
    4.a) Open Tether Module
    4.b) Close Tether Module
*/

#ifndef XCS_MODULES_H
#define XCS_MODULES_H

#include "tether.h"

/*
  1.) Resolve Module Type
*/


/*
  2.) Source Modules
*/

/* 2.a) Open Source Module

  Returns:
    0, if Successful
*/
int open_source(char* name)
{
  printf("Source Module Opened: %s\n", name);

  return 0;
}

/* 2.b) Close Source Module

  Returns:
    0, if Successful
*/
int close_source()
{
  printf("Source Module Closed\n");

  return 0;
}


/*
  3.) Header Modules (Submodules)
*/

/* 3.a) Open Submodule

  Returns:
    0, if Successful
*/
int open_header(char* name)
{
  printf("Submodule Opened: %s\n", name);

  return 0;
}

/* 3.b) Close Submodule

  Returns:
    0, if Successful
*/
int close_header()
{
  printf("Submodule Closed\n");

  return 0;
}


#endif
