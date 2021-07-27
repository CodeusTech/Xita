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
  Supported Chip Architecture/Assembly 
*/
enum XitaArchitecture
{
  Arm64,
  Arm32//,
  //x86
};


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
  ErrorCode setArchitecture(string target)
  {
    if (strcmp("Arm32", target.c_str()) == 0)
    {
      arch = XitaArchitecture::Arm32;
      l.log('d', "Chip", "Set System for 32-Bit Arm Architecture");
    }
    else if (strcmp("Arm64", target.c_str()) == 0)
    {
      arch = XitaArchitecture::Arm64;
      l.log('d', "Chip", "Set System for 64-Bit Arm Architecture");
    }
    else
    {
      yyerror("Chip file specifies an unsupported target architecture.\n Acceptable architectures include:  Arm32, Arm64");
      return ERR_UNSUPPORTED_ARCH;
    }

    return SUCCESS;
  }

  ErrorCode newInterface(string name)
  {
    interfaces.push_back(FirmwareInterface(name));

    l.log('d', "Chip", "Defined new Firmware Interface: "+name);

    return SUCCESS;
  }

  ErrorCode addRange(Address begin, Address end)
  {

    l.log('d', "Chip", "Defined new Firmware Interface Range: " + to_string(begin) + " - " + to_string(end) );
    // TODO: 
    //    There is more validation required here to ensure
    //    no two interfaces are claiming the same memory ranges
    return interfaces.back().addRange(begin, end);
  }

};
