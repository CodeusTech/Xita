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
#include "../../std/scope.h"

using namespace std;


ConstantID next_const = 1;
FunctionID next_funct = 1;

ConstantID get_next_constant() { return next_const++; }
FunctionID get_next_function() { return next_funct++; }

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
    cid = get_next_constant();
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
  FunctionID fid;
  Identifier identifier;
  Scope parent;
  Scope scope;
  TypeID rtn_type = TYPE_ARBITRARY;
  vector<FunctionParameterNode> parameters;

public:

//  CONSTRUCTORS
  FunctionNode(Identifier name)
  { 
    fid = get_next_function();
    parent = get_scope_curr();
    scope = get_scope_next(); 
    identifier = strdup(name);
    free(name);
  }

//  ACCESSORS
  Scope get_scope() const { return scope; }
  FunctionID get_ID() const { return fid; }
  Identifier get_identifier() const { return identifier; }
  TypeID get_type() const { return rtn_type; }

};



#endif
