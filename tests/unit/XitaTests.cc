/*
  XitaTests.cc
  Codeus Tech
  Authored on   August 26, 2021
  Last Modified August 29, 2021
*/

/*
  Contains driver for Xita unit tests
*/


#include "topics/regstack.h"
#include "topics/modules.h"  //  Deprecated in favor of "topics/constants.h" and "topics/functions"
#include "topics/types.h"
#include "topics/functions.h"


/*
  Defined as such to prevent expected crashes from testing.
*/
void yyerror(const char* error) {  }

int main()
{
  //  Prepare Test Environment
  printf("Preparing Test Environment...\n");
  UT_RegisterStacks RegisterStacks;
  XitaTest_ModuleHandling Modules;
  UT_TypesSystem    Types;
  UT_FunctionSystem Functions;

  //  Check for errors in Register Stack Descriptions
  printf("Testing Register Stacks with Arbitrary Data...\n");
  RegisterStacks.Describe();

  printf("Testing Module Node Internals...\n");
  Modules.DescribeAndTest();

  printf("Testing Type System Internals...\n");
  Types.Describe();

  printf("Testing Function System Internals...\n");
  Functions.Describe();


  return SUCCESS;
}

