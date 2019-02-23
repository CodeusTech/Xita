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
  3.) Metadata: Types
    3.a) Get/Set Total Type Bytes
    3.b) Get/Set Type Size
  4.) Metadata: Constants
    4.a) Get/Set Total Constant Bytes
    4.b) Get/Set Constant Size
  5.) Metadata: Executables
    5.a) Get/Set Total Executable Bytes
    5.b) Get/Set Executable Size
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
unsigned int get_argc()
{
  //  STUB STUB STUB

  return 0;
}

/* Set Argument Count

  Returns:
    0, if Successful
*/
unsigned int set_argc()
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

/* Set Argument Type

  Returns:
    0, if Successful
*/
int set_argt(int index)
{
  //  STUB STUB STUB

  return 0;
}


/*
  3.) Metadata: Types
*/

/*
  3.a) Get/Set Total Type Bytes
*/

/* Get Total Type Bytes

  Returns:
    t, where 't' is number of bytes for all types
*/
unsigned int get_type_bytes()
{
  //  STUB STUB STUB

  return 0;
}

/* Set Total Type Bytes
  
  Returns:
    0, if Successful
*/
int set_type_bytes(unsigned int bytes)
{
  //  STUB STUB STUB

  return 0;
}

/*
  3.b) Get/Set Type Size
*/

/* Get Type Size

  Returns:
    s, where 's' is the size of given Type ID
*/
unsigned int get_type_size(int tid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Type Size

  Returns:
    0, if Successful
*/
int set_type_size(int tid, unsigned int sz)
{
  //  STUB STUB STUB

  return 0;
}


/*
  4.) Metadata: Constants
*/

/*
  4.a) Get/Set Total Constant Bytes
*/

/* Get Total Constant Bytes

  Returns:
    c, where 'c' is number of bytes for all constants
*/
unsigned int get_const_bytes()
{
  //  STUB STUB STUB

  return 0;
}

/* Set Total Constant Bytes
  
  Returns:
    0, if Successful
*/
int set_const_bytes(unsigned int bytes)
{
  //  STUB STUB STUB

  return 0;
}

/*
  4.b) Get/Set Constant Size
*/

/* Get Constant Size

  Returns:
    s, where 's' is the size of given Constant ID
*/
unsigned int get_const_size(int cid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Constant Size

  Returns:
    0, if Successful
*/
int set_const_size(int cid, unsigned int sz)
{
  //  STUB STUB STUB

  return 0;
}


/*
  5.) Metadata: Executables
*/

/*
  5.a) Get/Set Total Executable Bytes
*/

/* Get Total Executable Bytes

  Returns:
    e, where 'e' is the number of bytes for all executables
*/
unsigned int get_exec_bytes()
{
  //  STUB STUB STUB

  return 0;
}

/* Set Total Executable Bytes

  Returns:
    0, if Successful
*/
int set_exec_bytes(unsigned int bytes)
{
  //  STUB STUB STUB

  return 0;
}

/*
  5.b) Get/Set Executable Size
*/

/* Get Executable Size

  Returns:
    s, where 's' the size of a given executable
*/
unsigned int get_exec_size(int eid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Executable Size

  Returns:
    0, if Successful
*/
int set_exec_size(int eid, unsigned int sz)
{
  //  STUB STUB STUB

  return 0;
}

#endif
