/*
  argument.h
  Codeus Tech
  Authored on   April 26, 2020
  Last Modified April 26, 2020
*/

/*
  Contains structure/implementations for arguments to other expressions
*/

#pragma once

#include <xcs/std/includes.h>


struct ArgumentNode
{
  TypeID tid;
  ADR reg;

  ArgumentNode(TypeID _tid, ADR _reg) 
  { 
    tid = _tid; 
    reg = _reg; 
  }
};


