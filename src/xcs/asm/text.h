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

//  Linux Libraries
#include <string>
#include <list>
#include <vector>

//  XCS Libraries
#include <xcs/std/scope.h>

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
  l.log("debug","debug",".text Section Generated");
  //printf(".text Section Generated\n");

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
  asm_text[get_scope_curr()].push_back(strdup(command));

  return 0;
}


void get_last_command()
{
  asm_text[get_scope_curr()].pop_back();
  return;
}


#endif
