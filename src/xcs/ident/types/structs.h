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

//  Linux Imports
#include <vector>
#include <string.h>

//  XCS Imports
#include <xcs/std/typedefs.h>

using namespace std;

extern "C" void yyerror(const char* error);

TypeID next_tid = 18;    //  Number of Types
ConstructorID next_cid = 18;


struct ElementNode
{
  Identifier ident;
  TypeID     type;
};


struct TypeParameterNode
{
  Identifier ident;
};

struct ConstructorNode
{
  Identifier ident;
  ConstructorID cid;
  vector<ElementNode> elements;
};

class TypeNode
{
/*
  PROPERTIES
*/
  Identifier                ident;        //  Type Identifier
  TypeID                    id;           //  Type ID Code
  ConstructorID             enum_term;    //  Starting Constructor ID #
  vector<TypeParameterNode> parameters;   //  Type Parameters
  vector<ConstructorNode>   constructors; //  Type Constructors
  vector<TypeID>            aliases;      //  Type Aliases

public: 

/*
  CONSTRUCTORS
*/
  TypeNode(Identifier _name)
  {
    //  Set Default Properties
    ident = strdup(_name);
    id = next_tid++;
    enum_term = next_cid;

    free(_name);
  }

/*
  ACCESSORS
*/
  unsigned long count_param()  { return parameters.size();   }
  unsigned long count_struct() { return constructors.size(); }
  ConstructorID get_enum_term(){ return enum_term; }

  TypeParameterNode get_parameter(int i)
  {
    /*if (i < 0 || i >= parameters.size())
      yyerror("Type Parameter out of bounds");*/
    return parameters[i];
  }

  ConstructorNode get_constructor(int i)
  {
    /*if (i < 0 || i >= parameters.size())
      yyerror("Constructor out of bounds");*/
    return constructors[i];
  }


/*
  MUTATORS
*/
  ErrorCode add_parameter(Identifier ident)
  {
    TypeParameterNode node;

    node.ident = strdup(ident);

    parameters.push_back(node);

    free(ident);

    //  Return Success
    return 0;
  }


  /*
    add_constructor(ident)
      ident: Capitialized Identifier (Constructor)

      Adds Constructor of name 'ident' to TypeNode 
  */
  ErrorCode add_constructor(Identifier ident)
  {
    ConstructorNode node;

    node.ident = strdup(ident);
    node.cid = next_cid++;

    constructors.push_back(node);

    free(ident);

    //  Return Success
    return 0;
  }


};





#endif
