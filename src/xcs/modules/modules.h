/*
  structs.h (_modules)
  Codeus Tech
  Authored on   April 15, 2020
  Last Modified  July 02, 2021
*/

/*
  Contains structural definitions for Context Manager's ModuleNode

  ModuleNode are the largest vectorized datatype in Xita's ContextManager.
  Each active Module contains a list of declared constants, functions, data
  types, as well as other imported "Submodules".  

  When a user invokes an identifier (e.g. a constant or function), the
  ContextManager starts by searching the current "context" ModuleNode.
  If the identifier isn't defined in the current context, each submodule
  is searched recursively in the same way until found.
*/

#ifndef _MODULES_STRUCTS_H
#define _MODULES_STRUCTS_H

#include <xcs/std/includes.h>
#include <xcs/types/types.h>  //  DEPRECATED
//#include <xcs/types/manager.h>
#include <xcs/regstack/structs.h>
#include <xcs/expressions/constants/constants.h>
#include <xcs/expressions/functions/functions.h>
#include <xcs/expressions/argument.h>

extern int yylineno;

//  Legal XCS Module Types
enum ModuleType
{
  XCSL_HEADER = 1,
  XCSL_SOURCE = 2,
  XCSL_TETHER = 3,
  XCSL_SYSTEM = 4,
};

class ModuleNode
{
  /*
    Private Data
  */
  ModuleID _mid;
  ModuleType _mtype;
  ModuleID _parent;
  ContextManager* context;


protected: 

  vector<Scope> scope_stack;
  Scope scope = 0;
  Scope next_scope = 1;
  int line_number = 0;

  

  vector<RegisterStack> register_stacks;

  TypeManager     types = TypeManager(context);
  vector<TypeNode> _types;
  vector<TypeclassNode> typeclasses;
  
  vector<ConstantNode> constants;
  vector<FunctionNode> functions;
  


public:
  //  Constructors
  ModuleNode(ModuleID mid, ModuleType mtype, ModuleID parent, ContextManager* context);

  vector<ModuleID> imported;
  
  /*
    1.) Private Accessors
  */
  ModuleID Id() { return _mid; }
  ModuleType Type() { return _mtype; }
  ModuleID Parent() { return _parent; }

  
  /*
    2.) Operations/Accessors
  */

  //  2.a) Register Stacks
  RegisterStack* rsCurrent() { return &register_stacks[scope]; }
  ADR rsSec() { return register_stacks[scope].sec(); }
  ADR rsTop() { return register_stacks[scope].top(); }
  ADR rsTop(int from_top) { return register_stacks[scope].from_top(from_top); }
  TypeID rsSecType() { return register_stacks[scope].sec_type(); }
  TypeID rsType() { return register_stacks[scope].top_type(); }
  TypeID rsType(int from_top) { return register_stacks[scope].from_top_type(from_top); }
  ErrorCode rsRemove(int from_top) { return register_stacks[scope].remove(from_top); }

  ADR rsPush(TypeID tid) { return register_stacks[scope].push(tid); }
  ADR rsMerge(TypeID tid, ADR reg);
  ErrorCode rsPop() { return register_stacks[scope].pop(); }
  ErrorCode rsSerialize() { return register_stacks[scope].serialize(); }
  ErrorCode rsSerialize(int top_n) { return register_stacks[scope].serialize(top_n); }
  
  //  2.b) Scope Handling
  ErrorCode initScope();
  ErrorCode beginScope();
  ErrorCode endScope();
  Scope setScope(Scope s) { scope = s; return s; }

  ErrorCode concludeExpression();
  int LineNumber() { return line_number; }
  int LineNumber(int line) { line_number = line; return line; }


  /*
    3.) Identifier Handling
  */

  //  2.a) Types
    ErrorCode _declareType(TypeID tid, Identifier ident)                     {_types.push_back(TypeNode(tid, _mid, ident)); return 0;}//{ return _types.declareType(tid, ident); }
    ErrorCode _declareType(TypeID tid, Identifier ident, unsigned long size) {_types.push_back(TypeNode(tid, _mid, ident, size)); return 0;}//{ return _types.declareType(tid, ident, size); }
    ErrorCode _declareTypeParameter(TypeID tid, Identifier ident);
    ErrorCode _declareTypeConstructor(ConstructorID cid, Identifier ident)   {_types.back().declareConstructor(cid, ident); return 0;}//{ return _types.declareConstructor(cid, ident); }
    ErrorCode _declareTypeElement(Identifier ident, TypeID tid);
    ErrorCode _declareTypeAlias(TypeID alias) { return _types.back().declareAlias(alias); }
    ErrorCode _declareTypeAlias(TypeID alias, TypeID declared) { return _types[alias].declareAlias(declared); }

    unsigned long _TypeSize(TypeID tid); //  In Bytes
    unsigned long _TypeSize(Identifier ident); //  In Bytes
    bool _IsAliased(TypeID alias, TypeID checked);
    
    TypeID _resolveType(Identifier ident);
    Identifier _resolveTypeIdentifier(TypeID tid);
    TypeID _resolveTypeParameter(Identifier ident);
    unsigned long* _resolveTypeConstructor(Identifier ident);
    Identifier _resolveConstructorIdentifier(ConstructorID cid);
    TypeID _resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid);

    ErrorCode _castType(TypeID tid);
    ErrorCode _castTypeConstructor(ConstructorID cid);

  //  2.b) Typeclasses
    ErrorCode _declareTypeclass(TypeID tid, Identifier ident, Identifier param);
    ErrorCode _declareTypeclassPrototype(PrototypeID pid, Identifier ident);

    TypeID _resolveTypeclass(Identifier ident);
    TypeID _resolveTypeclassParameter(Identifier ident);

  //  2.c) Constants
    ErrorCode declareConstant(ConstantID cid, Identifier ident, TypeID type, Arbitrary value);

    ConstantNode* resolveConstant(Identifier ident);

  //  2.d) Functions
    ErrorCode declareFunction(FunctionID fid, Identifier ident);
    ErrorCode declareFunctionParameter(Identifier ident);

    char* endDeclareFunction(TypeID tid);
    ErrorCode undeclareFunction();

    FunctionNode* resolveFunction(Identifier ident, list<ArgumentNode> args);
    FunctionParameterNode* resolveFunctionParameter(Identifier ident);
    TypeID* TypeSignature() { return functions.back().TypeSignature(); }
    unsigned long _CountFunctionParameters() { return functions.back().CountParameters(); }
    ErrorCode castParameter(ConstructorID cid, Index index) { return functions.back().castConstructorParameter(cid, index); }
    ParameterRestrictions _ParamRestrictions(Index i) { return functions.back().ParamRestrictions(i); }

  //  Resolve Arbitrary Identifiers
  unsigned long resolveExpression(Identifier ident);
};

#endif
