/*
  manager.h (Assembly)
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains Structure/Implementation for XCS Assembly Handling (AArch64)

  TABLE OF CONTENTS
  =================
  1.) Initialization Functions
    1.a) Generate BSS
    1.b) Generate Data
    1.c) Generate Text
*/

#pragma once

#include <xcs/std/includes.h>
#include <list>

using namespace std;

using std::list;

class AssemblyManager
{

  /*
    Private Data
  */

protected:


  //  Assembly Buffers
  vector<list<string> > asm_text;
  list<string> asm_bss;
  list<string> asm_data;

  Index command_scope = 0;
  vector<Index> command_scope_stack;


  /*
    1.) Initialization Functions
  */
  //  1.a) Generate BSS
  ErrorCode generate_bss(FILE* filename)
  {
    //  STUB STUB STUB
    l.log('D',"Assembly", ".bss Section Generated");
    //printf(".bss Section Generated\n");

    //  Print TEXT Segment Name into File
    fprintf(filename, ".section .bss:\n");

    /* Print TEXT Buffer Contents to File */
    for (list<string>::iterator it = asm_bss.begin(); it != asm_bss.end(); it++)
      fprintf(filename, "  %s\n", (*it).c_str());

    //  Pretty up file with new lines
    fprintf(filename, "\n\n");

    //  Return Success
    return 0;
  }

  // 1.b) Generate Data
  ErrorCode generate_data(FILE* filename)
  {
    //  Print TEXT Segment Name into File
    fprintf(filename, ".section .data:\n");

      /* Print TEXT Buffer Contents to File */
      for (list<string>::iterator it = asm_data.begin(); it != asm_data.end(); it++)
        fprintf(filename, "  %s\n", (*it).c_str());

    //  Pretty up file with new lines
    fprintf(filename, "\n\n");

    //  Stub Stub Stub
    l.log('D',"Assembly",".data Section Generated");
    //printf(".data Section Generated\n");

    //  Return Success
    return 0;
  }

  // 1.c) Generate Text
  ErrorCode generate_text(FILE* filename)
  {
    //  Print TEXT Segment Name into File
    fprintf(filename, ".section .text:\n\n");

    fprintf(filename, ".global __start\n__start:\n");

    string str = "wfe  //  Wait for Event";
    scope_curr = 0;
    addInstruction(str.c_str());

    for (vector<list<string> >::iterator scope = asm_text.begin(); scope < asm_text.end(); ++scope)
    {
      /* Print TEXT Buffer Contents to File */
      for (list<string>::iterator it = (*scope).begin(); it != (*scope).end(); it++)
        fprintf(filename, "  %s\n", (*it).c_str());
    }

    fprintf(filename, "\n\n");

    //  Report Success to Terminal
    l.log('D',"Assembly",".text Section Generated");
    //printf(".text Section Generated\n");

    //  Return Success
    return SUCCESS;
  }


public:

  AssemblyManager()
  {
    asm_text.push_back(list<string>());

    l.log('D', "Assembly", "Assembly Manager has been initialized");
  }

  ErrorCode generateAssembly(FILE* file)
  {
    if (generate_bss(file)) return 1;
    if (generate_data(file)) return 2;
    if (generate_text(file)) return 3;

    return SUCCESS;
  }

  /*
    2.) Assembly Operations
  */

  ErrorCode addConstant(Command command)
  { asm_data.push_back(strdup(command)); return SUCCESS; }

  ErrorCode addInstruction(Command command)
  { asm_text[get_scope_curr()].push_back(strdup(command)); return SUCCESS; }
  ErrorCode addInstruction(const char* command)
  { asm_text[get_scope_curr()].push_back(strdup(command)); return SUCCESS; }

  ErrorCode initFunction(Identifier ident, FunctionID fid)
  {
    asm_text.push_back(list<string>());   //  Add Buffer for new Function Commands
    get_scope_next();                     //  Adjust Assembly Scope Index

    string str = "__" + to_string(fid) + "_" + string(ident) + ":";
    addInstruction(str.c_str());
    return SUCCESS;
  }


  ErrorCode popLastInstruction()
  {
    asm_text[get_scope_curr()].pop_back();
    return SUCCESS;
  }

  ErrorCode concludeExpression()
  {
    scope_curr = 0;
    return SUCCESS;
  }

  
};
