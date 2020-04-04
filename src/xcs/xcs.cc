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
#include "admin.h"
#include <xcs/std/std.h>
#include <xcs/asm/asm.h>
#include <xcs/ident/ident.h>

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

		if (strcmp(argv[i], "--version") == 0) { printf("XCSL Cross-Compiler: v%s\n", XCSL_VERSION); return 0; }

	/*
		ASSEMBLY OPTIONS:
			* -a || --keep-assembly
	*/

		//  Keep Assembly Option
		if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--keep-assembly") == 0) 
		{
			keep_assembly = true;
		}

	/*
		OPTIMIZATION OPTIONS:
			* -a32i
			* -a32f
			* -a48sr
			* -a64sr
	*/
		//  Optimization Option: a32i
		else if (strcmp(argv[i], "-a32i") == 0) 
		{
			printf("Enabling 32-bit Integer Optimization\n");
			set_optimization(a32i);
		}
		//  Optimization Option: a32f
		else if (strcmp(argv[i], "-a32f") == 0) 
		{
			printf("Enabling 32-bit Floating-Point Optimization\n");
			set_optimization(a32f);
		}
		//  Optimization Option: a48sr
		else if (strcmp(argv[i], "-a48sr") == 0) 
		{
			printf("Enabling 48-Wide Tuple Returns\n");
			set_optimization(a48sr);
		}
		//  Optimization Option: a64sr
		else if (strcmp(argv[i], "-a64sr") == 0) 
		{
			printf("Enabling 64-Wide Tuple Returns\n");
			set_optimization(a64sr);
		}

		//  Assume Input File
		else
		{
			interpreted = false;

			//  Init Module Tree
			modules.push_back(ModuleNode());
			context = &modules[0];

			//  Initialize Buffers
			initialize_types();
			initialize_functions();
			
			yyin = fopen(argv[i], "r");
			yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

			//  Set Parser File Pointer
			//yypush_buffer_state(YY_CURRENT_BUFFER);
			while(!feof(yyin)) yyparse();

			//  Create Assembly File
			char* asm_fname = (char*) malloc(strlen(argv[i])+3);
			asm_fname[strlen(argv[i])] = 0;
			strncpy(asm_fname, argv[i], strlen(argv[i]));
			strncat(asm_fname, ".s", 3);

			char* obj_fname = (char*) malloc(strlen(argv[i])+3);
			obj_fname[strlen(argv[i])] = 0;
			strncpy(obj_fname, argv[i], strlen(argv[i]));
			strncat(obj_fname, ".o", 3);


			//  Populate Assembly File
			write_asm_file(asm_fname);
			
			//  Generate Object File using Cross Assembler
			char* _argc    = getenv("HOME");
			strcat(_argc, "/.opt/cross/bin/aarch64-elf-as");
			char _argv2[2][3]= {"-c", "-o"};

			printf ("Check:   %s\n", _argc);

			char* _argv[6] = {_argc, _argv2[0], asm_fname, _argv2[1], obj_fname, NULL};

			execvp(_argc, _argv);

			//  If `-a` option is not active, remove generated assembly file (TODO)

			free (asm_fname);

			return 0;
		}
	}


	/*
		3.) Interpreter Mode
	*/
	if (interpreted) yyin = stdin;
	//  Initialize Register Stack Backend

	while (!feof(yyin)) yyparse();

	return 0;
}

#endif
