/*
  structs.h (Operator)
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains base structures for contextual operator definitions
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/regstack/structs.h>


class OperatorNode
{


protected:
  vector< vector<TypeID> > operands;
  bool is_communitive = false;
  Identifier op;

public:

  OperatorNode() { }

  /*
    Private Accessors
  */
  Identifier Ident() { return op; }

  virtual char* resolve(RegisterStack* rs)
  {
    /*
      TODO: Type Check the Operator in question here
    */
    l.log('w', "Operators", "Unexpected Operator Function Call");

    return NULL;
  }

};

