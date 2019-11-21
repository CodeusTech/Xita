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

extern void yyerror(const char* error);

TypeID next_tid = 18;    //  Number of Types
ConstructorID next_cid = 18;


struct TypeParameterNode
{
  Identifier ident;
};


/*
  Records

    A record is an entry within a constructor.  
    Each record has a type expression and an identifier
*/
struct RecordNode
{
  Identifier ident;
  TypeID     type;
  vector<TypeID> extra; //  For type parameters, tuples
};


/*
  Constructors

    A constructor is used to create an entry of a certain data type
*/
class ConstructorNode
{
  Identifier ident;
  ConstructorID cid;
  vector<RecordNode> records;

public:
//  CONSTRUCTORS
  ConstructorNode(Identifier _name)
  {
    ident = _name;
    cid = next_cid++;
  }

//  ACCESSORS
  Identifier get_ident()  { return ident; }
  ConstructorID get_cid() { return cid; }
  vector<RecordNode> get_records() { return records; }

//  MUTATORS
  ErrorCode add_record(Identifier ident, TypeID tid)
  {
    RecordNode rec;
    rec.ident = strdup(ident);
    rec.type = tid;

    records.push_back(rec);

    free(ident);
    return 0;
  }
};


/*
  Type Nodes
*/
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
  vector<vector<TypeID> >   extra_alias;  //  For Handling Tuples and Parameterized Types

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
  Identifier get_ident() { return ident; }
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
    //printf("found constructor: %s\n", constructors[i].get_ident());
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
    add_alias(tid)
      tid: Type ID

      Allows this type identifier to serve as an alias
  */
  ErrorCode add_alias(TypeID tid)
  {
    if (tid <= 0)
      return 1;

    aliases.push_back(tid);

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
    ConstructorNode node = ConstructorNode(ident);

    constructors.push_back(node);


    //  Return Success
    return 0;
  }


};





#endif
