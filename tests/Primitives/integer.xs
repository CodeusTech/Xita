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
  3.) Static Optimization
*)

(*
  IMPORTANT NOTE:  
    It is completely possible that the Bugs marked in this test file are NOT bugs and are correctly operated.
    It *might* be the case that they should be using 32-bit registers, and the cross-compiler should internally track as 8/16 bit.
*)

(*
  1.) Integer Arithmetic
*)
let x = 0;;  -- Using this x variable, because integer arithmetic is statically optimized out

(*U8*) 5;;    --  BUG:  '5' is not being tracked as an 8-bit value
(x + 2) + 5;;
x - 1;;
x * 1;;
x / 1;;
x % 4;;

(*
  2.) Bitwise Arithmetic
*)

x & 5;;
x | 5;;
x ^ 10;;

x << 5;; 
x >> 2;;

(*
  3.) Static Optimization
*)

7 + 5;;     
20 - 8;;
3 * 4;;
36 / 3;;

12 | 0;;
15 & 12 & 8;;

6 << 1;;
24 >> 1


