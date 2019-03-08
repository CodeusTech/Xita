/*
  init.h (Assembly)
  Cody Fagley
  Authored on   March 8, 2019
  Last Modified March 8, 2019
*/

/*
  Contains Initialization Functionality for Generating Assembly
*/

#ifndef ASM_INIT_H
#define ASM_INIT_H



extern char** start_asm_text;
extern char**  curr_asm_text;
extern int count_asm_text;
extern int index_asm_text;

/*  Initialize AArch64 Text Buffer
  Returns:
    0, if Successful
*/
int init_asm_text()
{
  //  Allocate Memory
  start_asm_text = (char**) malloc(256 * sizeof(char*));
  curr_asm_text  = start_asm_text;
  index_asm_text = 0;

  start_asm_text[255] = (char*) 0;
  curr_asm_text[255]  = (char*) 0;

  return 0;
}

/*  Frees All Memory Associated with AArch64 Text Buffer
  Returns:
    0, if Successful
*/
int clear_asm_text()
{
  curr_asm_text = start_asm_text;

  //  If not at end of list, recurse next buffer
  if ( start_asm_text[255] != (char*) 0)
  {
    start_asm_text = (char**) start_asm_text[255];
    clear_asm_text((char**) start_asm_text[255]);
  }

  //  Free Current Buffer
  free(curr_asm_text);

  return 0;
}


#endif
