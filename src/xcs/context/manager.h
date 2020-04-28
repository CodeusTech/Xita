/*
  manager.h (context)
  Codeus Tech
  Authored on   April 15, 2020
  Last Modified April 26, 2020
*/

/*
  Contains structure/prototypes for XCS Context Manager


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

#ifndef CONTEXT_MANAGER_H
#define CONTEXT_MANAGER_H

#include <vector>
#include <list>

#include <xcs/std/includes.h>
#include <xcs/std/scope.h>

#include "expression.h"

#include <xcs/asm/manager.h>
#include <xcs/expressions/operators/manager.h>
#include <xcs/modules/modules.h>
#include <xcs/expressions/argument.h>

extern int yylineno;


/*
  ContextManager contains the top-level object in the XCS Cross-Compiler Backend

  In an active compile job, the instance's ContextManager has knowledge of all
  other active object instances (e.g. Types, Functions, Constants, Modules, etc.).
*/
class ContextManager
{
  /*
    Private Data
  */
  

protected:

  //  Managers
  AssemblyManager assembly;       //  Manages Buffers for producing Assembly Files
  OperatorManager operators;      //  Manages Active Operator Semantics (e.g. Addition)

  //  Modules
  vector<ModuleNode> modules;     //  All Imported Module Contexts
  ModuleNode* _context;           //  Current Module Context

  //  Context IDs
  ModuleID _next_mid = 1;         //  Next Module Node Index
  TypeID _next_tid = 0;           //  Indexing starts @ 0 for NULL Type/Constructor
  ConstructorID _next_constructor = 0; 
  ConstantID _next_cid = 1;       //  Next Constant ID
  FunctionID _next_fid = 1;       //  Next Function ID

  //  Active Compiler Data
    //  Last Encountered Data
  ExpressionType _last_expression;  //  Last Encountered Expression Type
  TypeID _last_type;                //  Last Encountered Type ID
  ConstructorID _last_constructor;  //  Last Encountered Type Constructor
  Arbitrary _last_data;             //  Last Encountered Data (of Arbitrary Type)
  unsigned long _last_index;        //  Used Encountered Index 
    //  Loaded Arguments
  list<ArgumentNode> arguments;   //  Arguments loaded for an expression (e.g. function)



public:
  //  Constructors
  ContextManager();

  /*
    1.) Accessors
  */
  ModuleID CurrentContext() { return _context->Id(); }

  //  Last Encountered Info
  ExpressionType LastExpression() { return _last_expression; }
  ExpressionType LastExpression(ExpressionType exp) { _last_expression = exp; return _last_expression; }
  TypeID LastType() { return _last_type; }
  TypeID LastType(TypeID type) { _last_type = type; return _last_type; }
  ConstructorID LastConstructor() { return _last_constructor; }
  ConstructorID LastConstructor(ConstructorID cid) { _last_constructor = cid; return _last_constructor; }
  Arbitrary LastData() { return _last_data; }
  Arbitrary LastData(Arbitrary data) { _last_data = data; return _last_data; }
  Index LastIndex() { return _last_index; }
  Index LastIndex(Index i) { _last_index = i; return _last_index; }
  
  //  Loaded Arguments
  unsigned long CountArguments() { return arguments.size(); }

  //  Contextual Line Number
  int LineNumber() { return _context->LineNumber(); }
  int LineNumber(int line) { return _context->LineNumber(line); }

  string TypeSignature();
  string TypeSignature(Identifier function);

  /*
    2.) Public Operations
  */

  //  2.a) Module Operations
  ErrorCode importModule(ModuleType mtype);
  ErrorCode executeModule();

  //  2.b) Assembly Operations
  ErrorCode generateAssembly(FILE* file) { return assembly.generateAssembly(file); }
  ErrorCode addInstruction(char* instruction) { return assembly.addInstruction(instruction); }
  ErrorCode popLastInstruction() { return assembly.popLastInstruction(); }

  //  2.c) Register Stack Operations
    //  Accessors
  ADR rsSec() { return _context->rsSec(); }
  ADR rsTop() { return _context->rsTop(); }
  ADR rsTop(int from_top) { return _context->rsTop(from_top); }
  TypeID rsSecType() { return _context->rsSecType(); }
  TypeID rsType() { return _context->rsType(); }
  TypeID rsType(int from_top) { return _context->rsType(from_top); }
    //  Operations
  ADR rsPush(TypeID tid) { return _context->rsPush(tid); }
  ErrorCode rsPushRegister(TypeID tid, ADR reg);
  ADR rsMerge(TypeID tid, ADR reg);
  ErrorCode rsPop() { return _context->rsPop(); }

  // 2.d) Scope Handling
  ErrorCode concludeExpression();

  //  2.e) Operators
  ErrorCode solveOperator(OperatorID oid);

  /*
    3.) Identifier Handling
  */

  //  3.a) Type Operations
  ErrorCode declareType(Identifier ident) { return _context->declareType(_next_tid++, ident); }
  ErrorCode declareType(Identifier ident, unsigned long size) { return _context->declareType(_next_tid++, ident, size); }
  ErrorCode declareTypeParameter(Identifier ident) { return _context->declareTypeParameter(_next_tid++, ident); }
  ErrorCode declareTypeConstructor(Identifier ident) { return _context->declareTypeConstructor(_next_constructor++, ident); }
  ErrorCode declareTypeElement(Identifier ident, TypeID tid) { return _context->declareTypeElement(ident, tid); }
  ErrorCode declareTypeAlias(TypeID tid) { return _context->declareTypeAlias(tid); }

  TypeID resolveType(Identifier ident);
  Identifier resolveTypeIdentifier(TypeID tid) { return _context->resolveTypeIdentifier(tid); }
  ConstructorID resolveConstructor(Identifier ident);
  Identifier resolveConstructorIdentifier(ConstructorID cid) { return _context->resolveConstructorIdentifier(cid); }
  TypeID resolveConstructorType(ConstructorID cid);
  TypeID resolveTypeElement(Identifier ident);

  //  3.b) Typeclass Operations
  ErrorCode declareTypeclass(Identifier ident) { return _context->declareTypeclass(_next_tid++, ident); }
  ErrorCode declareTypeclassPrototype(Identifier ident) { return _context->declareTypeclassPrototype(_next_fid++, ident); }
  ErrorCode declareTypeclassParameter(Identifier ident);

  //  3.c) Constant Operations
  ErrorCode declareConstant(Identifier ident) { return _context->declareConstant(_next_cid++, ident, _last_type, _last_data); }

  ConstantID resolveConstant(Identifier ident) { return _context->resolveConstant(ident); }

  //  3.d) Function Operations
  ErrorCode declareFunction(Identifier ident);
  ErrorCode declareFunctionParameter(Identifier ident) { return _context->declareFunctionParameter(ident); }

  ErrorCode endDeclareFunction();  //{ return _context->endDeclareFunction(); }
  ErrorCode undeclareFunction() { return _context->undeclareFunction(); }

  FunctionID resolveFunction(Identifier ident);
  TypeID resolveFunctionParameter(Identifier ident);

  //  3.e) Argument Operations
  ErrorCode loadArgument(TypeID tid, ADR reg) { arguments.push_back(ArgumentNode(tid, reg)); return SUCCESS; }
  ArgumentNode resolveArgument() { ArgumentNode arg = arguments.front(); arguments.pop_front(); return arg; }


  /*
    3.) Complex Operations
  */
  //  Resolve Identifiers
  unsigned long resolveExpression(Identifier ident);
  unsigned long castExpression(Identifier ident);
};


#include "manager.cpp"
#endif
