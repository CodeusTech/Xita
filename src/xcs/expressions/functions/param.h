/*
  param.h (Functions)
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains definitions/functions for handling Function Parameters in XCS backend
*/

#pragma once

#include <xcs/std/includes.h>


class FunctionParameterNode
{
  TypeID tid = TYPE_ARBITRARY;
  Identifier ident;
  ADR reg;


public:

  FunctionParameterNode(Identifier _ident, ADR _reg)
  {
    ident = strdup(_ident); free(_ident);
    reg = _reg;
  }

  Identifier Ident(){ return ident; }
  
  TypeID Type(){ return tid; }
  TypeID Type(TypeID _tid){ tid = _tid; return tid; }

  ADR Register() { return reg; }
  ADR Register(ADR _reg) { reg = _reg; return reg; }

};


