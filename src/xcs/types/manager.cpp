/*
  manager.cpp (Type Manager)
  Codeus Tech
  Authored on   June 1, 2020
  Last Modified June 1, 2020
*/

/*
  Contains extended function implementations for the XCSL Type Manager
*/

#include "manager.h"


/*
  Constructors
*/
TypeManager::TypeManager(ModuleID _context)
{
  //  Initialize Type Manager
  context = _context;
}


/*
  Declarations
*/

ErrorCode TypeManager::declareType(TypeID tid, Identifier ident)
{
  types.push_back(TypeNode(tid, context, ident));
  
  std::string str = "Declared Type: " + string(types.getIdentifier());
  l.log('D', "DeclType", str);

  return SUCCESS;
}

ErrorCode TypeManager::declareType(TypeID tid, Identifier ident, unsigned long size)
{
  types.push_back(TypeNode(tid, context, ident, size));
  
  std::string str = "Declared Type: " + string(types.getIdentifier());
  l.log('D', "DeclType", str);

  return SUCCESS;
}

ErrorCode TypeManager::pushConstructor(ConstructorID cid, Identifier ident)
{
  constructors.push_back(TypeConstructor(cid, types.back().Id(), types.back().Context(), ident));
  
  std::string str = "Declared Constructor: " + string(types.getIdentifier());
  l.log('D', "DeclType", str);

  return SUCCESS;
}




TypeID TypeManager::getTypeID(ConstructorID cid)
{
  for (Index i = 0; i < types.size(); ++i)
    if (types[i].findConstructorID(cid))
      return types[i].Id(); 
  return 0;
}

TypeID TypeManager::getTypeID(Identifier ident)
{
  for (Index i = 0; i < types.size(); ++i)
    if (strcmp(types[i].Ident(), ident) == 0)
      return types[i].Id();
  return 0;
}

