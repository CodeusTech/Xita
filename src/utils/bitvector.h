/*
  bitvector.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 22, 2019
*/

/*
  Contains Public Interface for Bit Vectors (Arbitrary # of Bits)

  Table of Contents
  =================
  1.) Initialization/Structures
    1.a) Bit Vector Structure
    1.b) Allocate Bit Vector
    1.c) Free Bit Vector
  2.) Bit Operations
    2.a) Set Bit
    2.b) Reset Bit
    2.c) Get Bit
  3.) Bit Vector Operations
    3.a) Create Clear Bit Vector
    3.b) Get Bit Range
    3.c) Append Bit Vectors
    3.d) Compare Bit Vectors
*/

#ifndef UTILS_BITVECTOR_H
#define UTILS_BITVECTOR_H


/*
  1.) Initialization/Structures
*/

/*
  1.a) Bit Vector Structure
*/

typedef struct bitvector
{
  unsigned long count; 
  unsigned long* data;
} BitVector;


/* 1.b) Allocate Bit Vector
  
  Returns:
    0, if Successful
*/
int bv_allocate()
{
  //  STUB STUB STUB

  return 0;
}

/* 1.c) Free Bit Vector

  Returns:
    0, if Successful
*/
int bv_free()
{
  //  STUB STUB STUB

  return 0;
}



/*
  2.) Bit Operations
*/

/* 2.a) Set Bit

  Returns:
    0, if Successful
*/
int set_bit(BitVector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}

/* 2.b) Reset Bit

  Returns:
    0, if Successful
*/
int reset_bit(BitVector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}

/* 2.c) Get Bit

  Returns:
    0, if Bit is Unset
    1, if Bit is Set
*/
int get_bit(BitVector bv, int n)
{
  //  STUB STUB STUB

  return 0;
}


/*
  3.) Bit Vector Operations
*/

/* 3.a) Create Clear Bit Vector

  Returns:
    p, where 'p' is pointer to new Bit Vector
*/
/*BitVector*/ int bv_clear(unsigned long size)
{
  // STUB STUB STUB

  return 0;
}


/* 3.b) Get Bit Range

  Returns:
    New Bit Vector containing target bits
*/
BitVector get_bits(BitVector bv, unsigned int start, unsigned int end)
{
  // STUB STUB STUB

  return bv;
}

/* 3.c) Append Bit Vectors

  Returns:
    0, if Successful
*/
int bv_append (BitVector dest, BitVector src)
{
  //  STUB STUB STUB

  return 0;
}

/* 3.d) Compare Bit Vectors

  Returns:
    0, if bit sequences are the same
*/
int bv_compare (BitVector bv1, BitVector bv2)
{
  //  STUB STUB STUB

  return 0;
}

#endif
