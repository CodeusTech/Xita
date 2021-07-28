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
  vector<string> loaded_drivers;

public:
  FirmwareManager(ContextManager* context);
  
  ErrorCode newChip(string name);
  ErrorCode setChipArch(string arch) { return chip.setArchitecture(arch); }
  XitaArchitecture getChipArch() { return chip.getArchitecture(); }

  //  Administrate Active FirmwareInterface Metadata
  ErrorCode addInterface(string name);
  ErrorCode addInterfaceRange(int begin, int end) { return chip.addInterfaceRange(begin, end); }

  ErrorCode activateDriver(string name);
  ErrorCode deactivateDriver();

  ErrorCode requestMemoryRead(Address addr);
  ErrorCode requestMemoryWrite(Address addr);
};


