(*
  basic.xs (Types)
  Codeus Tech
  Authored on   June 1, 2020
  Last Modified June 1, 2020
*)

(*
  Contains unit tests for trivial type declarations/expressions
*)


type flow = int | real;;      -- Type Aliases
type dog = Bulldog | Poodle;; -- Type Constructors

--  Constructor w/ argument
type switch =
    On of flow
  | Off;;

--  Recursive Type Validation/Invocation
let valve = On 5

