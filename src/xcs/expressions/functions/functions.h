/*
  functions.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains Structural functionality for function handling in XCS
*/

#pragma once

#include <xcs/std/includes.h>

#include "param.h"


class FunctionNode
{
  /*
    Private Data
  */
  FunctionID _fid;
  ModuleID _context;
  Identifier _ident;


protected:

  TypeID _rtn_type;
  ADR _rtn_reg;

  vector<FunctionParameterNode> parameters;


public:
  //  Constructors
  FunctionNode(FunctionID fid, ModuleID context, Identifier ident);
  
  /*
    Accessors
  */
  FunctionID Id() { return _fid; }
  ModuleID Context() { return _context; }
  Identifier Ident() { return _ident; }
  TypeID* TypeSignature();

  TypeID Type() { return _rtn_type; }
  TypeID Type(TypeID tid) { _rtn_type = tid; return _rtn_type; }
  ADR Register() { return _rtn_reg; }
  ADR Register(ADR reg) { _rtn_reg = reg; return _rtn_reg; }
  unsigned long CountParameters() { return parameters.size(); }
  TypeID ParameterRegister(unsigned long index) { return parameters[index].Register(); }
  TypeID ParameterType(unsigned long index) { return parameters[index].Type(); }
  ParameterRestrictions ParamRestrictions(Index index) { return parameters[index].Restrictions(); }

  /*
    Declarations
  */
  ErrorCode declareParameter(Identifier ident, ADR reg);

  /*
    Resolutions
  */
  FunctionParameterNode* resolveParameter(Identifier ident);

  /*
    Dynamic Operations
  */
  ErrorCode castConstructorParameter(ConstructorID cid, Index index) { return parameters[index].castConstructor(cid); }

};

