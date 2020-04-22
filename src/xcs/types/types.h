/*
  structs.h (Types)
  Codeus Tech
  Authored on   April 15, 2020
  Last Modified April 18, 2020
*/

/*
  Contains Backend Structural Definitions for XCS Data Types 
*/

#pragma once

#include <xcs/std/includes.h>

#include "constructor.h"
#include "param.h"
#include "typeclass.h"


class TypeNode
{
  /*
    Private Data
  */
  TypeID _tid;
  ModuleID _context;
  Identifier _ident;

protected:
  
  unsigned long _size;  //  In Bytes

  vector<TypeConstructor> constructors;
  vector<TypeParameterNode> parameters;
  vector<TypeID>               aliases;

public:
  //  Constructors
  TypeNode(TypeID tid, ModuleID context, Identifier ident);
  TypeNode(TypeID tid, ModuleID context, Identifier ident, unsigned long size);


  /*
    Accessors
  */
  TypeID Id() { return _tid; }
  ModuleID Context() { return _context; }
  Identifier Ident() { return _ident; }
  unsigned long Size() { return _size; }


  /*
    Type Operations
  */
  ErrorCode declareConstructor(ConstructorID cid, Identifier ident);
  ErrorCode declareElement(Identifier ident, TypeID tid);
  ErrorCode declareParameter(TypeID tid, Identifier ident);
  ErrorCode declareAlias(TypeID alias) { aliases.push_back(alias); return SUCCESS; }

  ConstructorID resolveConstructor(Identifier ident);
  TypeID resolveElement(Identifier ident, ConstructorID cid);
  TypeID resolveParameter(Identifier ident);

};


#include "types.cpp"


