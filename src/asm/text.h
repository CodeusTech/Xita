/*
  text.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified February 13, 2019
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

extern char** curr_asm_text;
extern int index_asm_text;
extern int count_asm_text;

/*
  1.) Structure
*/

/* 1.a) Generate Text

  Returns:
    0, if Successful
*/
ErrorCode generate_text()
{
  //  Stub Stub Stub

  /*
    TODO:
     * Error Check
     * Write .text Section Header to Assembly File
     * Write Entire .text Section Buffer to Assembly File
  */

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
  if (index_asm_text == 255)
  {
    curr_asm_text[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_text = (Command*) curr_asm_text[255];

    index_asm_text = 0;
  }
    
  curr_asm_text[index_asm_text] = strdup(command);
  index_asm_text++;
  count_asm_text++;

  return 0;
}

/* 2.b) Read Command

  Returns: 
    0, if Successful
*/
ErrorCode read_command()
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Choose ONE, Up to Implementor:
      + Read Out all Commands to Assembly File
      + Return a Single Command
  */

  //  Return Success
  return 0;
}



#endif
