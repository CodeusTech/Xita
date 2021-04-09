(*
  is.xs
  Codeus Tech
  Authored on     May 1, 2020
  Last Modified   May 1, 2020
*)

(*
  Contains test case file for eagerly type-checking an expression (returning a boolean value)
*)


--  Type Declarations
type age = 
    int
  | Age of int    
;;

--  Type Casting/Constructors
let test_age = Age 5;;

--  Eagerly evaluated (typecast) data
test_age is age;;

--  Arbitrary Data 
let test2_age = 5;;

--  Lazily evaluated type alias
test2_age is age



