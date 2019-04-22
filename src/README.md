
#  Navigating src/

###  Table of Contents

* [asm/](#arm-assembly)
* [bytecode/](#bytecode)
* [comments/](#comments)
* [conditions/](#conditions)
* [globals/](#globals)
* [gpio/](#general-purpose-i-o)
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

`comments/` contains backend functionality for XCS comments (especially
*reference guides*).  It includes the following documentary backend libraries:

* ref.h
  * Includes backend framework for XCS reference guides
  * **Note:** This serves as the standard for XCS technical manuals

###  Conditional Statements

`conditions/` contains backend functionality for conditional statements.
It includes the following conditional backend libraries:

* if.h
  * Includes functionality for handling `if ... then ... else` statements
* is.h
  * Includes functionality for handling `... is ...` statements
* match.h
  * Includes functionality for handling `match ... with ...` statements

###  Globals

`globals/` contains functionality that is required by all components of the
Linux-to-XCS Cross-Compiler.  It includes the following global libraries:

* buffers.h
  * Includes *C* Cross-Compiler Buffers for Linux-Side computations
* structs.h
  * Includes standard data type/structure definitions for cross-compiler

###  General Purpose I/O

`gpio/` contains backend functionality required by general purpose peripherals.
It includes the following firmware libraries:

* constants.h
  * Contains constant values (especially memory addresses) for use in all GPIO
* rng.h
  * Contains backend firmware for GPIO-based random number generator
* rtc.h
  * Contains backend firmware for Real-Time Clock
* timer.h
  * Contains backend firmware for Main Event Timer

###  Grammar

`grammar/` contains XCSL frontend functionality (e.g. user interface).
It includes the following XCSL grammar libraries:

* status.h
  * Contains integer error codes to be used system-wide
* xcsl.l
  * Contains lexical tokens used within XCSL grammar
* xcsl.y
  * Contains the syntactic structure of the XCS Language

###  Identifiers

`ident/` is probably the most important subdirectory within `src/`.
It includes all functionality related to user-defined identifiers.  This
covers everything from constant declarations to type inferrence.

`ident/` includes the following sub-libraries:

* Constructors
  * Framework for declaring/resolving type constructors
* Functions
  * Framework for declaring/resolving functional expressions
* Typeclasses
  * Framework for declaring/resolving typeclass expressions
* Types
  * Framework for declaring/resolving data types

For more information see [here](https://github.com/CodeusTech/XCSL-AArch64/tree/master/src/ident).

###  Memory

`memory/` contains XCS backend functionality for memory manipulation.  The
vast majority of XCS memory usage is internally manipulated, but syntax is
provided for static manipulation for firmware authoring.

`memory` contains the following memory libraries:

* alloc.h
  * Backend framework for internal memory allocation
* static.h
  * Semantics framework for static memory operators
* tree_ops.h
  * AVL framework tailored for memory allocator

###  External Modules

`modules/` contains XCS backend functionality for external module usage.
Includes libraries for:

* header.h
  * Contains backend functionality for importing submodules (headers)
* operations.h
  * Contains interface functionality for external module usage
* source.h
  * Contains backend functionality for executing source modules
* tether.h
  * Contains backend functionality for tether modules (daemons)

###  XCS Operators

###  Processes

###  Regular Expressions

###  Register Stacks

###  Misc. Utilities

###  XCSL-AArch64 Driver

