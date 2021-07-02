/*
  xalloc.cpp
  Codeus Tech
  Authored on   July 1, 2021
  Last Modified July 1, 2021
*/

/*
  Contains extended definitions for function declarations in header file.

  Specifically contains functionality for manipulating the dynamic memory
  allocation system including: Allocate memory, free memory, copy memory, etc.
*/

#include "xalloc.h"
#include <xcs/context/manager.h>


/*
  Constructors/Destructors
*/
MemoryAllocator::MemoryAllocator(ContextManager* context)
  : context(context)
{
  l.log('d', "MemoryAllocator", "Memory Allocator has been Initialized Successfully!");
}

MemoryAllocator::~MemoryAllocator()
{
  l.log('d', "MemoryAllocator", "Memory Allocator correctly shut down");
}


/*
  allocate()

  Xita's backend function for dynamically allocating memory for data.  
  The cross compiler assumes the top
*/
ErrorCode MemoryAllocator::allocate(unsigned long bytes)
{
  //  Push Number of Bytes for Serialization
  context->rsPush(TYPE_INTEGER);

  //  Create Strings
  char* str = (char*) malloc(15);
  char* top = get_reg(context->rsTop(), 32);

  //  Record the number of bytes that need to be allocated in register stack
  snprintf(str, 15, "mov   %s, %lu", top, bytes);
  context->addInstruction(str);

  //  Serialize Current Active Registers
  context->rsSerialize(1);

  //  Call Assembly-Defined Allocate Memory Function
  sprintf(str, "bl    _x_alloc");
  //  TODO:  Uncomment the following code when `_x_alloc` has assembly definition
  //context->addInstruction(str);

  l.log('w', "Memory", "`_x_alloc` is not implemented in assembly or called from cross compiler");
  l.log('d', "Memory", "Memory Node successfully allocated");

  //  NOTE:  It is assumed at this point that the top of the register stack is
  //         an address to a chunk of memory that is sized as requested above

  //  Free up Memory
  free (str);
  free (top);

  return SUCCESS;
}


/*
  deallocate()

  Xita's backend functionality for deallocating chunks of memory.
*/
ErrorCode MemoryAllocator::deallocate()
{

  //  NOTE:  It is assumed that the top register in the register stack
  //         is the address to deallocate when this function is called  

  char* str = (char*) malloc(17);

  snprintf(str, 17, "bl    _x_dealloc");

  //  TODO:  Uncomment the following code when `_x_dealloc` has assembly definition
  //context->addInstruction(str);

  l.log('w', "Memory", "`_x_dealloc` is not implemented in assembly or called from cross compiler");
  l.log('d', "Memory", "Memory Node successfully deallocated");

  free (str);

  return SUCCESS;
}
