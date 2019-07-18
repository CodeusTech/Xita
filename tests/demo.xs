(*
  demo.xs
  Codeus Tech
  Authored on   July 15, 2019
  Last Modified July 15, 2019
*)

(*
  Provides basic demo of XCSL features
*)

1 + 2;;

[10, 11, 12];;

if True < False
then 111
else 999;;

--  Sum Function
let sum x y = 
  {
    := x + y
    :=  if sum < 5
          then x
          else y
  } in 
    sum 7 8
