/*
  codes.h (Register Stacks)
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Register Codes for AArch64 Architecture

  Table of Contents
  =================
  1.) Get Register (Flexible)
  2.) Get 8-Bit Register
  3.) Get 16-Bit Register
  4.) Get 32-Bit Register
  5.) Get 64-Bit Register
*/

#ifndef REGSTACK_CODES_H
#define REGSTACK_CODES_H


/* 1.) Get Register (Flexible)
 
*/
char* get_reg(unsigned int i, unsigned char bits)
{
  char* str = (char*) malloc(5);
  switch (bits)
  {
    case 8:
      sprintf(str, "%c%u", 'b', i);
      return str;
    case 16:
      sprintf(str, "%c%u", 'h', i);
      return str;
    case 32:
      sprintf(str, "%c%u", 'w', i);
      return str;
    case 64:
      sprintf(str, "%c%u", 'x', i);
      return str;
    default:
      //  ERROR
      return NULL;
  }
}

#endif
