/*
  header.h
  Cody Fagley
  Authored on   February 23, 2019
  Last Modified February 23, 2019
*/

/*
  Contains Structures/Operations for XCS Internal Bytecode

  Table of Contents
  =================
  1.) Holistic Operations
    1.a) Build Header
    1.b) Read Header
  2.) Argument Operations
    2.a) Get/Set Argument Count
    2.b) Get/Set Argument Types
*/

#ifndef BYTECODE_HEADER_H
#define BYTECODE_HEADER_H

//  XCS Libraries
#include "../utils/bitvector.h"


/*
  1.) Holistic Operations
*/

/* 1.a) Build Header

  Returns:
    0, if Successful
*/
int build_header()
{
  //  STUB STUB STUB

  return 0;
}

/* 1.b) Read Header

  Returns:
    0, if Successful
*/
int read_header()
{
  //  STUB STUB STUB

  return 0;
}


/*
  2.) Argument Operations
*/

/*
  2.a) Get/Set Argument Counts
*/

/* Get Argument Count

  Returns:
    c, where 'c' is number of arguments
*/
int get_argc()
{
  //  STUB STUB STUB

  return 0;
}

/* Set Argument Count

  Returns:
    0, if Successful
*/
int set_argc()
{
  //  STUB STUB STUB

  return 0;
}


/* 
  2.b) Get/Set Argument Types
*/

/* Get Argument Type

  Returns:
    tid, where 'tid' is Type ID for an Argument
*/
int get_argt(int index)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Argument Types

  Returns:
    0, if Successful
*/
int set_argt(int index)
{
  //  STUB STUB STUB

  return 0;
}



#endif
