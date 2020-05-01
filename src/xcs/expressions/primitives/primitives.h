/*
  primitives.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Convenience File for primitive type #includes
*/

#pragma once

#include "special.h"
#include "integer.h"
#include "real.h"
#include "boolean.h"
#include "ascii.h"
#include "list.h"
#include "event.h"


ErrorCode initializePrimitives()
{
  if (initializeSpecialPrimitives()) return 1;
  if (initializeIntegerPrimitives()) return 2;
  if (initializeRealPrimitives())    return 3;
  if (initializeBooleanPrimitives()) return 4;
  if (initializeASCIIPrimitives())   return 5;
  if (initializeListPrimitives())    return 6;
  if (initializeEventPrimitives())   return 7;

  l.log('d', "Primitives", "Primitive data types have been initialized");

  return SUCCESS;
}

