/*
  clear.h
  Cody Fagley
  Authored on   March 12, 2019
  Last Modified March 12, 2019
*/

/*
  Clears the Terminal Screen
*/

#ifndef UTILS_CLEAR_H
#define UTILS_CLEAR_H


int clear_terminal()
{
  printf("\e[1;1H\e[2J");

  return 0;
}

#endif
