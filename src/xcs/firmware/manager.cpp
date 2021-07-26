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
{
    
}



/*
  Internal Helper Functions
*/
ErrorCode FirmwareManager::addFirmwareInterface(string name)
{
  //  TODO:
  //    This needs major work for validating that the interface appears
  //    properly in the loaded *.chip file and with the given name.

  chip.newInterface(name);

  return SUCCESS;
}


/*
  Public Interface Functions for FirmwareManager
*/
ErrorCode FirmwareManager::requestMemoryRead(Address addr)
{
  if (!active_driver)
  {
    //  There is no firmware driver loaded, so this request can be
    //  trivially tossed out without any additional information.  
    yyerror("Syntax Error:  ");
  }

  if (!active_driver->inRange(addr))
  {
    //  If the requested memory is not "in range" for active interface driver,
    //  the request should be tossed out and an error message should be thrown.
    yyerror("The executing code does not have ");
  }


}


ErrorCode FirmwareManager::requestMemoryWrite(Address addr)
{

  return SUCCESS;
}
