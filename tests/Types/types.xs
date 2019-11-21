(*
  types.xs
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified     July 15, 2019
*)

(*
  Test Cases for Types, Typeclasses, etc.

  Table of Contents
  =================
  1.) Types
    1.a) Type Declarations
    1.b) Type Expressions
  2.) Typeclasses
    2.a) Typeclass Declarations
*)

(*
  1.) Types
*)

(* 1.a) Type Declarations

    TYPE DECLARATIONS allow peristant use of a type/data structure within the
  declaring module and any importing modules.
*)

type flow = int | real;;
type dog = Bulldog | Poodle;;
type switch =
    On of flow
  | Off;;

(*
type node a = 
    Leaf 
  | Tree of (node a), a, (node a);;

(* 1.b) Type Expressions

    TYPE EXPRESSIONS are instances of a declared type/constructor
*)

type person = 
  Person of 
    age of int,
    name of string,
    height of int;;


type tree a = 
  Leaf |
  Node of 
    left of (tree a), 
    value of a,
    right of (tree a);;

(*
  2.) Typeclasses
*)

(*
  2.a) Typeclass Declarations
*)

Off 5;;

--  Invoke a Tree
Leaf
