/*
  chip.h
  Codeus Tech
  Authored on      July 22, 2021
  Last Modified December 7, 2022
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
  int register_width;

public:
  XitaChip() {}
  XitaChip(string name) : name(name)
  {
    l.log('d', "Chip", "Defined new Chip Device: " + name);
  }

  //  Properties
  XitaArchitecture Architecture() { return arch; }
  ErrorCode setArchitecture(char* target);
  int RegisterWidth() { return register_width; }

  ErrorCode newInterface(string name);
  FirmwareInterface* getInterface(string name);
  ErrorCode addInterfaceRange(Address begin, Address end);

};
