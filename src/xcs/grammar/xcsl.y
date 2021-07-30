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
  C.) Start of Xita Grammar
  D.) Start of Driver Grammar
  E.) Start of Chip Grammar

  ----------------------
  
  I. XITA DECLARATIONS

  I.1.) Top-Level Declarations
    I.1.a) Types
    I.1.b) Typeclasses
    I.1.c) Constants
    I.1.d) Functions

  ----------------------

  II. XITA EXPRESSIONS
  
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

  ---------------------------

  III. DRIVER MODULES



  ---------------------------

  IV. CHIP FILES


*/


//  Linux Libraries
#include "time.h"
#include "stdio.h"
#include "stdlib.h"

//  XCS Libraries
#include <xcs/context/manager.h>
#include <xcs/grammar/status.h>
#include <xcs/comments/comments.h>
#include <xcs/regstack/regstack.h>
#include <xcs/conditions/conditions.h>
#include <xcs/expressions/primitives/primitives.h>
#include <xcs/expressions/regex/regex.h>
#include <xcs/sys/utils/clear.h>
#include <xcs/sys/utils/delay.h>
#include <xcs/sys/proc/proc.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* error);
unsigned int grammar_status = GRAMMAR_RUNNING;

extern Scope xcs_args;

extern ContextManager context;


%}

/*
  ==========================

  A.) Token Declarations

  ==========================
*/

//  Preprocess Directives
%token CHIP DRIVER ARCH END

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
%token BOOL_OR_O BOOL_AND_O BOOL_XOR_O          // BOOLEAN COMPARISON
%token ARROW_L_O ARROW_R_O
%token OP_APPEND_O OP_LIST_CON_O
%token MEM_READ_O MEM_SET_O

//  Syntactic Operators
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD       // INTEGER ARITHMETIC
%token OP_GTE OP_GT OP_EQ OP_NEQ OP_LTE OP_LT   // INTEGER COMPARISON
%token BIT_AND BIT_OR BIT_XOR BIT_SHR BIT_SHL BIT_NOT   // BITWISE MANIPULATION
%token BOOL_OR BOOL_AND BOOL_XOR BOOL_NOT               // BOOLEAN COMPARISON
%token ARROW_L ARROW_R
%token OP_EXP OP_TUP OP_ASSIGN PAR_LEFT PAR_RIGHT OP_COMMA

//  List Operators/Keywords
%token OP_APPEND OP_LIST_CON
%token LIST_HEAD LIST_TAIL LIST_LENGTH
%token OP_LIST_L OP_LIST_R

//  Conditional Keywords
%token IF THEN ELSE
%token MATCH WITH

//  Functional Keywords
%token CONST LET IN
%token OP_INLINE

//  Datatype Keywords
%token TYPE TYPECLASS
%token IS OF REQ IMPL SIZEOF
%token OP_REC_L OP_REC_R OP_ELEMENT OP_TYPE

//  Static Memory Manipulation
%token MEM_READ MEM_SET THIS

// Integers
%token RNG

//  Filesystem Operations
%token FILEK REMOVE
%token READ WRITE APPEND
%token SEARCH TSEARCH
%token COPY MOVE RETAG

//  Special Operations
%token BUILD                //  Bytecode Operations
%token REGEX                //  Regular Expressions
%token TETHER SEND RECEIVE  //  Interprocess Communication

//  Utilities
%token CLEAR DELAY         
%token DEBUG DEBUG_PRINT 

//  Module Operations
%token SOURCE_M HEADER_M TETHER_M SYSTEM_M
%token SOURCE_H HEADER_H TETHER_H 
%token OPEN RUN IMPORT

//  Tether Module-Specific Operations
%token OFFER REQUEST XCS_UNDEF

/*
  ===========================

  B.) Order of Operations

  ===========================
*/
/*
  LOWEST-PRIORITY TOKEN
*/
//  Declaration Keywords
%left IF THEN ELSE

//  Logical Operators
%left BOOL_NOT BOOL_OR BOOL_AND
%left OP_GT OP_GTE OP_LT OP_LTE OP_EQ OP_NEQ IS

//  Numerical Operators
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD


