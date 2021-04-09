(*
  integer.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*)

(*
  Primitive Integer Test Cases

  Table of Contents
  =================
  1.) Integer Arithmetic
  2.) Bitwise Arithmetic
*)

(*
  IMPORTANT NOTE:  
    It is completely possible that the Bugs marked in this test file are NOT bugs and are correctly operated.
    It *might* be the case that they should be using 32-bit registers, and the cross-compiler should internally track as 8/16 bit.
*)

(*
  1.) Integer Arithmetic
*)
U8 5;;    --  BUG:  '5' is not being tracked as an 8-bit value
1 + 2;;
4 - 1;;
3 * 1;;
3 / 1;;
7 % 4;;

(*
  2.) Bitwise Arithmetic
*)

7 & 5;;
3 | 5;;
2 ^ 10;;


(I16 8) << 5;;  --  BUG:  '8' is not being tracked as a 16-bit value
67 >> 2;;

(I16 7) + 5     --  BUG:  '7' is not being tracked as a 16-bit value




