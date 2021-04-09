/*
  structs.h
  Codeus Tech
  Authored on   November 23, 2019
  Last Modified November 23, 2019
*/

/*
  Structure Definition for tracking active entries on the data stack
*/

#ifndef DATASTACK_STRUCTS_H
#define DATASTACK_STRUCTS_H

//  Linux Headers
#include <vector>

//  XCS Headers
#include <xcs/std/typedefs.h>


using namespace std;


class DataStack
{
  vector<ADR> entries;
  vector<TypeID> types;


public: 
//  CONSTRUCTORS
  DataStack() {}


//  ACCESSORS
  ADR top() { return entries.back(); }
  TypeID top_type() { return types.back(); }


//  MUTATORS
  
  /*
    push()

      Performs PUSH operation for data stack.
      This moves the top ADR in the current register stack to
        the microchip's local stack space.
      This also stores data type in compiler backend for tracking.
      After a PUSH operation, the register stack can remove its top.
  */
  ErrorCode push()
  {
    /*
      Get Top Register/Type from Current Function's Reg Stack
    */

    /*
      Push Register/Type into DataStack for Tracking
    */

    /*
      Write Push Sequence as Command to Assembly File
    */

    //  Return Success
    return 0;
  }


  /*
    pop()

      Performs POP operation for data stack.
      This removes the top entry (and its type) from the data stack, and
        moves it into the register from where it originally came.
      This should also restore the data type within its previous state.
  */
  ErrorCode pop()
  {
    /*
      Return the top of the data stack to its original register
    */

    /*
      Return data type from data stack
    */

    //  Return Success
    return 0;
  }


};


#endif
