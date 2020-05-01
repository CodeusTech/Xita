/*
  typeclass.h
  Codeus Tech
  Authored on   April 19, 2020
  Last Modified April 19, 2020
*/

/*
  Contains structural definitions for handling Typeclass definitions in XCS
*/

#pragma once

#include <xcs/std/includes.h>
#include "proto.h"


class TypeclassNode
{
  TypeID _tid;
  ModuleID _context;
  Identifier _ident;

  /*
    Protected Data
  */
protected:
  
  vector<TypeclassPrototypeNode> prototypes;

public:

  /*
    Constructors
  */
  TypeclassNode(TypeID tid, ModuleID context, Identifier ident)
  {
    _tid = tid;
    _context = context;
    _ident = strdup(ident); free(ident);
  }

  /*
    Private Accessors
  */
  TypeID Id() { return _tid; }
  ModuleID Context() { return _context; }
  Identifier Ident() { return _ident; }


  /*
    Operations
  */
 ErrorCode declarePrototype(PrototypeID pid, Identifier ident)
 {
   prototypes.push_back( TypeclassPrototypeNode(pid, ident) );
   return SUCCESS;
 }

 ErrorCode declarePrototypeParameter(Identifier ident, ADR reg)
 { return prototypes.back().declarePrototypeParameter(ident, reg); }

};



