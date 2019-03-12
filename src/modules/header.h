/*
  header.h
  Cody Fagley
  Authored on   March 12, 2019
  Last Modified March 12, 2019
*/

/*
  Contains Submodule Operations

  Table of Contents
  =================
  1.) External Submodules
    1.a) open Submodule
    1.b) close Submodule
*/

#ifndef MODULES_HEADER_H
#define MODULES_HEADER_H


/*
  1.) External Submodules
*/

/* 1.a) open Submodule

  Returns:
    0, if Successful
*/
int open_header(char* name)
{
  printf("Submodule Opened: %s\n", name);

  return 0;
}

/* 1.b) close Submodule

  Returns:
    0, if Successful
*/
int close_header()
{
  printf("Submodule Closed\n");

  return 0;
}


#endif
