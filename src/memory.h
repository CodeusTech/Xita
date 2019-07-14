/*
  memory.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains Backend Functionality for Memory Manipulation
*/

#ifndef XCS_MEMORY_H
#define XCS_MEMORY_H




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
