/*
  structs.h (functions)
  Codeus Tech
  Authored on   October 29, 2019
  Last Modified October 29, 2019
*/

/*
  Contains Data Structures for handling functions
*/

#ifndef FUNCTIONS_STRUCTS_H
#define FUNCTIONS_STRUCTS_H

//  Linux Libraries
#include <vector>
#include <string>
#include <cstdlib>

//  XCS Standard Libraries
#include "../../std/typedefs.h"
#include "../../std/typecodes.h"

//  XCS Utility Libraries
#include "../../utils/scope.h"

using namespace std;


class FunctionParameterNode
{
  ParameterID pid;
  Identifier ident;
  TypeID tid = TYPE_ARBITRARY;
};


/*  
  FunctionNode(ident)  
    * FunctionNodes hold all information that pertains to Functional Declarations
    * Functions can optionally have parameters.
    * Scope IDs are assigned upon Declaration
    * All Functions are typed for their most general use-case, and they all begin as Arbitrary Type
*/
class FunctionNode
{
  Identifier identifier;
  Scope parent;
  Scope scope;
  TypeID rtn_type = TYPE_ARBITRARY;
  vector<FunctionParameterNode> parameters;

public:

//  CONSTRUCTORS
  FunctionNode(Identifier name)
  { 
    parent = get_scope_curr();
    scope = get_scope_next(); 
    ident = strdup(name);
    free(name);
  }

//  ACCESSORS
  Identifier get_identifier() const { return identifier; }
  TypeID get_type() const { return rtn_type; }

};



#endif
