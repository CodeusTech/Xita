/*
  modules.h (Unit Tests)
  Codeus Tech
  Authored on   August 26, 2021
  Last Modified August 26, 2021
*/

/*
  Contains Unit Test Scenarios for Module-level Interactions
*/

#pragma once

#include <random>
#include <cassert>

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>
#include <xcs/source.h>

#include "../utils/generate.h"

class XitaTest_ModuleHandling
{

  /*
    Constant Value Tests
  */
  void shouldDeclareCorrectlyFormattedConstants(void)
  {
    ContextManager context = ContextManager();
    context.newData(TYPE_INTEGER, (Arbitrary) random()); //  TODO:  Change to be any type

    ErrorCode status = context.declareConstant(generate_random_identifier(MAX_IDENTIFIER_SIZE));
    assert(status == SUCCESS);
  }
  void shouldRejectDeclareConstantWithUndefinedType(void)
  {
    ContextManager context = ContextManager();
    context.newData(random() + NUMBER_TYPES+1, (Arbitrary) random()); //  TODO:  Change to be any type

    ErrorCode status = context.declareConstant(generate_random_identifier(MAX_IDENTIFIER_SIZE));
    assert(status == ERR_TYPE_UNDEFINED);
  }
  void shouldRejectDeclareConstantWithUnsupportedType(void)
  {
    //  Test Null Type
    ContextManager context = ContextManager();
    context.newData(TYPE_NULL, (Arbitrary) random()); //  TODO:  Change to be any type

    ErrorCode status = context.declareConstant(generate_random_identifier(MAX_IDENTIFIER_SIZE));
    assert(status == ERR_TYPE_UNSUPPORTED);

    //  Test Arbitrary Type
    context.newData(TYPE_ARBITRARY, (Arbitrary) random()); //  TODO:  Change to be any type
    status = context.declareConstant(generate_random_identifier(MAX_IDENTIFIER_SIZE));
    assert(status == ERR_TYPE_UNSUPPORTED);
  }


  void shouldDeclareCorrectlyFormattedFunctions(void)
  {
    ContextManager context = ContextManager();
    ModuleNode node = ModuleNode(random(), ModuleType::XCSL_SOURCE, 0, &context);

    ErrorCode status = node.declareFunction(random(),                                         //  Function ID
                                            generate_random_identifier(MAX_IDENTIFIER_SIZE)); //  Identifier
    assert(status == SUCCESS);
  }


public:
  XitaTest_ModuleHandling() { }

  void DescribeAndTest(void) 
  {
    //  Describe Constant Behavior
    this->shouldDeclareCorrectlyFormattedConstants();
    this->shouldRejectDeclareConstantWithUndefinedType();
    this->shouldRejectDeclareConstantWithUnsupportedType();

    //  Describe Function Behavior
    this->shouldDeclareCorrectlyFormattedFunctions();
  }

};

