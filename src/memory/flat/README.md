
#  Flat Memory Allocator

This sublibrary provides access to a trivial, unoptimized memory allocator.  Although this isn't viable as a long-term option, it is pursued so that other development teams can proceed while an optimized version is produced.  

Basically, this allocator starts at the first usable memory address.  Then each time memory is allocated, the next concatenated memory address is allocated next.  Once it reaches the end of usable memory, it begins again at the beginning. 


This allocator is used within XCS's systems for:

 * Types & Data Structures
 * Process Management
 * Filesystems 

