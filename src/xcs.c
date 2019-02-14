/*
  xcs.c (AArch64)
  Cody Fagley
  Authored on   January 28, 2019
  Last Modfieid January 28, 2019
*/

/*
	Program Driver for XCS Linux-to-XCS Cross Compiler


	Table of Contents
	=================
	1.) Default Compiler Options
	2.) Handle Compiler Options
	3.) Interpreter Mode
*/

//  Import Grammar Libraries
#include "../lex.yy.c"

//  Linux Libraries
#include "stdbool.h"
#include "stdio.h"

extern FILE* yyin;

/*
	1.) Default Compiler Options
*/
bool interpreted 		= true;	// LIVE INTERPRETER MODE
bool keep_assembly 	= false;

//  Driver File
int main(int argc, char** argv) 
{
	/*
		2.) Handle Compiler Options
	*/
	
	for (int i = 1; i < argc; i++)
	{

		//  Keep Assembly Option
		if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--keep-assembly") == 0) 
		{
			keep_assembly = true;
		}
		//  Assume Input File
		else
		{
			interpreted = false;
			yyin = fopen(argv[i], "r");
			while(!feof(yyin)) yyparse();
		}
	}


	/*
		3.) Interpreter Mode
	*/
	if (interpreted) yyin = stdin;

	while (!feof(yyin)) yyparse();

	return 0;
}