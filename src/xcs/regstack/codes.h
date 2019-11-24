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
char* get_reg(ADR i, unsigned char bits)
{
  char* str = (char*) malloc(5);
  
  /*
    TODO: 
      * Reconnect 'bits' functionality to size registers to best fit
  */
  if (i < 14) sprintf(str, "w%u", i-1); else
  if (i < 28) sprintf(str, "w%u", i+3); else
  if (i < 41) sprintf(str, "v%u", i-28); else
              sprintf(str, "v%u", i-24);

  return str;
}

#endif
