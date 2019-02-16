/*
  static.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains functionality for Direct Memory Access
  
  Table of Contents
  =================
  1.) Read Expression from Memory
  2.) Write Expression to Memory
*/

#ifndef MEMORY_STATIC_H
#define MEMORY_STATIC_H



/* 1.) Read Expression from Memory

  Returns:
    0, if Successful
*/
int memory_read_exp(char* ident)
{
  printf("%s generated from memory\n", ident);

  return 0;
}


/*
  2.) Write Expression to Memory

  Returns:
    0, if Successful
*/
int memory_write_exp()
{
  printf("Expression Written to Memory\n");

  return 0;
}





#endif
