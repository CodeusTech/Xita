/*
  text.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified March 25, 2019
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

extern Command* curr_asm_text;
extern unsigned int* index_asm_text;
extern unsigned int* count_asm_text;
extern Scope scope_next;

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
  fprintf(filename, ".text:\n");


  for (int j = 0; j < scope_next; j++)
  {
    curr_asm_text = start_asm_text[j];

    /* Print TEXT Buffer Contents to File */
    for (int i = 0; i < count_asm_text[j]; i++)
    {
      if (i == 255) 
      {
        curr_asm_text = (char**) start_asm_text[j][i];
        free(start_asm_text);
        i = 0;
        count_asm_text[j] -= 255;
      }
      fprintf(filename, "  %s", curr_asm_text[i]);
      free(curr_asm_text[i]);
    }
  }

  //  Pretty up file with new lines
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
  if (index_asm_text == 255)
  {
    curr_asm_text[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_text = (Command*) curr_asm_text[255];

    index_asm_text[scope_curr] = 0;
  }
    
  curr_asm_text[index_asm_text[scope_curr]] = strdup(command);

  index_asm_text[scope_curr]++;
  count_asm_text[scope_curr]++;

  return 0;
}


Command get_last_command()
{
  --count_asm_text[scope_curr];
  return curr_asm_text[--index_asm_text[scope_curr]];
}

#endif
