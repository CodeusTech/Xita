(*
  demo.xs
  Codeus Tech
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*)

(*
  Provides basic demo of XCSL features
*)

-- Constants
const Int32 five = 5;;

--  Functions
let sum x y = (x + y);;
let sum x y z = (x + y + z);;

--  Execution
if five == 5
then (sum 1 2)
else (sum 3 4 5)

