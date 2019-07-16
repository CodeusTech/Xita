/*
  expressions.h (Types)
  Cody Fagley
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*/

/*
  Executable type expressions for use within XCS Source

  TYPE EXPRESSIONS are ... TODO ...

  TABLE OF CONTENTS
  =================
  1.) Type Expression
*/

#ifndef TYPES_EXPRESSIONS_H
#define TYPES_EXPRESSIONS_H


/* 1.) Type Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_type (Identifier ident)
{
  printf("Type Expression: %s\n", ident);

  return 0;
}

/* 2.) Constructor Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_constructor (Identifier ident)
{
  printf("Constructor Expression: %s\n", ident);
  
  return 0;
}


#endif
