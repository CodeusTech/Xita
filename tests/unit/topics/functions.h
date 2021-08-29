/*
  functions.h   (Unit Tests)
  Codeus Tech
  Authored on   August 29, 2021
  Last Modified August 29, 2021
*/

/*
  Contains Unit Testing Protocols for Xita Function Internals
*/

#pragma once

#include "../UnitTest.h"


class UT_FunctionSystem 
  : XitaUnitTester
{

  bool shouldAcceptCorrectlyFormedFunctionDeclarations()
  {
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

public:
  UT_FunctionSystem () { }

  void Describe(void) override
  {
    description = 
      this ->
                shouldAcceptCorrectlyFormedFunctionDeclarations()
        and_it  shouldAcceptOverloadedFunctionsWithDifferentParameters()
      
        but_it  shouldRejectOverloadedFunctionsWithSameParameters()
    _____
  }

};


