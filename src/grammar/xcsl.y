%{
/*
  xcsl.y  (AArch64)
  Cody Fagley
  Authored on   January 29, 2019
  Last Modified February 16, 2019
*/

/*
  Contains context-free grammar used in all XCS Modules.

  Table of Contents
  ======================
  A.) Token Declarations
  B.) Order of Operations
  C.) Start of Grammar
  
  D.) Source Modules
  ----------------------
  1.) XCSL Expressions
  2.) Primitive Expressions
    2.a) Integer Expressions
    2.b) Boolean Expressions
    2.c) Real Expressions
    2.d) Character Expressions
    2.e) String Expressions
    2.f) List Expressions
  3.) Conditional Expressions
    3.a) if ... then ... else ...
    3.b) match ... with ...
    3.c) ... is ...
  4.) Functional Expressions
    4.a) Constants
    4.b) Function Declarations/Invocations
    4.c) Parameters/Arguments
  5.) Datatype Expressions
    5.a) Types
    5.b) Constructors
    5.c) Typeclass/Prototypes
    5.d) Primitive Typeclasses
  6.) Direct Memory Access (DMA)
    6.a) Read Expression from Memory
    6.b) Write Expression to Memory
  7.) Process Operations
    7.a) Build/Run
  8.) Interprocess Communication
    8.a) Process Tethers
    8.b) Send/Receive
  9.) Special Operations
    9.a) Regular Expressions

  
  E.) Tether Modules
  ----------------------
  1.) Tether Module Structure
  2.) Tether Expressions
  3.) Ask/Offer
    3.a) Offer Statements
    3.b) Ask Statements
*/

//  XCS Libraries
#include "src/ident.h"
#include "src/regex.h"
#include "src/bytecode/bytecode.h"
#include "src/conditions/conditions.h"
#include "src/functions/functions.h"
#include "src/memory/memory.h"
#include "src/modules/modules.h"
#include "src/primitives/primitives.h"
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
  A.) Token Declarations
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

//  Comments
%token COMMENT

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR                // BOOLEAN COMPARISON
%token ARROW_L ARROW_R
%token OP_SEP OP_TUP OP_ASSIGN PAR_LEFT PAR_RIGHT OP_COMMA

//  List Operators/Keywords
%token OP_LIST_L OP_LIST_R LIST_C OP_APPEND OP_LIST_CON
%token LIST_HEAD LIST_TAIL

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token CONST LET IN

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF REQ
%token OP_REC_L OP_REC_R OP_ELEMENT

//  Static Memory Manipulation
%token MEM_READ MEM_SET THIS

// Integers
%token INT_T RNG
%token U8_T U8_C I8_T I8_C 
%token U16_T U16_C I16_T I16_C
%token U32_T U32_C I32_T I32_C
%token U64_T U64_C I64_T I64_C

// Booleans
%token BOOL_T BOOL_C

// Real Numbers
%token REAL_T
%token FLOAT_T FLOAT_C DOUBLE_T DOUBLE_C

// Characters/Strings
%token CHAR_T CHAR_C
%token STRING_T STRING_C
%token BYTE_STRING  /* DEPRECATED */

// Lists
%token LIST_T LIST_C

//  Special Operations
%token BUILD RUN            //  Bytecode Operations
%token REGEX                //  Regular Expressions
%token TETHER SEND RECEIVE  //  Interprocess Communication

//  Module Operations
%token OPEN TETHER_M SOURCE_M HEADER_M
%token TETHER_H OFFER ASK

/*
  B.) Order of Operations
*/
%left OP_TUP
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left OP_SEQ


/*
  C.) Start of Grammar
*/
%start xcs
%%

xcs:
    xcs_source  {/* Source Module Structure */}
  | xcs_tether  {/* Tether Module Structure */}
;

open_source:
  OPEN SOURCE_M STRING { open_source($3); };

open_tether:
  OPEN TETHER_M STRING { open_tether($3); };

open_header:
  OPEN HEADER_M STRING { open_header($3); };

open:
    open_source { close_source(); }
  | open_tether { close_tether(); }
  | open_header { close_header(); }
;

/*
  D.) Source Modules
*/

xcs_source:
    src         { printf("Finished Parsing Source Module.\n"); }
;

src:
    src OP_SEP src
  | open     { }
  | exp
;

/*
  1.) XCSL Expressions
*/
exp:
    PAR_LEFT exp PAR_RIGHT
  | exp_if            { }
  | exp_match         { }
  | exp_is            { }
  | decl_const        { }
  | decl_funct        { }
  | exp_funct         { }
  | decl_type         { }
  | decl_typeclass    { }
  | IDENTIFIER OP_ELEMENT IDENTIFIER {printf("Element %s within %s accessed\n", $3, $1);}
  | exp_memread       { }
  | exp_memwrite      { }
  | exp_byte_build    { }
  | exp_byte_run      { }
  | exp_tether        { }
  | exp_send          { }
  | exp_receive       { }
  | exp_ask           { }
  | exp_integer       {/* For Testing */}
  | exp_boolean       {/* For Testing */}
  | exp_real          {/* For Testing */}
  | exp_char          {/* For Testing */}
  | exp_string        {/* For Testing */}
  | exp_list          { }
  | exp_regex         { }
  | exp OP_TUP exp    { add_to_tuple(); }
  | ident_construct exp {}
