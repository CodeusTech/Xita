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


#include <xcs/std/typedefs.h>
#include <xcs/ident/functions/structs.h>


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

  //  Module Properties
  ModuleType mod_type = XCSL_HEADER;  //  Default to HEADER Type
  ModuleID _id;

  //  Relationships
  ModuleID parent;
  vector<ModuleNode> children;

  /*
    Identifier Bindings
  */
  //  TODO: Move constants, functions, etc. here
  vector<TypeNode> types;

 /*
   Public Interface
 */
public: 
//  Constructors
  ModuleNode() {  }
  ModuleNode(ModuleType mtype) { mod_type = mtype; }

//  ACCESSORS
  ModuleType get_module_type() { return mod_type; }

  //  Types
  vector<TypeNode> get_types() { return types;  }
  TypeNode get_type(TypeID tid) {return types[tid]; }
  TypeNode get_last_type() { return types.back(); }

  ConstructorNode get_last_constructor() { return types.back().get_constructor(types.back().count_struct()-1); }

//  MUTATORS

  //  Types
  ErrorCode add_type(TypeNode node) { types.push_back(node); return 0; }
  ErrorCode add_constructor(Identifier ident) { types.back().add_constructor(ident); return 0; }
  ErrorCode add_record(Identifier ident, TypeID tid) 
    { int st = types.back().count_struct(); types.back().get_constructor(st-1).add_record(ident, tid); return 0; }


  ErrorCode open_header(char* fname)
  {
    //  STUB STUB STUB
    free (fname);

    //  Return Success
    return 0;
  }

  ErrorCode open_source(char* fname)
  {
    //  STUB STUB STUB
    free (fname);

    //  Return Success
    return 0;
  }

  ErrorCode open_tether(char* fname)
  {
    //  STUB STUB STUB
    free (fname);

    //  Return Success
    return 0;
  }

};




#endif
