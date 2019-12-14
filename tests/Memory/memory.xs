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
let write_entry entry offset = 
  offset <-* entry;;


--write_entry 10 5;;


let read_int offset = 
  offset   *-> entry  in
  offset+4 *-> entry2 in
    entry + entry2;;


let read_ offset = 
  offset *-> this;;


(read_int 10) + (read_ 5)
    