;

/*
  2.) Primitive Expressions
*/

/*
  2.a) Integer Expressions
*/
exp_integer:
    PAR_LEFT exp_integer PAR_RIGHT
  | exp_integer OP_ADD exp_integer    { integer_addition(); }
  | exp_integer OP_SUB exp_integer    { integer_subtraction(); }
  | exp_integer OP_MUL exp_integer    { integer_multiplication(); }
  | exp_integer OP_DIV exp_integer    { integer_division(); }
  | exp_integer OP_MOD exp_integer    { integer_modulus(); }
  | exp_integer BIT_AND exp_integer   { bitwise_and(); }
  | exp_integer BIT_OR exp_integer    { bitwise_or(); }
  | exp_integer BIT_SHL exp_integer   { bitwise_shl(); }
  | exp_integer BIT_SHR exp_integer   { bitwise_shr(); }
  | exp_integer BIT_XOR exp_integer   { bitwise_xor(); }
  | INT        {/* Push int into Register Stack */}
  | RNG        { printf("Random Number Generated\n"); }
  | IDENTIFIER {/* Treat Identifier as Integer */}
;

/*
  2.b) Boolean Expressions
*/
exp_boolean:
    exp_boolean OP_EQ  exp_boolean    { boolean_eq();  }
  | exp_boolean OP_NEQ exp_boolean    { boolean_neq(); }
  | exp_boolean OP_GT  exp_boolean    { boolean_gt();  }
  | exp_boolean OP_GTE exp_boolean    { boolean_gte(); }
  | exp_boolean OP_LT  exp_boolean    { boolean_lt();  }
  | exp_boolean OP_LTE exp_boolean    { boolean_lte(); }
  | exp_boolean BOOL_AND exp_boolean  { boolean_and(); }
  | exp_boolean BOOL_OR  exp_boolean  { boolean_or();  }
  | exp_boolean BOOL_XOR exp_boolean  { boolean_xor(); }
  | TRUE   {/* Push '1' into Register Stack */}
  | FALSE  {/* Push '0' into Register Stack */}
  | exp_integer
;

/*
  2.c) Real Expressions
*/
exp_real:
    exp_real OP_ADD exp_real     { real_addition();       }
  | exp_real OP_SUB exp_real     { real_subtraction();    }
  | exp_real OP_MUL exp_real     { real_multiplication(); }
  | exp_real OP_DIV exp_real     { real_division();       }
  | exp_real OP_ADD exp_integer  { real_addition();       }
  | exp_real OP_SUB exp_integer  { real_subtraction();    }
  | exp_real OP_MUL exp_integer  { real_multiplication(); }
  | exp_real OP_DIV exp_integer  { real_division();       }
  | exp_integer OP_ADD exp_real  { real_addition();       }
  | exp_integer OP_SUB exp_real  { real_subtraction();    }
  | exp_integer OP_MUL exp_real  { real_multiplication(); }
  | exp_integer OP_DIV exp_real  { real_division();       }
  | REAL           {/* Push real into SSE stack */}
  | FLOAT_C  REAL  {/* Push float into SSE stack */}
  | DOUBLE_C REAL  {/* Push double into SSE stack */}
;

/*
  2.d) Character Expressions
*/
exp_char:
    CHAR        { literal_char($1); }
  | CHAR_C INT  { char_from_int($2); }
;

/*
  2.e) String Expressions
*/
exp_string:
    exp_string OP_APPEND exp_string { string_append(); }
  | STRING  {/* Push pointer to string onto Register Stack */}
;

/*
  2.f) List Expressions
*/
list:
    OP_LIST_L {  }
;

exp_list:
    list param_list OP_LIST_R       { }
  | exp_list OP_APPEND exp_list     { list_append();    }
  | exp OP_LIST_CON exp_list        { list_construct(); }
  | LIST_TAIL exp_list              { list_tail();      }

;

/*
  LIST PARAMETERS
*/
param_list:
    param_list OP_COMMA param_list
  | STRING                        { add_to_list($1); }
  | exp
;

/*
  3.) Conditional Expressions
*/

/*
  3.a) if ... then ... else ...
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
  3.b) match ... with ...
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
  | param_match param_with ARROW_R exp                  {  }
;

param_match:
    ident_construct 
;

param_with: 
  IDENTIFIER param_with
  | {/* INTENTIONALLY LEFT BLANK */}
;

/*
  3.c) ... is ...
*/

exp_is:
    exp IS ident_construct  { is_construct(); }
  | exp IS ident_type       { is_type();      }
;

/*
  4.) Functional Expressions
*/

/*
  4.a) Constants
*/
const:
    CONST IDENTIFIER OF ident_type { declare_constant($2); }
;

decl_const:
    const OP_ASSIGN exp
;

