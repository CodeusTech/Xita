/*
  ops.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains semantics for static memory operators
*/

#ifndef MEMORY_OPS_H
#define MEMORY_OPS_H

#include <cstdlib>
#include <string>

#include <xcs/regstack/utils.h>

#include "utils.h"




/* 1.) Read Expression from Memory
  Returns:
    0, if Successful
*/
int memory_read_exp(char* ident)
{
  decl_memory_variable(ident);
}

/*
  memory_read_exp()
    
*/
int memory_read_this()
{
  //  Make Room on Register Stack for new entry
  rs_push(2);

  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "ldr %s,[%s,0]", top, sec);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}


/*
  2.) Write Expression to Memory
  Returns:
    0, if Successful
*/
int memory_write_exp()
{
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  char* top = get_reg(rs_top(), 32);
  char* sec = get_reg(rs_sec(), 32);
  rs_pop();

  sprintf(str, "str %s,[%s,0]", top, sec);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  free(top);
  free(sec);

  return 0;
}


#endif