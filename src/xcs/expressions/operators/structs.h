/*
  structs.h (Operators)
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 28, 2020
*/

/*
  Contains structure/implementations for XCS Operands
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/regstack/structs.h>




class Operand
{

protected:
  TypeID _rtn;
  TypeID* _tids;

  vector<char*> instructions;


public:
  Operand(TypeID rtn, TypeID* tids) { _tids = tids; _rtn = rtn; }
  ErrorCode addInstruction(char* comm) { instructions.push_back(comm); return SUCCESS; }

  TypeID* OperandTypes() { return _tids; }
  TypeID  ReturnType() { return _rtn; }
};



class Operator
{

protected:
  vector<Operand> operands;
  char* op;
  bool is_communitive = true;


public:

  virtual char* resolve(RegisterStack* rs) { l.log('d', "Operators", "Operator has been Resolved..."); }


};

