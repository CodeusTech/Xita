/*
  chip.h
  Codeus Tech
  Authored on   July 22, 2021
  Last Modified July 22, 2021
*/

/*
  Defines structure/procedures for Xita Chip objects
*/

#pragma once

#include <xcs/std/includes.h>

#include "interface.h"

using namespace std;



/*
  XitaChip classes hold data contained within Xita's `*.chip` files

  These the first half of Xita's asynchronous firmware system
  (the other half being the firmware driver source files)

  Each Chip has several designated "Firmware Interfaces".
  Each Firmware Interface is linked up with a single Firmware "Driver".
*/
class XitaChip
{

protected:

  string name;
  vector<FirmwareInterface> interfaces;
  XitaArchitecture arch;


public:
  XitaChip() {}
  XitaChip(string name) : name(name) 
  {
    l.log('d', "Chip", "Defined new Chip Device: " + name);
  }

  //  Architecture
  XitaArchitecture getArchitecture() { return arch; }
  ErrorCode setArchitecture(string target);

  ErrorCode newInterface(string name);
  FirmwareInterface* getInterface(string name);
  ErrorCode addInterfaceRange(Address begin, Address end);

};
