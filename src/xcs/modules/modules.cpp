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

ModuleNode::ModuleNode(ModuleID mid, ModuleType mtype, ModuleID parent)
{
  _mid = mid;
  _mtype = mtype;
  _parent = parent;

  register_stacks.push_back(RegisterStack());
  l.log('d', "Modules", "Initialized Module");
}


/*
  2.) Operations/Accessors
*/

//  2.b) Register Stacks
char* ModuleNode::rsPushRegister(TypeID tid, ADR src) 
{
  //  If all registers are in use, reroute to extended stack space
  ADR dest = rsPush(tid);

  //  Copy Data from src to dest
  char* str = (char*) malloc(50);
  sprintf(str, "  mov   %s, %s", get_reg(dest, 8*TypeSize(tid)), get_reg(src, 8*TypeSize(tid)));  

  return str;
}

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

//  3.a) Types
  //  Declarations
ErrorCode ModuleNode::declareType(TypeID tid, Identifier ident)
{ 
  types.push_back( TypeNode(tid, _mid, ident) ); 
  
  std::string str = "Declared Type: " + string(types.back().Ident());
  l.log('D', "DeclType", str);
  return SUCCESS; 
}
ErrorCode ModuleNode::declareType(TypeID tid, Identifier ident, unsigned long size)
{ 
  types.push_back( TypeNode(tid, _mid, ident, size) ); 
  
  std::string str = "Declared Type: " + string(types.back().Ident());
  l.log('D', "DeclType", str);
  return SUCCESS; 
}

  //  Declare Parameter
  ErrorCode ModuleNode::declareTypeParameter(TypeID tid, Identifier ident)
  { return types.back().declareParameter(tid, ident); }

  //  Declare Constructor
  ErrorCode ModuleNode::declareTypeConstructor(ConstructorID cid, Identifier ident)
  { return types.back().declareConstructor(cid, ident); }

  //  Declare Element
  ErrorCode ModuleNode::declareTypeElement(Identifier ident, TypeID tid)
  { return types.back().declareElement(ident, tid); }


unsigned long ModuleNode::TypeSize(TypeID tid)
{
  for (unsigned long i = 0; i < types.size(); ++i)
    if (tid == types[i].Id())
      return types[i].Size();
  return 0;
}
unsigned long ModuleNode::TypeSize(Identifier ident)
{
  for (unsigned long i = 0; i < types.size(); ++i)
    if (strcmp(ident, types[i].Ident()))
      return types[i].Size();
  return 0;
}

bool ModuleNode::IsAliased(TypeID alias, TypeID checked)
{
  for (Index i = 0; i < types.size(); ++i)
    if (types[i].Id() == alias)
      return types[i].IsAliased(checked);
  return false;
}

  //  Invocations
TypeID ModuleNode::resolveType(Identifier ident)
{
  TypeID tid = resolveTypeclass(ident);
  if (tid) return tid;

  for (unsigned long i = 0; i < types.size(); ++i)
    if (strcmp(ident, types[i].Ident()) == 0)
      return types[i].Id();

  return 0;
}

Identifier ModuleNode::resolveTypeIdentifier(TypeID tid)
{
  for (unsigned long i = 0; i < types.size(); ++i)
    if (tid == types[i].Id())
      return types[i].Ident();

  return NULL;
}

  TypeID ModuleNode::resolveTypeParameter(Identifier ident)
  {
    TypeID tid;
    if ((tid = types.back().resolveParameter(ident)))
      return tid;

    return 0;
  }

  unsigned long* ModuleNode::resolveTypeConstructor(Identifier ident)
  {
    unsigned long* rtn = (unsigned long*) malloc(sizeof(unsigned long)*2);
    ConstructorID cid;
    for (unsigned long i = 0; i < types.size(); ++i)
      if ((cid = types[i].resolveConstructor(ident)))
      {
        rtn[0] = types[i].Id();
        rtn[1] = cid;
        return rtn;
      }

    rtn[0] = 0; rtn[1] = 0;
    return rtn;
  }
  Identifier ModuleNode::resolveConstructorIdentifier(ConstructorID cid)
  {
    char* str;
    for (unsigned long i = 0; i < types.size(); ++i)
      if ((str = types[i].resolveConstructorIdentifier(cid)))
        return str;
    return 0;
  }

  TypeID ModuleNode::resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid)
  {
    for (unsigned long i = 0; i < types.size(); ++i)
      if (types[i].Id() == tid)
        return types[i].resolveElement(ident, cid);
    return 0;
  }

  ErrorCode ModuleNode::castType(TypeID tid)
  {

    string str = "Last data element has been type cast to " + string(resolveTypeIdentifier(tid));
    l.log('D', "TypeCheck", str);
    
    return SUCCESS;
  }

  ErrorCode ModuleNode::castTypeConstructor(ConstructorID cid)
  {
    return SUCCESS;
  }


//  3.b) Typeclasses
  //  Declarations
ErrorCode ModuleNode::declareTypeclass(TypeID tid, Identifier ident, Identifier param)
{ 
  string tmp = string(ident);
  typeclasses.push_back( TypeclassNode(tid, _mid, ident, param) ); 

  string str = "Declared Typeclass: " + tmp;
  l.log('d', "DeclTypeclass", str);
  return SUCCESS; 
}

  //  Declare Prototype
  ErrorCode ModuleNode::declareTypeclassPrototype(PrototypeID pid, Identifier ident)
  { return typeclasses.back().declarePrototype(pid, ident); }


TypeID ModuleNode::resolveTypeclass(Identifier ident)
{
  TypeID tid;
  if ((tid = resolveTypeclassParameter(ident)))
  {
    l.log('d', "ExpTypeclass", "Resolved typeclass parameter: " + string(ident));
    return tid;
  }

  for (Index i = 0; i < typeclasses.size(); ++i)
    if (strcmp(ident, typeclasses[i].Ident()) == 0)
      return typeclasses[i].Id();
  return 0;
}

  TypeID ModuleNode::resolveTypeclassParameter(Identifier ident)
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
  return 0;
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
    rsPush(TYPE_ARBITRARY); //  Allocate a register for the parameter
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
    return 0;
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