//  Literal Values
%left IDENTIFIER
%left CONSTRUCTOR
%left INT REAL TRUE FALSE CHAR STRING


%left OP_COMMA OP_ELEMENT

//  Order Keepers
%left OP_LIST_L OP_LIST_R
%left PAR_LEFT PAR_RIGHT

//  Assignment Operators
%left OP_ASSIGN IN
%left TYPE TYPECLASS LET CONST
%left MEM_SET MEM_READ

%left DEBUG

//  Expression Seperator
%left OP_EXP

//  Preprocess Directives
%left CHIP DRIVER END
/*
  HIGHEST-PRIORITY TOKEN
*/

%type <val_int> if if1 then else1
%type <val_int> lit_integer
%type <val_string> var_memread

/*
  C.) Start of Grammar
*/
%start main
%%

main:
    xita_chip
  | xita_driver
  | xita_source

ref_com:
    DOC { decl_ref_comment($1); }
;

xita_source:
    ref_com xita_source { }
  | src  { }
;

/*
  D.) Source Modules
*/
src2:
    decl    { context.concludeExpression();  }
  | exp     { context.concludeExpression();  } 
;

src:
    src2 OP_EXP src {  }
  | src2  
;


/*
    I. DECLARATIONS
*/

/*
  I.1.) Top-Level Declarations
*/
decl:
    decl_type           
  | decl_typeclass     
  | decl_const          
  | decl_funct    
  | decl_open
//  | decl_fnew
  | DEBUG STRING                             { printf("%s\n", $2); }
;

decl_open:
    OPEN
  | RUN 
  | IMPORT
;

/*
  I.1.a) Types
*/

/* Type Declarations */
decl_type:
    pre_decl_type param_type OP_ASSIGN decl_struct implements
  | pre_decl_type            OP_ASSIGN decl_struct implements
  | pre_decl_type param_type OP_ASSIGN decl_struct
  | pre_decl_type            OP_ASSIGN decl_struct
;

  pre_decl_type: 
      DEBUG STRING TYPE IDENTIFIER { add_debug_message($4, $2); context.declareType($4); }
    | TYPE IDENTIFIER  { context.declareType($2); }
  ;

  param_type:
      param_type param_type 
    | IDENTIFIER            { context.declareTypeParameter($1); }
  ;

  implements:
      IMPL l_typeclass OP_TYPE impl_proto
  ;

    l_typeclass:
        l_typeclass OP_COMMA l_typeclass
      | IDENTIFIER  { context.implementTypeclass($1); }
    ;

    impl_proto:
        impl_proto OP_COMMA impl_proto
      | impl_proto_decl impl_proto_param OP_ASSIGN exp
    ;

    impl_proto_decl:
      IDENTIFIER  { l.log('d', "ImplProto", "Prototype declared: " + string($1)); }
      ;

    impl_proto_param:
        impl_proto_param impl_proto_param
      | IDENTIFIER        { l.log('d', "ImplProto", "Prototype Parameter declared: " + string($1) ); }
    ;

  /* Type Constructor Declarations */
  decl_struct:
      decl_struct BIT_OR decl_struct
    | pre_decl_struct OF decl_record 
    | pre_decl_struct OF exp_type     
    | pre_decl_struct                 
    | exp_type   { context.declareTypeAlias(context.LastType()); }
  ;

    pre_decl_struct:
      CONSTRUCTOR  { context.declareTypeConstructor($1); }
    ;

    decl_record:
        decl_record OP_COMMA decl_record
      | IDENTIFIER OP_TYPE exp_type OP_ASSIGN exp { context.declareTypeElement($1, context.LastType()); }
      | IDENTIFIER OP_TYPE exp_type               { context.declareTypeElement($1, context.LastType()); }
    ;
  

/*
  I.1.b) Typeclasses
*/

decl_typeclass:
    pre_decl_typeclass REQ exp_prototype
