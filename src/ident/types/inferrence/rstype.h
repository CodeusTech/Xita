/*
  rstype.h
  Cody Fagley
  Authored on   March 16, 2019
  Last Modified March 16, 2019
*/

/*
  Contains Type Inferrence Protocols for Register Stack Operations

  Table of Contents
  =================
  1.) Push Value Type
  2.) Pop Value Type
*/

#ifndef INFERRENCE_RSTYPE_H
#define INFERRENCE_RSTYPE_H

extern unsigned int** rs_types;

/* 1.) Push Value Type

  Returns:
    0, if Successful
*/
int rs_push_type(int typecode)
{
  //  STUB STUB STUB

  //  Add TOP typecode to RS Types Stack

  return 0;
}

/*
  2.) Pop Value Type
*/
int rs_pop_type()
{
  //  STUB STUB STUB

  //  Remove TOP typecode from RS Types Stack
}


#endif

