(*
  debug.xs
  Codeus Tech
  Authored on   November 14, 2019
  Last Modified November 14, 2019
*)

--  Tests Debug Messages with Terminal I/O


--  Define function 'test_me', with debug message "Hello World!!"
debug "Hello World!!"
let test_me = 1;;

--  Prints "Hello World!!" to native OS terminal
@test_me;;

--  Prints "Woot!" to native OS terminal
debug "Woot!"

