/*
  primitives.h
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Mass inclusion file for handling XCS Primitive Types
*/

#pragma once


#include "special.h"
#include "integer.h"
#include "real.h"
#include "boolean.h"
#include "char.h"


/*
  Initialize Primitive Type/Constructors
*/
ErrorCode initPrimitives()
{
  if (declarePrimitiveNull()) return 1;
  if (declarePrimitiveArbitrary()) return 2;
  if (declarePrimitiveIntegers()) return 3;
  if (declarePrimitiveReals()) return 4;

  if (declarePrimitiveAscii()) return 6;

  return SUCCESS;
}



