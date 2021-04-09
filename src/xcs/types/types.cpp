/*
  structs.cpp (Types)
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified April 18, 2020
*/

/*
  Contains extended implementations for structures used by XCS Type System
*/

#include "types.h"



/*
  Constructors
*/
//  Default backend constructor for Type Nodes
TypeNode::TypeNode(TypeID tid, ModuleID context, Identifier ident)
{
  _tid = tid;
  _context = context;
  _ident = strdup(ident);
  _size = 0;

  if (tid > 2)
  {
    std::string str = "Type " + string(ident) + " has been Initialized";
    l.log('d', "Types", str);
  }
}
//  This constructor is used for primitives
TypeNode::TypeNode(TypeID tid, ModuleID context, Identifier ident, unsigned long size)
{
  _tid = tid;
  _context = context;
  _ident = strdup(ident);
  _size = size;
}


/*
  Declarations
*/

//  Declare Constructor
ErrorCode TypeNode::declareConstructor(ConstructorID cid, Identifier ident)
{
  constructors.push_back( TypeConstructor(cid, _tid, _context, ident) );
  return SUCCESS;
}

//  Declare Element
ErrorCode TypeNode::declareElement(Identifier ident, TypeID tid)
{ return constructors.back().declareElement(tid, ident); }

//  Declare Parameter
ErrorCode TypeNode::declareParameter(TypeID tid, Identifier ident)
{ 
  parameters.push_back( TypeParameterNode(ident, tid) );
  return SUCCESS;
}

/*
  Resolution
*/

//  Resolve Constructor
ConstructorID TypeNode::resolveConstructor(Identifier ident)
{
  for (unsigned long i = 0; i < constructors.size(); ++i)
    if (strcmp(constructors[i].Ident(), ident) == 0)
      return constructors[i].Id();
  return 0;
}

Identifier TypeNode::resolveConstructorIdentifier(ConstructorID cid)
{
  for (Index i = 0; i < constructors.size(); ++i)
    if (constructors[i].Id() == cid)
      return constructors[i].Ident();
  return NULL;
}

//  Resolve Element
TypeID TypeNode::resolveElement(Identifier ident, ConstructorID cid)
{
  TypeID tid;
  for (unsigned long i = 0; i < constructors.size(); ++i)
    if ((tid = constructors[i].resolveElement(ident)))
      return tid;
  return 0;
}

TypeID TypeNode::resolveParameter(Identifier ident)
{
  for (Index i = 0; i < parameters.size(); ++i)
    if (strcmp(parameters[i].Ident(), ident) == 0)
      return parameters[i].Id();
  return 0;
}


bool TypeNode::findConstructorID(ConstructorID cid)
{
  for (Index i = 0; i < constructors.size(); ++i)
    if (constructors[i].Id() == cid)
      return true;
  return false;
}
