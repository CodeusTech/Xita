/*
  interface.h (firmware)
  Codeus Tech
  Authored on   July 22, 2021
  Last Modified July 22, 2021
*/

/*
  Defines Structure/Implementations for FirmwareInterface used in XitaChip
*/

#pragma once

#include <xcs/std/includes.h>

using namespace std;

class FirmwareInterface
{

  string _name;

  vector<Address> range_start;
  vector<Address> range_end;

public: 
  FirmwareInterface(string name) : _name(name) {}

  string Name() { return _name; }

  ErrorCode addRange(Address start, Address end)
  {
    // TODO: 
    //    This needs to be validity checked before blindly adding the range LOL
    range_start.push_back(start);
    range_end.push_back(end);

    l.log('d', "Chip", "Defined new Firmware Interface Range: " + to_string(start) + " - " + to_string(end) );
    return SUCCESS;
  }

  //  Returns true if a 'target' memory address is within the FirmwareInterface
  bool inRange(Address target)
  {
    for (Index i = 0; i < range_start.size(); ++i)
      if (target >= range_start[i] && target <= range_end[i])
        return true;
    return false;
  }

};

