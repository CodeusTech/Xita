%{
/*
  xcsl.y  (AArch64)
  Cody Fagley
  Authored on    January 29, 2019
  Last Modified    March  7, 2019
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
    5.c) Records
    5.d) Typeclass/Prototypes
    5.e) Primitive Typeclasses
  6.) Direct Memory Access (DMA)
    6.a) Read Expression from Memory
    6.b) Write Expression to Memory
  7.) Process Operations
    7.a) Build/Run
    7.b) Process Tethers
    7.c) Send/Receive
  8.) Special Operations
    8.a) Regular Expressions

  
  E.) Tether Modules
  ----------------------
  1.) Tether Module Structure
  2.) Tether Expressions
  3.) Request/Offer
    3.a) Offer Statements
    3.b) Request Statements
*/


//  Linux Libraries
#include "time.h"
#include "stdio.h"
#include "stdlib.h"

//  XCS Libraries
#include "src/bytecode/bytecode.h"
#include "src/comments/comments.h"
#include "src/conditions/conditions.h"
#include "src/gpio/gpio.h"
#include "src/grammar/status.h"
#include "src/ident/ident.h"
#include "src/memory.h"
#include "src/modules/modules.h"
#include "src/operator/operator.h"
#include "src/primitives/primitives.h"
#include "src/proc/proc.h"
#include "src/regex/regex.h"
#include "src/regstack/regstack.h"
#include "src/utils/clear.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* error);
unsigned int grammar_status = GRAMMAR_RUNNING;


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
  char* val_doc;
}

//  Primitive Tokens
%token<val_int> INT
%token<val_real> REAL
%token<val_char> CHAR
%token<val_string> STRING
%token<val_ident> IDENTIFIER CONSTRUCTOR
%token<val_doc> DOC
%token TRUE FALSE

//  Comments
%token COMMENT DOC_NEWLINE REFERENCE

//  Override Operators
%token OP_ADD_O OP_SUB_O OP_MUL_O OP_DIV_O OP_MOD_O  // INTEGER ARITHMETIC
%token OP_GTE_O OP_GT_O OP_EQ_O OP_NEQ_O OP_LTE_O OP_LT_O // INTEGER COMPARISON
%token BIT_AND_O BIT_OR_O BIT_XOR_O BIT_SHR_O BIT_SHL_O // BITWISE MANIPULATION
%token BOOL_OR_O BOOL_AND_O BOOL_XOR_O                  // BOOLEAN COMPARISON
%token ARROW_L_O ARROW_R_O
%token OP_APPEND_O OP_LIST_CON_O
%token MEM_READ_O MEM_SET_O

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR                // BOOLEAN COMPARISON
%token ARROW_L ARROW_R
%token OP_SEP OP_TUP OP_ASSIGN PAR_LEFT PAR_RIGHT OP_COMMA

//  List Operators/Keywords
%token OP_LIST_L OP_LIST_R LIST_C LIST_T OP_APPEND OP_LIST_CON
%token LIST_HEAD LIST_TAIL

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token CONST LET IN

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF REQ IMPL
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

//  Special Operations
%token BUILD RUN            //  Bytecode Operations
%token REGEX                //  Regular Expressions
%token TETHER SEND RECEIVE  //  Interprocess Communication
%token CLEAR                //  Clear Terminal

//  Module Operations
%token OPEN SOURCE_M HEADER_M TETHER_M
%token SOURCE_H HEADER_H TETHER_H 

//  Tether Module-Specific Operations
%token OFFER REQUEST

/*
  B.) Order of Operations
*/
%left REAL INT
%left OP_TUP
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left PAR_LEFT PAR_RIGHT
%left OP_SEQ

/*
  C.) Start of Grammar
*/
%start xcs
%%
ref_com:
    DOC { decl_ref_comment($1); }
;

xcs:
    ref_com xcs { }
  | xcs_source  {/* Source Module Structure */}
  | xcs_tether  {/* Tether Module Structure */}
;

