/*
  operations.h (Types)
  Cody Fagley
  Authored on   February 19, 2019
  Last Modified     July 15, 2019
*/

/*
  Contains structures/operations for types

  Table of Contents
  =================
  1.) Compiler Buffers
    1.a) Types
    1.b) Constructors
    1.c) Initialize Type Buffers
  1.) Utility Operations
    1.a) Get Next TypeID
    1.b) Get Current TypeID
  2.) Type Operations
    2.a) Find Type

*/

#ifndef TYPES_OPERATIONS_H
#define TYPES_OPERATIONS_H

/*
  1.) Compiler Buffers
*/

//  1.a) Types
extern TypeID  next_type;
extern Identifier*  ident_types;
extern Identifier** param_types;
extern unsigned int* pcount_types;

//  1.b) Constructors
extern Identifier**   ident_construct;
extern unsigned int*  count_construct;
extern Identifier***  ident_elements;
extern TypeID***      type_elements;
extern unsigned int** count_elements;

/* 1.c) Initialize Type Buffers

  Allocates necessary memory to begin declaring types
*/
ErrorCode type_init()
{
  /*
    Allocate memory for buffers
  */
  //  Types
  ident_types = (Identifier*) malloc(256 * sizeof(Identifier));
  param_types = (Identifier**) malloc(256 * sizeof(Identifier));
  pcount_types = (unsigned int*) malloc(256 * sizeof(unsigned int));
  
  //  Constructors
  ident_construct = (Identifier*) malloc(256 * sizeof(Identifier));
  count_construct = (unsigned int*) malloc(256 * sizeof(unsigned int));
  ident_elements = (Identifier**) malloc(256 * sizeof(Identifier*));
  type_elements = (TypeID**) malloc(256 * sizeof(TypeID*));
  count_elements = (unsigned int**) malloc(256 * sizeof(unsigned int*));


  //  Return Success
  return 0;
}

/*
  2.) Utility Operations
*/

//  2.a) Get Next TypeID
TypeID get_next_tid(){ return next_type++; }
//  2.b) Get Current TypeID
TypeID get_curr_tid(){ return next_type - 1; }


/*
  3.) Type Operations
*/

/* 3.a) Find Type

  Returns:
    0, if ident is not a Type
    1, if ident is of Arbitrary Type
    i, if ident is a Type, where 'i' is index in Types Buffer
*/
int find_type (char* ident)
{
  printf("Type Found: %s\n", ident);

  return 0;
}



#endif
