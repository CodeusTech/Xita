%{
/*
  xita.y
  Codeus Tech
  Authored on   July 30, 2021
  Last Modified July 30, 2021
*/

/*
  NOTE:   THIS IS NOT ACTIVELY USED YET!!
          Eventually, this will replace `xcsl.y` as the primary grammar file

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

//  Order Keepers
%left PAR_LEFT PAR_RIGHT

%left ELSE //  For 'Dangling Else' Problem
%right OP_ELEMENT

%left OP_EXP
/*
  HIGHEST-PRIORITY TOKENS
*/

%start xita

//  There are 21 Shift/Reduce Conflicts, 
//   ALL caused by 'dangling else' expressions
%expect 21

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
    chip_header chip_arch chip_interface  { printf("Finished Parsing Chip File\n"); }
;

chip_header:
    CHIP CONSTRUCTOR { context.newChip($2); }
;

chip_arch:
    ARCH STRING { context.setChipArch($2); }
;

chip_interface:
    chip_interface OP_TUP chip_interface
  | chip_interface_name OP_TYPE chip_interface_range 
;
  
  chip_interface_name:
    CONSTRUCTOR { context.addFirmwareInterface($1); }
  ;

  chip_interface_range:
    chip_interface_range OP_COMMA chip_interface_range
  | INT OP_ADD INT { context.addFirmwareRange($1, $1+$3); } /* This operation will accept a number of offset bytes */
  | INT OP_SUB INT { context.addFirmwareRange($1, $3); }    /* This operation will accept minimum/maximium bounds  */
  ;


/*
  ===========================

  D.) Xita Driver Grammar

  ===========================
*/
xita_driver:
    driver_header
;

driver_header:
    DRIVER CONSTRUCTOR { printf("Driver Encountered:  %s\n", $2); }
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
  | constructor
  | primitive
  | exp OP_ELEMENT IDENTIFIER
  | IDENTIFIER
;

/*
  F.1) Primitive Expressions
*/
primitive:
    INT
  | REAL
  | TRUE
  | FALSE
  | STRING
  | CHAR
;

/*
  F.2) Arithmetic Expressions
*/
arithmetic:
    exp OP_MUL exp
  | exp OP_DIV exp
  | exp OP_MOD exp
  | exp OP_ADD exp
  | exp OP_SUB exp
;

/*
  F.3) Bitwise Expressions
*/
bitwise:
    BIT_NOT exp
  | exp BIT_XOR exp
  | exp BIT_AND exp
  | exp BIT_OR exp
  | exp BIT_SHL INT
  | exp BIT_SHR INT
;

/*
  F.4) Logical Expressions
*/
logical:
    exp IS IDENTIFIER
  | exp IS CONSTRUCTOR
  | BOOL_NOT exp
  | exp BOOL_AND exp
  | exp BOOL_OR exp
  | exp BOOL_XOR exp
  | exp OP_LT exp
  | exp OP_LTE exp
  | exp OP_GT exp
  | exp OP_GTE exp
  | exp OP_EQ exp
  | exp OP_NEQ exp
  
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
    else_pre exp 
  ;

  else_pre:
    ELSE
  ;


/*
  F.6) Functional Expressions
*/
function:
    IDENTIFIER function_args
;

  function_args:
      primitive function_args
    | primitive
    | IDENTIFIER function_args
    | IDENTIFIER
    | PAR_LEFT exp PAR_RIGHT function_args
    | PAR_LEFT exp PAR_RIGHT
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
  OPEN
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
    CONST CONSTRUCTOR IDENTIFIER OP_ASSIGN exp
;

/*
  2.) Declare Function
*/
decl_function:
    decl_function_pre decl_function_param OP_ASSIGN exp IN exp
  | decl_function_pre OP_ASSIGN exp IN exp
  | decl_function_pre decl_function_param OP_ASSIGN exp
  | decl_function_pre OP_ASSIGN exp
;

  decl_function_pre:
    LET IDENTIFIER
  ;

  decl_function_param:
      decl_function_param IDENTIFIER
    | IDENTIFIER
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

