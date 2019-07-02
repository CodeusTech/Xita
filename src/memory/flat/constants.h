/*
  constants.h
  Cody Fagley
  Authored on   July 2, 2019
  Last Modified July 2, 2019
*/

/*
  Contains an itemized list of constants for use within flat memory allocator
*/

#ifndef FLAT_CONSTANTS_H
#define FLAT_CONSTANTS_H

//  First Usable Range of Memory
unsigned long long mem1_begin = 0x00000000;
unsigned long long mem1_end   = 0x1FFFFFFF;

//  Second Usable Range of Memory
unsigned long long mem2_begin = 0x21000000;
unsigned long long mem2_end   = 0x40000000;

#endif
