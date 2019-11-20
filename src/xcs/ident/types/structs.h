/*
  structs.h
  Cody Fagley
  Authored on   November 19, 2019
  Last Modified November 19, 2019
*/

/*
  Contains Standard TYPE Structures for use in XCS Compiler Backend
*/

#ifndef TYPES_STRUCTS_H
#define TYPES_STRUCTS_H


#include <vector>

#include <xcs/std/typedefs.h>


using namespace std;


struct ElementNode
{
  Identifier ident;
  TypeID     type;
};

struct ConstructorNode
{
  Identifier ident;
  ConstructorID cid;
  vector<ElementNode> elements;
};

struct TypeNode
{
  Identifier type_ident;  //  Type Identifier
  TypeID     type_id;
  vector<Identifier> param_type; //  Parameter Types
  vector<ConstructorNode> constructors;
};





#endif
