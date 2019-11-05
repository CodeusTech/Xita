/*
  header.h
  Cody Fagley
  Authored on   March 18, 2019
  Last Modified  July 29, 2019
*/

/*
  Contains backend functionality for importing Header Modules

  Table of Contents
  =================
  1.) Parse Header Module
  2.) Import Header (Submodule)
*/

#ifndef MODULES_HEADER_H
#define MODULES_HEADER_H

#include "operations.h"

#include <cstdlib>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>


/* 2.) Import Header (Submodule)

  Returns:
   0, if Successful
*/
ErrorCode open_header(Identifier ident)
{
  //  Allocate Buffers
  char** argvH = (char**) malloc(3*sizeof(char*));

  pid_t  pid;
  int    status;

  //  Set Recursive Call's `argv`
  argvH[0] = strndup("/usr/bin/xcs-aarch64", 21);  
  argvH[1] = strndup("-a", 3);
  argvH[2] = strndup(ident, strlen(ident)+1);
  printf("Call: %s %s %s\n", argvH[0], argvH[1], argvH[2]);

  if ((pid = fork()) < 0) 
  {     
    //  Fork a child process 
    printf("*** ERROR: forking child process failed\n");
  }
  else if (pid == 0) 
  {    
    //  Create external module assembly libraries
    execvp(argvH[0], argvH);
  }
  else 
  {                                  /* for the parent:      */
    while (wait(&status) != pid)       /* wait for completion  */
        ;
  }


  //  Free Buffers
  for (int arg = 0; arg < 3; arg++) free(argvH[arg]);
  free(argvH);

  //  Return Success
  return 0;
}


#endif

