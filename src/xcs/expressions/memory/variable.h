/*
  variable.h (Memory)
  Codeus Tech 
  Authored on   October 28, 2020
  Last Modified October 28, 2020
*/

/*
  Contains definitions for handling instances of memory variables
*/

#pragma once

#include <xcs/std/includes.h>


class MemoryVariable
{
  Identifier ident;
  TypeID tid = TYPE_ARBITRARY;

public:
  MemoryVariable(Identifier ident) 
    : ident(ident) 
  {}

  Identifier Ident() { return ident; }
  TypeID Type() { return tid; }
};
