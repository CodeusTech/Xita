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
    SomeIdentifier(funct)

    // Declare a Function with that Identifier
    test( context.declareFunction(funct) )
      expect(SUCCESS)

    // Need Data to be declared for return value
    test( context.rsPush(TYPE_ARBITRARY) )
      expect_greater_than(0)

    test( context.endDeclareFunction() )
      expect(SUCCESS)

    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptFunctionsWithParameters()
  {
    TestWithNewContext

    // Generate Random Valid Identifiers
    SomeIdentifier(funct)
    SomeIdentifier(param1)
    SomeIdentifier(param2)

    // Declare a Function with that Identifier
    test( context.declareFunction(funct) )
      expect(SUCCESS)


    test( context.declareFunctionParameter(param1) )
      expect(SUCCESS)

    test( context.declareFunctionParameter(param2) )
      expect(SUCCESS)

    // Need Data to be declared for return value
    test( context.rsPush(TYPE_ARBITRARY) )
      expect_greater_than(0)

    test( context.endDeclareFunction() )
      expect(SUCCESS)

    

    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptOverloadedFunctionsWithDifferentParameters()
  {
    SUCCESSFUL_ACCEPT
  }

  bool shouldRejectOverloadedFunctionsWithSameParameters()
  {
    SUCCESSFUL_REJECT
  }

  bool shouldRejectFunctionsWithNoReturnValue()
  {
    TestWithNewContext

    // Generate Random Valid Identifier
    SomeIdentifier(funct)

    // Declare a Function with that Identifier
    test( context.declareFunction(funct) )
      expect(SUCCESS)

    // Need Data to be declared for return value
    //    Note that this has been excluded for this test

    //  Try to wrap up function without return value
    test( context.endDeclareFunction() )
      expect(ERR_FUNCT_NO_RETURN)

    SUCCESSFUL_REJECT
  }

public:
  UT_FunctionSystem () { }

  void Describe(void) override
  {
    description = 
      this -> 
                shouldAcceptFunctionsWithNoParameters()
        and_it  shouldAcceptFunctionsWithParameters()
        and_it  shouldAcceptOverloadedFunctionsWithDifferentParameters()
      
        but_it  shouldRejectOverloadedFunctionsWithSameParameters()
        _and_it shouldRejectFunctionsWithNoReturnValue()
    _____

    ValidateDescription();
  }

};


