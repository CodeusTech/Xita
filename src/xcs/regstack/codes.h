/*
  codes.h (Register Stacks)
  Cody Fagley
  Authored on   March 14, 2019
  Last Modified  July 29, 2021
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






/* 1.) Get Register (Flexible)
 
*/
char* get_reg(ADR i, unsigned char bits)
{
  /* TODO: Replace optimization if conditions with #IFDEF and #DEFINE statements  */

  char* str = (char*) malloc(10);
  
  /* Get string representation of ARMv8 register */
  if (target_architecture == XitaArchitecture::Arm64)
  {
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
  /* Get string representation of ARMv7 register */
  } else if (target_architecture == XitaArchitecture::Arm32)
  {
    if (i < 12) sprintf(str, "r%u", i);
  } else if (target_architecture == XitaArchitecture::x86_64)
  {
    switch(bits)
    {
      case (8):
        if      (i == 1) sprintf(str, "%bl");
        else if (i == 2) sprintf(str, "\%cl");
        else if (i == 3) sprintf(str, "\%dl");
        else if (i == 4) sprintf(str, "\%sil");
        else if (i == 5) sprintf(str, "\%dil");
        else if (i > 5 && i < 11) sprintf(str, "%r%db", (i+5));
        break;
      case (16):
        if      (i == 1) sprintf(str, "%bx");
        else if (i == 2) sprintf(str, "\%cx");
        else if (i == 3) sprintf(str, "\%dx");
        else if (i == 4) sprintf(str, "\%si");
        else if (i == 5) sprintf(str, "\%di");
        else if (i > 5 && i < 11) sprintf(str, "%r%dw", (i+5));
        break;
      case (32):
        if      (i == 1) sprintf(str, "\%ebx");
        else if (i == 2) sprintf(str, "\%ecx");
        else if (i == 3) sprintf(str, "\%edx");
        else if (i == 4) sprintf(str, "\%esi");
        else if (i == 5) sprintf(str, "\%edi");
        else if (i > 5 && i < 11) sprintf(str, "%r%dd", (i+5));
        break;
      case (64):
        if      (i == 1) sprintf(str, "\%rbx");
        else if (i == 2) sprintf(str, "\%rcx");
        else if (i == 3) sprintf(str, "\%rdx");
        else if (i == 4) sprintf(str, "\%rsi");
        else if (i == 5) sprintf(str, "\%rdi");
        else if (i > 5 && i < 11) sprintf(str, "%r%d", (i+5));
        break;
      
    }
  }

  return str;
}

#endif
