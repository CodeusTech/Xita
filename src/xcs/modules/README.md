
#  External Modules

XCS implements four types of **external modules**:

 * Source
 * Submodule (Header)
 * System
 * Tether


###  Source Modules

**Source modules** are executed when they are interpreted.  Declarations are used internally within the source module, but they are not preserved through module termination.  In other words, functions can be declared and used within the source module, but they will not exist outside of the module.  

Applications generally only use one or a couple source modules, and the majority of the functionality resides within external submodules.  


###  Submodules

**Submodules** are the exact opposite of source modules.  Functions declared within submodules can be executed freely by parent modules, but none of the code will be directly executed within the submodule.  Instead, a source/tether module will generally import/use the functions within submodules.

Submodules are more-or-less organizational.  They are used to keep complex softwares organized, regardless of having only one entry point (e.g. the source module). 


### System Modules

**System Modules** are essentially the same as source modules, except with elevated privileges.  System modules are not restricted in access within the system.  These also do not physically exist within the filesystem, but instead reside within the bootloader's image file.  

Canonical examples of system modules are:

 * Filesystem
 * Network Sockets
 * USB Drivers


### Tether Modules

**Tether Modules** provide an obfuscating mechanism for user-programmed software protocols.  These are not necessarily treated as active applications; they are always available for other modules, but only run when it is necessary.  Once their task is completed, they go back to being inactive until called upon again.
