/*
  debug.h
  Codeus Tech
  Authored on   November 14, 2019
  Last Modified November 14, 2019
*/

/*
  Contains functionality for storing/printing identifier DEBUG STRINGS to native OS
*/

#ifndef IDENT_DEBUG_H
#define IDENT_DEBUG_H

#include <cstring>
#include <cstdlib>

#include <xcs/std/structs.h>

using namespace std;


/*
  add_debug_message(ident, msg)
    ident: string (c-style)
    msg: string (c-style)

    Binds a debug message to an XCSL identifier for quick testing

    Returns:
      0, if Successful
*/
ErrorCode add_debug_message(Identifier ident, char* msg)
{
  DebugMessageNode node = DebugMessageNode();
  node.ident = strdup(ident);
  node.msg = strdup(msg); 

  debug.push_back(node);

  free(msg);

  //  Return Success
  return 0;
}


/*
  print_debug_message(ident)
*/
ErrorCode print_debug_message(Identifier ident)
{
  for (vector<DebugMessageNode>::iterator iter = debug.begin(); iter != debug.end(); iter++)
    if (strcmp((*iter).ident, ident) == 0)
      printf("%s\n", (*iter).msg);

  //  Return Success
  return 0;
}

#endif