open_source:
  OPEN SOURCE_M STRING { open_source($3); }
;

open_tether:
  OPEN TETHER_M STRING { open_tether($3); }
;

open_header:
  OPEN HEADER_M STRING { open_header($3); }
;

open:
    open_source {  }
  | open_tether {  }
  | open_header {  }
;

/*
  D.) Source Modules
*/

xcs_source:
    src         { source_end(); }
;


src:
    src OP_SEP src  {}
  | open     { }
  | exp  { curr_reg = 0; }
;

/*
  1.) XCSL Expressions
*/
exp:
    PAR_LEFT exp PAR_RIGHT
  | exp_if              { }
  | exp_is              { }
  | exp_match           { }
  | exp OP_ADD exp      { infer_addition(); }
  | exp OP_SUB exp      { infer_subtraction(); }
  | exp OP_MUL exp      { infer_multiplication(); }
  | exp OP_DIV exp      { infer_division(); }
  | exp OP_MOD exp      { infer_modulus(); }
  | exp BOOL_AND exp    { infer_bool_and(); }
  | exp BOOL_OR exp     { infer_bool_or();  }
  | exp BOOL_XOR exp    { infer_bool_xor(); }
  | exp BIT_AND exp     { infer_bit_and(); }
  | exp BIT_OR exp      { infer_bit_or(); }
  | exp BIT_XOR exp     { infer_bit_xor(); }
  | exp BIT_SHL exp     { infer_bit_shl(); }
  | exp BIT_SHR exp     { infer_bit_shr(); }
  | exp OP_LT exp       { infer_bool_lt(); }
  | exp OP_LTE exp      { infer_bool_lte(); }
  | exp OP_GT exp       { infer_bool_gt(); }
  | exp OP_GTE exp      { infer_bool_gte(); }
  | exp OP_EQ exp       { infer_bool_eq(); }
  | exp OP_NEQ exp      { infer_bool_neq(); }
  | exp OP_APPEND exp   { infer_append(); }
  | exp OP_LIST_CON exp { infer_list_con(); }
  | exp_integer         {/* For Testing */}
  | exp_boolean         {/* For Testing */}
  | exp_real            {/* For Testing */}
  | exp_char            {/* For Testing */}
  | exp_string          {/* For Testing */}
  | exp_list            { }
  | exp_regex           { }
  | decl_const          { }
  | decl_funct          { }
  | decl_type           { }
  | decl_typeclass      { }
  | exp_funct           { }
  | IDENTIFIER          { printf("Type Inferred: %s\n", $1); }
  | exp_construct       { }
  | exp OP_ELEMENT exp_record  { printf("Record Accessed\n"); }
  | exp_memread         { }
  | exp_memwrite        { }
  | exp_byte_build      { }
  | exp_byte_run        { }
  | exp_tether          { }
  | exp_send            { }
  | exp_receive         { }
  | exp_request         { }
  | exp OP_TUP exp      { add_to_tuple(); }
  | REFERENCE IDENTIFIER  { exp_ref_comment(); }
  | CLEAR               { clear_terminal(); }
;

/*
  2.) Primitive Expressions
*/

/*
  2.a) Integer Expressions
*/
exp_integer:
    RNG        { rng(); }
  | INT  
    { 
      last_data = (void*) (long) $1; 
      last_type = TYPE_INTEGER;
      push_int((long) last_data);   
    }
;

/*
  2.b) Boolean Expressions
*/
exp_boolean:
    TRUE   { push_int(1); }
  | FALSE  { push_int(0); }
;

/*
  2.c) Real Expressions
*/
exp_real:
    FLOAT_C REAL  { push_real_lit($2); }
  | DOUBLE_C REAL { push_real_lit($2); }
  | REAL          { push_real_lit($1); }
;

/*
  2.d) Character Expressions
*/
exp_char:
    CHAR        { last_data = (void*) (unsigned long) $1; push_char_lit((unsigned char) $1); }
  | CHAR_C INT  { last_data = (void*) (unsigned long) $2; push_char_int((unsigned char) $2); }
