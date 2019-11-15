%{
/*
  xcsl.y  (AArch64)
  Cody Fagley
  Authored on    January 29, 2019
  Last Modified     July 21, 2019
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
  
  I. DECLARATIONS

  1.) Top-Level Expressions

  ----------------------

  II. EXPRESSIONS
  
  1.) XCSL Expressions
  2.) Primitive Expressions
    2.a) Integer Expressions
    2.b) Boolean Expressions
    2.c) Real Expressions
    2.d) Character Expressions
    2.e) String Expressions
    2.f) List Expressions
  3.) Basic Operations
    3.a) Arithmetic Expressions
    3.b) Logical Expressions
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
#include <xcs/bytecode/bytecode.h>
#include <xcs/comments/comments.h>
#include <xcs/conditions/conditions.h>
#include <xcs/grammar/status.h>
#include <xcs/ident/ident.h>
#include <xcs/memory.h>
#include <xcs/modules/modules.h>
#include <xcs/operator/operator.h>
#include <xcs/primitives/primitives.h>
#include <xcs/proc/proc.h>
#include <xcs/regex/regex.h>
#include <xcs/regstack/regstack.h>
#include <xcs/utils/clear.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* error);
unsigned int grammar_status = GRAMMAR_RUNNING;

extern Scope xcs_args;


%}

/*
  A.) Token Declarations
*/

//  Primitive Data Types
%union {
	long long val_int;
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
%token OP_INLINE

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF REQ IMPL SIZEOF
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

//  Filesystem Operations
%token FILEK REMOVE
%token READ WRITE APPEND
%token SEARCH TSEARCH
%token COPY MOVE RETAG

//  Special Operations
%token BUILD RUN            //  Bytecode Operations
%token REGEX                //  Regular Expressions
%token TETHER SEND RECEIVE  //  Interprocess Communication

//  Utilities
%token CLEAR DELAY         
%token DEBUG DEBUG_PRINT 

//  Module Operations
%token OPEN SOURCE_M HEADER_M TETHER_M
%token SOURCE_H HEADER_H TETHER_H 

//  Tether Module-Specific Operations
%token OFFER REQUEST

/*
  B.) Order of Operations
*/
//  High-Order Operations
%left OP_ASSIGN OP_INLINE
%left BUILD CLEAR
%left LET
%left TYPE TYPECLASS REQUIRES
%left FILEK

%left OP_ELEMENT OP_COMMA

//  Memory Operations
%left MEM_READ MEM_SET

//  List Operations
%left OP_APPEND LIST_HEAD LIST_TAIL

//  Constructors
%left CONSTRUCTOR
%left U8 I8 U16 I16 U32 I32 U64 I64 FLOAT_C DOUBLE_C STRING_C CHAR_C



//  Override Operators
%left OP_LT_O OP_LTE_O OP_GT_O OP_GTE_O OP_EQ_O OP_NEQ_O BOOL_AND_O BOOL_OR_O BOOL_XOR_O 
%left BIT_AND_O BIT_OR_O BIT_XOR_O 
%left OP_ADD_O OP_SUB_O OP_DIV_O OP_MUL_O OP_MOD_O OP_APPEND_O OP_LIST_CON_O
%left MEM_READ_O MEM_SET_O ARROW_L_O ARROW_R_O 

//  Literal Operations
%left IDENTIFIER
%left REAL INT TRUE FALSE
%left BOOL_AND BOOL_OR BOOL_XOR OP_LT OP_GT OP_LTE OP_GTE OP_EQ OP_NEQ IS

//  Operator Arithmetic
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left BIT_AND BIT_OR BIT_SHL BIT_SHR BIT_XOR

%left IN

//  Order Keepers
%left OP_LIST_L OP_LIST_R
%left OP_REC_L OP_REC_R
%left PAR_LEFT PAR_RIGHT

//  Seperators
%left OP_TUP
%left OP_SEQ

%type <val_int> if if1 then else1

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
  | src  { }
  | xcs_tether  {/* Tether Module Structure */}
;

/*
  D.) Source Modules
*/
src2:
    decl    { end_scope();  }
  | exp     { end_scope();  } 
;

src:
    src2 OP_SEP src
  | src2  
;


/*
    I. DECLARATIONS
*/

/*
  I.1.) Top-Level Declarations
*/
decl:
    decl_const          
  | decl_funct   
  | decl_type           
  | decl_typeclass      
  | decl_open
  | decl_fnew
;

/*
  4.) External Module Declarations
*/
decl_open:
    open_source
  | open_tether
  | open_header
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



/*
    II. EXPRESSIONS
*/

/*
  II.1.) Top-Level Expressions
*/
exp:
    PAR_LEFT exp PAR_RIGHT
  | DELAY exp exp  
  | DEBUG STRING        { printf("%s\n", $2); }
  | DEBUG_PRINT IDENTIFIER { print_debug_message($2); }
  | exp OP_ELEMENT OP_LIST_L exp OP_LIST_R { printf("ARRAY/LIST ELEMENT ACCESSED\n"); }
  | exp_primitive
  | exp_arith
  | exp_logical
  | exp_conditional
  | exp_funct           {printf("function declared\n");}
  | exp_regex       
  | exp_request   
  | exp_memIO
  | exp_ipcIO
  | exp_fileIO
  | exp OP_TUP exp      { add_to_tuple(); }
  | CLEAR               { clear_terminal(); }
;

/*
  2.) Primitive Expressions
*/

exp_primitive:
    exp_integer         {/* For Testing */}
  | exp_boolean         {/* For Testing */}
  | exp_real            {/* For Testing */}
  | exp_char            {/* For Testing */}
  | exp_string          {/* For Testing */}
  | exp_list            { }
  | exp OP_ELEMENT exp_record  { printf("Record Accessed\n"); }
  | exp_struct
  | IDENTIFIER          { resolve_expression($1); }
  | CONSTRUCTOR         {  }
;

/*
  2.a) Integer Expressions
*/
exp_integer:
    RNG             { /*rng();*/ }
  | SIZEOF exp_type { printf("TYPE SIZE CHECKED\n"); }
  | INT             { last_type = TYPE_INTEGER; push_int((long long) $1); }
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
pre_list:
    OP_LIST_L {  }
;

exp_list:
    pre_list param_list OP_LIST_R { }
  | exp OP_LIST_CON exp           { }
  | LIST_TAIL exp_list            { list_tail(); }
  | OP_LIST_L OP_LIST_R           { }
  | exp OP_APPEND exp             { infer_append(); }
;

/*
  LIST PARAMETERS
*/
param_list:
    param_list OP_COMMA param_list
  | exp { decl_list(); }
;

/*
  3.) Basic Operations
*/

/*
  3.a) Arithmetic Expressions
*/
exp_arith:
    exp OP_ADD exp      { infer_addition(); }
  | exp OP_SUB exp      { infer_subtraction(); }
  | exp OP_MUL exp      { infer_multiplication(); }
  | exp OP_DIV exp      { infer_division(); }
  | exp OP_MOD exp      { infer_modulus(); }
  | exp BIT_AND exp     { infer_bit_and(); }
  | exp BIT_OR exp      { infer_bit_or(); }
  | exp BIT_XOR exp     { infer_bit_xor(); }
  | exp BIT_SHL INT     { infer_bit_shl($3); }
  | exp BIT_SHR INT     { infer_bit_shr($3); }
;

/*
  3.b) Logical Expressions
*/
exp_logical:
  | exp BOOL_AND exp    { infer_bool_and(); }
  | exp BOOL_OR exp     { infer_bool_or();  }
  | exp BOOL_XOR exp    { infer_bool_xor(); }
  | exp OP_LT exp       { infer_bool_lt(); }
  | exp OP_LTE exp      { infer_bool_lte(); }
  | exp OP_GT exp       { infer_bool_gt(); }
  | exp OP_GTE exp      { infer_bool_gte(); }
  | exp OP_EQ exp       { infer_bool_eq(); }
  | exp OP_NEQ exp      { infer_bool_neq(); }
  | exp_is              { }
;

/*
  3.) Conditional Expressions
*/
exp_conditional:
    exp_if              { }
  | exp_match           { }
;

/*
  3.a) if ... then ... else ...
*/
//  IF ...
//  HELPER FUNCTION
if1:
  IF      { $$ = decl_if(); };
// CALLABLE FUNCTION
if:
  if1 exp { $$ = exp_if($1); }
;

//  THEN ...
// CALLABLE FUNCTION
then:
  if THEN exp { $$ = exp_then($1); }
;

//  ELSE ...
//  HELPER FUNCTION
else1:
  then ELSE      { $$ = decl_else($1); }
;
// CALLABLE FUNCTION
exp_if:
  else1 exp { exp_else($1); }
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
    exp IS exp_struct { /*is_construct();*/ }
  | exp IS exp_type   { is_type();      }
;

/*
  4.) Functional Expressions
*/

/*
  4.a) Constants
*/
decl_const:
    CONST IDENTIFIER OF exp_type OP_ASSIGN exp_const { decl_constant($2); }
  | CONST exp_struct IDENTIFIER  OP_ASSIGN exp_const { decl_constant($3); }
;

exp_const:
    INT     { last_data = (void*) (unsigned long long) $1; }
  | IDENTIFIER { last_data = (void*) find_constant($1); }
  | exp_const OP_ADD INT {last_data = (void*) ((unsigned long long) last_data + $3); }
;

/*
  4.b) Function Declarations/Invocations
*/
pre_let:
    ref_com let
  | let
;

let:
    DEBUG STRING LET IDENTIFIER { add_debug_message($4, $2); decl_function($2); }
  | LET IDENTIFIER OF exp_type  { decl_function($2); }
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
__decl_funct:
    pre_let exp_param OP_ASSIGN exp   { ret_function(); }
  | pre_let OP_ASSIGN exp             { ret_function(); }
;

decl_funct:
    pre_let exp_param OP_ASSIGN exp   { ret_function(); }
  | pre_let OP_ASSIGN exp             { ret_function(); }
;

exp_param:
    exp_param IDENTIFIER { functions.back().add_parameter($2); }
  | IDENTIFIER { functions.back().add_parameter($1); }
;

exp_inline:
    OP_INLINE exp exp_inline {  }
  | {/* Intentionally Left Blank */}
;

/*
  FUNCTION EXPRESSIONS (INVOCATIONS)
*/

exp_funct:
    __decl_funct IN exp   { undecl_function(); }
  | IDENTIFIER arg_funct  { resolve_function( find_function($1) ); }
;


/*
  ARGUMENT EXPRESSIONS (INVOCATIONS)
*/
arg_funct:
    arg_funct arg_funct {  }
  | exp_primitive           { argt.push_back(last_type); }
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
    PAR_LEFT exp_type exp_type PAR_RIGHT  {printf("Parameterized Type Found\n");}
  | exp_type OP_LIST_L INT OP_LIST_R    {printf("Type Array initialized\n");}
  | INT_T           { last_type = 2;  }    
  | U8_T            { last_type = 3;  } 
  | I8_T            { last_type = 4;  }  
  | U16_T           { last_type = 5;  } 
  | I16_T           { last_type = 6;  } 
  | U32_T           { last_type = 7;  } 
  | I32_T           { last_type = 8;  } 
  | U64_T           { last_type = 9;  } 
  | I64_T           { last_type = 10; } 
  | REAL_T          { last_type = 11; } 
  | FLOAT_T         { last_type = 12; } 
  | DOUBLE_T        { last_type = 13; } 
  | BOOL_T          { last_type = 14; } 
  | CHAR_T          { last_type = 15; } 
  | STRING_T        { last_type = 16; } 
  | LIST_T      
  | exp_type OP_TUP exp_type { printf("Implement Me\n"); }
  | exp_type OP_COMMA exp_type
  | IDENTIFIER      { exp_type($1); }
;

/*
  TYPE DECLARATIONS
*/
dinit_type: 
  TYPE IDENTIFIER  { decl_type($2); }
;

decl_type:
    dinit_type param_type OP_ASSIGN decl_struct implements
;

implements:
    IMPL l_typeclass
  | 
;

l_typeclass:
    l_typeclass OP_COMMA l_typeclass
  | IDENTIFIER  { impl_typeclass($1); }
;

param_type:
    param_type param_type 
  | IDENTIFIER            { decl_type_param($1); }
  |                       {/* Intentionally Left Blank */}
;

/*
  5.b) Constructors
*/


/*
  CONSTRUCTOR IDENTIFIERS
*/
decl_struct:
    decl_struct BIT_OR decl_struct
  | CONSTRUCTOR OF exp_type { decl_constructor($1); }
  | CONSTRUCTOR             { decl_constructor($1); }
  | exp_type                {printf("TODO: Implement Type Aliases\n");}
;

exp_struct:
    exp_struct exp 
  | CONSTRUCTOR { exp_constructor($1); }
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
    IDENTIFIER      { exp_typeclass($1); }
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
exp_memIO:
    exp_memread         { }
  | exp_memwrite        { }
;


read:
  exp MEM_READ {  }
;

exp_memread:
    read IDENTIFIER IN exp { memory_read_exp($2); }
  | read THIS { memory_read_exp(); }
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

exp_ipcIO:
    exp_byte_build      { }
  | exp_byte_run        { }
  | exp_tether
  | exp_send
  | exp_receive
;

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
  8.) Filesystem Operations
*/
exp_fileIO:
    exp_fread
  | exp_fwrite
  | exp_fsearch
;


exp_fpath:
    exp_ffilter OP_LIST_CON exp_fname 
;

exp_ffilter:
    exp_ffilter OP_COMMA exp_ffilter 
  | exp_ffilter OP_ADD exp_ffilter
  | exp_ftag        
;

exp_ftag:
    IDENTIFIER    { printf("Tag Encountered: %s\n", $1); free($1); }
  | OP_ELEMENT IDENTIFIER { printf("Hidden Tag Encountered: %s\n", $2); free($2); }
  | CONSTRUCTOR   { free($1); }
  | OP_ELEMENT CONSTRUCTOR { printf("Hidden Tag Name Encountered: %s\n", $2); free($2); }
;

exp_fname:
    IDENTIFIER    { printf("File Name Encountered: %s\n", $1); free($1); }
  | OP_ELEMENT IDENTIFIER { printf("Hidden File Name Encountered: %s\n", $2); free($2); }
  | CONSTRUCTOR   { free($1); }
  | OP_ELEMENT CONSTRUCTOR { printf("Hidden File Name Encountered: %s\n", $2); free($2); }
;


/*
  New File
*/
decl_fnew:
  FILEK IDENTIFIER exp_fpath  { printf("File Declared: %s\n", $2); }
;


/*
  Read File
*/
exp_fread:
  READ IDENTIFIER           {printf("Return Contents of File: %s\n", $2); free($2);}
;

/*
  Write File
*/
exp_fwrite:
    WRITE IDENTIFIER STRING   {printf("\"%s\" has been written to %s\n", $3, $2); free($3); free($2);}
  | APPEND IDENTIFIER STRING  {printf("\"%s\" has been appended to %s\n", $3, $2); free($3); free($2);}
;

/*
  Search for File
*/
exp_fsearch:
    TSEARCH exp_ffilter 
  | SEARCH exp_fpath
  | SEARCH exp_fname
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
  | decl_offer
  | decl
  | exp
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

decl_offer:
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
  
  //rs_end();

	exit(grammar_status);
}

