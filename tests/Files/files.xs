(*
  files.xs
  Cody Fagley
  Authored on   July 24, 2019
  Last Modified July 24, 2019
*)

(*
  Contains test case script for Filesystem Expressions
*)

--  Create/Open a file named fito_the_dog, with tags: dogs, spaniels
file fito dogs, spaniels : fito_the_dog;;

--  Erase old fito and write new file containing "hello"
write fito "hello";;

--  Write " world!" at the end of fito
append fito " world!";;

--  Return "Hello World!" to caller
read fito ;;

--  List of files with both 'dogs' AND 'spaniels' tags
tsearch dogs+.spaniels;;

--  Get all spaniels named fito_the_dog
search spaniels : fito_the_dog;;

--  Get all files named fito_the_dog
search fito_the_dog