; 

  pre_decl_typeclass:
      TYPECLASS IDENTIFIER IDENTIFIER { context.declareTypeclass($2, $3); }
  ;

  exp_prototype:
      exp_prototype proto_comma exp_prototype      { }
    | prototype param_prototype OP_ASSIGN exp_type { }
  ;

  prototype:
      IDENTIFIER    { context.declareTypeclassPrototype($1); }
    /*
    | OP_ADD_O      { context.declareTypeclassPrototype("(+)"); }
    | OP_SUB_O      { context.declareTypeclassPrototype("(-)"); }
    | OP_MUL_O      { context.declareTypeclassPrototype("(*)"); }
    | OP_DIV_O      { context.declareTypeclassPrototype("(/)"); }
    | OP_MOD_O      { context.declareTypeclassPrototype("(%)"); }
    | BOOL_AND_O    { context.declareTypeclassPrototype("(&&)"); }
    | BOOL_OR_O     { context.declareTypeclassPrototype("(||)"); }
    | BOOL_XOR_O    { context.declareTypeclassPrototype("(^^)"); }
    | BIT_AND_O     { context.declareTypeclassPrototype("(&)"); }
    | BIT_OR_O      { context.declareTypeclassPrototype("(|)"); }
    | BIT_XOR_O     { context.declareTypeclassPrototype("(^)"); }
    | BIT_SHL_O     { context.declareTypeclassPrototype("(<<)"); }
    | BIT_SHR_O     { context.declareTypeclassPrototype("(>>)"); }
    | OP_LT_O       { context.declareTypeclassPrototype("(<)"); }
    | OP_LTE_O      { context.declareTypeclassPrototype("(<=)"); }
    | OP_GT_O       { context.declareTypeclassPrototype("(>)"); }
    | OP_GTE_O      { context.declareTypeclassPrototype("(>=)"); }
    | OP_EQ_O       { context.declareTypeclassPrototype("(==)"); }
    | OP_NEQ_O      { context.declareTypeclassPrototype("(!=)"); }
    | OP_APPEND_O   { context.declareTypeclassPrototype("(++)"); }
    | OP_LIST_CON_O { context.declareTypeclassPrototype("(:)"); } */
  ;

  /*
    PROTOTYPE PARAMETERS
  */
  param_prototype:
      param_prototype param_prototype 
    | exp_type      {/* param_proto($1); */}
    | {/* DO NOTHING */}
  ;

/*
  I.1.c) Constants
*/
assign_const:
  OP_ASSIGN  { context.newData(TYPE_ARBITRARY, NULL); }
;

decl_const:
    DEBUG STRING CONST IDENTIFIER OF exp_type assign_const add_value_const    
  | DEBUG STRING CONST ident_struct IDENTIFIER  assign_const add_value_const  
  | CONST IDENTIFIER OF exp_type assign_const add_value_const                 { context.declareConstant($2); }
  | CONST ident_struct IDENTIFIER  assign_const add_value_const               { context.declareConstant($3); }
;

add_value_const:
    add_value_const OP_ADD add_value_const  { }
  | INT         { context.addData(TYPE_INTEGER,(Arbitrary) $1); }
  | STRING      { context.addData(TYPE_STRING,(Arbitrary) $1); }
  | IDENTIFIER  { context.addData($1); }
;

/*
    II. EXPRESSIONS
*/

/*
  II.1.) Top-Level Expressions
*/
exp:
    PAR_LEFT exp PAR_RIGHT
  | exp_delay exp   
  | exp OP_ELEMENT OP_LIST_L exp OP_LIST_R  { printf("ARRAY/LIST ELEMENT ACCESSED\n"); }
  | exp OP_LIST_CON exp_list       { printf("List Constructed\n"); }    
  | exp_memIO
  | exp_conditional  
  | exp OP_ELEMENT exp_record  
  | exp_literal      
  | exp_arith        
  | LIST_HEAD exp_list
  | exp_regex   
  | exp_ipcIO
//  | exp_fileIO
//  | exp OP_TUP exp                           { add_to_tuple(); }
  | DEBUG_PRINT IDENTIFIER                   { print_debug_message($2); }
  | CLEAR                                    { clear_terminal(); }
  | decl  
  | XCS_UNDEF
;

exp_delay:
  DELAY exp { exp_delay(); }
;

/*
  2.) Primitive Expressions
*/

exp_literal:
    exp_identifier  
  | exp_primitive
  | exp_struct
;

