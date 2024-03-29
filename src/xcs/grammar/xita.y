%{
/*
  xita.y
  Codeus Tech
  Authored on     July 30, 2021
  Last Modified  August 6, 2021
*/

/*
  Contains grammar structure/implementation for Xita Programming Language

  Table of Contents
  =========================
  A.) Token Declarations
  B.) Order of Operations
  C.) Xita Chip Grammar
  D.) Xita Driver Grammar
  E.) Xita Source Grammar
  F.) Xita Generic Expressions
    F.1) Primitive Expressions
    F.2) Arithmetic Expressions
    F.3) Bitwise Expressions
    F.4) Logical Expressions
    F.5) Conditional Expressions
    F.6) Functional Expressions
    F.7) Data Type Constructors
  G.) Xita Generic Declarations
    G.1) Constant Declarations
    G.2) Function Declarations
    G.3) Data Type Declarations
    G.4) Typeclass Declarations

*/


//  Linux Libraries
#include "time.h"
#include "stdio.h"
#include "stdlib.h"

//  XCS Libraries
#include <xcs/std/includes.h>
#include <xcs/context/manager.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

void yyerror(const char* error);

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
%token CONST PUBLIC SYSTEM LET IN
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
%token MEM_ACC

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
  LOWEST-PRIORITY TOKENS
*/

//  Non-Associative Operators/Keywords
%nonassoc OP_COMMA OP_TUP

//  Logical Operators
%left BOOL_NOT BOOL_OR BOOL_AND BOOL_XOR
%left OP_GT OP_GTE OP_LT OP_LTE OP_EQ OP_NEQ IS

%left BIT_AND BIT_OR BIT_SHL BIT_SHR BIT_XOR BIT_NOT

//  Numerical Operators
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV OP_MOD

%left MEM_SET MEM_READ

//  Order Keepers
%left PAR_LEFT PAR_RIGHT


%left STATIC
%left ELSE //  For 'Dangling Else' Problem
%right OP_ELEMENT

%left OP_EXP
/*
  HIGHEST-PRIORITY TOKENS
*/

%start xita


/*
  SHIFT/REDUCE EXPECTATIONS (VALID)
  =====================================
    * Dangling Else (Generic)       20
    * Dangling Else (Drivers)       20
    * Dangling Memory Set          170

    TOTAL                           40
*/
%expect 210

%%

/*
  Main Entry Function
*/
xita:
    xita_chip
  | xita_driver
  | xita_source
;


/*
  ===========================

  C.) Xita Chip Grammar

  ===========================
*/
xita_chip:
    chip_header chip_arch chip_interface  
;

chip_header:
    CHIP CONSTRUCTOR { context.newChip($2); }
;

chip_arch:
    ARCH STRING { context.setChipArch($2); }
;

chip_interface:
    chip_interface_name OP_TYPE chip_interface_range OP_TUP chip_interface
  | chip_interface_name OP_TYPE chip_interface_range 
;
  
  chip_interface_name:
    CONSTRUCTOR { context.addFirmwareInterface($1); }
  ;

  chip_interface_range:
    chip_interface_range OP_COMMA INT OP_ADD INT { context.addFirmwareRange($3, $3+$5); } /* This operation will accept a number of offset bytes */
  | chip_interface_range OP_COMMA INT OP_SUB INT { context.addFirmwareRange($3, $5); } /* This operation will accept a number of offset bytes */
  | INT OP_ADD INT { context.addFirmwareRange($1, $1+$3); } /* This operation will accept a number of offset bytes */
  | INT OP_SUB INT { context.addFirmwareRange($1, $3); }    /* This operation will accept minimum/maximium bounds  */
  ;


/*
  ===========================

  D.) Xita Driver Grammar

  ===========================
*/
xita_driver:
    driver_header exps_driver
;

driver_header:
    DRIVER CONSTRUCTOR { printf("Driver Encountered:  %s\n", $2); }
;

exps_driver:
    decl_driver OP_EXP exps_driver
  | exp_driver OP_EXP exps_driver
  | module exps_driver
  | decl_driver
  | exp_driver
;

exp_driver:
    PAR_LEFT exp_driver PAR_RIGHT
  | condition_driver
  | function_driver
  | arithmetic_driver
  | bitwise_driver
  | logical_driver
  | memory
  | primitive
  | constructor_driver
  | exp_driver OP_ELEMENT IDENTIFIER
  | IDENTIFIER                        { context.resolveExpression($1); }
;

memory:
    MEM_ACC INT    { printf("Memory Accessed at: %d\n", (int) $2); pushInteger((Arbitrary)$2); }
  | MEM_ACC IDENTIFIER { printf("Memory Accessed for Constant: %s\n", (char*) $2); }
  | set_memory exps_driver
  | memory_variable IN exps_driver
;
  memory_variable:
    INT MEM_READ IDENTIFIER { printf("Memory ( %lld ) Read into Variable: %s\n", $1, $3); context.addMemoryVariable($3); pushInteger((Arbitrary)$1); }
  ;
  set_memory:
    INT MEM_SET   { printf("Memory Set at: %lld\n", $1); pushInteger((Arbitrary)$1); }
  ;

/*
  To keep parser protocols separate for driver files and source files,
  each of the "Generic Expressions" found in section `F.)` of this file
  must be rebuilt with `exp_driver` instead of `exp`.
  
  If this isn''t done, it results in numerous reduce/reduce errors that will
  make cross-compiler behavior inconsistent (and wrong).
*/
  /*
    Expressions
  */
  arithmetic_driver:
      exp_driver OP_ADD exp_driver { context.resolveOperator(OPERATOR_ADDITION); }
    | exp_driver OP_SUB exp_driver { context.resolveOperator(OPERATOR_SUBTRACT); }
    | exp_driver OP_MUL exp_driver { context.resolveOperator(OPERATOR_MULTIPLY); }
    | exp_driver OP_DIV exp_driver { context.resolveOperator(OPERATOR_DIVISION); }
    | exp_driver OP_MOD exp_driver { context.resolveOperator(OPERATOR_MODULUS);  }
  ;
  bitwise_driver:
      BIT_NOT exp_driver
    | exp_driver BIT_XOR exp_driver     { context.resolveOperator(OPERATOR_BIT_XOR); }
    | exp_driver BIT_AND exp_driver     { context.resolveOperator(OPERATOR_BIT_AND); }
    | exp_driver BIT_OR exp_driver      { context.resolveOperator(OPERATOR_BIT_OR);  }
    | exp_driver BIT_SHL exp_driver     { context.resolveOperator(OPERATOR_BIT_SHL); }
    | exp_driver BIT_SHR exp_driver     { context.resolveOperator(OPERATOR_BIT_SHR); } 
  ;
  logical_driver:
      exp_driver IS IDENTIFIER
    | exp_driver IS CONSTRUCTOR
    | exp_driver OP_LT exp_driver       { context.resolveOperator(OPERATOR_LT);  }
    | exp_driver OP_LTE exp_driver      { context.resolveOperator(OPERATOR_LTE); }
    | exp_driver OP_GT exp_driver       { context.resolveOperator(OPERATOR_GT);  }
    | exp_driver OP_GTE exp_driver      { context.resolveOperator(OPERATOR_GTE); }
    | exp_driver OP_EQ exp_driver       { context.resolveOperator(OPERATOR_EQ);  }
    | exp_driver OP_NEQ exp_driver      { context.resolveOperator(OPERATOR_NEQ); }
    | exp_driver BOOL_AND exp_driver    { context.resolveOperator(OPERATOR_AND); }
    | exp_driver BOOL_OR exp_driver     { context.resolveOperator(OPERATOR_OR);  }
    | BOOL_NOT exp_driver        { context.resolveOperator(OPERATOR_NOT); }
  ;
  condition_driver:
    if_d then_d else_d
  ;
    if_d:
        if_pre exp_driver
    ;
      then_d: 
        then_pre exp_driver
      ;
      else_d:
        else_pre exp_driver  %expect 20
      ;
  function_driver:
      IDENTIFIER function_args_d  { context.resolveFunction($1); }
  ;
    function_args_d:
        function_args_d primitive   { context.loadArgument(context.LastType()); }
      | primitive                 { context.loadArgument(context.LastType()); }
      | function_args_d IDENTIFIER  { context.loadArgument(context.LastType()); }
      | IDENTIFIER                { context.loadArgument(context.LastType()); }
      | function_args_d PAR_LEFT exp_driver PAR_RIGHT  { context.loadArgument(context.LastType()); }
      | PAR_LEFT exp_driver PAR_RIGHT    { context.loadArgument(context.LastType()); }
    ;
  constructor_driver:
      CONSTRUCTOR constructor_args_d
    | CONSTRUCTOR
  ;
    constructor_args_d:
        OP_REC_L record_args_d OP_REC_R
      | primitive constructor_args_d
      | primitive
      | IDENTIFIER constructor_args_d
      | IDENTIFIER
      | PAR_LEFT exp_driver PAR_RIGHT constructor_args_d
      | PAR_LEFT exp_driver PAR_RIGHT
    ;
    record_args_d:
        exp_driver OP_COMMA record_args_d
      | exp_driver
    ;
  /*
    Declarations
  */
  decl_driver:
      decl_constant
    | decl_function_d
    | decl_type_d
    | decl_typeclass
  ;
    decl_function_d:
        __decl_function_d IN exp_driver  { context.undeclareFunction(); }
      | __decl_function_d 
    ;
      __decl_function_d:
          decl_function_pre decl_function_param OP_ASSIGN exp_driver { context.endDeclareFunction(); }
        | decl_function_pre OP_ASSIGN exp_driver                     { context.endDeclareFunction(); }
      ;
    decl_type_d:
        TYPE IDENTIFIER OP_ASSIGN decl_type_constructor IMPL IDENTIFIER OP_TYPE decl_type_implements_d
      | TYPE IDENTIFIER OP_ASSIGN decl_type_constructor
    ;
      decl_type_implements_d:
          decl_type_implements_d OP_COMMA IDENTIFIER decl_type_implements_param OP_ASSIGN exp_driver
        | decl_type_implements_d OP_COMMA IDENTIFIER OP_ASSIGN exp_driver
        | IDENTIFIER decl_type_implements_param OP_ASSIGN exp_driver
        | IDENTIFIER OP_ASSIGN exp_driver
      ;


/*
  ===========================

  E.) Xita Source Grammar

  ===========================
*/
xita_source:
  exps
;


/*
  ===========================

  F.) Xita Generic Expressions

  ===========================
*/
exps:
    decl OP_EXP exps
  | exp OP_EXP exps
  | module exps
  | decl
  | exp
;

exp:
    PAR_LEFT exp PAR_RIGHT
  | condition
  | function
  | arithmetic
  | bitwise
  | logical
  | primitive
  | constructor
  | exp OP_ELEMENT IDENTIFIER
  | IDENTIFIER                  { context.resolveExpression($1); }
;

/*
  F.1) Primitive Expressions
*/
primitive:
    REAL
  | INT { pushInteger((Arbitrary) $1); }
  | TRUE
  | FALSE
  | STRING
  | CHAR
;


/*
  F.2) Arithmetic Expressions
*/
arithmetic:
    exp OP_ADD exp      { context.resolveOperator(OPERATOR_ADDITION); }
  | exp OP_SUB exp      { context.resolveOperator(OPERATOR_SUBTRACT); }
  | exp OP_MUL exp      { context.resolveOperator(OPERATOR_MULTIPLY); }
  | exp OP_DIV exp      { context.resolveOperator(OPERATOR_DIVISION); }
  | exp OP_MOD exp      { context.resolveOperator(OPERATOR_MODULUS); }
;

/*
  F.3) Bitwise Expressions
*/
bitwise:
    BIT_NOT exp
  | exp BIT_XOR exp     { context.resolveOperator(OPERATOR_BIT_XOR); }
  | exp BIT_AND exp     { context.resolveOperator(OPERATOR_BIT_AND); }
  | exp BIT_OR exp      { context.resolveOperator(OPERATOR_BIT_OR);  }
  | exp BIT_SHL exp     { context.resolveOperator(OPERATOR_BIT_SHL); }
  | exp BIT_SHR exp     { context.resolveOperator(OPERATOR_BIT_SHR); } 
;

/*
  F.4) Logical Expressions
*/
logical:
    exp IS IDENTIFIER
  | exp IS CONSTRUCTOR
  | exp OP_LT exp       { context.resolveOperator(OPERATOR_LT);  }
  | exp OP_LTE exp      { context.resolveOperator(OPERATOR_LTE); }
  | exp OP_GT exp       { context.resolveOperator(OPERATOR_GT);  }
  | exp OP_GTE exp      { context.resolveOperator(OPERATOR_GTE); }
  | exp OP_EQ exp       { context.resolveOperator(OPERATOR_EQ);  }
  | exp OP_NEQ exp      { context.resolveOperator(OPERATOR_NEQ); }
  | exp BOOL_AND exp    { context.resolveOperator(OPERATOR_AND); }
  | exp BOOL_OR exp     { context.resolveOperator(OPERATOR_OR);  }
  | BOOL_NOT exp        { context.resolveOperator(OPERATOR_NOT); }
;

/*
  F.5) Conditional Expressions
*/
condition:
  if then else
;

if:
    if_pre exp
;
  if_pre:
    IF
  ;

  then: 
    then_pre exp
  ;

  then_pre:
    THEN
  ;

  else:
    else_pre exp  %expect 20
  ;

  else_pre:
    ELSE 
  ;


/*
  F.6) Functional Expressions
*/
function:
    IDENTIFIER function_args  { context.resolveFunction($1); }
;

  function_args:
      function_args primitive   { context.loadArgument(context.LastType()); }
    | primitive                 { context.loadArgument(context.LastType()); }
    | function_args IDENTIFIER  { context.loadArgument(context.LastType()); }
    | IDENTIFIER                { context.loadArgument(context.LastType()); }
    | function_args PAR_LEFT exp PAR_RIGHT  { context.loadArgument(context.LastType()); }
    | PAR_LEFT exp PAR_RIGHT    { context.loadArgument(context.LastType()); }
  ;

/*
  F.7) Data Type Constructors
*/
constructor:
    CONSTRUCTOR constructor_args
  | CONSTRUCTOR
;

  constructor_args:
      OP_REC_L record_args OP_REC_R
    | primitive constructor_args
    | primitive
    | IDENTIFIER constructor_args
    | IDENTIFIER
    | PAR_LEFT exp PAR_RIGHT constructor_args
    | PAR_LEFT exp PAR_RIGHT
  ;

  record_args:
      exp OP_COMMA record_args
    | exp
  ;

module:
  OPEN STRING
;


/*
  ===========================

  G.) Xita Generic Decalarations

  ===========================
*/
decl:
    decl_constant
  | decl_function
  | decl_type
  | decl_typeclass
;

/*
  1.) Declare Constant
*/
decl_constant:
    CONST CONSTRUCTOR IDENTIFIER decl_constant_assign constant_value { context.declareConstant($3); }
;
  decl_constant_assign:
    OP_ASSIGN { context.newData(TYPE_ARBITRARY, NULL); }
  ;
  constant_value:
      constant_value OP_ADD constant_value  { }
    | INT         { context.addData(TYPE_INTEGER,(Arbitrary) $1); }
    | STRING      { context.addData(TYPE_STRING,(Arbitrary) $1); }
    | IDENTIFIER  { context.addData($1); }
  ;

/*
  2.) Declare Function
*/
decl_function:
    __decl_function IN exp  { context.undeclareFunction(); }
  | __decl_function 
;

  __decl_function:
      decl_function_pre decl_function_param OP_ASSIGN exp { context.endDeclareFunction(); }
    | decl_function_pre OP_ASSIGN exp                     { context.endDeclareFunction(); }
  ;

  decl_function_pre:
    LET IDENTIFIER  { context.declareFunction($2); }
  ;

  decl_function_param:
      decl_function_param IDENTIFIER{  context.declareFunctionParameter($2); }
    | IDENTIFIER { context.declareFunctionParameter($1); }
  ;

/*
  3.) Data Type Declaration
*/
decl_type:
    TYPE IDENTIFIER OP_ASSIGN decl_type_constructor IMPL IDENTIFIER OP_TYPE decl_type_implements
  | TYPE IDENTIFIER OP_ASSIGN decl_type_constructor
;

  decl_type_constructor:
      decl_type_constructor BIT_OR CONSTRUCTOR OF decl_type_body
    | CONSTRUCTOR OF decl_type_body
    | decl_type_constructor BIT_OR CONSTRUCTOR
    | CONSTRUCTOR
    | decl_type_constructor BIT_OR IDENTIFIER
    | IDENTIFIER
  ;

  decl_type_body:
      decl_type_body OP_COMMA IDENTIFIER OP_TYPE IDENTIFIER
    | IDENTIFIER OP_TYPE IDENTIFIER
    | IDENTIFIER
  ;

  decl_type_implements:
      decl_type_implements OP_COMMA IDENTIFIER decl_type_implements_param OP_ASSIGN exp
    | decl_type_implements OP_COMMA IDENTIFIER OP_ASSIGN exp
    | IDENTIFIER decl_type_implements_param OP_ASSIGN exp
    | IDENTIFIER OP_ASSIGN exp
  ;

  decl_type_implements_param:
      decl_type_implements_param IDENTIFIER
    | IDENTIFIER
  ;


/*
  4.) Typeclass Declaration
*/
decl_typeclass:
    TYPECLASS IDENTIFIER decl_typeclass_param REQ decl_typeclass_proto
  | TYPECLASS IDENTIFIER REQ decl_typeclass_proto
;

  decl_typeclass_param:
      decl_typeclass_param IDENTIFIER 
    | IDENTIFIER
  ;

  decl_typeclass_proto:
      decl_typeclass_proto OP_COMMA IDENTIFIER decl_typeclass_proto_param OP_ASSIGN IDENTIFIER
    | IDENTIFIER decl_typeclass_proto_param OP_ASSIGN IDENTIFIER
    | decl_typeclass_proto OP_COMMA IDENTIFIER OP_ASSIGN IDENTIFIER
    | IDENTIFIER OP_ASSIGN IDENTIFIER
  ;

    decl_typeclass_proto_param:
        decl_typeclass_proto_param IDENTIFIER
      | IDENTIFIER
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

