/*
  mangle.h
  Codeus Tech
  Authored on   October 31, 2019
  Last Modified October 31, 2019
*/

/*
  Contains random number mangling utility library
*/

#ifndef UTILS_MANGLE_H
#define UTILS_MANGLE_H

//  Linux Libraries
#include <cstdlib> //  rand()
#include <time.h>


// Name Mangling
unsigned long long mangle = rand();

unsigned long long get_mangle()
{
  mangle += rand() + time(NULL);
  srand(mangle);
  mangle += rand();
  return mangle;
}


#endif
