(*
  memory.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified   August 11, 2019
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


(*
  2.) Write Memory
*)
let write_entry dumb_parameter entry offset = 
  offset <-* entry;;


--write_entry 10 5;;


let read_int dumb_parameter offset = 
  offset *-> entry in
    entry;;

--read_int 10

