/*
  tether.h
  Cody Fagley
  Authored on   March 12, 2019
  Last Modified March 12, 2019
*/

/*
  Contains Protocols for External Tether Modules

  Table of Contents
  =================
  1.) External Modules
    1.a) open Tether Module
    1.b) close Tether Module
  2.) Tether Module Activation
    2.a) activate Tether Module
    2.b) deactivate Tether Module
*/

#ifndef MODULES_TETHER_H
#define MODULES_TETHER_H


/*
  1.) Tether Modules
*/

/* 1.a) open Tether Module

  Returns:
    0, if Successful
*/
int open_tether(char* name)
{
  printf("Tether Module Opened: %s\n", name);

  return 0;
}

/* 1.b) close Tether Module

  Returns:
    0, if Successful
*/
int close_tether()
{
  printf("Tether Module Closed\n");

  return 0;
}


/*
  2.) Tether Module Activation
*/

/* 2.a) activate Tether Module

  Returns:
    0, if Successful
*/
int activate_tether(char* ident)
{
  printf("Tether Module Activated: %s\n", ident);

  return 0;
}

/* 2.b) deactivate Tether Module

  Returns:
    0, if Successful
*/
int deactivate_tether(char* ident)
{
  printf("Tether Module Deactivated: %s\n", ident);
}

#endif
