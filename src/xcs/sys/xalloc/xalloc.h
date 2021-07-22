/*
  xalloc.h
  Codeus Tech
  Authored on   July 1, 2021
  Last Modified July 2, 2021
*/

/*
  `xalloc` is the backend memory allocation system used for 
  dynamic memory allocation in Xita-AArch64

  This system library provides static and dynamic memory analysis, as
  well as system standard functions (e.g. alloc, dealloc, and realloc)
*/

#pragma once

#include <xcs/std/includes.h>

class ContextManager;


/*
  Each `MemoryNode` represents a currently allocated chunk of runtime memory.

  This stripped down Node definition is intended to get the system running,
  and nothing else.  It should be replaced by a fuller featured Node definition
*/
struct MemoryNode
{
  Address _start;
  Address _end;
  unsigned long size;

  MemoryNode(Address start, Address end)
  {
    _start = start;
    _end = end;
    size = end - start;
  }
};

/*
  Each `MemoryAllocator` contains a list of MemoryNodes that are allocated,
  along with relevant metadata for allocated memory.
*/
class MemoryAllocator
{

protected:
  
  unsigned long long _start = 0;
  unsigned long long _next  = 0;
  unsigned long long _last  = 0;

  ContextManager* context;

public:

  MemoryAllocator(ContextManager* context);
  ~MemoryAllocator();

  ErrorCode writeAssemblyConstants();

  ErrorCode allocate(unsigned long bytes);
  ErrorCode deallocate();

  bool isAllocated(Address address);


};



