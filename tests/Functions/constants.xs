(*
  constants.xs
  Codeus Tech
  Authored on   February 16, 2019
  Last Modified      May 26, 2020
*)

(*
  Contains Test Case for Functional Expressions
*)

  type color = Color of int;;  --  RGB Notation

  --  Constant Declarations
  const Color red = 0xFF0000;; 
  const Color yellow = red + 0x00FF00;;

  --  Constant Expressions
  red * 32;;  --  Invoke Constant

  --  Functional Overrides (1 Time Use)
  let red = 0xaa0000 in 
    red - 1      --  Check Overriden Value: 'red'
  ;;

  --  Check Current Default Value: 'red'
  red

