(*
  lists.xs
  Cody Fagley
  Authored on        July 14, 2019
  Last Modified  December 13, 2019
*)

(*
  Contains test cases for XCS Primitive Linked Lists
*)

--let lst = tl [1, 2, 3, 4];;

--lst.[2];;

--  Test 1: Empty List
let empty = [];;

--  Test 2: Parameterization
let two_elements x y = [x, y];;

--  Test 3: Concatenation
let new_two = empty ++ (two_elements 1 2);;

--  Test 4: Get Head of List
let one = hd new_two;;

--  Test 5: Get Tail of List
let two = tl new_two;;

--  Test 6: Construction
5 :: [];;

len [one]


