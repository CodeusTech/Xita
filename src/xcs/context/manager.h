/*
  manager.h (context)
  Codeus Tech
  Authored on   April 15, 2020
  Last Modified April 16, 2020
*/

/*
  Contains structure/prototypes for XCS Context Manager


  Table of Contents
  =================
  1.) Private Variable Access
  2.) Public Operations
    2.a) Module Operations
    2.b) Register Stack Operations
    2.c) Scope Handling
  3.) Identifier Handling
    3.a) Type Operations
    3.b) Typeclass Operations
    3.c) Constant Operations
    3.d) Function Operations
*/

#ifndef CONTEXT_MANAGER_H
#define CONTEXT_MANAGER_H

#include <vector>

#include <xcs/std/includes.h>

#include <xcs/modules/modules.h>

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

  //  Module Data
  vector<ModuleNode> modules;    //  All Imported Module Contexts
  ModuleNode* _context;          //  Current Module Context
  ModuleID _next_mid = 1;         //  Next Module Node Index

  //  Type Data
  TypeID _next_tid = 0;               //  Indexing starts @ 0 for NULL Type
  ConstructorID _next_constructor = 0; 
  ConstantID _next_cid = 1;
  FunctionID _next_fid = 1;

  TypeID _last_type;                //  Last Encountered Type ID
  ConstructorID _last_constructor;  //  Last Encountered Type Constructor
  Arbitrary _last_data;             //  Last Encountered Data (of Arbitrary Type)

  

public:
  //  Constructors
  ContextManager();

  /*
    1.) Private Variable Access
  */
  ModuleID CurrentContext() { return _context->Id(); }

  //  Getter/Setter: _last_type
  TypeID LastType() { return _last_type; }
  TypeID LastType(TypeID type) { _last_type = type; return type; }
  ConstructorID LastConstructor() { return _last_constructor; }
  ConstructorID LastConstructor(ConstructorID cid) { _last_constructor = cid; return cid; }
  Arbitrary LastData() { return _last_data; }
  Arbitrary LastData(Arbitrary data) { _last_data = data; return data; }

  //  Contextual Line Number
  int LineNumber() { return _context->LineNumber(); }
  int LineNumber(int line) { return _context->LineNumber(line); }


  /*
    2.) Public Operations
  */

  //  2.a) Module Operations
  ErrorCode importModule(ModuleType mtype);
  ErrorCode executeModule();

  //  2.b) Register Stack Operations
    //  Accessors
  ADR rsSec() { return _context->rsSec(); }
  ADR rsTop() { return _context->rsTop(); }
  ADR rsTop(int from_top) { return _context->rsTop(from_top); }
  TypeID rsSecType() { return _context->rsSecType(); }
  TypeID rsType() { return _context->rsType(); }
  TypeID rsType(int from_top) { return _context->rsType(from_top); }
    //  Operations
  ADR rsPush(TypeID tid) { return _context->rsPush(tid); }
  ErrorCode rsPushRegister(TypeID tid, ADR reg) { return _context->rsPushRegister(tid, reg); }
  ErrorCode rsPop() { return _context->rsPop(); }

  // 3.c) Scope Handling
  ErrorCode concludeExpression() { LastType(TYPE_ARBITRARY); LastData((Arbitrary) 0); return _context->concludeExpression(); }


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
  ConstructorID resolveConstructor(Identifier ident);
  TypeID resolveTypeElement(Identifier ident);

  //  3.b) Typeclass Operations
  ErrorCode declareTypeclass(Identifier ident) { return _context->declareTypeclass(_next_tid++, ident); }
  ErrorCode declareTypeclassPrototype(Identifier ident) { return _context->declareTypeclassPrototype(_next_fid++, ident); }
  ErrorCode declareTypeclassParameter(Identifier ident);

  //  3.c) Constant Operations
  ErrorCode declareConstant(Identifier ident) { return _context->declareConstant(_next_cid++, ident, _last_type, _last_data); }

  ConstantID resolveConstant(Identifier ident) { return _context->resolveConstant(ident); }

  //  3.d) Function Operations
  ErrorCode declareFunction(Identifier ident) { return _context->declareFunction(_next_fid++, ident); }
  ErrorCode declareFunctionParameter(Identifier ident) { return _context->declareFunctionParameter(ident); }

  ErrorCode endDeclareFunction() { return _context->endDeclareFunction(); }
  ErrorCode undeclareFunction() { return _context->undeclareFunction(); }

  FunctionID resolveFunction(Identifier ident) { return _context->resolveFunction(ident); }


  /*
    3.) Complex Operations
  */
  unsigned long resolveExpression(Identifier ident) { return _context->resolveExpression(ident); }
  
};

#include "manager.cpp"
#endif
