(*
  complex_nodefault.xs
  Codeus Tech
  Authored on   June 1, 2020
  Last Modified June 1, 2020
*)

(*
  Contains unit tests for complex data types, WITHOUT default values
*)

type attributes = 
  Attributes of
    age     : int, 
    weight  : int
;;


type person = 
  Person of 
    name  : string,
    stats : attributes,
    height: int
;;

let joe = 
  Person {"Joe", Attributes {15, 155}, 65 }
;;

joe.height

