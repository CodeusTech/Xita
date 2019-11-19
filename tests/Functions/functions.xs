(*
  functions.xs
  Codeus Tech
  Authored on   October 30, 2019
  Last Modified October 30, 2019
*)

(*
  Contains test-case file for XCS Function Testing
*)


let sum t x y = x + y;;
let sum t x y z = x + y + z;;
let prod t x y = x * y;;

sum 0 1 2;;
prod 0 1 2;;
sum 0 1 2;;

--  Test Parameter Overloading
sum 0 1 2 3;;

--  Test Nested Functions
let test x = 
    1