exp_identifier:
    PAR_LEFT IDENTIFIER arg_funct PAR_RIGHT  { context.resolveFunction($2); }
  | IDENTIFIER arg_funct  { context.resolveFunction($1); }
  | IDENTIFIER            { context.resolveExpression($1); }
;


exp_primitive:
    exp_list            { context.LastType(TYPE_LIST);    }
  | exp_integer 
  | exp_boolean         { context.LastType(TYPE_BOOLEAN); }
//  | exp_real            { context.LastType(TYPE_REAL);    }
  | exp_char            { context.LastType(TYPE_CHAR);    }
  | STRING              { pushString($1);  }
;

/*
  2.a) Integer Expressions
*/
lit_integer:
    PAR_LEFT lit_integer PAR_RIGHT  { $$ = $2; }
  | lit_integer BIT_AND lit_integer { $$ = $1 & $3; }
  | lit_integer BIT_OR lit_integer  { $$ = $1 | $3; }
  | lit_integer BIT_XOR lit_integer { $$ = $1 ^ $3; }
  | lit_integer BIT_SHL lit_integer { $$ = $1 << $3; }
  | lit_integer BIT_SHR lit_integer { $$ = $1 >> $3; }
  | lit_integer OP_MUL lit_integer  { $$ = $1 * $3; }
  | lit_integer OP_DIV lit_integer  { $$ = $1 / $3; }
  | lit_integer OP_MOD lit_integer  { $$ = $1 % $3; }
  | lit_integer OP_ADD lit_integer  { $$ = $1 + $3; }
  | lit_integer OP_SUB lit_integer  { $$ = $1 - $3; }
  | INT   { $$=$1; }
;

exp_integer:
    LIST_LENGTH exp_list { printf("List of Length determined\n"); }
  | RNG             { /*rng();*/ }
  | SIZEOF exp_type { printf("TYPE SIZE CHECKED\n"); }
  | lit_integer     {  pushInteger((Arbitrary) $1); }
;

/*
  2.b) Boolean Expressions
*/
exp_boolean:
    exp OP_LT exp       { context.resolveOperator(OPERATOR_LT);  }
  | exp OP_LTE exp      { context.resolveOperator(OPERATOR_LTE); }
  | exp OP_GT exp       { context.resolveOperator(OPERATOR_GT);  }
  | exp OP_GTE exp      { context.resolveOperator(OPERATOR_GTE); }
  | exp OP_EQ exp       { context.resolveOperator(OPERATOR_EQ);  }
  | exp OP_NEQ exp      { context.resolveOperator(OPERATOR_NEQ); }
  | exp BOOL_AND exp    { context.resolveOperator(OPERATOR_AND); }
  | exp BOOL_OR exp     { context.resolveOperator(OPERATOR_OR);  }
  | BOOL_NOT exp        { context.resolveOperator(OPERATOR_NOT); }
  | TRUE                { pushData(TYPE_BOOLEAN, (Arbitrary) 1); }
  | FALSE               { pushData(TYPE_BOOLEAN, (Arbitrary) 0); }
;

/*
  2.c) Real Expressions
*/
/* NEEDS INTERVENTION!
exp_real:
    FLOAT_C REAL  { push_real_lit($2); }
  | DOUBLE_C REAL { push_real_lit($2); }
  | REAL          { push_real_lit($1); }
;
*/

/*
  2.d) Character Expressions
*/
exp_char:
  CHAR        { pushData(TYPE_CHAR, (void*) $1); }
;

/*
  2.e) String Expressions
exp_string:
    exp_string OP_APPEND exp_string { string_append(); }
  | STRING  { pushData(TYPE_STRING, (void*) $1); }
;
*/

/*
  2.f) List Expressions
*/

exp_list:
    OP_LIST_L OP_LIST_R               { printf("Empty List\n"); }
  | OP_LIST_L param_list OP_LIST_R    {  printf("List Initialized\n"); }
  | LIST_TAIL exp_list
  | exp_list OP_APPEND exp_list   { printf("Lists Concatenated\n"); }
  | IDENTIFIER { context.resolveExpression($1); }
  | PAR_LEFT IDENTIFIER arg_funct PAR_RIGHT  { context.resolveFunction($2); }