;

/*
  2.e) String Expressions
*/
exp_string:
    exp_string OP_APPEND exp_string { string_append(); }
  | STRING  { last_data = $1; push_int(1); /*Push String to Register Stack*/ }
;

/*
  2.f) List Expressions
*/
list:
    OP_LIST_L {  }
;

exp_list:
    list param_list OP_LIST_R  { }
  | exp OP_LIST_CON exp_list   { }
  | LIST_TAIL exp_list         { list_tail(); }
  | OP_LIST_L OP_LIST_R        { }

;

/*
  LIST PARAMETERS
*/
param_list:
    param_list OP_COMMA param_list
  | exp { decl_list(); }
;

/*
  3.) Conditional Expressions
*/

/*
  3.a) if ... then ... else ...
*/
//  IF ...
//  HELPER FUNCTION
if1:
  IF      { decl_if(); };
// CALLABLE FUNCTION
if:
  if1 exp { exp_if(); };

//  THEN ...
//  HELPER FUNCTION
then1:
  THEN      { decl_then(); };
// CALLABLE FUNCTION
then:
  then1 exp { exp_then(); };

//  ELSE ...
//  HELPER FUNCTION
else1:
  ELSE      { decl_else(); };
// CALLABLE FUNCTION
else:
  else1 exp { exp_else(); };

exp_if:
    if then else { exp_if_then_else(); }
;

/*
  3.b) match ... with ...
*/
match1:
    MATCH { decl_match(); };
match:
    match1 exp { exp_match(); };

with1:
    WITH { decl_with(); } ;
with:
    with1 exp_with { exp_with(); };

exp_match:
    match with { exp_match_with(); };

exp_with:
    param_match ARROW_R exp OP_COMMA exp_with  { }
  | param_match ARROW_R exp                    { }
;

param_match:
    exp       {/* Check for Equivalence */}
;


/*
  3.c) ... is ...
*/

exp_is:
    exp IS exp_construct  { is_construct(); }
  | exp IS exp_type       { is_type();      }
;

/*
  4.) Functional Expressions
*/

/*
  4.a) Constants
*/
decl_const:
    CONST IDENTIFIER OF exp_type OP_ASSIGN exp  { decl_constant($2); }
  | CONST exp_construct {}
;

/*
  4.b) Function Declarations/Invocations
*/
pre_let:
    ref_com let
  | let
;

let:
    LET IDENTIFIER OF exp_type  { decl_function($2); }
  | LET IDENTIFIER              { decl_function($2); }
  | LET OP_ADD_O                { override_add(); }
  | LET OP_SUB_O                { override_sub(); }
  | LET OP_MUL_O                { override_mul(); }
  | LET OP_DIV_O                { override_div(); }
  | LET OP_MOD_O                { override_mod(); }
  | LET BOOL_AND_O              { override_bool_and(); }
  | LET BOOL_OR_O               { override_bool_or(); }
  | LET BOOL_XOR_O              { override_bool_xor(); }
  | LET BIT_AND_O               { override_bit_and(); }
  | LET BIT_OR_O                { override_bit_or(); }
  | LET BIT_XOR_O               { override_bit_xor(); }
  | LET BIT_SHL_O               { override_bit_shl(); }
  | LET BIT_SHR_O               { override_bit_shr(); }
  | LET OP_LT_O                 { override_lt(); }
  | LET OP_LTE_O                { override_lte(); }
  | LET OP_GT_O                 { override_gt(); }
  | LET OP_GTE_O                { override_gte(); }
  | LET OP_EQ_O                 { override_eq(); }
  | LET OP_NEQ_O                { override_neq(); }
  | LET OP_APPEND_O             { override_append(); }
  | LET OP_LIST_CON_O           { override_list_con(); }
;

/*
  FUNCTION DECLARATIONS
*/
decl_funct:
    pre_let exp_param OP_ASSIGN exp IN exp { decl2_function(); }
  | pre_let exp_param OP_ASSIGN exp        { decl2_function(); }
