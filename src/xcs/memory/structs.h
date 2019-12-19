/*
  structs.h
  Codeus Tech
  Authored on   December 13, 2019
  Last Modified December 13, 2019
*/

/*
  Contains structures related to Memory Use
*/

#ifndef MEMORY_STRUCTS_H
#define MEMORY_STRUCTS_H

//  Linux Libraries
#include <string.h>
#include <stdlib.h>

//  XCS Libraries
#include <xcs/std/typedefs.h>
#include <xcs/std/typecodes.h>

extern void yyerror(const char* error);


/*
  MemoryVariableNode
    * Used for holding temporary structures created from a memory address
    * Has an identifier and a containing ADR
*/
class MemoryVariableNode
{
  Identifier identifier;
  ADR reg; 
  TypeID type;

public:
//  CONSTRUCTORS
  MemoryVariableNode(Identifier ident, ADR adr) 
  {
    identifier = strdup(ident);
    reg = adr;
    type = TYPE_ARBITRARY;

    free(ident);
  }

  Identifier get_identifier() { return identifier; }
  ADR get_register() { return reg; }
  TypeID get_type() { return type; }

};


#endif
