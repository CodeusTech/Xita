/*
  manager.h (context)
  Codeus Tech
  Authored on    April 15, 2020
  Last Modified August 03, 2021
*/

/*
  Contains structure/prototypes for Xita Context Manager

  The ContextManager is a singular global object for managing the language's
  active metadata.  The ContextManager's most important job is to provide an
  interface between the other various "Manager" classes in Xita's backend.  

  The ContextManager has access to each of Xita's System Managers:
    * AssemblyManager
    * OperatorManager
    * DataManager
    * MemoryVariableManager

  The ContextManager provides a central backend interface for:
    * Modules
    * Data Types
    * Functions
    * Constants
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
#include <xcs/data/manager.h>
#include <xcs/types/manager.h>
#include <xcs/firmware/manager.h>

#include <xcs/modules/modules.h>
#include <xcs/expressions/argument.h>
#include <xcs/expressions/memory/memory.h>

#include <xcs/sys/xalloc/xalloc.h>

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

  //  System Managers
  AssemblyManager assembly;                           //  Manages Buffers for producing Assembly Files
  OperatorManager operators = OperatorManager(this);  //  Manages Active Operator Semantics (e.g. Addition)
  DataManager     data = DataManager(this);           //  Manages Active Backend Data Values/Types
  MemoryVariableManager memory; //  DEPRECATED!!!  Will be merged into MemoryAllocator
  MemoryAllocator xalloc = MemoryAllocator(this);
  FirmwareManager firmware = FirmwareManager(this);

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

  ModuleID CurrentContext() { return _context->Id(); }

  //  Last Encountered Data /* DEPRECATED SECTION */
  /*
    NOTE!!  There has to be a way to clean this crap up.  All of these "Last*()" functions
            are necessary for something in Xita.  We need to reorganize into managers
  */
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
  bool TypeCheck();
  //  Last Encountered Data
  ErrorCode newData(TypeID tid, Arbitrary value) { return data.newData(tid, value); }
  ErrorCode addData(TypeID tid, Arbitrary value) { return data.addData(tid, value); }
  ErrorCode addData(Identifier ident)            { return data.addData(ident); }

  //  New interface functionality to simplify the "LastEncounteredData" system
  ErrorCode rsData(ConstructorID cid);


  
  //  Loaded Arguments
  unsigned long CountArguments() { return arguments.size(); }

  //  Contextual Line Number
  int LineNumber() { return _context->LineNumber(); }
  int LineNumber(int line) { return _context->LineNumber(line); }

  string TypeSignature();
  string TypeSignature(Identifier function);

  /*
    Chip/Firmware Operations
  */
  ErrorCode newChip(string name) { return firmware.newChip(name); }
  ErrorCode setChipArch(string arch) { return firmware.setChipArch(arch); }
  ErrorCode addFirmwareInterface(string name) { return firmware.addInterface(name); }
  ErrorCode addFirmwareRange(int begin, int end) { return firmware.addInterfaceRange(begin, end); }
  ErrorCode requestMemoryRead(int addr) { return firmware.requestMemoryRead(addr); }
  ErrorCode requestMemoryWrite(int addr) { return firmware.requestMemoryWrite(addr); }
  ErrorCode getArchRegisterWidth() { return firmware.getArchRegisterWidth(); }


  /*
    2.) Public Operations
  */

  //  2.a) Module Operations
  ErrorCode importModule(ModuleType mtype);
  ErrorCode executeModule();

  //  2.b) Assembly Operations
  ErrorCode generateAssembly(FILE* file) { return assembly.generateAssembly(file); }
  ErrorCode addInstruction(char* instruction) { return assembly.addInstruction(instruction); }
  ErrorCode addInstruction(const char* instr) { return assembly.addInstruction(instr); }
  ErrorCode addConstant(char* constant) { return assembly.addConstant(constant); }
  ErrorCode addString(char* str) { return assembly.addString(str); }
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
  ADR rsPush(TypeID tid);
  ErrorCode rsCopy(TypeID tid, ADR src);
  ADR rsMerge(TypeID tid, ADR reg);
  ErrorCode rsPop() { return _context->rsPop(); }
  ErrorCode rsSerialize() { return _context->rsSerialize(); }
  ErrorCode rsSerialize(int top_n) { return _context->rsSerialize(top_n); }

  // 2.d) Scope Handling
  ErrorCode concludeExpression();

  //  2.e) Operators
  ErrorCode resolveOperator(OperatorID oid);

  /*
    3.) Identifier Handling
  */

  //  3.a) Type Operations
    //  Declarations
  ErrorCode declareType(Identifier ident) { return _context->_declareType(_next_tid++, ident); }
  ErrorCode declareType(Identifier ident, unsigned long size) { return _context->_declareType(_next_tid++, ident, size); }
  ErrorCode declareTypeParameter(Identifier ident);
  ErrorCode declareTypeConstructor(Identifier ident) { return _context->_declareTypeConstructor(_next_constructor++, ident); }
  ErrorCode declareTypeElement(Identifier ident, TypeID tid);
  ErrorCode declareTypeAlias(TypeID tid);

    //  Resolve
  TypeID resolveType(Identifier ident); //  TODO: This should return reference to TypeNode
  Identifier resolveTypeIdentifier(TypeID tid) { return _context->_resolveTypeIdentifier(tid); }
  TypeID resolveTypeParameter(Identifier ident);
  ConstructorID resolveConstructor(Identifier ident);
  Identifier resolveConstructorIdentifier(ConstructorID cid) { return _context->_resolveConstructorIdentifier(cid); }
  TypeID resolveConstructorType(ConstructorID cid);
  TypeID resolveTypeElement(Identifier ident);

    //  Information
  unsigned long long TypeSize(TypeID tid) { return 4; } //  TODO: Implement Me!

  //  3.b) Typeclass Operations
  ErrorCode declareTypeclass(Identifier ident, Identifier param) { return _context->_declareTypeclass(_next_tid++, ident, param); }
  ErrorCode declareTypeclassPrototype(Identifier ident) { return _context->_declareTypeclassPrototype(_next_fid++, ident); }

  TypeID resolveTypeclass(Identifier ident);
  ErrorCode implementTypeclass(Identifier ident);

  //  3.c) Constant Operations
  ErrorCode declareConstant(Identifier ident);
  
  ConstantID resolveConstant(Identifier ident);
  ConstantNode* resolveConstantNode(Identifier ident) { return _context->resolveConstant(ident); }

  //  3.d) Function Operations
  ErrorCode declareFunction(Identifier ident);
  ErrorCode declareFunctionParameter(Identifier ident);

  ErrorCode endDeclareFunction();  //{ return _context->endDeclareFunction(); }
  ErrorCode undeclareFunction() { return _context->undeclareFunction(); }

  FunctionID resolveFunction(Identifier ident);
  TypeID resolveFunctionParameter(Identifier ident);

  //  3.e) Argument Operations
  ErrorCode loadArgument(TypeID tid) { arguments.push_back(ArgumentNode(tid, rsTop())); return SUCCESS; }
  ArgumentNode resolveArgument() { ArgumentNode arg = arguments.front(); arguments.pop_front(); return arg; }

  //  3.f) Memory Operations
  ErrorCode addMemoryVariable(Identifier ident) { memory.addMemoryVariable(ident); return SUCCESS; }
  ErrorCode rmMemoryVariable(Identifier ident)  { memory.rmMemoryVariable(ident);  return SUCCESS; }
  TypeID resolveMemoryVariable(Identifier);

  /*
    3.) Complex Operations
  */
  //  Resolve Identifiers
  unsigned long resolveExpression(Identifier ident);
  unsigned long castExpression(Identifier ident);
  ErrorCode pushExpression(TypeID tid);
};


#endif