;

/*
  FUNCTION EXPRESSIONS (INVOCATIONS)
*/
exp_funct:
    IDENTIFIER param_arg  { exp_function($1); }
;

/*
  4.c) Parameters/Arguments
*/

/*
  PARAMETER EXPRESSIONS (DECLARATIONS)
*/
param:
    IDENTIFIER { decl_parameter($1); }
;

exp_param:
    param exp_param  { }
  | {/* INTENTIONALLY LEFT BLANK */}
;

/*
  ARGUMENT EXPRESSIONS (INVOCATIONS)
*/
arg:
    exp { load_argument(scope_curr); }
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
  TYPE IDENTIFIERS
*/
exp_type:
    exp_type exp_type
  | INT_T             { last_type = 2;  }
  | U8_T              { last_type = 3;  }
  | I8_T              { last_type = 4;  }
  | U16_T             { last_type = 5;  }
  | I16_T             { last_type = 6;  }
  | U32_T             { last_type = 7;  }
  | I32_T             { last_type = 8;  }
  | U64_T             { last_type = 9;  }
  | I64_T             { last_type = 10; }
  | REAL_T            { last_type = 11; }
  | FLOAT_T           { last_type = 12; }
  | DOUBLE_T          { last_type = 13; }
  | BOOL_T            { last_type = 14; }
  | CHAR_T            { last_type = 15; }
  | STRING_T          { last_type = 16; }
  | LIST_T            { last_type = 17; }
  | exp_type OP_TUP exp_type { printf("Implement Me\n"); }
  | OP_REC_L record OP_REC_R { printf("Implement Me\n"); }
  | IDENTIFIER        { last_type = find_type($1); }
;

/*
  TYPE DECLARATIONS
*/
dinit_type: 
  TYPE IDENTIFIER  {/* Declare Identifier as Type and Refresh Buffers */}
;

decl_type:
  dinit_type param_type OP_ASSIGN decl_construct implements
;

implements:
    IMPL l_typeclass
  | 
;

l_typeclass:
    IDENTIFIER OP_COMMA l_typeclass  {printf("Typeclass %s Implemented\n", $1);}
  | IDENTIFIER                       {printf("Typeclass %s Implemented\n", $1);}
;

param_type:
    IDENTIFIER param_type     {printf("Type Parameter '%s' Encountered\n", $1); }
  | {/* Intentionally Left Blank */}
;

/*
  5.b) Constructors
*/

/*
  CONSTRUCTOR IDENTIFIERS
*/
exp_construct:
    INT
  | U8_C exp
  | I8_C exp
  | U16_C exp
  | I16_C exp
  | U32_C exp
  | I32_C exp
  | U64_C exp
  | I64_C exp
  | REAL
  | FLOAT_C exp
  | DOUBLE_C exp
  | CHAR_C exp
  | TRUE
  | FALSE
//| STRING_C exp
  | CONSTRUCTOR exp {exp_constructor($1);}
  | CONSTRUCTOR     {exp_constructor($1);}
;

decl_construct:
  | decl_construct BIT_OR decl_construct
  | CONSTRUCTOR OF exp_type { decl_constructor($1); }
  | CONSTRUCTOR             { decl_constructor($1); }
  | exp_type                {  }
;

/*
  5.c) Records
*/

/*
  TYPE RECORDS
*/
record:
    record OP_COMMA record
  | IDENTIFIER OF exp_type    { decl_element($1); }
;

exp_record:
    exp OP_ELEMENT exp_record  {}
  | IDENTIFIER { exp_element($1); }
;

/*
  5.d) Typeclass/Prototypes
*/

/*
  TYPECLASS DECLARATIONS
*/
typeclass:
    TYPECLASS IDENTIFIER { decl_typeclass($2); }
;

decl_typeclass:
    typeclass REQ exp_prototype
; 

exp_typeclass:
    IDENTIFIER
