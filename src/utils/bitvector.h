/*
  bitvector.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 21, 20190
*/

/*
  Contains Public Interface for Bit Vectors (Arbitrary # of Bits)

  Table of Contents
  =================
  1.) Initialization/Structures
  2.) Bit Operations
    2.a) Set Bit
    2.b) Reset Bit
    2.c) Get Bit
  3.) Bit Vector Operations
    3.a) Append Bit Vectors
*/

#ifndef UTILS_BITVECTOR_H
#define UTILS_BITVECTOR_H


/*
  1.) Initialization/Structures
*/

typedef unsigned long* bitvector;

/*
  2.) Bit Operations
*/

/* 2.a) Set Bit

  Returns:
    0, if Successful
*/
int set_bit(bitvector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}

/* 2.b) Reset Bit

  Returns:
    0, if Successful
*/
int reset_bit(bitvector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}

/* 2.c) Get Bit

  Returns:
    0, if Bit is Unset
    1, if Bit is Set
*/
int get_bit(bitvector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}


/*
  3.) Bit Vector Operations
*/

/* 3.a) Append Bit Vectors

  Returns:
    0, if Successful
*/
int bv_append (bitvector dest, bitvector src)
{
  //  STUB STUB STUB

  return 0;
}

/* 3.b) Get Bits

  Returns:
    New Bit Vector containing target bits
*/
bitvector get_bits(bitvector bv)
{
  // STUB STUB STUB

  return bv;
}

#endif
