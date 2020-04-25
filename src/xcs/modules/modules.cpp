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
{ types.push_back( TypeNode(tid, _mid, ident) ); return SUCCESS; }
ErrorCode ModuleNode::declareType(TypeID tid, Identifier ident, unsigned long size)
{ types.push_back( TypeNode(tid, _mid, ident, size) ); return SUCCESS; }

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

  //  Invocations
TypeID ModuleNode::resolveType(Identifier ident)
{
  for (unsigned long i = 0; i < types.size(); ++i)
    if (strcmp(ident, types[i].Ident()))
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


  TypeID ModuleNode::resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid)
  {
    for (unsigned long i = 0; i < types.size(); ++i)
      if (types[i].Id() == tid)
        return types[i].resolveElement(ident, cid);
    return 0;
  }


//  3.b) Typeclasses
  //  Declarations
ErrorCode ModuleNode::declareTypeclass(TypeID tid, Identifier ident)
{ typeclasses.push_back( TypeclassNode(tid, _mid, ident) ); return SUCCESS; }

  //  Declare Prototype
  ErrorCode ModuleNode::declareTypeclassPrototype(PrototypeID pid, Identifier ident)
  { return typeclasses.back().declarePrototype(pid, ident); }

  //  Declare Prototype Parameter
  ErrorCode ModuleNode::declareTypeclassParameter(Identifier ident, ADR reg)
  { return typeclasses.back().declarePrototypeParameter(ident, reg); }


//  3.c) Constants
  //  Declare Constant
ErrorCode ModuleNode::declareConstant(ConstantID cid, Identifier ident, TypeID type, Arbitrary value)
{ constants.push_back( ConstantNode(cid, _mid, ident, type, value) ); return SUCCESS; }

  //  Resolve Constant
ConstantID ModuleNode::resolveConstant(Identifier ident)
{
  for (unsigned long i = 0; i < constants.size(); ++i)
    if (strcmp(constants[i].Ident(), ident) == 0)
    {
      //  Constant Found -- Resolve Here
      //  Push Type
      rsPush(constants[i].Type());

      //  Grab Value from Constant Address
      //    and push into the Register Stack

      return constants[i].Id();
    }
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
  ErrorCode ModuleNode::endDeclareFunction()
  {
    //  Return to Parent Scope
    scope = scope_stack.back(); scope_stack.pop_back();

    std::string _str = "Function "; _str.append(functions.back().Ident()); _str += " declared";
    l.log('D', "Functions", _str);

    return SUCCESS;
  }

  //  Undeclare Function (let ... in ...)
  ErrorCode ModuleNode::undeclareFunction()
  {
    endDeclareFunction();
    functions.pop_back();

    return SUCCESS;
  }


  //  Attempt to Resolve Function by Identifier
  FunctionNode* ModuleNode::resolveFunction(Identifier ident)
  {
    for (unsigned long i = 0; i < functions.size(); ++i)
      if (strcmp(functions[i].Ident(), ident) == 0)
        return &functions[i];
    return 0;
  }

  FunctionParameterNode* ModuleNode::resolveFunctionParameter(Identifier ident)
  {
    return functions.back().resolveParameter(ident);
  }


unsigned long ModuleNode::resolveExpression(Identifier ident)
{
  return SUCCESS; //  STUB DEPRECATED
}

