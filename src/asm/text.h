/*
  text.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified     July 21, 2019
*/

/*
  .text Section Contains Executable Code

  Table of Contents
  =================
  1.) Structure
    1.a) Generate Text
  2.) Operations
    2.a) Add Command
    2.b) Read Command
*/

#ifndef ASM_TEXT_H
#define ASM_TEXT_H

//  XCS Libraries
extern Scope scope_next;

//  Linux Libraries
#include <string>
#include <list>
#include <vector>

using namespace std;

using std::list;
using std::vector;
using std::string;


/*
  1.) Structure
*/

/* 1.a) Generate Text

  Returns:
    0, if Successful
*/
ErrorCode generate_text(FILE* filename)
{
  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .text.xcs:\n\n");

  fprintf(filename, ".global __start\n__start:\n");

  for (vector<list<string>>::iterator scope = asm_text.begin(); scope < asm_text.end(); ++scope)
  {
    /* Print TEXT Buffer Contents to File */
    for (list<string>::iterator it = (*scope).begin(); it != (*scope).end(); it++)
      fprintf(filename, "  %s\n", (*it).c_str());
  }

  fprintf(filename, "\n\n");

  //  Report Success to Terminal
  printf(".text Section Generated\n");

  //  Return Success
  return 0;
}


/*
  2.) Operations
*/

/* 2.a) Add Command
  
    Returns:
      0, if Successful
*/
ErrorCode add_command(Command command)
{
  asm_text[scope_curr].push_back(strdup(command));

  free(command);

  return 0;
}


void get_last_command()
{
  asm_text[scope_curr].pop_back();
  return;
}


ErrorCode end_scope()
{
  curr_reg = 0; 
  scope_curr = 0;
  last_type = 0;

  return 0;
}

#endif
