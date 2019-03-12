/*
  source.h
  Cody Fagley
  Authored on   March 12, 2019
  Last Modified March 12, 2019
*/

/*
  Contains Operations for Source Modules

  Table of Contents
  =================
  1.) External Source Modules
    1.a) open Source Module
    1.b) close Source Module
*/

#ifndef MODULES_SOURCE_H
#define MODULES_SOURCE_H

/*
  1.) Exernal Source Modules
*/

/* 1.a) open Source Module

  Returns:
    0, if Successful
*/
int open_source(char* name)
{
  printf("Source Module Opened: %s\n", name);

  return 0;
}

/* 1.b) close Source Module

  Returns:
    0, if Successful
*/
int close_source()
{
  printf("Source Module Closed\n");

  return 0;
}


#endif
