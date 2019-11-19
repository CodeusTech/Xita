(*
  types.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified     July 15, 2019
*)

(*
  Test Cases for Types, Typeclasses, etc.

  Table of Contents
  =================
  1.) Types
    1.a) Type Declarations
    1.b) Type Expressions
  2.) Typeclasses
    2.a) Typeclass Declarations
*)

(*
  1.) Types
*)

(* 1.a) Type Declarations

    TYPE DECLARATIONS allow peristant use of a type/data structure within the
  declaring module and any importing modules.
*)

type flow = int;;
type dog = Bulldog | Poodle;;
type switch =
    On of flow
  | Off;;

(*
type node a = 
    Leaf 
  | Tree of (node a), a, (node a);;

(* 1.b) Type Expressions

    TYPE EXPRESSIONS are instances of a declared type/constructor
*)

(*let search a = 
  if U8 5 is I32
  then 1
  else 2

(*
  2.) Typeclasses
*)

(*
  2.a) Typeclass Declarations
*)

On 5
