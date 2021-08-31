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
#include <xcs/context/manager.h>

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

  //  TODO: Add a field to this class for current ContextManager
  //        Then get stack order for current register stack from that.
  sprintf(str, "mov   x16, xzr");

  //  TODO: Serialize the top n registers (up to 8) into x16 here
  unsigned long long serial_number = 0;

  //  TODO: Add the instructions in `str` to the current context
  sprintf(str, "mov   x16, %llu", serial_number);


  l.log('w', "RegStack", "Register Stack is not getting serialized yet");
  l.log('d', "RegStack", "Current Register Stack has been serialized");

  return SUCCESS;
}


unsigned int RegisterStack::MaxRegisters()
{
switch (context->getChipArch())
{
  case XitaArchitecture::Arm64:
    return NUM_DATA_REGISTERS_Arm64;
  case XitaArchitecture::Arm32:
    return NUM_DATA_REGISTERS_Arm32;
  case XitaArchitecture::x86_64:
    return NUM_DATA_REGISTERS_x86_64;
}
return 0;
}

ErrorCode RegisterStack::pop()
{
if (context->getChipArch() == XitaArchitecture::Undefined) return ERR_REGSTACK_UNDEF_ARCH;
if (!registers.size()) return ERR_REGSTACK_POP_EMPTY;
registers.pop_back();
types.pop_back();
return SUCCESS;
}


ADR RegisterStack::push(TypeID tid)
{
if (context->getChipArch() == XitaArchitecture::Undefined) return ERR_REGSTACK_UNDEF_ARCH;

//  If all registers are in use, reroute to extended stack space
if (registers.size() >= MaxRegisters()) { return MaxRegisters() + 1; } 
//  TODO: FIX THE ABOVE LINE!!!

//  Acquire a mangled random number in ADR range
ADR check = (ADR) (get_mangle() % MaxRegisters()) + 1;

//  If the test register is not in use, add it to active ADRs vector
while (isActive(check)) check = (ADR) (get_mangle() % MaxRegisters()) + 1;

//  If all else is kosher, Add the entry and type
registers.push_back(check);
types.push_back(tid);

string str = "Pushed register " + to_string(check) + " with TypeID: " + to_string(tid);

//l.log('D', "RegStack", str);

return check;
}
