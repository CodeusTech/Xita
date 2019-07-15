(*
  boolean.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*)

(*
  Primitive Boolean Test Cases

  Table of Contents
  =================
  1.) Boolean Comparisons
  2.) Integer Comparisons
*)

(*
  1.) Boolean Comparisons
*)

let a = True && False;;
let b = True || False;;
let c = True ^^ False;;

(*
  2.) Integer Comparisons
*)

let d = 1 <  2;;
let e = 1 <= 1;;
3 == 6;;
let g = 3 >= 4
