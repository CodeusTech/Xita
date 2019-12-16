/*
  utils.h (Modules)
  Codeus Tech
  Authored on   December 14, 2019
  Last Modified December 14, 2019
*/

/*
  Contains interface functionality for manipulating modules by context
*/

#ifndef MODULES_UTILS_H
#define MODULES_UTILS_H

//  Linux Imports
#include <string>

//  XCS Imports
#include <xcs/std/typedefs.h>
#include <xcs/std/error.h>
#include <xcs/std/buffers.h>


/*
  Open an external XCS "HEADER" file
*/
ErrorCode open_header(char* module)
{
  printf("Header File Opened: %s\n", module);

  

  //  Return Success
  return SUCCESS;
}


/*
  Open an extern XCS "SOURCE" file
*/
ErrorCode open_source(char* module)
{
  //  STUB STUB STUB

  //  Return Success
  return SUCCESS;
}

ErrorCode open_tether(char* module)
{
  //  STUB STUB STUB

  //  Return Success
  return SUCCESS;
}

ErrorCode open_system(char* module)
{
  //  STUB STUB STUB

  //  Return Success
  return SUCCESS;
}



//ModuleNode context() { return modules[current_context]; }


#endif
