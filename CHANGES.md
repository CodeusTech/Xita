
#  XCSL-AArch64 Change Log

**Current Version:  v0.27**


### 0.27.0
* Defined new `FirmwareManager` class to manage metadata for target hardware
    * Built some trivial test files for testing chips/firmware drivers
* Framework started (but not used) for allowing Xita to cross-compile to a number of architectures
* Coming Soon:  A new grammar parser is needed to continue development on the Firmware framework
    * Firmware drivers and chip files need to have special syntactic parsers to separate userspace development


### 0.26.0
* Rewrite/organized a lot of the project's documentation for open source collaboration
* Started laying out the memory allocation system (not used in stable version)
    * Started organizing backend interactions between memory allocator and data types system
* Designed new firmware system to restrict how memory can be accessed directly in Xita
    * Updated syntax highlighter to recognize `*.chip` files and driver-specific keywords
* Reorganized code from private codebase into Xita-AArch64 (e.g. `rpi3-boot.s`, `rpi3-linker.ld`)

### 0.25.0
* Started building and refining documentation
    * Added a README to expressions
    * Modified Makefile and other scripts for small name changes (e.g. XCS -> Xita)
* Started combing through all source files to add comments, READMEs, etc.

### 0.24.0
* Initial Version as Open Source
    * Officially changed name to XCS from Xita

### 0.23.0
* Added high-level managers:
    * Assembly Manager
    * Operator Manager 
        * Many operators are not fully operational
        * Overrides are temporarily broken
* Reworked high-level managers
    * Types Manager
    * Functions Manager
        * **BUG:**  Functions are required to be enclosed in `( )`
* **NOTE:**  Many changes in 0.23.0 have broken core functionalities and introduced shift conflicts.  The new changes *are* correct, so these bugs will need to be resolved before 0.24

### 0.22.0
* Added `l.log()` commands to trace comiler backend logic flow
  * Operators
  * Functions
  * Parameters
  * Constants
* Added initial lazy type-checking to Functions/Parameters
  * Buggy, but frequently works
* Added initial eager type-checking to Constants

### 0.21.0
* Added "CHANGES.md" to track changes between versions in text
* Added initial framework/shell of XCSL's new `ContextManager`
* Added global logger to XCSL Internal
  * Rewrote all Code to use `l.log()`, rather than `printf()`
