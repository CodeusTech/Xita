/*
  constructor.h
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified April 18, 2020
*/

/*
  Contains Structural definitions for Type Constructors
*/


#pragma once

#include <vector>

#include <xcs/std/includes.h>


/*
  Constructor Element
*/
struct ConstructorElement
{
  TypeID tid;
  Identifier ident;

  ConstructorElement(TypeID _tid, Identifier _ident)
  {
    tid = _tid;
    ident = strdup(_ident);
    free(ident);
  }
};


/*
  Type Constructor
*/
class TypeConstructor
{
  /*
    Private Data
  */
  ConstructorID _cid;
  TypeID _tid;
  ModuleID _context;
  Identifier _ident;

protected:
  vector<ConstructorElement> _elements;
  unsigned long _size;

public: 
  /*
    Constructors
  */
  TypeConstructor(ConstructorID cid, TypeID tid, ModuleID context, Identifier ident)
  {
    _cid = cid;
    _tid = tid;
    _context = context;
    _size = 0;
    _ident = strdup(ident); free(ident);
  }


  /*
    Private Member Access
  */
  ConstructorID Id() { return _cid; }
  TypeID TypeId() { return _tid; }
  ModuleID Context() { return _context; }
  Identifier Ident() { return _ident; }

  /*
    Public Operations
  */
  ErrorCode declareElement(TypeID tid, Identifier ident) 
  { 
    l.log('D', "Types/Constructors", "Element added to Constructor"); 
    _elements.push_back(ConstructorElement(tid, ident)); 
    return SUCCESS; 
  }

  TypeID resolveElement(Identifier ident)  
  { 
    for (unsigned long i = 0; i < _elements.size(); ++i)
      if (strcmp(_elements[i].ident, ident) == 0) 
        return _elements[i].tid;
    return 0;
  }

};

