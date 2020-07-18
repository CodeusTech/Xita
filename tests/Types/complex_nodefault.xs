(*
  complex_nodefault.xs
  Codeus Tech
  Authored on   June 1, 2020
  Last Modified June 1, 2020
*)

(*
  Contains unit tests for complex data types, WITHOUT default values
*)

type person = 
  Person of 
    name    : string,
    age     : int,
    weight  : int
;;

let joe = 
  Person {"Joe", 15, 155}
;;

joe.paul.age

