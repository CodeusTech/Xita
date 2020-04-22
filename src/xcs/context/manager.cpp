/*
  manager.cpp
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified April 18, 2020
*/

/*
  Contains implementations for ContextManager Class


  Table of Contents
  =================
  2.) Public Operations
    2.a) Module Operations
    2.b) Type Operations
*/

#include "manager.h"

/*
  Constructors
*/
ContextManager::ContextManager()
{
  modules.push_back(ModuleNode(0, ModuleType::XCSL_SOURCE, 0));
  _context = &modules[0];
  l.log('D', "ContextManager", "Context Manager has been initialized");
  printf("Context Manager has been Initialized\n");
}



/*
  2.) Public Operations
*/

//  2.a) Module Operations
ErrorCode ContextManager::importModule(ModuleType mtype)
{
  int index = modules.size();
  modules.push_back(ModuleNode(_next_mid++, mtype, modules.back().Id()));
  _context = &modules[index];
  l.log('D', "Modules", "Module Imported and Context Shifted Accordingly");

  return SUCCESS;
}

ErrorCode ContextManager::executeModule() { /* Down the Road */ return SUCCESS; }





/*
  3.) Identifier Operations
*/

/*
  3.a) Type Operations
*/
 //  Resolutions
 TypeID ContextManager::resolveType(Identifier ident)
 {
  TypeID tid;

  if (tid = _context->resolveType(ident))
    return LastType(tid);

  for (unsigned long i = 0; i < _context->imported.size(); ++i)
    if (tid = modules[_context->imported[i]].resolveType(ident))
      return LastType(tid);
  
  return 0;
 }

 ConstructorID ContextManager::resolveConstructor(Identifier ident)
 {
   unsigned long* rtn = _context->resolveTypeConstructor(ident);
   
   if (rtn[0])
   {
     LastType(rtn[0]);
     LastConstructor(rtn[1]);

     free(rtn);
     return LastConstructor();
   }

   return 0;
 }

 TypeID ContextManager::resolveTypeElement(Identifier ident)
 {
   TypeID tid = _context->resolveTypeElement(ident, LastConstructor(), LastType());
   if (tid) return tid;

   /*
    TODO: Check other child module nodes for this element identifier
   */

   return 0;
 }




/*
  3.b) Typeclass Operations
*/
 //  Declarations
 ErrorCode ContextManager::declareTypeclassParameter(Identifier ident)
 {
   rsPush(TYPE_ARBITRARY);
   return _context->declareTypeclassParameter(ident, rsTop());
 }

/*
  3.c) Constant Operations
*/




