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
  1.) Get Register  --  a32i
  2.) Get Register  --  a32f
  3.) Get Register (Flexible)
*/

#ifndef REGSTACK_CODES_H
#define REGSTACK_CODES_H


/*  Get Register  --  a32i

*/
char* get_reg_a32i(ADR i, unsigned char bits)
{
  char* str = (char*) malloc(10);

  /*
    TODO: 
      * Reconnect 'bits' functionality to size registers to best fit
  */
  switch(bits)
  {
    case (8):
      if (i < 14) sprintf(str, "b%u", i-1); else
      if (i < 28) sprintf(str, "b%u", i+3); else
                  sprintf(str, "v%u.s[%d]", (i-24)/4, (i-24)%4); //  TODO:  This needs reviewed.
                                                                 //  Pretty sure it is wrong...
      break;
    case (16):
      if (i < 14) sprintf(str, "s%u", i-1); else
      if (i < 28) sprintf(str, "s%u", i+3); else
                  sprintf(str, "v%u.s[%d]", (i-24)/4, (i-24)%4); //  TODO:  This needs reviewed.
                                                                 //  Pretty sure it is wrong...
      break;
    case (32):
      if (i < 14) sprintf(str, "w%u", i-1); else
      if (i < 28) sprintf(str, "w%u", i+3); else
                  sprintf(str, "v%u.s[%d]", (i-24)/4, (i-24)%4); //  TODO:  This needs reviewed.
                                                                 //  Pretty sure it is wrong...
      break; 
    case (64):
      if (i < 14) sprintf(str, "x%u", i-1); else
      if (i < 28) sprintf(str, "x%u", i+3); else
                  sprintf(str, "v%u.s[%d]", (i-24)/4, (i-24)%4); //  TODO:  This needs reviewed.
                                                                 //  Pretty sure it is wrong...
      break;
  }

  return str;
}


/* Get Register  --  a32f

*/
char* get_reg_a32f(ADR i, unsigned char bits)
{
  char* str = (char*) malloc(10);


  return str; 
}


/* 1.) Get Register (Flexible)
 
*/
char* get_reg(ADR i, unsigned char bits)
{
  /* TODO: Replace optimization if conditions with #IFDEF and #DEFINE statements  */

  //  Route a32i Register Name Request
  if (get_optimization() == a32i) return get_reg_a32i(i, bits);

  char* str = (char*) malloc(10);
  
  switch(bits)
  {
    case (8):
      if (i < 29) sprintf(str, "b%u", i); else
      if (i < 41) sprintf(str, "v%u.s[0]", i-28); else
                  sprintf(str, "v%u.s[0]", i-24); 
      break;
    case (16):
      if (i < 29) sprintf(str, "s%u", i); else
      if (i < 41) sprintf(str, "v%u.s[0]", i-28); else
                  sprintf(str, "v%u.s[0]", i-24);
      break;
    case (32):
      if (i < 29) sprintf(str, "w%u", i); else
      if (i < 41) sprintf(str, "v%u.s[0]", i-28); else
                  sprintf(str, "v%u.s[0]", i-24);
      break;
    case (64):
      if (i < 29) sprintf(str, "x%u", i); else
      if (i < 41) sprintf(str, "v%u.s[0]", i-28); else
                  sprintf(str, "v%u.s[0]", i-24);
      break;
  }

  return str;
}

#endif
