/*
  structs.h (Modules)
  Cody Fagley
  Authored on   December 8, 2019
  Last Modified December 8, 2019
*/

/*
  Contains structural definitions for external module import system
*/

#ifndef MODULES_STRUCTS_H
#define MODULES_STRUCTS_H

#include <vector>

#include <xcs/std/typedefs.h>
#include <xcs/std/status.h>
#include <xcs/std/error.h>

#include <xcs/ident/functions/structs.h>
#include <xcs/ident/types/structs.h>

extern ModuleID next_context;

using namespace std;

enum ModuleType
{
  XCSL_HEADER = 1,
  XCSL_SOURCE = 2,
  XCSL_TETHER = 3,
  XCSL_SYSTEM = 4,
};


class ModuleNode
{
 /*
   Private Properties
 */
  //  Meta Properties
  ParserStatus status = ParserStatus::Running;
  ModuleID _id;
  ModuleType mod_type = XCSL_HEADER;  //  Default to HEADER Type

  //  Relationships
  ModuleID parent;
  vector<ModuleNode> children;

  /*
    Identifier Bindings
  */
  vector<ConstantNode> constants;
  vector<FunctionNode> functions = vector<FunctionNode>();
  vector<TypeNode> types;

 /*
   Public Interface
 */
public: 
//  Constructors
  ModuleNode() { }
  ModuleNode(ModuleType mtype, ModuleID _parent) 
  { 
    mod_type = mtype; 
    parent = _parent; 
    _id = next_context++;
  }

//  ACCESSORS
  ModuleID get_ID() { return _id; }
  ModuleType get_module_type() { return mod_type; }
  ParserStatus get_status() { return status; }

  //  Constants
  vector<ConstantNode> get_constants() { return constants; }
  ConstantNode get_constant(ConstantID cid) { return constants[cid]; }
  unsigned int count_constants() { return constants.size(); }

  // Functions
  vector<FunctionNode> get_functions() { return functions; }
  FunctionNode get_function(FunctionID fid) { return functions[fid]; }
  FunctionNode get_last_function() { return functions.back(); }
  ErrorCode remove_last_function() { functions.pop_back(); return 0; }
  unsigned int count_functions() { return functions.size(); }

    Identifier get_function_identifier(FunctionID fid) { return functions[fid].get_identifier(); }

    //  Functional Register Stacks
    ErrorCode push(FunctionID fid, TypeID tid) { return functions[fid].push(tid); }
    ErrorCode push_reg(FunctionID fid, TypeID tid, ADR reg) { return functions[fid].push_reg(tid, reg); }
    ErrorCode push_rtn(FunctionID fid, TypeID tid, ADR reg) { return functions[fid].push_rtn(tid, reg); }
    ErrorCode pop(FunctionID fid) { return functions[fid].pop(); }

    ADR get_from_top(FunctionID fid, int index) { return functions[fid].from_top(index); }
    ADR get_top(FunctionID fid) { return functions[fid].get_top(); }
    ADR get_sec(FunctionID fid) { return functions[fid].get_sec(); }
    ADR get_rtn(FunctionID fid, int rtn_index) { return functions[fid].return_register(rtn_index); }

    TypeID get_from_top_type(FunctionID fid, int index) { return functions[fid].from_top_type(index); }
    TypeID get_top_type(FunctionID fid) { return functions[fid].get_top_type(); }
    TypeID get_sec_type(FunctionID fid) { return functions[fid].get_sec_type(); }
    TypeID get_rtn_type(FunctionID fid, int rtn_index) { return functions[fid].return_type(rtn_index); }

    unsigned int count_ADRs(FunctionID fid) const { return functions[fid].count_reg(); }
    unsigned int count_param(FunctionID fid) const { return functions[fid].count_param(); }
    unsigned int count_rtn(FunctionID fid) const { return functions[fid].count_rtn(); }

    FunctionID get_parent(FunctionID fid) const { return functions[fid].get_parent(); }
    bool is_active(FunctionID fid, ADR reg) const { return functions[fid].is_active(reg); }

    //  Parameters
    ADR get_param_reg(FunctionID fid, ParameterID p) { return functions[fid].get_param_reg(p); }



  //  Types
  vector<TypeNode> get_types() { return types;  }
  TypeNode get_type(TypeID tid) {return types[tid]; }
  TypeNode get_last_type() { return types.back(); }
  unsigned int count_types() { return constants.size(); }

  ConstructorNode get_last_constructor() { return types.back().get_constructor(types.back().count_struct()-1); }

//  MUTATORS

  // Meta Properties
  ErrorCode set_status(ParserStatus stat) { status = stat; return SUCCESS; }

  //  Types
  ErrorCode add_type(TypeNode node) { types.push_back(node); return 0; }
  ErrorCode add_constructor(Identifier ident) { types.back().add_constructor(ident); return 0; }
  ErrorCode add_record(Identifier ident, TypeID tid) 
    { int st = types.back().count_struct(); types.back().get_constructor(st-1).add_record(ident, tid); return 0; }

  //  Constants
  ErrorCode add_constant(ConstantNode cnst) { constants.push_back(cnst); return 0; }

  //  Functions
  ErrorCode add_function(FunctionNode fnode) { functions.push_back(fnode); return 0; }
  ErrorCode add_parameter(Identifier ident) { return functions.back().add_parameter(ident); }

};




#endif
