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
    1.1) Primitive Types/Constructors
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
	int val_int;
	double val_real;
  char val_char;
  char* val_string;
}

//  Primitive Tokens
%token<val_int> INT
%token<val_real> REAL
%token<val_char> CHAR
%token<val_string> STRING
%token TRUE FALSE

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR                // BOOLEAN COMPARISON
%token OP_SEP OP_ASSIGN

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token CONST LET IN

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF

//  Static Memory Manipulation
%token MEM_READ MEM_SET

/*  
  1.1) Primitive Types/Constructors
*/
// Integers
%token INT_T 
%token U8_T U8_C I8_T I8_C 
%token U16_T U16_C I16_T I16_T
%token U32_T U32_C I32_T I32_T
%token U64_T U64_C I64_T I64_T

// Real Numbers
%token REAL_T REAL_C
%token FLOAT_T FLOAT_C DOUBLE_T DOUBLE_C

// Characters/Strings
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
    INT                                       {/* For Testing */}
  | REAL                                      {/* For Testing */}
  | CHAR                                      {/* For Testing */}
  | STRING                                    {/* For Testing */}
  | exp_boolean                               {/* For Testing */}
  | exp OP_SEP exp                            {/* For Testing */}
  | TYPE IDENTIFIER OP_ASSIGN exp_constructor { printf("Type Declared\n"); }
  | IDENTIFIER                                {/* For Testing */}
;

/*
  BOOLEAN EXPRESSIONS
*/
exp_boolean:
    TRUE
  | FALSE
;

/*
  CONSTRUCTOR EXPRESSIONS
*/
exp_constructor:
    CONSTRUCTOR BIT_OR exp_constructor
  | CONSTRUCTOR
;

%%

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}