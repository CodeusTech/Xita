/*
  parameter.h (tethers)
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains backend functionality for tether parameters

  Table of Contents
  =================
  1.) Declare Tether Parameter
  2.) Clear Tether Parameters
*/

#ifndef TETHERS_PARAMETER_H
#define TETHERS_PARAMETER_H



/* 1.) Declare Tether Parameter

  Returns:
    0, if Successful
*/
int declare_tether_parameter (char* param)
{
  printf("%s, ", param);

  return 0;
}



/* 2.) Clear Tether Parameters
  
  Returns:
    0, if Successful
*/
int clear_tether_parameters ()
{
  printf("Tether Parameters Cleared!\n");

  return 0;
}


#endif
