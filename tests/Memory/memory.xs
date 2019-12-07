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
  offset *-> entry in
    entry;;

    const controlAddress of u32 = 0x7E215080;; -- bits 0-5 (specifies number of bits to shift)

debug "set the shift length in control register"
let set_spi_shiftLen shift = 
  controlAddress *-> cs in
    if shift then
      controlAddress <-* ((cs & 0xFFFFFC0) + shift)
    else
      controlAddress <-* (cs & 0xFFFFFC0);;-- get bits 0-5 (specifies number of bits to shift)

debug "get the shift length in control register"
let get_spi_shiftLen =  controlAddress *-> rtn in (rtn & 0x0000003F)

