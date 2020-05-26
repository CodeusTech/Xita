(*
  constants.xs
  Codeus Tech
  Authored on   February 16, 2019
  Last Modified      May 22, 2020
*)

(*
  Contains Test Case for Functional Expressions
*)


--  Constant Declarations
const Int pi = 314;;
const Int other = pi + 3;;

--  Constant Expressions
other * 32;;

--  Functional Overrides
let pi = 314 in 
  pi
;;

--  Functional Undeclare (let ... in ...)
--    Should Compile for Constant Form
pi

