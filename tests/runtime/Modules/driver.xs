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

  --  TODO: Fix Relative Path
  --        Project Root -> Recursive Pathing
  open tests/runtime/Modules/header_one.xh
  open tests/runtime/Modules/header_two.xh

  test + test2

