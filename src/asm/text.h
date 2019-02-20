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
int generate_text()
{

  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add Command
  
*/
int add_command(char* command)
{
  if (index_asm_text == 255)
  {
    curr_asm_text[255] = (char**) malloc(256 * sizeof(char*));
    curr_asm_text = (char**) curr_asm_text[255];

    index_asm_text = 0;
  }
    
  curr_asm_text[index_asm_text] = strdup(command);
  index_asm_text++;
  count_asm_text++;

  return 0;
}

#endif
