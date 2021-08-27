/*
  XitaTests.cc
  Codeus Tech
  Authored on   August 26, 2021
  Last Modified August 26, 2021
*/

/*
  Contains driver for Xita unit tests
*/


#include "topics/regstack.h"
#include "topics/modules.h"


/*
  Defined as such to prevent expected crashes from testing.
*/
void yyerror(const char* error) {  }

int main()
{
  //  Prepare Test Environment
  printf("Preparing Test Environment...\n");
  XitaTest_RegisterStacks RegisterStacks;
  XitaTest_ModuleHandling Modules;

  //  Check for errors in Register Stack Descriptions
  printf("Testing Register Stacks with Arbitrary Data...\n");
  RegisterStacks.DescribeAndTest();

  printf("Testing Module Node Internals...\n");
  Modules.DescribeAndTest();

  return SUCCESS;
}

