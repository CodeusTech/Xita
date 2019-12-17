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


type node a = 
    Leaf 
  | Tree of 
      node a; a; node a;;

(* 1.b) Type Expressions

    TYPE EXPRESSIONS are instances of a declared type/constructor
*)

type person = 
  Person of 
    age     : int     = 10,
    name    : string  = "Person",
    height  : int;;


type tree a = 
  Leaf |
  Node of 
    left  : tree a, 
    value : a,
    right : tree a;;

(*
  2.) Typeclasses
*)

(*
  2.a) Typeclass Declarations
*)

Off 5;;

--  Invoke a Tree
--debug "Build an integer tree, with one right-side branch"
let some_tree = Node (left=Node (left=Leaf, value=2, right=Leaf), value=1, right=Leaf)

--  Syntactically identical structure
(*Node (
  left = Leaf, 
  value = 1, 
  right = Node (
    left = Leaf, 
    value = 1, 
    right = Leaf
  ) 
)*)


