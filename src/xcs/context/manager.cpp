/*
  manager.cpp
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified April 24, 2020
*/

/*
  Contains implementations for ContextManager Class


  Table of Contents
  =================
  1.) Private Variable Access
  2.) Public Operations
    2.a) Module Operations
    2.b) Assembly Operations
    2.c) Register Stack Operations
    2.d) Scope Handling
  3.) Identifier Handling
    3.a) Type Operations
    3.b) Typeclass Operations
    3.c) Constant Operations
    3.d) Function Operations
*/

#include "manager.h"

/*
  Constructors
*/
ContextManager::ContextManager()
{
  //  Add Root Module/Scope
  modules.push_back(ModuleNode(0, ModuleType::XCSL_SOURCE, 0));
  _context = &modules[0];

  //  Set Type
  LastType(TYPE_ARBITRARY);

  l.log('D', "ContextManager", "Context Manager has been initialized");
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


// 2.c) Register Stacks

  ErrorCode ContextManager::rsPushRegister(TypeID tid, ADR reg) 
  { 
    LastType(tid);
    char* str = _context->rsPushRegister(tid, reg); 

    addInstruction(str);

    return SUCCESS; 
  }

  ADR ContextManager::rsMerge(TypeID tid, ADR reg)
  {
    LastType(tid);
    return _context->rsMerge(tid, reg);
  }


//  2.d) Scope Handling
ErrorCode ContextManager::concludeExpression()
{ 
  LastType(TYPE_ARBITRARY); 
  LastData((Arbitrary) TYPE_ARBITRARY);

  assembly.concludeExpression();
  return _context->concludeExpression(); 
}


// 2.e) Operators
ErrorCode ContextManager::solveOperator(OperatorID oid) 
{ 
  char* ret = operators.solveOperator(oid, _context->rsCurrent()); 
  if (ret) { addInstruction(ret); free(ret); rsPop(); }
  return SUCCESS;
}


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

  if ((tid = _context->resolveType(ident)))
    return LastType(tid);

  for (unsigned long i = 0; i < _context->imported.size(); ++i)
    if ((tid = modules[_context->imported[i]].resolveType(ident)))
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

     std::string str = "Resolved Constructor: " + string(ident);

     l.log('D', "Constructors", str);

     free(rtn);
     return LastConstructor();
   }

   std::string str = "Failed to Resolve Constructor: " + string(ident);
   l.log('E', "Constructors", str);

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


/*
  3.d) Function Operations
*/


ErrorCode ContextManager::declareFunction(Identifier ident) 
{
  FunctionID fid = _next_fid++;
  assembly.initFunction(ident, fid);
  return _context->declareFunction(fid, ident);
}

FunctionID ContextManager::resolveFunction(Identifier ident)
{
  //  Executed when function is called
  char* str = (char*) malloc(50);

  //  First check current context
  FunctionNode* node = _context->resolveFunction(ident, arguments);
  if (node)
  {
    /*
      TODO: Compare Parameter/Argument Count/Types for handling overloaded functions
    */

    //  Handle Arguments
    char* arg_reg; char* param_reg; int i = 0;
    while (!arguments.empty())
    {
      ArgumentNode arg = resolveArgument();
      arg_reg = get_reg(arg.reg, 8*4);                      /* TODO: Replace w/ Type Size */
      param_reg = get_reg(node->ParameterRegister(i), 8*4); /* TODO: Replace w/ Type Size */

      sprintf (str, "  mov   %s, %s", param_reg, arg_reg);
      addInstruction(str);
      i++;
    
      free(arg_reg); free(param_reg);
    }

    sprintf(str, "  bl    __%lu_%s", node->Id(), ident);
    addInstruction(str);
    
    rsMerge(node->Type(), node->Register());

    std::string _str = "Resolved function "; _str.append(ident); _str += " resolved as type " + string(resolveTypeIdentifier(LastType()));
    l.log('D', "Functions", _str);

    free (str);
    return node->Id();
  }

  //  TODO: Check Child (Imported) Module Nodes


  free (str);
  return 0;
}


TypeID ContextManager::resolveFunctionParameter(Identifier ident)
{ 
  FunctionParameterNode* param = _context->resolveFunctionParameter(ident); 
  if (param)
  {
    LastType(param->Type());
    rsPushRegister(LastType(), param->Register());
    
    string str = "Resolved parameter " + string(ident) + " of type " + resolveTypeIdentifier(LastType()) + " in register: " + to_string(param->Register());
    l.log('d', "Functions", str);
    return LastType();
  }
  return 0;
}


/*
  Resolve Arbitrary Identifier Expression
*/
unsigned long ContextManager::resolveExpression(Identifier ident) 
{
  unsigned long _id;

  if ((_id = resolveFunctionParameter(ident)))
    return _id;

  if ((_id = resolveFunction(ident)))
    return _id;

  //  Resolve Constant


  std::string _str = "Identifier "; _str.append(ident); _str += "Could not be resolved";
  l.log('W', "Identifiers", _str);

  return 0;
}
