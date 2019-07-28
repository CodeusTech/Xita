/*
  bss.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified March 25, 2019
*/

/*
  .bss Section Contains Uninitialized Data (Variables)

  Table of Contents
  =================
  1.) Structure
    1.a) Generate BSS
  2.) Operations
    2.a) Add to BSS
*/

#ifndef ASM_BSS_H
#define ASM_BSS_H


/*
  1.) Structure
*/

/* 1.a) Generate BSS

  Returns:
    0, if Successful
*/
ErrorCode generate_bss(FILE* filename)
{
  //  STUB STUB STUB
  printf(".bss Section Generated\n");

  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .bss.xcs:\n");

  curr_asm_bss = start_asm_bss;

  /* Print TEXT Buffer Contents to File */
  for (int i = 0; i < count_asm_bss; i++)
  {
    if (i == 255) 
    {
      curr_asm_bss = (char**) start_asm_bss[i];
      free(start_asm_bss);
      i = 0;
      count_asm_bss -= 255;
    }
    fprintf(filename, "  %s", curr_asm_bss[i]);
    free(curr_asm_bss[i]);
  }


  free(curr_asm_bss);
  //  Pretty up file with new lines
  fprintf(filename, "\n\n");

  //  Return Success
  return 0;
}

/*
  2.) Operations
*/

/* 2.a) Add to BSS
  Adds BSS Command to .bss Section of Assembly File

  Returns:
    0, if Successful
*/
ErrorCode add_to_bss(Identifier ident, TypeID tid)
{
  if (index_asm_bss == 255)
  {
    curr_asm_bss[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_bss = (Command*) curr_asm_bss[255];

    index_asm_bss = 0;
  }

  char* str = (char*) malloc(256);

  sprintf(str, "%s, %lu", ident, tid);
    
  curr_asm_bss[index_asm_bss] = strdup(str);
  index_asm_bss++;
  count_asm_bss++;

  free(str);

  // Return Success
  return 0;
}



#endif
