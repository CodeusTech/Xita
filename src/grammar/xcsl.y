%{
/*
  xcsl.y  (AArch64)
  Cody Fagley
  Authored on   January 29, 2019
  Last Modified February 10, 2019
*/

/*
  Contains context-free grammar used in all XCS Modules.

  Table of Contents
  ======================
  1.) Token Declarations
  2.) Order of Operations
  3.) Start of Grammar
  4.) XCSL Expressions
  5.) Primitive Expressions
  6.) Conditional Expressions
  7.) Functional Expressions
  8.) Datatype Expressions
  9.) Special Operations
  
  A.) Tether Module Expressions 
*/

//  XCS Libraries
#include "src/regex.h"
#include "src/bytecode/bytecode.h"
#include "src/conditions/conditions.h"
#include "src/functions/functions.h"
#include "src/tethers/tethers.h"
#include "src/types/types.h"

//  Linux Libraries
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

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
  char* val_ident;
}

//  Primitive Tokens
%token<val_int> INT
%token<val_real> REAL
%token<val_char> CHAR
%token<val_string> STRING
%token<val_ident> IDENTIFIER CONSTRUCTOR
%token TRUE FALSE

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR                // BOOLEAN COMPARISON
%token ARROW_L ARROW_R
%token OP_SEP OP_TUP OP_ASSIGN PAR_LEFT PAR_RIGHT OP_COMMA
%token OP_LIST_L OP_LIST_R

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token CONST LET IN

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF REQ

//  Static Memory Manipulation
%token MEM_READ MEM_SET

// Integers
%token INT_T RNG
%token U8_T U8_C I8_T I8_C 
%token U16_T U16_C I16_T I16_C
%token U32_T U32_C I32_T I32_C
%token U64_T U64_C I64_T I64_C

// Real Numbers
%token REAL_T
%token FLOAT_T FLOAT_C DOUBLE_T DOUBLE_C

// Characters/Strings
%token CHAR_T CHAR_C
%token STRING_T STRING_C
%token BYTE_STRING  // DEPRECATED

// Booleans
%token BOOL_T

//  Special Operations
%token BUILD RUN            //  Bytecode Operations
%token REGEX                //  Regular Expressions
%token TETHER SEND RECEIVE  //  Interprocess Communication

//  Module Operations
%token LOAD
%token TETHER_H OFFER ASK

/*
  2.) Order of Operations
*/
%left OP_TUP
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left OP_SEQ


/*
  3.)  Start of Grammar
*/
%start xcs
%%

xcs:
    xcs_source  {/* Source Module Structure */}
  | xcs_tether  {/* Tether Module Structure */}
;

xcs_source:
    src             { printf("Finished Parsing Source Module.\n"); }
;

src:
    src OP_SEP src
  | exp
  | LOAD STRING     { printf("Module %s Loaded\n", $2); }
;

/*
  4.) XCSL Expressions
*/
exp:
    exp_integer       {/* For Testing */}
  | exp_real          {/* For Testing */}
  | exp_char          {/* For Testing */}
  | exp_string        {/* For Testing */}
  | exp_boolean       {/* For Testing */}
  | exp_byte_build    { }
  | exp_byte_run      { }
  | exp_tether        { }
  | exp_send          { }
  | exp_receive       { }
  | exp_ask           { }
  | exp_regex         { }
  | decl_funct        { }
  | exp_funct         { printf("Function Invoked\n");           }
  | exp_const         { }
  | exp_type          { }
  | exp_typeclass     { }
  | exp_if            { }
  | exp_match         { }
  | exp_list          { }
  | exp OP_TUP exp    { add_to_tuple(); }
  | IDENTIFIER        { printf("Found Identifier: %s\n", $1);   }
;

/*
  5.) Primitive Expressions
*/

/*
  INTEGER EXPRESSIONS
*/
exp_integer:
    exp_integer OP_ADD exp_integer 
  | exp_integer OP_SUB exp_integer
  | exp_integer OP_MUL exp_integer
  | exp_integer OP_DIV exp_integer
  | exp_integer OP_MOD exp_integer
  | exp_integer BIT_AND exp_integer
  | exp_integer BIT_OR exp_integer
  | exp_integer BIT_SHL exp_integer
  | exp_integer BIT_SHR exp_integer
  | exp_integer BIT_XOR exp_integer
  | INT        {/* Push int into Register Stack */}
  | U8_C  INT  {/* Push int into Register Stack */}
  | I8_C  INT  {/* Push int into Register Stack */}
  | U16_C INT  {/* Push int into Register Stack */}
  | I16_C INT  {/* Push int into Register Stack */}
  | U32_C INT  {/* Push int into Register Stack */}
  | I32_C INT  {/* Push int into Register Stack */}
  | U64_C INT  {/* Push int into Register Stack */}
  | I64_C INT  {/* Push int into Register Stack */}
  | RNG        { printf("Random Number Generated\n"); }
  | IDENTIFIER {/* Push ident into Register Stack */}
