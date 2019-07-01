
#  XCS Memory Allocator

This library contains functionality for handling memory -- statically or dynamically.  It provides functionality for handling static memory (using provided operators), as well as internal backend memory allocation/deallocation.  

Most notably, this includes functions for:

 * Check if address is allocated
 * Allocate Memory Address
 * Deallocate (Free) Memory Address
 
Dynamic memory allocation is used heavily throughout the system including:
 
 * XCS Configuration Space
 * User Declarations, especially data structures
 * Process Scheduling

###  Data Structures

`tree_ops.h` includes functionality for manipulating internal data structures (e.g. memory nodes).  These definitions are used to form the dynamic memory allocation backend.  


###  Static Operators

XCS provides arithmetic operators for reading/writing specific memory addresses.  These only work for a special range of numbers and do not allow access to unauthorized memory space.  These operators are specifically provided for generation of firmware drivers.

```Haskell
-- Read 2 bytes from Address 0x0080
0x0080 *-> this 2

-- Write 2 bytes (value: 16) to Address 0x0080
0x0080 <-* 16 2
```


