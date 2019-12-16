(*
  mod.xs
  Cody Fagley
  Authored on   July 28, 2019
  Last Modified July 28, 2019
*)

(*
  Contains a source script to open the header for testing
*)

  let parameter = 55;;

  open tests/Modules/header_one.xh
  open tests/Modules/header_two.xh

  (test_function test2 55) + 1
