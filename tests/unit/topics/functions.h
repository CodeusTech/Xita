/*
  functions.h   (Unit Tests)
  Codeus Tech
  Authored on   August 29, 2021
  Last Modified August 30, 2021
*/

/*
  Contains Unit Testing Protocols for Xita Function Internals
*/

#pragma once

#include "../UnitTest.h"


class UT_FunctionSystem 
  : XitaUnitTester
{

  bool shouldAcceptFunctionsWithNoParameters()
  {
    TestWithNewContext

    // Generate Random Valid Identifier
    GivenSomeIdentifier (funct)

    // Declare a Function with that Identifier
    expect( context.declareFunction(funct) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_succeed

    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptFunctionsWithParameters()
  {
    TestWithNewContext

    // Generate Random Valid Identifiers
    GivenSomeIdentifier(funct)
    GivenSomeIdentifier(param1)
    GivenSomeIdentifier(param2)

    // Declare a Function with that Identifier
    expect( context.declareFunction(funct) )
      to_succeed

    expect( context.declareFunctionParameter(param1) )
      to_succeed

    expect( context.declareFunctionParameter(param2) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_succeed

    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptOverloadedFunctionsWithDifferentParameters()
  {
    TestWithNewContext

    // Generate Random Valid Identifiers
    GivenSomeIdentifier(funct)
    GivenDuplIdentifier(funct, funct2)
    GivenSomeIdentifier(param1)

    // Declare a Function with that Identifier
    expect( context.declareFunction(funct) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_succeed

    // Declare a Function with duplicated Identifier
    expect( context.declareFunction(funct2) )
      to_succeed

    //  Add a Parameter to change overloading properties
    expect( context.declareFunctionParameter(param1) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_succeed

    SUCCESSFUL_ACCEPT
  }

  bool shouldRejectOverloadedFunctionsWithSameParameters()
  {
    TestWithNewContext

    // Generate Random Valid Identifiers
    GivenSomeIdentifier(funct)
    GivenDuplIdentifier(funct, funct2)
    GivenSomeIdentifier(param1)

    // Declare a Function with that Identifier
    expect( context.declareFunction(funct) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_succeed

    // Declare a Function with duplicated Identifier
    expect( context.declareFunction(funct2) )
      to_succeed

    // Need Data to be declared for return value
    expect( context.rsPush(TYPE_ARBITRARY) )
      to_be_greater_than(0)

    expect( context.endDeclareFunction() )
      to_be(ERR_FUNCT_REDEFINE)

    SUCCESSFUL_REJECT
  }

  bool shouldRejectFunctionsWithNoReturnValue()
  {
    TestWithNewContext

    // Generate Random Valid Identifier
    GivenSomeIdentifier(funct)

    // Declare a Function with that Identifier
    expect( context.declareFunction(funct) )
      to_succeed

    // Need Data to be declared for return value
    //    Note that this has been excluded for this test

    //  Try to wrap up function without return value
    expect( context.endDeclareFunction() )
      to_be(ERR_FUNCT_NO_RETURN)

    SUCCESSFUL_REJECT
  }

public:
  UT_FunctionSystem () { }

  this_describes(functions)
        it  shouldAcceptFunctionsWithNoParameters()
    and_it  shouldAcceptFunctionsWithParameters()
    and_it  shouldAcceptOverloadedFunctionsWithDifferentParameters()
  
    but_it  shouldRejectOverloadedFunctionsWithSameParameters()
    _and_it shouldRejectFunctionsWithNoReturnValue()
  _____

};


