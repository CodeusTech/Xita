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



struct ParameterRestrictions
{
  vector<ConstructorID> construct;
  vector<Identifier> element;
};


class FunctionParameterNode
{
  TypeID tid = TYPE_ARBITRARY;
  Identifier ident;
  ADR reg;
  Index _index;

  //  Dynamically-Defined Restrictions
  ParameterRestrictions restrictions;

public:

  FunctionParameterNode(Identifier _ident, ADR _reg, Index i)
  {
    ident = strdup(_ident); free(_ident);
    reg = _reg;
    _index = i;
  }

  Identifier Ident(){ return ident; }
  
  TypeID Type(){ return tid; }
  TypeID Type(TypeID _tid){ tid = _tid; return tid; }
  ADR Register() { return reg; }
  ADR Register(ADR _reg) { reg = _reg; return reg; }
  Index getIndex() { return _index; }
  ParameterRestrictions Restrictions() { return restrictions; }

  ErrorCode castConstructor(ConstructorID cid) { restrictions.construct.push_back(cid); return SUCCESS; }
};