;

/*
  BOOLEAN EXPRESSIONS
*/
exp_boolean:
    exp_integer OP_EQ  exp_integer
  | exp_integer OP_NEQ exp_integer
  | exp_integer OP_GT  exp_integer
  | exp_integer OP_GTE exp_integer
  | exp_integer OP_LT  exp_integer
  | exp_integer OP_LTE exp_integer
  | exp_integer BOOL_AND exp_integer
  | exp_integer BOOL_OR  exp_integer
  | exp_integer BOOL_XOR exp_integer
  | exp_boolean BOOL_AND exp_boolean
  | exp_boolean BOOL_OR  exp_boolean
  | exp_boolean BOOL_XOR exp_boolean
  | TRUE   {/* Push '1' into Register Stack */}
  | FALSE  {/* Push '0' into Register Stack */}
;

/*
  REAL EXPRESSIONS
*/
exp_real:
    exp_number OP_ADD exp_number 
  | exp_number OP_SUB exp_number
  | exp_number OP_MUL exp_number
  | exp_number OP_DIV exp_number
  | REAL           {/* Push real into SSE stack */}
  | FLOAT_C  REAL  {/* Push float into SSE stack */}
  | DOUBLE_C REAL  {/* Push double into SSE stack */}
;

/*
  CHARACTER EXPRESSIONS
*/
exp_char:
    CHAR        {/* Push Character onto Register Stack */}
  | CHAR_C INT  {/* Convert Integer to Character using ASCII Code */}
;

/*
  STRING EXPRESSIONS
*/
exp_string:
    STRING  {/* Push pointer to string onto Register Stack */}
;

/*
  LIST EXPRESSIONS
*/
list:
    OP_LIST_L {  }
;

exp_list:
    OP_LIST_L param_list OP_LIST_R { printf("have been added to list\n"); }
;

/*
  LIST PARAMETERS
*/
param_list:
    param_list OP_COMMA param_list
  | STRING                        { add_to_list($1); }
;

/*
  6.) Conditional Expressions
*/

/*
  IF ... THEN ... ELSE ... EXPRESSIONS
*/
if:
  IF exp_boolean { if_statement(); }
;

then:
  THEN exp { then_statement(); }
;

else:
  ELSE exp { else_statement(); }
;

exp_if:
    if then else {  }
;

/*
  MATCH ... WITH ... EXPRESSIONS
*/
match:
    MATCH IDENTIFIER { match_statement(); }
;

with:
    WITH  { with_statement(); }
;

exp_match:
    match with exp_with { conclude_match(); }
;

exp_with:
    param_match param_with ARROW_R exp OP_COMMA exp_with  {  }
  | param_match param_with ARROW_R exp                    {  }
;

param_match:
    ident_construct 
;

param_with: 
  IDENTIFIER param_with
  | {/* INTENTIONALLY LEFT BLANK */}
;

/*
  7.) Functional Expressions
*/

/*
  CONSTANT EXPRESSIONS
*/
const:
    CONST IDENTIFIER OF ident_type { declare_constant($2); }
;

exp_const:
    const OP_ASSIGN exp
;

/*
  FUNCTION DECLARATIONS
*/
let:
  LET IDENTIFIER { declare_function($2); }
;

decl_funct:
    let exp_param OP_ASSIGN exp
      {}
  | let OF IDENTIFIER exp_param OP_ASSIGN exp
      {}
;

/*
  PARAMETER EXPRESSIONS (DECLARATIONS)
*/
param:
    IDENTIFIER { declare_parameter($1); }
;

exp_param:
    param exp_param  { }
  | {/* INTENTIONALLY LEFT BLANK */}
;


/*
  FUNCTION EXPRESSIONS (INVOCATIONS)
*/
exp_funct:
    IDENTIFIER param_arg
;

/*
  ARGUMENT EXPRESSIONS (INVOCATIONS)
*/
param_arg:
    exp param_arg  {/* Accept arbitrary number of arguments */}
  | {/*INTENTIONALLY LEFT BLANK*/}
;

