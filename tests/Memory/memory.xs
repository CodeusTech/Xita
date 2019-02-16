(*
  memory.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*)

(*
  Test Cases for Direct Memory Access

  Table of Contents
  =================
  1.) Read Memory
  2.) Write Memory
*)


(*
  1.) Read Memory
*)

let f = 0x00000000 *-> num in num + 1;;

let read_gpio port = 
  (0x3F000000 + port) *-> this;;


(*
  2.) Write Memory
*)

0x3F000000 <-* gpio_expression

