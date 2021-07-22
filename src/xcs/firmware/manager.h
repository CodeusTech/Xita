/*
  manager.h (firmware)
  Codeus Tech
  Authored on   July 22, 2021
  Last Modified July 22, 2021
*/

/*
  Defines structure/procedures for Xita's FirmwareManager class

  The FirmwareManager is used to keep track cross-compiler's target chip
  and its associated firmware interfaces.
*/

#pragma once


#include <xcs/std/includes.h>

#include "chip.h"

class ContextManager;



class FirmwareManager
{
  ContextManager* _context;

  XitaChip chip;
  

public:
  FirmwareManager(ContextManager* context);

};
