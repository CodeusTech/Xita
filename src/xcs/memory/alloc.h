/*
  alloc.h
  Codeus Tech
  Authored on   November 18, 2019
  Last Modified November 18, 2019
*/

/*
  Contains functionality for allocating/deallocating memory in XCS backend
*/


#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H

//  XCS Imports
#include <xcs/std/typedefs.h>


/*
  _xcs_alloc(size)
    size: # of Bytes Allocated for Data

    Issues a command to XCSE image to allocate 'size' bytes of dynamic memory
*/
ErrorCode _xcs_alloc(unsigned long _size)
{
  char* str = (char*) malloc(50);
  //char* reg = get_reg(rs_top(), 32);

  /*
    Load parameters with allocation arguments
  */
  //  x3 holds size
  sprintf(str, "mov   x3, #%lu", _size);
  add_command(str);

  //  x4 holds data
  //sprintf(str, "mov x4, %s", reg);
  //add_command(str);

  sprintf(str, "bl    __xcs_alloc");
  add_command(str);

  free (str);
  //free (reg);

  //  Return Success
  return 0;
}


#endif
