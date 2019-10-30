/*
  structs.h (functions)
  Codeus Tech
  Authored on   October 29, 2019
  Last Modified October 29, 2019
*/

/*
  Contains Data Structures for handling functions

  
  TABLE OF CONTENTS
  =================
  1.) Constants
  2.) Functions
*/

#ifndef FUNCTIONS_STRUCTS_H
#define FUNCTIONS_STRUCTS_H

//  Linux Libraries
#include <vector>
#include "string.h"
#include <cstdlib>

//  XCS Standard Libraries
#include "../../std/typedefs.h"
#include "../../std/typecodes.h"

//  XCS Utility Libraries
#include "../../utils/scope.h"

using namespace std;



/*
  1.) Constants
*/

class ConstantNode
{
  ConstantID cid;
  Identifier identifier;
  TypeID tid;
  Arbitrary value;

public: 
//  CONSTRUCTORS
  ConstantNode(Identifier ident, TypeID _tid, Arbitrary val)
  {
    identifier = strdup(ident);
    tid = _tid;
    value = val;
  }

//  ACCESSORS
  ConstantID get_ID() const { return cid; }
  Identifier get_identifier() const { return identifier; }
  TypeID     get_type() const { return tid; }
  Arbitrary  get_value() const { return value; }

//  MUTATORS
  ErrorCode set_value(Arbitrary data) { value = data; return 0; /*Success*/ }
};


/*
  FunctionParameterNode(ident)
*/
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
    identifier = strdup(name);
    free(name);
  }

//  ACCESSORS
  Identifier get_identifier() const { return identifier; }
  TypeID get_type() const { return rtn_type; }

};



#endif
