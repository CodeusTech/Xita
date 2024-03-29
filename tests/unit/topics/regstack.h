/*
  regstack.h (Unit Tests)
  Codeus Tech
  Authored on   August 25, 2021
  Last Modified August 25, 2021
*/

/*
  Contains Unit Testing "Scenarios" for Xita register stack
*/

#pragma once

#include <stdio.h>
#include <cassert>
#include <random>

#include <xcs/std/includes.h>
#include <xcs/regstack/regstack.h>


/*
 *  This class executes unit tests on Xita Register Stack
 */
class XitaTest_RegisterStacks
{



  /*
    Tests Attempt to Operate on Undefined Architecture
      * Confirms that both Push and Pop are rejected with deliberate error code
  */
  void shouldRejectForUndefinedArchitecture()
  {
    /*
      Operating Conditions/Scenario
    */
    RegisterStack rs = RegisterStack(XitaArchitecture::Undefined);

    //  Push a new value onto the mock RegisterStack and check the generated code.
    const ADR generated_register_code = rs.push(TYPE_ARBITRARY);
    
    //  Expect an Error that describes "register stack encountered undefined architecture".
    assert(generated_register_code == ERR_REGSTACK_UNDEF_ARCH);

    //  Attempt to Pop from the register stack
    const ErrorCode pop_status = rs.pop();
    
    //  Expect an Error for undefined architecture
    assert(pop_status == ERR_REGSTACK_UNDEF_ARCH);
  }

  /*
    Tests Normal Operation
      * Confirms that each method within RegisterStack generates validated return values
  */
  void shouldCorrectlyPushAndPopRegistersFor(XitaArchitecture arch)
  {
    /*
      Operating Conditions/Scenario
    */
    RegisterStack rs = RegisterStack(arch);
    int number_of_data_registers;
    if (arch == XitaArchitecture::Arm64) 
      number_of_data_registers = NUM_DATA_REGISTERS_Arm64;    //  Set Number of Data Registers
    else if (arch == XitaArchitecture::Arm32)                 //  As According to Defined Constant Specs
      number_of_data_registers = NUM_DATA_REGISTERS_Arm32;
    else if (arch == XitaArchitecture::x86_64) 
      number_of_data_registers = NUM_DATA_REGISTERS_x86_64;

    //  Push a new value onto the mock RegisterStack and check the generated code.
    const ADR generated_register_code = rs.push(TYPE_ARBITRARY);
    
    //  Check that registers are produced are within proper bounds
    assert(generated_register_code > 0);
    assert(generated_register_code <= number_of_data_registers);

    //  Check that buffers are storing data correctly
    assert(rs.size() == 1);
    assert(rs.top() == generated_register_code);

    const ErrorCode pop_status = rs.pop();
    assert(pop_status == SUCCESS);
  }

  /*
    Tests Pop when array of registers is already empty or cannot otherwise be "popped"
  */
  void shouldRejectPopWhenEmpty()
  {
    /*
      Operating Conditions/Scenario
        * Should have consistent behavior across architectures
    */
    int random_supported_architecture = (random() % NUM_SUPPORTED_ARCH) + 1;
    RegisterStack rs = RegisterStack((XitaArchitecture)random_supported_architecture);

    const ErrorCode pop_status = rs.pop();
    assert (pop_status == ERR_REGSTACK_POP_EMPTY);
  }

public:
  XitaTest_RegisterStacks() {}

  /*
    The "Main" interface function
  */
  void DescribeAndTest()
  {
    this->shouldRejectForUndefinedArchitecture();

    this->shouldCorrectlyPushAndPopRegistersFor(Arm64);
    this->shouldCorrectlyPushAndPopRegistersFor(Arm32);
    this->shouldCorrectlyPushAndPopRegistersFor(x86_64);

    this->shouldRejectPopWhenEmpty();
  }


};



