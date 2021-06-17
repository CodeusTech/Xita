
# XCS Cross-Compiler Backend

![Alt Overview_Image](https://github.com/CodeusTech/XCSL-AArch64/blob/PreAlpha-Dev/src/xcs/XCompilerOverview.png)


### Directory/Project Structure

* asm
  * 'asm' contains Xita's `AssemblyManager` which handles data written to assembly files
* comments
  * 'comments' contains functionality related to Xita's comments.  Of note, it controls the semantic functionality of documentation comments (reference guides)
* conditions
  * 'conditions' contains logical operations for conditional execution.  E.g. `if ... then ... else ...` and `match ... with ...`
* context
  * 'context' contains Xita's `ContextManager`.  The ContextManager is responsible for managing active data scopes and module ownership
* data
  * 'data' tracks data as it moves through cross-compiler buffers.  This is largely for correctness checking
* expressions
  * 'expressions' contains a collection of sublibraries for managing literal values and identifiers
* grammar
  * 'grammar' contains the sublibraries used for generating/parsing the grammar and syntax
* modules
  * 'modules' contains definitions for multifile Xita modules and rules on how they can interact
* proc
  * 'proc' *will eventually* contain definitions for back-end process scheduling.  This has been designed and verified, but is a ways from the current state of development.
* regex
  * 'regex' will contain semantic definitions for creating/reading regular expressions
* regstack
  * 'regstack' contains definitions and structures for managing Xita register stacks
* std
  * 'std' contains Xita's core "standard" libraries and constant definitions
* sys
  * 'sys' will contain utility backend functionality for OS subsystems, e.g. bit vectors, delay functions, etc.
* types
  * 'types' contains libraries for type declaration and dynamic type/constructor checking
* utils
  * 'utils' contains miscellaneous utility libraries needed in backend development of process scheduling, memory allocation, and filesystems.  These will eventually be reorganized into the 'sys' library




**NOTE: PROJECT WAS RESTRUCTURED AS PART OF `TYPE CHECKING`, SO ADDITIONAL WORK ON THIS PAGE IS NEEDED**


