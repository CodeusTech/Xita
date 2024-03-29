/*
  typedefs.h (XCS STANDARD)
  Codeus Tech
  Authored on   October 29, 2019
  Last Modified October 29, 2019
*/

/*
  Contains standard type definitions for use within the XCSL Cross-Compiler
*/

#ifndef XCS_TYPEDEFS_H
#define XCS_TYPEDEFS_H


/*
  1.) Infrastructure
*/

typedef int ErrorCode;
typedef char* Command;
typedef unsigned long Index;

/*
  ID NUMBERS
*/
typedef unsigned long ID_NUMBER;
//  Functions
typedef unsigned long ConstantID;
typedef unsigned long FunctionID;
typedef unsigned int ParameterID;
typedef unsigned int MemoryVariableID;
typedef unsigned int OperatorID;

//  Types
typedef unsigned long TypeID;
typedef unsigned long ConstructorID;
typedef unsigned int ElementID;

//  Typeclasses
typedef unsigned long TypeclassID;
typedef unsigned int PrototypeID;

//  Processes
typedef unsigned long ModuleID;
typedef unsigned long ProcessID;
typedef unsigned long OfferID;


/*
  TYPENAMES
*/
typedef void* Arbitrary;
typedef char* Identifier;
typedef char* Constructor;
typedef unsigned long Address;


/*
  Register Stacks
*/

typedef int ADR;
typedef unsigned int Scope;



#endif
