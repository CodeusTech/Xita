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
#include <stdio.h>

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>
#include "utils/generate.h"


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
#define TestWithNewContext { context = ContextManager(); }
#define TestWithoutContext { /* Maybe this should NULL out context? */ }

#define  and_it     &&
#define _and_it     ||
#define but_it      !=(
#define _____       );

#define test(expr)  { status = expr; }
#define expect(err) { assert(status == err); }

#define SUCCESSFUL_ACCEPT { return true;  }
#define SUCCESSFUL_REJECT { return false; }

