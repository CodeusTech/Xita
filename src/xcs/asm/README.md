#  AArch64 Assembly Libraries

The `asm` XCSL Library provides backend functionality for building and segmenting assembly files.  

This includes:

* Backend Compiler Buffers
* Assembly File Manipulation
* Segmentation
* Command Printing

There are three major segments to know about:

* BSS
* Data
* Text

### BSS 

**BSS Segment** holds all uninitialized *variables*.  This allocates memory for an identifier without initalizing it to a value.

### Data

**Data Segment** holds all initialized *constants*.  This allocates memory for an identifier AND initializes it to a value.

### Text

**Text Segment** holds all executable source code.  This contains a list of commands to be sent to the executional unit.  
