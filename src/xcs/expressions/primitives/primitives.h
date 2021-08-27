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


ErrorCode initializePrimitives(ContextManager context)
{
  if (initializeSpecialPrimitives(context)) return 1;
  if (initializeIntegerPrimitives(context)) return 2;
  if (initializeRealPrimitives(context))    return 3;
  if (initializeBooleanPrimitives(context)) return 4;
  if (initializeASCIIPrimitives(context))   return 5;
  if (initializeListPrimitives(context))    return 6;
  if (initializeEventPrimitives(context))   return 7;

  l.log('d', "Primitives", "Primitive data types have been initialized");

  return SUCCESS;
}

