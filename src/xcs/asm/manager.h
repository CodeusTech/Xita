/*
  manager.h (Assembly)
  Codeus Tech
  Authored on    April 22, 2020
  Last Modified  August 6, 2021
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

  Index next_scope = 1;
  Index instruction_scope = 0;
  vector<Index> instruction_scope_stack;


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
    fprintf(filename, "  runtime: .skip 0x10000000\n\n");

    //  Return Success
    return SUCCESS;
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
    return SUCCESS;
  }

  // 1.c) Generate Text
  ErrorCode generate_text(FILE* filename)
  {
    //  Print TEXT Segment Name into File
    fprintf(filename, ".section .text:\n\n");

    fprintf(filename, ".global __start\n__start:\n");
    if (target_architecture == XitaArchitecture::Arm32)
    {
      fprintf(filename, "  push  {r12, lr}\n");
      scope_curr = 0;
      string str = "pop   {r12, lr}";
      addInstruction(str.c_str());
    }

    if (target_architecture == XitaArchitecture::Arm32 || target_architecture == XitaArchitecture::Arm64)
    {
      string str = "wfe  //  Wait for Event";
      addInstruction(str.c_str());
    }

    for (vector<list<string> >::iterator scope = asm_text.begin(); scope < asm_text.end(); ++scope)
    {
      /* Print TEXT Buffer Contents to File */
      for (list<string>::iterator it = (*scope).begin(); it != (*scope).end(); it++)
        fprintf(filename, "  %s\n", (*it).c_str());

      if (scope != asm_text.begin()) 
        switch (target_architecture)
        {
          case XitaArchitecture::Arm32:
            fprintf(filename, "    pop   {r12, lr}\n");
            fprintf(filename, "    bx    lr\n");
            break;
          case XitaArchitecture::Arm64:
          case XitaArchitecture::x86_64:
            fprintf(filename, "    ret\n");
            break;
        }
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
  { asm_text[instruction_scope].push_back(strdup(command)); return SUCCESS; }
  ErrorCode addInstruction(const char* command)
  { asm_text[instruction_scope].push_back(strdup(command)); return SUCCESS; }
  
  ErrorCode addString(char* str)
  { 
    Index i = asm_data.size();
    char* s = (char*) malloc(50 + strlen(str));
    sprintf(s, "_s_%lu: .string \"%s\"", i, str);
    asm_data.push_back(strdup(s)); 
    free(s);
    free(str);
    return SUCCESS; 
  }



  /*
    Function Operations
  */
  ErrorCode initFunction(Identifier ident, FunctionID fid)
  {
    asm_text.push_back(list<string>());   //  Add Buffer for new Function Commands
    instruction_scope_stack.push_back(instruction_scope);
    instruction_scope = next_scope++;

    string str = "__" + to_string(fid) + "_" + string(ident) + ":";
    switch (target_architecture)
    {
      case XitaArchitecture::Arm32:
        addInstruction(str.c_str());
        str = "  push  {r12, lr}";
        addInstruction(str.c_str());
        break;
      case XitaArchitecture::Arm64:
      case XitaArchitecture::x86_64:
        addInstruction(str.c_str());
        break;
      default:
        break;
    }

    return SUCCESS;
  }
  ErrorCode endFunction()
  {
    instruction_scope = instruction_scope_stack.back();
    instruction_scope_stack.pop_back();
    return SUCCESS;
  }


  ErrorCode popLastInstruction()
  {
    asm_text[instruction_scope].pop_back();
    return SUCCESS;
  }

  ErrorCode concludeExpression()
  {
    scope_curr = 0;
    return SUCCESS;
  }

  
};
