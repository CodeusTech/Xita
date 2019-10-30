/*
  scope.h
  Cody Fagley
  Authored on   March 16, 2019
  Last Modified March 16, 2019
*/

/*
  Contains Functionality for Lexical Scoping

  Table of Contents
  =================
  1.) Get Current Scope
  2.) Get Next Scope
  3.) Get Return Scope
*/

#ifndef UTILS_SCOPE_H
#define UTILS_SCOPE_H

#include "../std/structs.h"


extern Scope scope_curr;
extern Scope scope_next;


/* 1.) Get Current Scope

  Returns:
    Current Scope Context
*/
Scope get_scope_curr() 
{ 
  return scope_curr; 
}

/* 2.) Get Next Scope

  Returns:
    Next Scope Context
*/
Scope get_scope_next()
{
  //  Set Previous Scope

  scope_curr = scope_next++;

  return scope_curr;
}

/* 3.) Get Return Scope

  Returns:
    Parent Scope of Parameter
*/
Scope get_scope_return(Scope s)
{
  //  Find Parent p of Scope s

  //  Set scope_curr to p

  return scope_curr;
}



#endif