;

/*
  LIST PARAMETERS
*/
param_list:
    param_list OP_COMMA param_list
  | exp { }
;

/*
  3.) Basic Operations
*/

/*
  3.a) Arithmetic Expressions
*/
exp_arith:
    exp OP_ADD exp      { context.resolveOperator(OPERATOR_ADDITION); }
  | exp OP_SUB exp      { context.resolveOperator(OPERATOR_SUBTRACT); }
  | exp OP_MUL exp      { context.resolveOperator(OPERATOR_MULTIPLY); }
  | exp OP_DIV exp      { context.resolveOperator(OPERATOR_DIVISION); }
  | exp OP_MOD exp      { context.resolveOperator(OPERATOR_MODULUS); }
  | exp BIT_AND exp     { context.resolveOperator(OPERATOR_BIT_AND); }
  | exp BIT_OR exp      { context.resolveOperator(OPERATOR_BIT_OR);  }
  //| BIT_NOT exp         { infer_bit_not(); }
  | exp BIT_XOR exp     { context.resolveOperator(OPERATOR_BIT_XOR); }
  | exp BIT_SHL exp     { context.resolveOperator(OPERATOR_BIT_SHL); }
  | exp BIT_SHR exp     { context.resolveOperator(OPERATOR_BIT_SHR); } 
;



/*
  5.) Datatype Expressions
*/

/*
    5.a) Types
*/

/*
  TYPE EXPRESSIONS
*/
exp_type:
    exp_type exp_type  { }
  | exp_type OP_LIST_L INT OP_LIST_R    {printf("Type Array initialized\n");}
  | IDENTIFIER      { context.resolveType($1); }
  | OFFER         { printf("Implement Offers as Types\n"); }
  | exp_type OP_TUP exp_type {  }
;

/*
  5.b) Constructors
*/

ident_struct:
  CONSTRUCTOR { context.resolveConstructor($1); }
;

exp_struct:
    CONSTRUCTOR OP_REC_L data_struct OP_REC_R   { context.resolveConstructor($1); }
  | CONSTRUCTOR exp                             { context.resolveConstructor($1); }
  | CONSTRUCTOR                                 { context.resolveConstructor($1); }  
;

data_struct:
    data_struct OP_COMMA data_struct
  | IDENTIFIER OP_ASSIGN exp
  | exp
;

/*
  5.c) Records
*/

/*
  TYPE RECORDS
*/

exp_record:
    IDENTIFIER                { context.resolveTypeElement($1); }
;

arg_record: 
    arg_record OP_COMMA arg_record
  | IDENTIFIER OP_ASSIGN exp
  | exp   { l.log('D', "ExpConstruct", "Constructor Parameter Loaded"); }
;

/*
  5.d) Typeclass/Prototypes
*/


/*
  PROTOTYPE EXPRESSIONS
*/

proto_comma:
  OP_COMMA {  }
;
    

/*
  5.e) Primitive Typeclasses
*/


/*
  3.) Conditional Expressions
*/
exp_conditional:
    exp_if              { }
  | exp_match           { }
  | exp_is              { }
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
//    exp IS exp_struct { /*is_construct();*/ }
    exp IS exp_type   { isType(); }
;

/*
  4.) Functional Expressions
*/

/*
  4.a) Constants
*/

op_const:
    OP_ADD
  | OP_SUB
  | OP_MUL
  | OP_DIV
  | OP_MOD
;

exp_const:
    exp_const op_const exp_const
  | INT     { context.addData(TYPE_INTEGER, (Arbitrary)$1); }
  | STRING  { context.addData(TYPE_STRING, (Arbitrary)$1);  }
  | IDENTIFIER 
;

/*
  4.b) Function Declarations/Invocations
*/
pre_let:
    ref_com let
  | let
;

let:
    DEBUG STRING LET IDENTIFIER { add_debug_message($4, $2); context.declareFunction($4); }
  | LET IDENTIFIER OF exp_type  { context.declareFunction($2); }
  | LET IDENTIFIER              { context.declareFunction($2);  }
  /*
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
  | LET OP_LIST_CON_O           { override_list_con(); }*/
;

