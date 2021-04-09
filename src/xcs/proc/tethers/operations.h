/*
  operations.h (tethers)
  Cody Fagley
  Authored on   February 20, 2019
  Last Modified February 20, 2019
*/

/*
  Contains Backend Functionality for Process Tethers

  Table of Contents
  =================
  1.) Create Process Tether
  2.) Break Process Tether
*/

#ifndef TETHERS_OPERATIONS_H
#define TETHERS_OPERATIONS_H

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
