/*
  body.h
  Cody Fagley
  Authored on   February 23, 2019
  Last Modified February 23, 2019
*/

/*
  Contains Executable Functionality of Bytecode

  Table of Contents
  =================
  1.) Declarations: Types
    1.a) Get/Set Number of Constructors (each type)
    1.b) Get/Set Constructor ID Number
    1.c) Get/Set Number of Elements (each constructor)
    1.d) Get/Set Element Type ID
  2.) Declarations: Constants
    2.a) Get/Set Constant Type
    2.b) Get/Set Constant Value
  3.) Declarations: Executables
    3.a) Entry Function

*/

#ifndef BYTECODE_BODY_H
#define BYTECODE_BODY_H

/*
  1.) Declarations: Types
*/

/*
  1.a) Get/Set Number of Constructors (each type)
*/

/* Get Number of Constructors

  Returns:
    n, where 'n' is the Number of constructors for a given type ID
*/
unsigned int get_num_construct(unsigned int tid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Number of Constructors

  Returns:
    0, if Successful
*/
int set_num_construct(unsigned int tid, unsigned int con)
{
  //  STUB STUB STUB

  return 0;
}

/*
  1.b) Get/Set Constructor ID Number
*/

/* Get Constructor ID Number

  Returns:
    0, if Unsuccessful...?  I don't know, yet.
*/
unsigned int get_cid(unsigned int tid, unsigned int con)
{
  // STUB STUB STUB

  return 0;
}

/* Set Constructor ID Number

  Returns:
    0, if Successful
*/
int set_cid(unsigned int tid, unsigned int cid)
{
  // STUB STUB STUB

  return 0;
}

/*
  1.c) Get/Set Number of Elements (each constructor)
*/

/* Get Number of Elements

  Returns:
    0, if Type is an alias
    n, if Type has 

*/
int get_num_elements(unsigned int cid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Number of Elements

  Returns:
    0, if Successful
*/
int set_num_elements(unsigned int cid)
{
  //  STUB STUB STUB

  return 0;
}

/*
  1.d) Get/Set Element Type ID
*/

/* Get Element Type ID

  Returns:
    tid, where 'tid' is the Type ID Number for a given element
*/
int get_element_tid(unsigned int cid, unsigned int eid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set ELement Type ID

  Returns:
    0, if Successful
*/
int set_element_tid(unsigned int cid, unsigned int eid, unsigned int tid)
{
  //  STUB STUB STUB

  return 0;
}


/*
  2.) Declarations: Constants
*/

/*
  2.a) Get/Set Constant Type
*/

/* Get Constant Type

  Returns:
    tid, where 'tid' is the Type ID Number for const
*/
int get_constant_type(unsigned int constid)
{
  //  STUB STUB STUB

  return 0;
}

/* Set Constant Type

  Returns:
    0, if Successful
*/
int set_constant_type(unsigned int constid, unsigned int tid)
{
  //  STUB STUB STUB

  return 0;
}

/*
  2.b) Get/Set Constant Value
*/

/* Get Constant Value
  
  Returns:
    p?, where p? is data/pointer for a constant.
*/
void* get_constant_value(unsigned int constid)
{
  //  STUB STUB STUB

  return (void*) 0;
}

/* Set Constant Value

  Returns:
    0, if Successful
*/
int set_constant_value(unsigned int constid, void* value)
{
  //  STUB STUB STUB

  return 0;
}

/*
  3.) Declarations: Executables
*/

/*

*/

#endif
