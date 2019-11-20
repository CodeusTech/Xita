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
  for (int i = 0; i < types.size(); i++)
    for (int j = 0; j < types[i].count_struct(); j++)
      if (strcmp(types[i].get_constructor(j).ident, ident) == 0)
        return types[i].get_constructor(j).cid;

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
  
  //  Free Buffers
  free(ident);
  
  return 0;
}


#endif
