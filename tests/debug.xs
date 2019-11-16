(*
  debug.xs
  Codeus Tech
  Authored on   November 14, 2019
  Last Modified November 14, 2019
*)

--  Tests Debug Messages with Terminal I/O


--  Define function 'test_me', with debug message "Hello World!!"
debug "Hello World!!"
let test_me i = 1;;

--  Prints "Hello World!!" to native OS terminal
@test_me;;


(* 
  Practical Example
  =================
*)
debug "Person can be a specific person or a defined custom example."
type person = 
    Cody 
  | Jake 
  | Person of 
      name of string, 
      age of int;;


--  Prints "Woot!" to native OS terminal
@person

