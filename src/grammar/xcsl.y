%{
/*
  xcsl.y  (AArch64)
  Cody Fagley
  Authored on   January 29, 2019
  Last Modified January 29, 2019
*/

/*
  Contains context-free grammar for X-Ita Control System Language (XCSL)

  Table of Contents
  ======================
  1.) Token Declarations
  2.) Order of Operations
  3.) Start of Grammar
*/

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);


%}

/*
  1.) Token Declarations
*/

//  Primitive Data Types
%union {
	int Int;
	float Real;
  char Char;
  char* String;
}

//  Primitive Tokens
%token<Int> INT
%token<Real> REAL
%token<Char> CHAR
%token<String> STRING
%token TRUE FALSE

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR                // BOOLEAN COMPARISON
%token OP_SEP

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token LET IN

//  Datatype Keywords
%token TYPE TYPECLASS

//  Primitive Types/Constructors
%token INT_T INT_C
%token REAL_T REAL_C
%token CHAR_T CHAR_C
%token STRING_T STRING_C


//  Constructors/Identifiers
%token CONSTRUCTOR IDENTIFIER

/*
  2.) Order of Operations
*/

%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left OP_SEQ


/*
  3.)  Start of Grammar
*/
%start exp
%%

exp: 
    INT
  | REAL
  | CHAR
  | STRING
  | bool_exp
  | exp OP_SEP exp
  | CONSTRUCTOR {/* For Testing */}
  | IDENTIFIER  {/* For Testing */}
;

bool_exp:
    TRUE
  | FALSE
;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}