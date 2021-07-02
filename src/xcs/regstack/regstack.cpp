/*
  regstack.cpp
  Codeus Tech
  Authored on   July 2, 2021
  Last Modified July 2, 2021
*/

/*
  Extended function implementations for register stack operations
*/

#include "structs.h"

//  TODO: Add COntextManager as owner of register stack.  
//        Add Serialization Instructions to COntext assembly.

/*
  Serialize functionality (Entire Stack)
*/
ErrorCode RegisterStack::serialize()
{
  //  TODO: hash the register stack order into the serialization registers
  //        This should be done for the entire register stack

  l.log('w', "RegStack", "Register Stack relied on unimplemented 'serialize' function.");

  return SUCCESS;
}

/*
  Serialize the top *n* registers of the stack
*/
ErrorCode RegisterStack::serialize(int top_n)
{

  int reg_val = 0;


  //  TODO:  Change this to handle more than 8 !!!
  //         It is set to 8 right now, because that is the limit of a single
  //         ADR in size.  This should use more than one ADR if necessary.
  for (int i = 0; i < 8; ++i)
  {
    reg_val += (from_top(i) >> (i*4));
  }

  char* str = (char*) malloc(80);

  sprintf(str, "mov   x16, xzr");
  

  l.log('d', "RegStack", "Current Register Stack has been serialized");

  return SUCCESS;
}


