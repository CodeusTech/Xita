(*
  complex.xs
  Codeus Tech
  Authored on   December 12, 2019
  Last Modified December 12, 2019
*)

(*
  Gives more rigerous testing examples for XCS Functions
*)

let do_first_thing param1 = param1 + 2;;
let do_second_thing param1 param2 = (do_first_thing param1) + param2;;

(do_second_thing (do_first_thing 3) 8)




