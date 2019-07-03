/*
  listexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains list primitive expressions

  Definitions
  ===========

  
  Table of Contents
  =================
  1.) List Literals
    1.a) List Constructor
    1.b) List Tail
  2.) List Arithmetic
    2.a) Append Lists
  3.) List Traversal
*/

#ifndef PRIMITIVES_LISTEXP_H
#define PRIMITIVES_LISTEXP_H

//  XCS Libraries
#include "typecodes.h"
#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include "../globals/structs.h"

/*
  1.) List Literals
*/

/* 1.a) List Constructor

  Returns:
    0, if Successful
*/
int list_construct()
{
  printf("List Constructed: \n");

  //  TODO:  Error Check

  //  Push List Pointer to Register Stack
  ADR reg = rs_push();

  return 0;
}

/* 1.b) List Tail

  Returns:
    0, if Successful
*/
int list_tail()
{
  printf("Returned Tail of List\n");

  //  TODO: Error Check

  //  Push Tail List Pointer to Register Stack
  ADR reg = rs_push();

  return 0;
}


/*
  2.) List Arithmetic
*/

/* 2.a) Append Lists

  Returns:
    0, if Successful
*/
int list_append()
{
  printf("Lists Appended");

  //  TODO: Error Check

  //  Get Register Codes
  ADR top = rs_pop();
  ADR sec = rs_pop();

  //  Append Lists Together
  //  Push Final List onto Register Stack
  ADR reg = rs_push();

  return 0;
}


/*
  3.) List Traversal
*/



#endif
