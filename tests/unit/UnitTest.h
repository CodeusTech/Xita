/*
  UnitTest.h
  Codeus Tech
  Authored on   August 27, 2021
  Last Modified August 29, 2021
*/

/*
  Template Class to be inherited by other Xita-Compliant Unit Tests
  
  Contains utilities for expediting and standardizing Unit Tests
*/

#pragma once

#include <cassert>
#include <random>
#include <string>
#include <stdio.h>

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>
#include "utils/generate.h"

using namespace std;

/*
  Base for Unit Tests

    This class provides 
*/
class XitaUnitTester
{

protected:
  ContextManager context;
  ErrorCode status;

  bool description;
  void ValidateDescription() { assert(description == true); }
  

public:
  XitaUnitTester() { }

  virtual void Describe() { }

};


/*
  Description-Based Syntax Simplification
*/
#define TestWithNewContext { context = ContextManager(XitaArchitecture::Arm64);  }
#define TestWithoutContext { /* Maybe this should NULL out context? */ }

#define this_describes(name) void Describe(void) override { description =
#define   it     this ->
#define  and_it  &&
#define _and_it  ||
#define  but_it  !=(
#define  _____   ); ValidateDescription(); }

#define expect(expr)  { status = expr; }

#define to_succeed { assert(status == SUCCESS); }
#define to_fail { assert(status != SUCCESS); }

#define to_be(err) { assert(status == err); }
#define to_be_greater_than(err) { assert(status > err); }
#define to_be_less_than(err) { assert(status < err); }

#define SUCCESSFUL_ACCEPT { return true;  }
#define SUCCESSFUL_REJECT { return false; }

