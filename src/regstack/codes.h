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
char* get_reg(int i, unsigned char bits)
{
  char* str;
  switch (bits)
  {
    case 8:
      sprintf(str, "%c%d\0", 'B', i);
      break;
    case 16:
      sprintf(str, "%c%d\0", 'H', i);
      break;
    case 32:
      sprintf(str, "%c%d\0", 'W', i);
      break;
    case 64:
      sprintf(str, "%c%d\0", 'X', i);
      break;
    default:
      //  ERROR
      return NULL;
  }
}

/* Get  8-Bit Register */
char* get_reg8 (int i) { get_reg(i,  8); };

/* Get 16-Bit Register */
char* get_reg16(int i) { get_reg(i, 16); };

/* Get 32-Bit Register */
char* get_reg32(int i) { get_reg(i, 32); };

/* Get 64-Bit Register */
char* get_reg64(int i) { get_reg(i, 64); };

#endif
