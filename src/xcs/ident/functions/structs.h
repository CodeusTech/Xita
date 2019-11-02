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
#include <xcs/std/typedefs.h>
#include <xcs/std/typecodes.h>
#include <xcs/std/scope.h>

#include <xcs/regstack/regstack.h>

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
  ParameterID Generation
*/
ParameterID parameter_index = 1;
ParameterID get_parameter_id() { return parameter_index++; }

/*
  FunctionParameterNode(ident)
*/
class FunctionParameterNode
{
  ParameterID pid;
  Identifier ident;
  TypeID tid;
  ADR reg;

public:

//  CONSTRUCTORS
  FunctionParameterNode(Identifier name)
  {
    pid = get_parameter_id();
    ident = strdup(name);
    free (name);
    tid = TYPE_ARBITRARY;
  }



//  ACCESSORS
  ParameterID get_ID()          { return pid; }
  Identifier  get_identifier()  { return ident; }
  TypeID      get_type()        { return tid; }
  ADR         get_reg()         { return reg; }


//  MUTATORS
  ErrorCode set_identifier(Identifier _ident) { ident = strdup(_ident); free(_ident); return 0; }
  ErrorCode set_type(TypeID _tid) { tid = _tid; return 0; }
  ErrorCode set_reg(ADR adr) { reg = adr; return 0; }

//  DEEP COPY
  typedef FunctionParameterNode Self;
  Self copy()
  {
    Self data = Self(ident);
    data.tid = tid;
    data.pid = pid;
    return data;
  }
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
  ParameterID param_index;
  RegisterStack reg_stack;

public:

//  CONSTRUCTORS
  FunctionNode(Identifier name)
  { 
    fid = get_next_function();
    parent = get_scope_curr();
    scope = get_scope_next(); 
    set_scope_curr(scope);
    identifier = strdup(name);
    free(name);
    param_index = parameter_index;
    reg_stack = RegisterStack();
    parameters = vector<FunctionParameterNode>();
  }

//  ACCESSORS
  //  General Accessors
  Scope get_scope() const { return scope; }
  Scope get_parent() const { return parent; }
  FunctionID get_ID() const { return fid; }
  Identifier get_identifier() const { return identifier; }
  TypeID get_type() const { return rtn_type; }

  unsigned int count_param() const { return parameters.size(); }
  vector<FunctionParameterNode> get_param() { return parameters; }
  TypeID get_param_type(int p) { return parameters[p].get_type(); }
  ADR get_param_reg(int p) { return parameters[p].get_reg(); }
  
  //  Register Stack Accessors
  ADR get_top() { return reg_stack.top(); }
  ADR get_sec() { return reg_stack.sec(); }
  TypeID get_top_type() { return reg_stack.top_type(); }
  TypeID get_sec_type() { return reg_stack.sec_type(); }

//  MUTATORS
  ErrorCode push(TypeID tid) { return reg_stack.push(tid); }
  ErrorCode pop() { return reg_stack.pop(); }

  ErrorCode add_parameter(Identifier ident)
  {
    FunctionParameterNode node = FunctionParameterNode(ident);

    push(2);
    node.set_reg(get_top());
    
    parameters.push_back(node);

    return 0;
  }

  /* 2.) Serialize Register Stack

    Returns:
      0, if Successful
  */
  /*ErrorCode serialize()
  {
    unsigned long long reg1 = (unsigned long long) 0;

    //  Create Serial Integers
    for (int i = 0; i < active; i++)
    {
      unsigned long long test = (unsigned long long) rs[scope_curr].rs_code[rs_sec()];
      unsigned long long test2 = ((31 & test) << (i * 5));

      reg1 |= test2;

      ADR reg = rs_pop();
    }

    char* str = (char*) malloc(50);
    sprintf(str, "mov   W30, %llu\n", reg1);

    add_command(str);

    return 0;
  }*/

};



#endif
