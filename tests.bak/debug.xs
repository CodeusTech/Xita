(*
  debug.xs
  Codeus Tech
  Authored on   November 14, 2019
  Last Modified November 14, 2019
*)

--  Tests Debug Messages with Terminal I/O

--  Print Debug Message for initial test
debug "Test 1: Initial Test";;

--  Define function 'test_me', with debug message "Hello World!!"
debug "Hello World!!"
let test_me = 1 + 1;;

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


--  Prints debug message for type Person
@person

--  Define Constant value 'guy' equal to 'Cody'
--debug ""
--const guy of person = 1 --Person (name="Cody", age=27)


