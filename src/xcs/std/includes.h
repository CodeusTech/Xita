/*
  includes.h (std)
  Codeus Tech
  Authored on   April 16, 2020
  Last Modified April 16, 2020
*/

/*
  Includes a list of standard Xita/Linux Libraries that will
  be used in most source files in Xita cross compiler.
*/

#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H

//  Linux Standard Includes
#include <stdlib.h>
#include <string.h>
#include <vector>
 
//  XCS Standard Includes
#include "typedefs.h"
#include "typecodes.h"
#include "error.h"
#include "logger.h"
#include "buffers.h"
#include "status.h"

#include <xcs/regstack/codes.h>

#include <xcs/types/constants.h>

#include <xcs/expressions/operators/constants.h>

#endif
