/*
  memops.h
  Codeus Tech
  Authored on   March 3, 2021
  Last Modified March 3, 2021
*/

/*
  XCS Memory Operators
  ====================
  There are two operators for memory access, and they are both ONLY 
    accessible from the cross-compiler environment.  

  *  MEMORY GET:  Accesses data from a memory address and reads the value
    into an appropriately sized CPU register
  *  MEMORY SET:  Writes data from a CPU register into an appropriately
    sized memory address
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/regstack/structs.h>
/*
  Data 
*/
char* resolveMemoryGet(RegisterStack* rs)
{
  rs->push(TYPE_ARBITRARY);
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 64);

  char* str = (char*) malloc(200);
  sprintf(str, "  and   %s, %s, 0xFFFFFFFF\n  ldr   %s, [%s]", sec, sec, top, sec);

  rs->removeSec();
  rs->duplicateTop();

  free(top);
  free(sec);

  return str;
}


/*
  resolveMemorySet(rs)
    PRE:  Register Stack (rs) holds the data entry on TOP and address on SEC
  NOTE:  Memory addresses must ALWAYS be read/written as 64-bit register
*/
char* resolveMemorySet(RegisterStack* rs)
{
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 64);

  char* str = (char*) malloc(50);
  sprintf(str, "  and   %s, %s, 0xFFFFFFFF\n    str   %s, [%s]", sec, sec, top, sec);

  rs->removeSec();
  rs->duplicateTop();

  free(top);
  free(sec);

  return str;
}


