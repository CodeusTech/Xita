/*
  is.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains backend functionality for explicit type checking
*/

#ifndef CONDITIONS_IS_H
#define CONDITIONS_IS_H


/*
  Returns:
    0, if Successful
*/
int is_construct()
{
  //  STUB STUB STUB
  printf("Expression checked for constructor equivalence\n");

  /*
    Compare TOP Constructor vs SECOND Constructor
  */

  /*
    Pop TOP from Register Stack
    Store Result in SECOND
  */
  rs_pop();

  return 0;
}

/*
  Returns:
    0, if Successful
*/
int is_type()
{
  //  STUB STUB STUB
  printf("Expression checked for type equivalence\n");

  /*
    Compare TOP Type vs SECOND Type
  */

  /*
    Pop TOP from Register Stack
    Store Result in SECOND
  */
  rs_pop();

  return 0;
}

#endif