;


/*
  PROTOTYPE EXPRESSIONS
*/
prototype:
  IDENTIFIER  { decl_proto($1); }
  | OP_ADD_O     { decl_proto("(+)"); }
  | OP_SUB_O     { decl_proto("(-)"); }
  | OP_MUL_O     { decl_proto("(*)"); }
  | OP_DIV_O     { decl_proto("(/)"); }
  | OP_MOD_O     { decl_proto("(%)"); }
  | BOOL_AND_O   { decl_proto("(&&)"); }
  | BOOL_OR_O    { decl_proto("(||)"); }
  | BOOL_XOR_O   { decl_proto("(^^)"); }
  | BIT_AND_O    { decl_proto("(&)"); }
  | BIT_OR_O     { decl_proto("(|)"); }
  | BIT_XOR_O    { decl_proto("(^)"); }
  | BIT_SHL_O    { decl_proto("(<<)"); }
  | BIT_SHR_O    { decl_proto("(>>)"); }
  | OP_LT_O      { decl_proto("(<)"); }
  | OP_LTE_O     { decl_proto("(<=)"); }
  | OP_GT_O      { decl_proto("(>)"); }
  | OP_GTE_O     { decl_proto("(>=)"); }
  | OP_EQ_O      { decl_proto("(==)"); }
  | OP_NEQ_O     { decl_proto("(!=)"); }
  | OP_APPEND_O  { decl_proto("(++)"); }
  | OP_LIST_CON_O{ decl_proto("(:)"); }
;

proto_comma:
  OP_COMMA { printf("\n"); }
;

exp_prototype:
    exp_prototype proto_comma exp_prototype      { }
  | prototype param_prototype OP_ASSIGN exp_type { printf("\n"); }
;

/*
  PROTOTYPE PARAMETERS
*/
param_prototype:
    param_prototype param_prototype 
  | exp_type      {/* param_proto($1); */}
;
    

/*
  5.e) Primitive Typeclasses
*/

/*
  7) Direct Memory Access (DMA)
*/

/*
  6.a) Read Expression from Memory
*/
read:
  exp MEM_READ IDENTIFIER { memory_read_exp($3); }
;

exp_memread:
    read IN exp { }
  | exp MEM_READ THIS
;

/*
  6.b) Write Expression to Memory
*/
exp_memwrite:
    exp MEM_SET exp { memory_write_exp(); }
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
    BUILD IDENTIFIER { build_header($2); }
;

/*
  RUN EXECUTABLE BYTECODE STRING
*/
exp_byte_run:
    RUN STRING { run_bytestring($2); }
;

/*
  7.b) Process Tethers
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
  7.c) Send/Receive
*/
exp_send:
    SEND IDENTIFIER exp  { exp_send($2); }
;

exp_receive:
    RECEIVE IDENTIFIER   { exp_receive($2); }
;


/*
  8.) Special Operations
*/

/*
  8.a) Regular Expressions
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
  3.) Request/Offer
*/

/*
  3.a) Offer Statements
*/
offer:
    OFFER IDENTIFIER              { decl_offer($2); }
  | OFFER IDENTIFIER OF exp_type  { decl_offer($2); }
;

exp_offer:
    offer param_offer OP_ASSIGN exp
;

param_offer:
    IDENTIFIER param_offer  {/* Function Parameters for Offer */}
  |       {/* INTENTIONALLY LEFT BLANK */}
;

/*
  3.b) Request Statements
*/
exp_request:
    REQUEST IDENTIFIER arg_request { exp_request($2); }
;

arg_request:
    exp arg_request
  |       {/* INTENTIONALLY LEFT BLANK */}
;

%%

/*
  GENERIC ERROR MESSAGE
*/
void yyerror(const char* error) {
	fprintf(stderr, "\nParse error in line %d: %s\n\n", yylineno, error);

  //  TODO: DEALLOCATE ALL BUFFERS
  
  rs_end();

	exit(grammar_status);
}

