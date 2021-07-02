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
#include "xcs/modules/modules.h"

/*
  Constructors
*/
TypeManager::TypeManager(ModuleNode* context)
  : owner(context)
{}


/*
  Declarations
*/

ErrorCode TypeManager::declareType(TypeID tid, Identifier ident)
{
  
  std::string str = "Declared Type: " + string(ident);
  l.log('D', "DeclType", str);

  return SUCCESS;
}

ErrorCode TypeManager::declareType(TypeID tid, Identifier ident, unsigned long size)
{
  std::string str = "Declared Type: " + string(ident);
  l.log('D', "DeclType", str);

  return SUCCESS;
}

ErrorCode TypeManager::declareConstructor(ConstructorID cid, Identifier ident)
{
  
  std::string str = "Declared Constructor: " + string(ident);
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

