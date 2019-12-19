/*
  init.h (Functions)
  Codeus Tech
  Authored on   December 18, 2019
  Last Modified December 18, 2019
*/

/*
  Contains protocols for initializing the cross-compiler for functions
*/

#ifndef FUNCTIONS_INIT_H
#define FUNCTIONS_INIT_H

#include <xcs/std/typedefs.h>
#include <xcs/std/error.h>

ErrorCode initialize_functions()
{
  char* str = (char*) malloc(50);
  sprintf(str, " ");

  add_function(str);
  return SUCCESS;
}


#endif
