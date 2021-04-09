(*
  constants.xs (Complex Types)
  Codeus Tech
  Authored on   May 26, 2020
  Last Modified May 26, 2020
*)

(*
  Contains Unit Tests for Constants of Complex Type
*)


type color = Color of int;;

--  Constant Declarations
const Color red = 0xFF0000;; --  RGB Notation
const Color yellow = red + 0x00FF00;;

--  Constant Expressions
red * 32;;  --  Invoke Constant

--  Functional Overrides (1 Time Use)
let red = 0xAA0000 in 
  red - 1      --  Check Overriden Value: 'red'
;;

--  Check Current Default Value: 'red'
red;;

type name = Name of string;;

const Name guy = "Guy Person";;

guy


