/*
  proto.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains functionality for handling typeclass prototype functionality
*/

#pragma once

#include <xcs/std/includes.h>


struct PrototypeParameterNode
{
  Identifier ident;
  TypeID tid = TYPE_ARBITRARY;
  ADR reg;

  PrototypeParameterNode(Identifier _ident, ADR _reg)
  {
    ident = strdup(_ident); free(_ident);
    reg = _reg;
  }
};


class TypeclassPrototypeNode
{
  PrototypeID _id;
  Identifier _ident;

protected:
  vector<PrototypeParameterNode> parameters;
  TypeID return_type = TYPE_ARBITRARY;


public:

  /*
    Constructors
  */
  TypeclassPrototypeNode(PrototypeID id, Identifier ident)
  {
    _id = id;
    _ident = strdup(ident); free(ident);
  }

  ~TypeclassPrototypeNode() { free(_ident); } 


  /*
    Accessors
  */
  FunctionID Id() { return _id; }
  Identifier Ident() { return _ident; }

  TypeID Type() { return return_type; }
  TypeID Type(TypeID rtype) { return_type = rtype; return rtype; }


  /*
    Operations
  */
 ErrorCode declarePrototypeParameter(Identifier ident, ADR reg) 
  { parameters.push_back(PrototypeParameterNode(ident, reg)); return SUCCESS; }


};

