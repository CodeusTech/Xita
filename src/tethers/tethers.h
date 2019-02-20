/*
  tethers.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified Feburary 20, 2019
*/

/*
  Contains Backend Functionality for Process Tethers

  Table of Contents
  =================
  1.) Create Process Tether
  2.) Break Process Tether
*/

#ifndef XCS_TETHERS_H
#define XCS_TETHERS_H

//  Internal Tether Headers
#include "parameter.h"
#include "ipc.h"
#include "module.h"


/* 1.) Create Process Tether

  Returns:
    0, if Successful
*/
int create_process_tether()
{
  printf("are executed in separate threads and tethered together.\n");        
  
  return 0;
}


/* 2.) Break Process Tether

  Returns:
    0, if Successful
*/
int break_process_tether()
{
  printf("Process Tethers have been Broken\n");        
  
  return 0;
}


#endif
