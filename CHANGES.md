
#  XCSL-AArch64 Change Log


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
* Added initial framework/shell of XCSL's new `ContextManager`
* Added global logger to XCSL Internal
  * Rewrote all Code to use `l.log()`, rather than `printf()`

