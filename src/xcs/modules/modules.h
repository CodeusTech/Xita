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
#include <xcs/types/types.h>
#include <xcs/regstack/structs.h>
#include <xcs/expressions/constants/constants.h>
#include <xcs/expressions/functions/functions.h>

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
  ADR rsSec() { return register_stacks[scope].sec(); }
  ADR rsTop() { return register_stacks[scope].top(); }
  ADR rsTop(int from_top) { return register_stacks[scope].from_top(from_top); }
  TypeID rsSecType() { return register_stacks[scope].sec_type(); }
  TypeID rsType() { return register_stacks[scope].top_type(); }
  TypeID rsType(int from_top) { return register_stacks[scope].from_top_type(from_top); }

  ADR rsPush(TypeID tid) { printf("rsPushed"); return register_stacks[scope].push(tid); }
  ErrorCode rsPushRegister(TypeID tid, ADR reg) { return register_stacks[scope].push_reg(tid, reg); }
  ErrorCode rsPop() { return register_stacks[scope].pop(); }
  
  //  2.b) Scope Handling
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
    ErrorCode declareType(TypeID tid, Identifier ident);
    ErrorCode declareType(TypeID tid, Identifier ident, unsigned long size);
    ErrorCode declareTypeParameter(TypeID tid, Identifier ident);
    ErrorCode declareTypeConstructor(ConstructorID cid, Identifier ident);
    ErrorCode declareTypeElement(Identifier ident, TypeID tid);
    ErrorCode declareTypeAlias(TypeID alias) { return types.back().declareAlias(alias); }

    TypeID resolveType(Identifier ident);
    unsigned long* resolveTypeConstructor(Identifier ident);
    TypeID resolveTypeElement(Identifier ident, ConstructorID cid, TypeID tid);

  //  2.b) Typeclasses
    ErrorCode declareTypeclass(TypeID tid, Identifier ident);
    ErrorCode declareTypeclassPrototype(PrototypeID pid, Identifier ident);
    ErrorCode declareTypeclassParameter(Identifier ident, ADR reg);


  //  2.c) Constants
    ErrorCode declareConstant(ConstantID cid, Identifier ident, TypeID type, Arbitrary value);

    ConstantID resolveConstant(Identifier ident);

  //  2.d) Functions
    ErrorCode declareFunction(FunctionID fid, Identifier ident);
    ErrorCode declareFunctionParameter(Identifier ident);

    ErrorCode endDeclareFunction();
    ErrorCode undeclareFunction();

    FunctionID resolveFunction(Identifier ident);
    unsigned long resolveFunctionParameter(Identifier ident);


  //  Resolve Arbitrary Identifiers
  unsigned long resolveExpression(Identifier ident);

  
};


#include "modules.cpp"
#endif
