/*
  xcs.c (AArch64)
  Cody Fagley
  Authored on   January 28, 2019
  Last Modfieid February 13, 2019
*/

/*
	Program Driver for XCS Linux-to-XCS Cross Compiler


	Table of Contents
	=================
	1.) Default Compiler Options
	2.) Handle Compiler Options
	3.) Interpreter Mode
*/

#ifndef XCS_CC
#define XCS_CC

//  Linux Libraries
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//  XCS Libraries
#include <xcs/std/std.h>
#include <xcs/asm/asm.h>

//  Import Grammar Libraries
#include "../../lex.yy.c"

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
		if (strncmp(argv[i], "-a", 2) == 0 || strncmp(argv[i], "--keep-assembly", 15) == 0) 
		{
			keep_assembly = true;
		}

		//  Assume Input File
		else
		{
			interpreted = false;

			//  Initialize Register Stack Backend
			rs_init(0);

			//  Init Text Buffer
			list<string> tmp;
			asm_text.push_back(tmp);

			//  Set Parser File Pointer
			yyin = fopen(argv[i], "r");
			while(!feof(yyin)) yyparse();

			//  Create Assembly File
			char* asm_fname = (char*) malloc(strlen(argv[i])+3);
			asm_fname[strlen(argv[i])] = 0;
			strncpy(asm_fname, argv[i], strlen(argv[i]));
			strncat(asm_fname, ".s", 3);


			//  Populate Assembly File
			write_asm_file(asm_fname);

			free (asm_fname);

			return 0;
		}
	}


	/*
		3.) Interpreter Mode
	*/
	if (interpreted) yyin = stdin;
	rs_init(scope_curr);

	while (!feof(yyin)) yyparse();

	return 0;
}

#endif
