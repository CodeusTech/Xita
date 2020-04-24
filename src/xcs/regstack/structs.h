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
#include <xcs/std/typedefs.h>
#include <xcs/std/optimize.h>
#include <xcs/utils/mangle.h>

using namespace std;

extern void yyerror(const char* str);

class RegisterStack
{
  vector<ADR> registers;
  vector<TypeID> types;


public:

//  CONSTRUCTORS
  RegisterStack() 
  {
    l.log('d', "RegStack", "Initialized New Register Stack");
  }

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

//  MUTATORS
  ADR push(TypeID tid)
  {
    //  If all registers are in use, reroute to extended stack space
    if (registers.size() >= NUMBER_OF_ADRS) { return NUMBER_OF_ADRS + 1; } 
    //  TODO: FIX THE ABOVE LINE!!!

    //  Acquire a mangled random number in ADR range
    ADR check = (ADR) (get_mangle() % NUMBER_OF_ADRS) + 1;

    //  If the test register is not in use, add it to active ADRs vector
    while (isActive(check)) check = (ADR) (get_mangle() % NUMBER_OF_ADRS) + 1;

    //  If all else is kosher, Add the entry and type
    registers.push_back(check);
    types.push_back(tid);

    string str = "Pushed register " + to_string(check) + " with TypeID: " + to_string(tid);

    //l.log('D', "RegStack", str);

    return check;
  }

  ErrorCode pop()
  {
    registers.pop_back();
    types.pop_back();
    return 0;
  }

  ADR from_top(int i) { return registers.at(registers.size()-(i+1)); }
  ADR top() { return registers.back(); }
  ADR sec() { return registers.at(registers.size()-2); }

  ADR from_top_type(int i) { return types.at(types.size()-(i+1)); }
  ADR top_type() { return types.back(); }
  ADR sec_type() { return types.at(types.size()-2); }

  unsigned int size() const { return registers.size(); }
};


#endif
