/*
  param.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains definitions/implementations for type parameters
*/

#pragma once

#include <xcs/std/includes.h>


class TypeParameterNode
{
  Identifier _ident;
  TypeID _tid;


public:

  /*
    Constructors
  */
  TypeParameterNode(Identifier ident, TypeID tid)
  {
    _tid = tid;
    _ident = strdup(ident); free(ident);
  }

  ~TypeParameterNode() { free(_ident); }


  /*
    Accessors
  */
  Identifier Ident() { return _ident; }
  TypeID Id() { return _tid; }



};

