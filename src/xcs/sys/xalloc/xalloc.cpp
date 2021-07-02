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
*/
ErrorCode MemoryAllocator::allocate(unsigned long bytes)
{
  //  Push Number of Bytes for Serialization
  context->rsPush(TYPE_INTEGER);

  //  Create Strings
  char* str = (char*) malloc(50);
  char* top = get_reg(context->rsTop(), 32);

  //  Record the number of bytes that need to be allocated in register stack
  sprintf(str, "mov   %s, %lu", top, bytes);
  context->addInstruction(str);

  //  Serialize Current Active Registers
  context->rsSerialize(1);

  //  Free up Memory
  free (str);
  free (top);

  return SUCCESS;
}


ErrorCode MemoryAllocator::deallocate()
{
  return SUCCESS;
}
