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
  vector<FirmwareInterface> interfaces;

public:
  XitaChip() {}

  ErrorCode newInterface(string name)
  {
    interfaces.push_back(FirmwareInterface(name));
    return SUCCESS;
  }

  ErrorCode addRange(string interface_name, Address begin, Address end)
  {
    for (Index i = 0; i < interfaces.size(); ++i)
      if (strcmp(interface_name, interfaces[i].Name()) == 0)
      {
        // TODO: 
        //    There is more validation required here to ensure
        //    no two interfaces are claiming the same memory ranges
        return interfaces[i].addRange(begin, end);
      }
  }

};
