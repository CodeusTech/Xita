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

  TypeID Type() { return _rtn_type; }


  /*
    Declarations
  */
  ErrorCode declareParameter(Identifier ident, ADR reg);

  /*
    Resolutions
  */
  FunctionID resolve();
  unsigned long resolveParameter(Identifier ident);

};



#include "functions.cpp"
