(*
  functions.xs
  Codeus Tech
  Authored on   October 30, 2019
  Last Modified October 30, 2019
*)

(*
  Contains test-case file for XCS Function Testing
*)


let sum x y = x + y;;
let sum x y z = x + y + z;;
let prod x y = x * y;;

(sum 1 2) + 2;;
(prod 1 2);;
(sum 1 2);;

--  Test Parameter Overloading
(sum 1 2 3);;

--  Test Nested Functions
debug "Test Unparameterized Functions"
let test = 
    1;;

@test

