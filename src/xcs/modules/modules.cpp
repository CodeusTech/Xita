/*
  structs.cpp (Modules)
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified April 18, 2020
*/

/*
  Contains implementations for ModuleNode class

  Table of Contents
  =================
  1.) Private Variable Access
  2.) Operations/Accessors
    2.a) Register Stacks
    2.b) Scope Handling
  3.) Identifier Handling
    3.a) Types
    3.b) Typeclasses
    3.c) Constants
    3.d) Functions
*/

#include "modules.h"
#include <xcs/regstack/structs.h>

extern void yyerror(const char* error);

ModuleNode::ModuleNode(ModuleID mid, ModuleType mtype, ModuleID parent, ContextManager* context)
  : context(context)
{
  _mid = mid;
  _mtype = mtype;
  _parent = parent;

  register_stacks.push_back(RegisterStack());
  //_types = TypeManager(mid);

  l.log('d', "Modules", "Initialized Module");
}


/*
  2.) Operations/Accessors
*/


ADR ModuleNode::rsMerge(TypeID tid, ADR reg)
{
  return register_stacks[scope].merge(tid, reg);
}


//  2.c) Scope Handling
ErrorCode ModuleNode::beginScope()
{
  scope_stack.push_back(scope);
  scope = next_scope++;

  return SUCCESS;
}

ErrorCode ModuleNode::endScope()
{
  scope = scope_stack.back();
  scope_stack.pop_back();

  return SUCCESS;
}

ErrorCode ModuleNode::concludeExpression()
{
  setScope(0);
  for (unsigned long i = 0; i < register_stacks[0].size(); ++i)
    register_stacks[0].pop();

  l.log('D', "Scoping", "Concluded current expression");

  return SUCCESS;
}


/*
  3.) Identifier Handling
*/

  //  Declare Parameter
  ErrorCode ModuleNode::_declareTypeParameter(TypeID tid, Identifier ident)
  { return _types.back().declareParameter(tid, ident); }

  //  Declare Element
  ErrorCode ModuleNode::_declareTypeElement(Identifier ident, TypeID tid)
  { return _types.back().declareElement(ident, tid); }


unsigned long ModuleNode::_TypeSize(TypeID tid)
{
  for (unsigned long i = 0; i < _types.size(); ++i)
    if (tid == _types[i].Id())
      return _types[i].Size();
  return 0;
}
unsigned long ModuleNode::_TypeSize(Identifier ident)
{
  for (unsigned long i = 0; i < _types.size(); ++i)
    if (strcmp(ident, _types[i].Ident()))
      return _types[i].Size();
  return 0;
}

bool ModuleNode::_IsAliased(TypeID alias, TypeID checked)
{
  for (Index i = 0; i < _types.size(); ++i)
    if (_types[i].Id() == alias)
      return _types[i].IsAliased(checked);
  return false;
}

  //  Invocations
TypeID ModuleNode::_resolveType(Identifier ident)
{
  TypeID tid = _resolveTypeclass(ident);
  if (tid) return tid;

  for (unsigned long i = 0; i < _types.size(); ++i)
    if (strcmp(ident, _types[i].Ident()) == 0)
      return _types[i].Id();

  return 0;
}

Identifier ModuleNode::_resolveTypeIdentifier(TypeID tid)
{
  for (unsigned long i = 0; i < _types.size(); ++i)
    if (tid == _types[i].Id())
      return _types[i].Ident();

  return NULL;
}

  TypeID ModuleNode::_resolveTypeParameter(Identifier ident)
  {
    TypeID tid;
    if ((tid = _types.back().resolveParameter(ident)))
      return tid;

    return 0;
  }

  unsigned long* ModuleNode::_resolveTypeConstructor(Identifier ident)
  {

    unsigned long* rtn = (unsigned long*) malloc(sizeof(unsigned long)*2);
    ConstructorID cid;
    for (unsigned long i = 0; i < _types.size(); ++i)
      if ((cid = _types[i].resolveConstructor(ident)))
      {
        rsPush(_types[i].Id());
        rtn[0] = _types[i].Id();
        rtn[1] = cid;
        return rtn;
      }

    rtn[0] = 0; rtn[1] = 0;
    return rtn;
  }
  Identifier ModuleNode::_resolveConstructorIdentifier(ConstructorID cid)
  {
    char* str;
    for (unsigned long i = 0; i < _types.size(); ++i)
      if ((str = _types[i].resolveConstructorIdentifier(cid)))
        return str;
    return 0;
  }

  TypeID ModuleNode::_resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid)
  {
    TypeID _tid;
    for (unsigned long i = 0; i < _types.size(); ++i)
      if (tid == _types[i].Id())
        if ((_tid = _types[i].resolveElement(ident, cid)))
          return _tid;
    return 0;
  }

  ErrorCode ModuleNode::_castType(TypeID tid)
  {

    string str = "Last data element has been type cast to " + string(_resolveTypeIdentifier(tid));
    l.log('D', "TypeCheck", str);
    
    return SUCCESS;
  }

  ErrorCode ModuleNode::_castTypeConstructor(ConstructorID cid)
  {
    return SUCCESS;
  }


