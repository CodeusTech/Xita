/*
  xcs.c (AArch64)
  Cody Fagley
  Authored on   January 28, 2019
  Last Modfieid December 7, 2022
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
#include <stdlib.h>
#include <sys/wait.h>

//  XCS Libraries
#include "meta.h"
#include <xcs/std/std.h>
#include <xcs/asm/asm.h>
#include <xcs/std/includes.h>
#include <xcs/std/buffers.h>
#include <xcs/context/manager.h>
#include <xcs/expressions/primitives/primitives.h>
#include <xcs/std/forwards.h>
#include <xcs/std/help.h> 

//  XCS Source (*.cpp) Files
#include "source.h"

//  Import Grammar Libraries
#include "../../lex.yy.c"

extern FILE* yyin;
extern int yylineno;

ContextManager context = ContextManager(XitaArchitecture::Undefined);

//  Driver File
int main(int argc, char** argv) 
{ 

	/*
		1.) Default Compiler Options
	*/
	bool interpreted 		= false;  //  This feature should normally be 'true' by default
																//  but is currently deactivated.	
	XitaArchitecture arch = XitaArchitecture::Undefined;
	bool keep_assembly 	= false;
			 XCS_VERBOSE    = false;

	/*
		2.) Handle Compiler Options
	*/
	
	for (int i = 1; i < argc; i++)
	{

		if (strcmp(argv[i], "--version") == 0) { printf("XCSL Cross-Compiler: v%s\n", XCSL_VERSION); return 0; }

	/*
		ASSEMBLY OPTIONS:
			* --version
			* -a || --keep-assembly
			* -c [file.chip] || --chip file.chip
			* -h || --help
			* -v || --verbose

	*/

		//  Keep Assembly Option
		else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--assembly") == 0) 
		{
			keep_assembly = true;
		}

		//  Keep Assembly Option
		else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) 
		{
			XCS_VERBOSE = true;
		}

		//  Help Message
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) 
		{
			return help_msg();
		}

		else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--chip") == 0)
		{
			i++;

			yyin = fopen(argv[i], "r");
			yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

			//  Set Parser File Pointer
			//yypush_buffer_state(YY_CURRENT_BUFFER);
			while(!feof(yyin)) yyparse();
		}

		//  Assume Input File
		else
		{
			yylineno = 1;
			interpreted = false;

			if (context.getChipArch() == XitaArchitecture::Undefined) throw ExceptionMissingChipFile;
			
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
			
			char* _argc    = getenv("HOME");
			char _argv2[2][3]= {"-c", "-o"};

			//  Generate Object File using Cross Assembler
			switch (target_architecture)
			{
				case XitaArchitecture::Arm32:
					strcat(_argc, "/.ctxopt/asm/ARMv7/bin/arm-none-eabi-as");

					break;
				case XitaArchitecture::Arm64:
					strcat(_argc, "/.ctxopt/asm/ARMv8/bin/aarch64-elf-as");

					break;
				case XitaArchitecture::x86_64:

					break;
				default:
					break;
			}

			char* _argv[6] = {_argc, _argv2[0], asm_fname, _argv2[1], obj_fname, NULL};

			pid_t pid;

			int  status;
			if ((pid = fork()) < 0) 
			{     
				printf("*** ERROR: forking child process failed\n");
				exit(1);
			}
			else if (pid == 0) { 
				execvp(_argc, _argv);
			}
			
			waitpid(pid, NULL, 0);

			//  If `-a` option is not active, remove generated assembly file (TODO)
			if (!keep_assembly)
			{
				char* rm_argv[3] = {"rm", asm_fname, NULL};
				execvp(rm_argv[0], rm_argv);
			}

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
