
#  Expressions

**Expressions** are the core building blocks in Xita programming language.  
An expression is any executable code that results in some arbitrary value.


##  Types of Expressions

*  Primitive Expressions
   * _Primitive_ values are ones that are defined to always have a known value in Xita.  E.g. integer/boolean literals, strings, lists, etc.
   * ` 1 `
   * ` true `
   * ` "hello reader" `
*  Arithmetic Expressions
   * _Arithmetic_ expressions result in a mathematical operation such as Addition, Subtraction, Multiplication, Division, and Modulus.
   * ` 1 + 1 `
*  Logical Expressions
   * _Logical_ Expressions result in a comparative operation that tests an expression for True/False
   * ` x >= y `
*  Conditional Expressions
   * _Conditional_ Expressions control the flow of program logic
   * ` if x > y then "x is bigger" else "x is smaller" `
*  Constant Expressions
   * _Constant_ Expressions enable self-documenting code by labeling values that will not change during execution
   * ` pi `
*  Functional Expressions
   * _Functional_ Expressions map identifiers to complex, parameterized functionalities
   * ` (sum x y) `


##  Expressions vs Declarations

While expressions represent executions of source code, **declarations** map a value or functionality to an identifier.  
For example, once a function or constant is _declared_, it can be used freely as an expression for the rest of execution.  

Declarations are distinguished from expressions in that they do not resolve as any value other than "SUCCESS" or an error code.  By contrast, expressions always return a value when executed.  

