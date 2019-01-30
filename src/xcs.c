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
	3.) Begin Parsing
*/

//  Import Grammar Libraries
#include "../lex.yy.c"

//  Linux Libraries
#include "stdbool.h"


/*
	1.) Default Compiler Options
*/
bool interpreted = true;	// LIVE INTERPRETER MODE

//  Driver File
int main(int argc, char** argv) 
{
	/*
		2.) Handle Compiler Options
	*/
	

	//  Set standard input, if in Interpreter Mode
	if (interpreted) yyin = stdin;

	/*
		3.) Begin Parsing
	*/
	while (!feof(yyin)) yyparse();

	return 0;
}