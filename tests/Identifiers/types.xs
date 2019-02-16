(*
  types.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
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
    On (*of flow*) 
  | Off;;


(*
  2.) Typeclass Declarations
*)

typeclass num requires
  sum x y,
  diff x y,
  prod x y,
  quot x y
  

