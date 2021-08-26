/*
  structs.h
  Codeus Tech
  Authored on   October 30, 2019
  Last Modified October 30, 2019
*/

/*
  Contains Data Structures used within XCS's Register Stack Infrastructure
*/

#ifndef REGSTACK_STRUCTS_H
#define REGSTACK_STRUCTS_H

//  Linux Libraries
#include <vector>

//  XCS Libraries
#include <xcs/std/includes.h>
#include <xcs/std/typedefs.h>
#include <xcs/sys/utils/mangle.h>

using namespace std;

//  Forward Declarations
extern void yyerror(const char* str);
class ContextManager;


/*
  Register Stacks are the core structure used for managing the
  system's processor (CPU) register stacks.

  Each RegisterStack contains a list of CPU registers that are
  actively holding software data.  Additionally, the data's type
  is tracked for type-checking correctness purposes.  

  The RegisterStack tracks data by its literal datatype.  That means
  type equivalence and typeclass membership needs to be checked by
  the data owner (i.e. at the time of use) if that is applicable.
*/
class RegisterStack
{
  vector<ADR> registers;
  vector<TypeID> types;
  XitaArchitecture arch = XitaArchitecture::Undefined;
	

  unsigned int MaxRegisters()
  {
    switch (arch)
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

public:

//  CONSTRUCTORS
  RegisterStack(XitaArchitecture arch)
    : arch(arch)
  {
    l.log('d', "RegStack", "Initialized New Register Stack with defined architecture");
  }


/*
  MUTATORS
*/
  ADR push(TypeID tid)
  {
    if (arch == XitaArchitecture::Undefined) return ERR_REGSTACK_UNDEF_ARCH;

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

  /*
    duplicateTop() 
      Adds the top ADR/Type to the register stack again.
      This is used to correct subsequent automatic pop() operations.
  */
  ErrorCode duplicateTop()
  {
    registers.push_back(registers.back());
    types.push_back(types.back());

    return SUCCESS;
  }

  ADR merge(TypeID tid, ADR reg)
  {
    /*
      TODO: Check if 'reg' is already active
    */

    registers.push_back(reg);
    types.push_back(tid);

    return reg; //  Should return merged register (if 'reg' is active)
  }

  ErrorCode pop()
  {
    if (arch == XitaArchitecture::Undefined) return ERR_REGSTACK_UNDEF_ARCH;
    registers.pop_back();
    types.pop_back();
    return SUCCESS;
  }

  /*
    remove(from_top)
      This function removes the entry X places from top of the reg stack, then returns all entries above it to the stack.  
      If "from_top" == 0, it will remove the top entry of the stack; "from_top" == 1 will remove the second from top.
  */
  ErrorCode remove(int from_top)
  {
    vector<ADR> buffer_reg;
    vector<TypeID> buffer_type;

    //  Store registers/types to buffer
    for (int i = 0; i < from_top; ++i)
    {
      buffer_reg.push_back(registers.back()); registers.pop_back();
      buffer_type.push_back(types.back()); types.pop_back();
    }

    //  Remove Target Register
    registers.pop_back();
    types.pop_back();

    //  Restore Registers/types from buffer
    for (int i = 0; i < from_top; ++i)
    {
      registers.push_back(buffer_reg.back()); buffer_reg.pop_back();
      types.push_back(buffer_type.back()); buffer_type.pop_back();
    }

    return SUCCESS;
  }

  ErrorCode removeSec() { return remove(1); }


/*
  ACCESSORS
*/
  ADR from_top(int i) { return registers.at(registers.size()-(i+1)); }
  ADR top() { return registers.back(); }
  ADR sec() { return registers.at(registers.size()-2); }

  ADR from_top_type(int i) { return types.at(types.size()-(i+1)); }
  ADR top_type() { return types.back(); }
  ADR sec_type() { return types.at(types.size()-2); }

  unsigned int size() const { return registers.size(); }

  /*
    isActive(test)
      Returns true if the test ADR is already active
  */
  bool isActive(ADR test) const
  {
    for (unsigned long i = 0; i < registers.size(); i++)
      if ((registers[i]) == (test)) return true;
    return false;
  }

  ErrorCode serialize();  //  TODO:  Serializes entire register stack
  ErrorCode serialize(int top_n);       //  Serializes top n registers of register stack

};


#endif
