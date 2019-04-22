
#  Navigating src/

###  Table of Contents

* [asm/](#arm-assembly)
* [bytecode/](#bytecode)
* [comments/](#comments)
* [conditions/](#conditions)
* [globals/](#globals)
* [gpio/](#general-purpose-i/o)
* [grammar/](#grammar)
* [ident/](#identifiers)
* [memory/](#memory)
* [operator/](#xcs-operators)
* [proc/](#processes)
* [regex/](#regular-expressions)
* [regstack/](#register-stacks)
* [utils/](#misc.-utilities)
* [xcs.c](#xcsl-aarch64-driver)


###  ARM Assembly

`asm/` contains all of infrastructural procedures for formatting ARM Assembly 
files. 

XCSL-AArch64 procedurally generates and compiles GNU AArch64 assembly code to 
binary.  `asm/` includes the following sectional generation libraries:

* bss.h
  *  `.bss section` contains uninitialized data (Variables)
* data.h
  *  `.data section` contains initialized data (Constants)
* header.h
  *  Prints descriptive assembly comment header
* init.h
  *  Initializes assembly generation backend
* text.h
  *  `.text section` contains executable source code


###  Bytecode

`bytecode/` contains backend functionality for producing XCS Executable
Binary sequences (Bytecode).  It includes the following bytecode backend
libraries:

* body.h
  * Includes definitions for bytecode body sequences
  * ***DEPRECATED***
* build.h
  * Backend framework for generating XCS bytecode
* header.h
  * Includes definitions for bytecode metadata
* run.h
  * Backend framework for executing XCS bytecode

###  Comments

`comments/` contains backend funcitonality for XCS comments (especially
*reference guides*).  It includes the following documentary backend libraries:

* ref.h
  * Includes backend framework for XCS reference guides
  * **Note:** This serves as the standard for XCS technical manuals

###  Conditions

###  Globals

###  General Purpose I/O

###  Grammar

###  Identifiers

###  Memory

###  External Modules

###  XCS Operators

###  Processes

###  Regular Expressions

###  Register Stacks

###  Misc. Utilities

###  XCSL-AArch64 Driver

