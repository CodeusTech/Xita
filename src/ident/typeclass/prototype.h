/*
  prototype.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified    March  8, 2019
*/

/*
  Contains backend functionality for typeclass prototypes

  Table of Contents
  =================
  1.) Declare Prototype
  2.) Declare Prototype Parameter
*/

#ifndef TYPECLASS_PROTOTYPE_H
#define TYPECLASS_PROTOTYPE_H


/* 1.) Declare Prototype

  Returns:
    0, if Successful
*/
int declare_proto(char* str)
{
  printf("Prototype %s Declared, and requires parameters: ", str);

  return 0;
}


/* 2.) Declare Prototype Parameter

  Returns:
    0, if Successful

*/
int proto_param(char* str)
{
  printf("%s ", str);

  return 0;
}

/* 3.) Find Prototype

  Returns:
    0, if ident is not a Prototype
    i, if ident is a prototype, where 'i' is the index in buffer
*/
int find_proto(char* ident)
{
  printf("Found Prototype: %s\n", ident);

  return 0;
}

#endif
