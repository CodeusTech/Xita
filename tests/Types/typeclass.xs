(*
  typeclass.xs
  Codeus Tech
  Authored on   May 2, 2020
  Last Modified May 2, 2020
*)

(*
  Contains test case file for XCS Typeclass Declaration/Invocations
*)


typeclass number a requires
  sum  a a = a,
  diff a a = a,
  prod a a = a,
  div  a a = a;;

type age = int
  implements number:
    sum  x y = 1 + 2,
    diff x y = 3 - 4,
    prod x y = 5 * 6,
    div  x y = 7 / 8


