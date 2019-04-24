
# XCS Identifiers

Identifiers are user-defined keywords bound to alternate functionality.  
Canonical examples of identifiers are:

* Constants
* Functions
* Types

## Table of Contents

* [construct/](#type-constructors)
* [functions/](#functional-expressions)
* [typeclass/](#typeclasses)
* [types/](#types)

## Type Constructors

* operations.h
  * Backend funcitonality for handling *constructor* identifiers (e.g. declare, find, etc.)
  * *Will likely be reorganized into TYPES soon*

## Functional Expressions

* constant.h
  * Backend functionality for handling *constant* identifiers
* operations.h
  * Backend functionality for handling *functional* identifiers
* parameter.h 
  * Backend functionality for handling functional parameters
* recursion.h
  * Backend functionality for handling functional recursion

## Typeclasses

* operations.h
  * Backend functionality for handling *typeclass* identifiers
* prototype.h
  * Backend functionality for handling typeclass prototypes

## Types

* Complex Types
  * operations.h
    * Backend functionality for handling *type* identifiers
  * records.h
    * Backend functionality for handling types consisting of multiple elements
  * tuples.h
    * Backend functionality for anonymous tuples
* Type Inferrence
  * operator.h
    * Backend functionality for type-checking standard operators
  * rstype.h
    * Backend functionality for dynamically type-checking XCS register stack
* Primitive Types
  * boolexp.h
    * Backend functionality for handling *boolean* expressions
  * charexp.h
    * Backend functionality for handling *character* expressions
  * intexp.h
    * Backend functionality for handling *integer* expressions
  * listexp.h
    * Backend functionality for handling *list* expressions
  * realexp.h
    * Backend functionality for handling *real* expressions
  * strexp.h
    * Backend functionality for handling *string* expressions
  * typecodes.h
    * List of XCSL Primitive Type IDs



