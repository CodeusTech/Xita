(*
  constants.xs (Complex Types)
  Codeus Tech
  Authored on   May 26, 2020
  Last Modified May 26, 2020
*)

(*
  Contains Unit Tests for Constants of Complex Type
*)

type gender = Male | Female;;

type person = 
  Person of
    name : string,
    age  : int,
    sex  : gender
;;

const Person cody = 
  {
    name = "Cody Fagley",
    age = 27,
    sex = Male
  }



