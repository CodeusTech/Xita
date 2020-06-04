/*
  structs.h (_modules)
  Codeus Tech
  Authored on   April 15, 2020
  Last Modified April 16, 2020
*/

/*
  Contains structural definitions for Context Manager's ModuleNode


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


protected: 

  vector<Scope> scope_stack;
  Scope scope = 0;
  Scope next_scope = 1;
  int line_number = 0;

  //  Module-Specific Managers
  //TypeManager types;
  

  vector<RegisterStack> register_stacks;

  vector<TypeNode> types;
  vector<TypeclassNode> typeclasses;
  
  vector<ConstantNode> constants;
  vector<FunctionNode> functions;
  


public:
  //  Constructors
  ModuleNode(ModuleID mid, ModuleType mtype, ModuleID parent);

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

  ADR rsPush(TypeID tid) { return register_stacks[scope].push(tid); }
  char* rsPushRegister(TypeID tid, ADR reg);
  ADR rsMerge(TypeID tid, ADR reg);
  ErrorCode rsPop() { return register_stacks[scope].pop(); }
  
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
    ErrorCode declareType(TypeID tid, Identifier ident)                     {types.push_back(TypeNode(tid, _mid, ident)); return 0;}//{ return types.declareType(tid, ident); }
    ErrorCode declareType(TypeID tid, Identifier ident, unsigned long size) {types.push_back(TypeNode(tid, _mid, ident, size)); return 0;}//{ return types.declareType(tid, ident, size); }
    ErrorCode declareTypeParameter(TypeID tid, Identifier ident);
    ErrorCode declareTypeConstructor(ConstructorID cid, Identifier ident)   {types.back().declareConstructor(cid, ident); return 0;}//{ return types.declareConstructor(cid, ident); }
    ErrorCode declareTypeElement(Identifier ident, TypeID tid);
    ErrorCode declareTypeAlias(TypeID alias) { return types.back().declareAlias(alias); }
    ErrorCode declareTypeAlias(TypeID alias, TypeID declared) { return types[alias].declareAlias(declared); }

    unsigned long TypeSize(TypeID tid); //  In Bytes
    unsigned long TypeSize(Identifier ident); //  In Bytes
    bool IsAliased(TypeID alias, TypeID checked);
    
    TypeID resolveType(Identifier ident);
    Identifier resolveTypeIdentifier(TypeID tid);
    TypeID resolveTypeParameter(Identifier ident);
    unsigned long* resolveTypeConstructor(Identifier ident);
    Identifier resolveConstructorIdentifier(ConstructorID cid);
    TypeID resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid);

    ErrorCode castType(TypeID tid);
    ErrorCode castTypeConstructor(ConstructorID cid);

  //  2.b) Typeclasses
    ErrorCode declareTypeclass(TypeID tid, Identifier ident, Identifier param);
    ErrorCode declareTypeclassPrototype(PrototypeID pid, Identifier ident);

    TypeID resolveTypeclass(Identifier ident);
    TypeID resolveTypeclassParameter(Identifier ident);

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


#include "modules.cpp"
#endif