/*
  4.b) Function Declarations/Invocations
*/
let:
    LET IDENTIFIER OF ident_type  { declare_function($2); }
  | LET IDENTIFIER              { declare_function($2); }
  | LET PAR_LEFT OP_ADD PAR_RIGHT     {  }
  | LET PAR_LEFT OP_SUB PAR_RIGHT     {  }
  | LET PAR_LEFT OP_MUL PAR_RIGHT     {  }
  | LET PAR_LEFT OP_DIV PAR_RIGHT     {  }
  | LET PAR_LEFT OP_APPEND PAR_RIGHT  {  }
;

/*
  FUNCTION DECLARATIONS
*/
decl_funct:
    let exp_param OP_ASSIGN exp        {}
  | let exp_param OP_ASSIGN exp IN exp {  }
;

/*
  FUNCTION EXPRESSIONS (INVOCATIONS)
*/
exp_funct:
    IDENTIFIER param_arg  { invoke_function($1); }
;

/*
  4.c) Parameters/Arguments
*/

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
  ARGUMENT EXPRESSIONS (INVOCATIONS)
*/
arg:
    exp { load_argument(); }
;

param_arg:
    arg param_arg  {/* Accept arbitrary number of arguments */}
  | {/*INTENTIONALLY LEFT BLANK*/}
;

/*
  5.) Datatype Expressions
*/

/*
    5.a) Types
*/

/*
  TYPE RECORDS
*/
record:
    record OP_COMMA record
  | IDENTIFIER OF ident_type
;

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
  | LIST_T ident_type
  | ident_type OP_TUP ident_type
  | OP_REC_L record OP_REC_R
  | IDENTIFIER
;

/*
  TYPE DECLARATIONS
*/
type:
    TYPE IDENTIFIER { declare_type($2); }
;

decl_type:
    type OP_ASSIGN exp_constructor { }
  | type OP_ASSIGN ident_type {}
;

/*
  5.b) Constructors
*/

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
  CONSTRUCTOR DECLARATIONS
*/
constructor:
  CONSTRUCTOR  { declare_constructor($1); }
;

/*
  CONSTRUCTOR EXPRESSIONS
*/
exp_constructor:
    exp_constructor BIT_OR exp_constructor  { }
  | constructor OF ident_type               { }
  | constructor                             { }
;

/*
  5.c) Typeclass/Prototypes
*/

/*
  TYPECLASS DECLARATIONS
*/
typeclass:
    TYPECLASS IDENTIFIER { declare_typeclass($2); }
;

decl_typeclass:
    typeclass REQ exp_prototype
;

/*
  PROTOTYPE EXPRESSIONS
*/
prototype:
  IDENTIFIER  { declare_proto($1); }
;

proto_comma:
  OP_COMMA { printf("\n"); }
;

exp_prototype:
    prototype param_prototype proto_comma exp_prototype { }
  | prototype param_prototype            { printf("\n"); }
;

/*
  PROTOTYPE PARAMETERS
*/
param_prototype:
    param_prototype param_prototype 
  | IDENTIFIER      { proto_param($1); }
;
    


/*
  6) Direct Memory Access (DMA)
*/

/*
  6.a) Read Expression from Memory
*/
read:
  exp_integer MEM_READ IDENTIFIER { memory_read_exp($3); }
;

exp_memread:
    read IN exp { }
  | exp_integer MEM_READ THIS
;

/*
  6.b) Write Expression to Memory
*/
exp_memwrite:
    exp_integer MEM_SET exp { memory_write_exp(); }
;


/*
  7.) Process Operations
*/

/*
  7.a) Build/Run
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
  8.) Interprocess Communication
*/

/*
  8.a) Process Tethers
*/

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
    IDENTIFIER { declare_tether_parameter($1); }
;

param_tether:
    pteth param_tether {  }
  |                   {/* INTENTIONALLY LEFT BLANK */}
;

/*
  8.b) Send/Receive
*/
exp_send:
    SEND STRING exp  { ipc_send($2); }
;

exp_receive:
    RECEIVE STRING   { ipc_receive($2); }
;


/*
  9.) Special Operations
*/

/*
  9.a) Regular Expressions
*/
exp_regex:
    REGEX STRING  { regular_expression($2); }
;




/*
  E.) Tether Modules 
*/

/*
  1.) Tether Module Structure
*/
xcs_tether:
    TETHER_H teth_sep           { printf("Finished Parsing Tether Module.\n"); }
;

teth_sep:
    teth_sep OP_SEP teth_sep
  | tether
  | open    {}
  | exp
;

/*
  2.) Tether Expressions
*/
tether:
    exp_offer                     { }
;

/*
  3.) Ask/Offer
*/

/*
  3.a) Offer Statements
*/
offer:
    OFFER IDENTIFIER                { ipc_offer($2); }
  | OFFER IDENTIFIER OF ident_type  { ipc_offer($2); }
;

exp_offer:
    offer param_offer OP_ASSIGN exp
;

param_offer:
    IDENTIFIER param_offer  {/* Function Parameters for Offer */}
  |       {/* INTENTIONALLY LEFT BLANK */}
;

/*
  3.b) Ask Statements
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
	fprintf(stderr, "\nParse error in line %d: %s\n\n", yylineno, s);
	exit(1);
}

