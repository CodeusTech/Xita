
#  XCSL-AArch64 Change Log

**Current Version:  v0.25.0**

### 0.25.0
*  Started building and refining documentation
  * Added a README to expressions
  * Modified Makefile and other scripts for small name changes (e.g. XCS -> Xita)
*  Started combing through all source files to add comments, READMEs, etc.

### 0.24.0
*  Initial Version as Open Source
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
