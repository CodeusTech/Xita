/*
  run.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
*/

/*
  Contains functionality, specifically used for running bytecode
*/

#ifndef BYTECODE_RUN_H
#define BYTECODE_RUN_H

#include "header.h"
#include "body.h"

int run_bytestring(char* byte)
{
  printf("Running Bytecode Program: %s\n", byte);

  return 0;
}


#endif
