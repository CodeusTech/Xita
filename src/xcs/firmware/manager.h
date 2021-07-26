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


protected:

  //  Active Firmware Metadata
  XitaChip chip;
  FirmwareInterface* active_driver;


  //  Administrate Active FirmwareInterface Metadata
  ErrorCode addFirmwareInterface(string name);
  

public:
  FirmwareManager(ContextManager* context);
  
  ErrorCode activateDriver(string name);

  ErrorCode requestMemoryRead(Address addr);
  ErrorCode requestMemoryWrite(Address addr);
};


