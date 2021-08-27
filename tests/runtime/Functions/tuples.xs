(*
  tuples.xs
  Codeus Tech
  Authored on   December 13, 2019
  Last Modified December 13, 2019
*)

(*
  Unit testing file for Functions with multiple return values (Anonymous Tuples)
*)

--  Jumble Parameters/Returns and return as tuple
let return_three x y z = 
  y ; z ; x  ;;

--  Return second return value of 'return_three' (z) (3)
(return_three 1 2 3).{1}
