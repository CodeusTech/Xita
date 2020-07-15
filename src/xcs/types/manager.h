/*
  manager.h (Type Manager)
  Codeus Tech
  Authored on   June 1, 2020
  Last Modified June 1, 2020
*/

/*
  Contains structures/definitions for XCSL Type Manager

  The Type Manager is a structure for checking/validating type correctness during compilation.
*/

#pragma once

#include <vector>

#include <xcs/std/includes.h>
#include "types.h"

using namespace std;


class TypeManager
{
  /*
    Private Data
  */

protected:
  /*
    Protected Data
  */
  ModuleID context;

  //  Buffered Data
  vector<TypeNode> types;
  vector<TypeConstructor> constructors;

  //  Active data
  vector<TypeID> activeTypes;
  vector<ConstructorID> activeConstructors;

public: 
  TypeManager(ModuleID _context);

  ErrorCode declareType(TypeID tid, Identifier ident);
  ErrorCode declareType(TypeID tid, Identifier ident, unsigned long size);
  ErrorCode declareConstructor(ConstructorID cid, Identifier ident);
  ErrorCode declareParameter(TypeID tid, Identifier ident);

  TypeID getTypeID(Identifier ident);
  TypeID getTypeID(ConstructorID cid);

  Identifier getIdentifier() { return types.back().Ident(); }
  Identifier getIdentifier(Index i) { return types[i].Ident(); }
};


#include "manager.cpp"
