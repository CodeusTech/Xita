/*
  constants.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains structural definitions for XCS Constant Value Handling
*/

#pragma once

#include <xcs/std/includes.h>


class ConstantNode
{
  ConstantID _cid;
  ModuleID _context;


protected:
  Identifier _ident;
  TypeID _type;
  Arbitrary _value;


public:
  //  Constructors
  ConstantNode(ConstantID cid, ModuleID context, Identifier ident, TypeID type, Arbitrary value)
  {
    _cid = cid;
    _context = context;
    _type = type;
    _ident = strdup(ident); free(ident);
    _value = value;

    std::string str = "Constant " + string(ident) + " has been Initialized";
    l.log('D', "Constants", str);
  }

  /*
    Accessors
  */
  ConstantID Id() { return _cid; }
  ModuleID Context() { return _context; }

  Identifier Ident() { return _ident; }
  TypeID Type() { return _type; }
  Arbitrary Value() { return _value; }

};