/*
  FUNCTION DECLARATIONS
*/
__decl_funct:
    pre_let exp_param OP_ASSIGN exp  { context.endDeclareFunction(); }
  | pre_let           OP_ASSIGN exp  { context.endDeclareFunction(); }
;

decl_funct:
    __decl_funct IN exp   { context.undeclareFunction(); }
  | __decl_funct
;

exp_param:
    exp_param IDENTIFIER { context.declareFunctionParameter($2); }
  | IDENTIFIER { context.declareFunctionParameter($1); }
;

decl_prototypes:
    decl_prototypes OP_COMMA decl_prototypes
  | IDENTIFIER OP_ASSIGN exp
;


/*
  FUNCTION EXPRESSIONS (INVOCATIONS)
*/


/*
  ARGUMENT EXPRESSIONS (INVOCATIONS)
*/
arg_funct:
    arg_funct arg_funct 
  | exp_literal           { context.loadArgument(context.LastType(), context.rsTop()); }
;



/*
  7) Direct Memory Access (DMA)
*/
exp_memIO:
    exp_memread         { }
  | exp_memwrite        { }
;

/*
  6.a) Read Expression from Memory
*/
var_memread:
  IDENTIFIER                        { context.addMemoryVariable($1); $$ = $1; }
;

exp_memread:
//    exp MEM_READ var_memread IN exp { context.rmMemoryVariable($3); }
   exp MEM_READ THIS               { context.resolveOperator(OPERATOR_MEM_GET); }
;



/*
  6.b) Write Expression to Memory
*/
exp_memwrite:
    exp MEM_SET exp                 { context.resolveOperator(OPERATOR_MEM_SET); }
  | exp MEM_SET exp INT             {  }
;


/*
  7.) Process Operations
*/

exp_ipcIO:
    exp_tether
  | exp_send
  | exp_receive
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
/*
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

*/
/*
  New File
*/
/*
decl_fnew:
  FILEK IDENTIFIER exp_fpath  { printf("File Declared: %s\n", $2); }
;

*/
/*
  Read File
*//*
exp_fread:
  READ IDENTIFIER           {printf("Return Contents of File: %s\n", $2); free($2);}
;
*/
/*
  Write File

exp_fwrite:
    WRITE IDENTIFIER STRING   {printf("\"%s\" has been written to %s\n", $3, $2); free($3); free($2);}
  | APPEND IDENTIFIER STRING  {printf("\"%s\" has been appended to %s\n", $3, $2); free($3); free($2);}
;

/*
  Search for File

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
  =====================================

  III. DRIVER MODULES

  =====================================
*/

driver_header:
    DRIVER CONSTRUCTOR { printf("Driver Encountered:  %s\n", $2); }
;

xita_driver:
    driver_header xita_source END /* TODO: This will be changed from xita_source */
;


/*
  =====================================

  IV. CHIP FILES

  =====================================
*/

xita_chip:
    chip_header chip_arch chip_interface  { printf("Finished Parsing Chip File\n"); }
;

chip_header:
    CHIP CONSTRUCTOR { context.newChip($2); }
;

chip_arch:
    ARCH STRING { context.setChipArch($2); }
;

chip_interface:
    chip_interface chip_interface
  |  chip_interface_name OP_TYPE chip_interface_range OP_TUP 
;
  chip_interface_name:
    CONSTRUCTOR { context.addFirmwareInterface($1); }
;

  chip_interface_range:
    chip_interface_range OP_COMMA chip_interface_range
  | INT OP_ADD INT { context.addFirmwareRange($1, $1+$3); } /* This operation will accept a number of offset bytes */
  | INT OP_SUB INT { context.addFirmwareRange($1, $3); }    /* This operation will accept minimum/maximium bounds  */
;

%%

/*
  GENERIC ERROR MESSAGE
*/
void yyerror(const char* error) {
	fprintf(stderr, "\nCritical error in line %d\n %s\n\n", yylineno, error);
  
  //  TODO: DEALLOCATE ALL BUFFERS
  l.log('E', "Crash", error);
  l.log('C', "Crash", "Error occurred.  Printing Logs....");
  l.printLogs();
  l.write();
  
  //rs_end();

	exit(active_error_code);
}

