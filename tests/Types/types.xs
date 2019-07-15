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
  1.) Type Declarations
  2.) Typeclass Declarations
*)

(*
  1.) Type Declarations
*)

type flow = int;;
type dog = Bulldog | Poodle;;
type switch =
    On of flow
  | Off;;

type node a = 
    Leaf 
  | Tree of (node a), a, (node a)

(*
  2.) Typeclass Declarations
*)

