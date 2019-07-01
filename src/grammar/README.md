
#  XCSL Grammar

There are three files that form the backbone of the XCSL Cross-Compiler's grammar recognition:
 
 * `xcsl.l`
 * `xcsl.y`
 * `status.h`

 
### Lexical Tokenizer

`xcsl.l` is used to produce a list of lexical tokens to be used within XCSL's grammar, e.g. operators, keywords, etc.  If the language needs to be able to recongize a string as a special *token*, it is itemized within this file's list.  


### Grammar Parser

`xscl.y` is used to actually produce a single parser that recognizes the XCSL syntax.  It also maps executional semantics to each defined phrase.  Once the parser is generated, the XCSL over-arching wrapper program calls the parser with specified command-line options.


### Grammar Status

`status.h` contains definitions and ErrorCode numbers for use across the entire cross-compiler backend.  Whenever a function does not return a specific element, it instead returns an XCS **ErrorCode** number.  

Important ErrorCode numbers include:

 * **0** -- Running Successfully
 * **100** -- Typecheck Error
 * **101** -- Undefined Type
 * **200** -- Undefined Expression
