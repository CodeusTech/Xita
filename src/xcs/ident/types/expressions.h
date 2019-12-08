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

extern void yyerror();


#include <cstdlib>


#include <xcs/std/typedefs.h>

#include <xcs/primitives/intexp.h> // FOR TESTING
#include <xcs/memory/alloc.h>



/*
  find_type()
*/
TypeID find_type (Identifier ident)
{
  //  TODO:  Fix Memory Leak



  return 0;
}

/* 1.) Type Expression

  Returns:
    0, if Successful
*/
ErrorCode exp_type (Identifier ident)
{
  //  STUB STUB STUB
  printf("Type Expression: %s\n", ident);

  
  //  Free Buffers
  free(ident);

  return 0;
}

/*
  find_constructor()
*/
ConstructorID find_constructor (Identifier ident)
{
  //  TODO: Optimize This
  for (unsigned long i = 0; i < context.get_types().size(); i++)
    for (unsigned long j = 0; j < context.get_type(i).count_struct(); j++)
      if (strcmp(context.get_type(i).get_constructor(j).get_ident(), ident) == 0)
        
        //  TODO: Check if given arguments match constructor's expected layout

        return context.get_type(i).get_constructor(j).get_cid();

  return 0;
}

unsigned int get_constructor_size(Identifier ident)
{
  //  TODO: Optimize This
  for (unsigned long i = 0; i < context.get_types().size(); i++)
    for (unsigned long j = 0; j < context.get_type(i).count_struct(); j++)
      if (strcmp(context.get_type(i).get_constructor(j).get_ident(), ident) == 0)
        
        //  TODO: Check if given arguments match constructor's expected layout

        return context.get_type(i).get_constructor(j).get_size();

  return 0;
}

/* 2.) Constructor Expression

  Returns:
    0, if Successful
    1, if ident is not a declared Constructor
*/
ErrorCode exp_constructor (Identifier ident)
{
  unsigned int cid = find_constructor(ident);
  if (!cid) { yyerror("Undeclared Constructor\n"); }

  last_constructor = cid;
  printf("Invoked Constructor: %s\n", ident);
  
  //  Free Buffers
  free(ident);
  
  return 0;
}

ErrorCode exp_constructor_alloc (Identifier ident)
{
  unsigned int cid = find_constructor(ident);
  if (!cid) { yyerror("Undeclared Constructor\n"); }

  last_constructor = cid;
  printf("Invoked Constructor: %s\n", ident);

  //  TODO: REPLACE WITH MEMORY ALLOCATION SIZE IN BYTES
  //        FOR TESTING, pushing int for data to place in memory node
  unsigned int _size = get_constructor_size(ident);
  _xcs_alloc(_size);
  
  //  Free Buffers
  free(ident);
  
  return 0;
}


#endif