//  3.b) Typeclasses
  //  Declarations
ErrorCode ModuleNode::_declareTypeclass(TypeID tid, Identifier ident, Identifier param)
{ 
  string tmp = string(ident);
  typeclasses.push_back( TypeclassNode(tid, _mid, ident, param) ); 

  string str = "Declared Typeclass: " + tmp;
  l.log('d', "DeclTypeclass", str);
  return SUCCESS; 
}

  //  Declare Prototype
  ErrorCode ModuleNode::_declareTypeclassPrototype(PrototypeID pid, Identifier ident)
  { return typeclasses.back().declarePrototype(pid, ident); }


TypeID ModuleNode::_resolveTypeclass(Identifier ident)
{
  TypeID tid;
  if ((tid = _resolveTypeclassParameter(ident)))
  {
    l.log('d', "ExpTypeclass", "Resolved typeclass parameter: " + string(ident));
    return tid;
  }

  for (Index i = 0; i < typeclasses.size(); ++i)
    if (strcmp(ident, typeclasses[i].Ident()) == 0)
      return typeclasses[i].Id();
  return 0;
}

  TypeID ModuleNode::_resolveTypeclassParameter(Identifier ident)
  {
    if (!typeclasses.size()) return 0;
    return typeclasses.back().resolvePrototypeParameter(ident);
  }


//  3.c) Constants
  //  Declare Constant
ErrorCode ModuleNode::declareConstant(ConstantID cid, Identifier ident, TypeID type, Arbitrary value)
{ constants.push_back( ConstantNode(cid, _mid, ident, type, value) ); return SUCCESS; }

  //  Resolve Constant
ConstantNode* ModuleNode::resolveConstant(Identifier ident)
{
  for (Index i = 0; i < constants.size(); ++i)
    if (strcmp(constants[i].Ident(), ident) == 0)
      return &constants[i];
  return NULL;
}


//  3.d) Functions
  //  Declare Function
ErrorCode ModuleNode::declareFunction(FunctionID fid, Identifier ident)
{ 
  register_stacks.push_back(RegisterStack());             //  Add new Register Stack for the Function
  scope_stack.push_back(scope); scope = next_scope++;     //  Manipulate Relavent Scope Variables
  functions.push_back( FunctionNode(fid, _mid, ident) );  //  Add Function Node
  
  return SUCCESS; 
}

  //  Declare Parameter
  ErrorCode ModuleNode::declareFunctionParameter(Identifier ident)
  {
    return functions.back().declareParameter(ident, rsTop());
  }

  //  End Function Declaration
  char* ModuleNode::endDeclareFunction(TypeID tid)
  {
    functions.back().Type(tid);
    functions.back().Register(rsTop());

    endScope();

    return functions.back().Ident();
  }

  //  Undeclare Function (let ... in ...)
  ErrorCode ModuleNode::undeclareFunction()
  {
    functions.pop_back();

    return SUCCESS;
  }


  //  Attempt to Resolve Function by Identifier
  FunctionNode* ModuleNode::resolveFunction(Identifier ident, list<ArgumentNode> args)
  {
    for (unsigned long fi = 0; fi < functions.size(); ++fi)
      if (strcmp(functions[fi].Ident(), ident) == 0)
        if (args.size() == functions[fi].CountParameters())
          //  Type Check Argument/Parameter Types Here
            return &functions[fi];
    return NULL;
  }

  FunctionParameterNode* ModuleNode::resolveFunctionParameter(Identifier ident)
  { 
    if (!functions.size()) return NULL;
    return functions.back().resolveParameter(ident); 
  }


unsigned long ModuleNode::resolveExpression(Identifier ident)
{
  return SUCCESS; //  STUB DEPRECATED
}

