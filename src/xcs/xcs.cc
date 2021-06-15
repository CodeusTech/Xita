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
#include "meta.h"
#include <xcs/std/std.h>
#include <xcs/asm/asm.h>
#include <xcs/std/includes.h>
#include <xcs/std/buffers.h>

#include <xcs/context/manager.h>
#include <xcs/expressions/primitives/primitives.h>

#include <xcs/std/forwards.h>
#include <xcs/std/source.h>
#include <xcs/std/help.h> 

//  Import Grammar Libraries
#include "../../lex.yy.c"

extern FILE* yyin;

ContextManager context;

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

		//  Keep Assembly Option
		if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) 
		{
			XCS_VERBOSE = true;
		}

		//  Help Message
		if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) 
		{
			return help_msg();
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
			
			yyin = fopen(argv[i], "r");
			yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

			initializePrimitives();

			//  Set Parser File Pointer
			//yypush_buffer_state(YY_CURRENT_BUFFER);
			while(!feof(yyin)) yyparse();

			//  Create Assembly File
			char* asm_fname = (char*) malloc(strlen(argv[i])+3);
			asm_fname[strlen(argv[i])] = 0;
			strncpy(asm_fname, argv[i], strlen(argv[i]));
			strncat(asm_fname, ".s", 3);

			//  Create Object File
			char* obj_fname = (char*) malloc(strlen(argv[i])+3);
			obj_fname[strlen(argv[i])] = 0;
			strncpy(obj_fname, argv[i], strlen(argv[i]));
			strncat(obj_fname, ".o", 3);


			//  Produce Assembly File
			FILE* asm_file = fopen(asm_fname, "w");
			context.generateAssembly(asm_file);
			fclose(asm_file);

			l.printLogs();
 			l.write();
			
			//  Generate Object File using Cross Assembler
			char* _argc    = getenv("HOME");
			strcat(_argc, "/.opt/cross/bin/aarch64-elf-as");
			char _argv2[2][3]= {"-c", "-o"};

			char* _argv[6] = {_argc, _argv2[0], asm_fname, _argv2[1], obj_fname, NULL};

			//  If `-a` option is not active, remove generated assembly file (TODO)

			execvp(_argc, _argv);

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

	l.printLogs();
 	l.write();
	 
	return 0;
}

#endif
