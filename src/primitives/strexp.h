/*
  strexp.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains primitive string expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) String Literals
  2.) String Arithmetic
    2.a) Append Strings
    

*/

#ifndef PRIMITIVES_STREXP_H
#define PRIMITIVES_STREXP_H


/*
  1.) String Literals
*/


/*
  2.) String Arithmetic
*/

/* 2.a) Append Strings

  Returns:
    0, if Successful
*/
int string_append()
{
  printf("Strings have been appended\n");

  return 0;
}




#endif