/*
  8.) Datatype Expressions
*/

/*
  TYPE IDENTIFIERS
*/
ident_type:
    INT_T
  | U8_T
  | I8_T
  | U16_T
  | I16_T
  | U32_T
  | I32_T
  | U64_T
  | I64_T
  | REAL_T
  | FLOAT_T
  | DOUBLE_T
  | CHAR_T
  | STRING_T
  | BOOL_T
  | IDENTIFIER
;

/*
  CONSTRUCTOR IDENTIFIERS
*/
ident_construct:
    INT
  | U8_C
  | I8_C
  | U16_C
  | I16_C
  | U32_C
  | I32_C
  | U64_C
  | I64_C
  | REAL
  | FLOAT_C
  | DOUBLE_C
  | CHAR_C
  | TRUE
  | FALSE
  | STRING_C
  | CONSTRUCTOR
;

/*
  TYPE DECLARATIONS
*/
type:
    TYPE IDENTIFIER { declare_type($2); }
;

exp_type:
    type OP_ASSIGN exp_constructor { }
;

/*
  CONSTRUCTOR EXPRESSIONS
*/
constructor:
  CONSTRUCTOR  { declare_constructor($1); }
;

exp_constructor:
    constructor BIT_OR exp_constructor  { }
  | constructor                         { }
;

/*
  TYPECLASS DECLARATIONS
*/
typeclass:
    TYPECLASS IDENTIFIER { declare_typeclass($2); }
;

exp_typeclass:
    typeclass REQ exp_prototype
;

/*
  PROTOTYPE EXPRESSIONS
*/
exp_prototype:
    exp_prototype OP_COMMA exp_prototype  {/* Arbitrary Number of Function Prototypes */}
  | IDENTIFIER param_prototype            {/* Each Function must be implemented by all members of the typeclass */}
;

/*
  PROTOTYPE PARAMETERS
*/
param_prototype:
    IDENTIFIER param_prototype  {/* Prototype Parameters */}
  |                             {/* INTENTIONALLY LEFT BLANK */}
;

/*
  TYPECLASSES IDENTIFIERS
*/
exp_number:
    exp_real
  | exp_integer
;
    


/*
  9.) Special Operations
*/

/*
  BUILD EXECUTABLE BYTECODE STRING
*/
exp_byte_build:
    BUILD IDENTIFIER { build_bytestring($2); }
;

/*
  RUN EXECUTABLE BYTECODE STRING
*/
exp_byte_run:
    RUN STRING { run_bytestring($2); }
;

/*
  TETHER EXPRESSIONS
*/

exp_tether:
    TETHER param_tether { create_process_tether(); }
;

/*
  TETHER PARAMETERS
*/
pteth:
    IDENTIFIER { add_tether_parameter($1); }
;

param_tether:
    pteth param_tether {  }
  |                   {/* INTENTIONALLY LEFT BLANK */}
;

/*
  REGULAR EXPRESSIONS
*/
exp_regex:
    REGEX STRING  { regular_expression($2); }
;


/*
  INTERPROCESS COMMUNICATION
*/
exp_send:
    SEND STRING exp  { ipc_send($2); }
;

exp_receive:
    RECEIVE STRING   { ipc_receive($2); }
;

/*
  A.) Tether Module Expressions 
*/

/*
  TETHER MODULE STRUCTURE
*/
xcs_tether:
    TETHER_H teth_sep           { printf("Finished Parsing Tether Module.\n"); }
;

teth_sep:
    teth_sep OP_SEP teth_sep
  | tether
  | exp
;

/*
  TETHER EXPRESSIONS
*/
tether:
    exp_offer                     { }
;

/*
  OFFERING EXPRESSIONS/PARAMETERS
*/
offer:
    OFFER IDENTIFIER { ipc_offer($2); }
;

exp_offer:
    offer param_offer OP_ASSIGN exp
;

param_offer:
    IDENTIFIER param_offer  {/* Function Parameters for Offer */}
  |       {/* INTENTIONALLY LEFT BLANK */}
;

/*
  ASK EXPRESSIONS/PARAMETERS
*/
exp_ask:
    ASK CONSTRUCTOR IDENTIFIER arg_ask { ipc_ask($2, $3); }
;

arg_ask:
    exp arg_ask
  |       {/* INTENTIONALLY LEFT BLANK */}
;

%%

/*
  GENERIC ERROR MESSAGE
*/
void yyerror(const char* s) {
	fprintf(stderr, "Parse error in line %d: %s\n", yylineno, s);
	exit(1);
}

