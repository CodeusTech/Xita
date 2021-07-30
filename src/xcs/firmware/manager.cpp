/*
  manager.cpp (firmware)
  Codeus Tech
  Authored on   July 22, 2021
  Last Modified July 22, 2021
*/

/*
  Contains extended definitions for FirmwareManager procedures
*/


#include "manager.h"
#include "../context/manager.h"


/*
  Constructor Behavior
*/
FirmwareManager::FirmwareManager(ContextManager* context)
  : _context(context)
{ }


/*
  Public Interface Functions for Chip Data
*/
ErrorCode FirmwareManager::newChip(string name)
{
  chip = XitaChip(name);

  return SUCCESS;
}


/*
  Public Interface Functions for FirmwareManager
*/
ErrorCode FirmwareManager::addInterface(string name)
{
  //  TODO:
  //    This needs major work for validating that the interface appears
  //    properly in the loaded *.chip file and with the given name.

  chip.newInterface(name);

  return SUCCESS;
}


/*
  Activate/Deactivate Firmware Driver
*/
ErrorCode FirmwareManager::activateDriver(string name)
{
  //  Find the Driver
  active_driver = chip.getInterface(name);

  if (!active_driver)
  {
    //  The Driver name returned no matched results from the chip file.
    //  This should result in an error.  
    string str = "Firmware interface for `" + name + "` was not found in designated .chip file.";
    active_error_code = ERR_UNDEFINED_FIRM;
    yyerror(str.c_str());
    //return active_error_code;  //  Does nothing since yyerror uses exit()
  }

  for (Index i = 0; i < loaded_drivers.size(); ++i)
    if (name.compare(loaded_drivers[i]) == 0)
    {
      //  The Driver name returned no matched results from the chip file.
      //  This should result in an error.  
      string str = "Firmware interface for `" + name + "` has already been connected by another driver file.";
      active_error_code = ERR_REDEFINED_FIRM;
      yyerror(str.c_str());
      //return active_error_code;  //  Does nothing since yyerror uses exit()
    }

  loaded_drivers.push_back(name);
  return SUCCESS;
}


/*
  Perform Direct Memory Read/Write
*/
ErrorCode FirmwareManager::requestMemoryRead(Address addr)
{
  if (!active_driver)
  {
    //  There is no firmware driver loaded, so this request can be
    //  trivially tossed out without any additional information.  
    active_error_code = ERR_MEMORY_ACCESS;
    yyerror("Direct memory accesses can not be made from outside firmware drivers");
  }

  if (!active_driver->inRange(addr))
  {
    //  If the requested memory is not "in range" for active interface driver,
    //  the request should be tossed out and an error message should be thrown.
    active_error_code = ERR_MEMORY_ACCESS;
    yyerror("Illegal memory access attempt.  The active driver does not have ownership of the requested memory address (see .chip file)");
  }

  /*
    TODO:  
      At this point, we need to actually write out assembly instructions
  */

  return SUCCESS;
}

ErrorCode FirmwareManager::requestMemoryWrite(Address addr)
{
  /*
    TODO:
      At this point, we need to actually write out assembly instructions
  */

  return SUCCESS;
}
