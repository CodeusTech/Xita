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

#ifndef XCS_C
#define XCS_C

//  Linux Libraries
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//  XCS Libraries
#include "globals/globals.h"
#include "asm/asm.h"

//  Import Grammar Libraries
#include "../lex.yy.c"

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

			//  Initialize Buffers
			init_asm_text();
			rs_init();

			//  Set Parser File Pointer
			yyin = fopen(argv[i], "r");
			while(!feof(yyin)) yyparse();

			//  Create Assembly File
			char* asm_fname = strdup(argv[i]);
			strcat(asm_fname, ".s");

			//  Populate Assembly File
			write_asm_file(asm_fname);

			//  Free Buffered Memory
			clear_asm_text();

			//  Delete Assembly File (if not Keep Assembly)
			if (!keep_assembly) delete_asm_file(asm_fname);

			return 0;
		}
	}


	/*
		3.) Interpreter Mode
	*/
	if (interpreted) yyin = stdin;
	rs_init();

	while (!feof(yyin)) yyparse();

	return 0;
}

#endif
