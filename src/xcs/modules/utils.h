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
#include <xcs/std/status.h>

extern YY_BUFFER_STATE yy_create_buffer(FILE* file, int size);
extern void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
extern FILE* yyin;


ModuleID get_next_context() { return next_context++; }
ModuleID get_current_context() { return current_context; }



/*
  Open an external XCS "HEADER" file
*/
ErrorCode open_header(char* module)
{
  context->set_status(ParserStatus::Waiting);
  printf("Header File Opened: %s\n", module);

  modules.push_back(ModuleNode(XCSL_HEADER, current_context));
  
  //  Set Current Context Accordingly
  context = &modules[modules.size()-1];

  char* str = (char*) malloc(50);
  sprintf(str, " ");

  add_function(str);

  FILE* mod_file = fopen(module, "r");

  //  Set Parser File Pointer
  yypush_buffer_state(yy_create_buffer( mod_file, YY_BUF_SIZE ));

  printf("Header file Closed: %s\n", module);


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
