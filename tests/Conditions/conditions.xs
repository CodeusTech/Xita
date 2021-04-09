(*
  conditions.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*)

(*
  Contains Test Cases for Conditional Expressions

  Table of Contents
  =================
  1.) if ... then ... else ...
  2.) match ... with ...
  3.) ... is ...
*)

(*
  1.) if ... then ... else ...
*)

if True then 1 else 0;;
if 2 > 3 then 1 else 0;;


(*
  2.) match ... with ...
*)

match dog with
  BullDog -> 1,
  Poodle  -> 2;;

(*
  3.) ... is ...
*)

1 is int;;
1 is True



