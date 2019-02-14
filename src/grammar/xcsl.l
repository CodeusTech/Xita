%{
/*
  xcsl.l (AArch64)
  Cody Fagley
  Authored on   January 30, 2019
  Last Modified February 10, 2019
*/

/*
  Contains lexical tokens for use in XCS grammar

  Table of Contents
  =================
  1.) Primitive Data Types
  2.) Syntactic Operators
  3.) Conditional Keywords
  4.) Functional Keywords
  5.) Datatype Keywords
  6.) Special Operations

  A.) Tether Modules 
  B.) Constructors/Identifiers
*/

#include "xcsl.tab.c"
extern int yylex();

#include "string.h"

%}
%option noyywrap
%option yylineno
%%
[ \t\n] ;           // Eliminate Whitespace


%{
/*
  1.) Primitive Types/Constructors
*/
%}


"int" { return INT_T;  }  //  INFERRED INTEGER TYPE
"u8" { return U8_T; }     //  8-Bit UNSIGNED INTEGER TYPE
"U8" { return U8_C; }     //  8-Bit UNSIGNED INTEGER CONSTRUCTOR
"i8" { return I8_T; }     //  8-Bit SIGNED INTEGER TYPE
"I8" { return I8_C; }     //  8-Bit SIGNED INTEGER CONSTRUCTOR
"u16" { return U16_T; }   //  16-Bit UNSIGNED INTEGER TYPE
"U16" { return U16_C; }   //  16-Bit UNSIGNED INTEGER CONSTRUCTOR
"i16" { return I16_T; }   //  16-Bit SIGNED INTEGER TYPE
"I16" { return I16_C; }   //  16-Bit SIGNED INTEGER CONSTRUCTOR
"u32" { return U32_T; }   //  32-Bit UNSIGNED INTEGER TYPE
"U32" { return U32_C; }   //  32-Bit UNSIGNED INTEGER CONSTRUCTOR
"i32" { return I32_T; }   //  32-Bit SIGNED INTEGER TYPE
"I32" { return I32_C; }   //  32-Bit SIGNED INTEGER CONSTRUCTOR
"u64" { return U64_T; }   //  64-Bit UNSIGNED INTEGER TYPE
"U64" { return U64_C; }   //  64-Bit UNSIGNED INTEGER CONSTRUCTOR
"i64" { return I64_T; }   //  64-Bit SIGNED INTEGER TYPE
"I64" { return I64_C; }   //  64-Bit SIGNED INTEGER CONSTRUCTOR

"real" { return REAL_T; }       //  INFERRED REAL NUMBER TYPE
"float" { return FLOAT_T; }     //  FLOATING POINT TYPE
"Float" { return FLOAT_C; }     //  FLOATING POINT CONSTRUCTOR
"double" { return DOUBLE_T; }   //  DOUBLE PRECISION TYPE
"Double" { return DOUBLE_C; }   //  DOUBLE PRECISION CONSTRUCTOR

"char" { return CHAR_T; }  //  CHARACTER TYPE
"Char" { return CHAR_C; }  //  CHARACTER CONSTRUCTOR 
"string" { return STRING_T; }  //  STRING TYPE
"String" { return STRING_C; }  //  STRING CONSTRUCTOR

"bool" { return BOOL_T; }
"True" { return TRUE; }     //  BOOLEAN PRIMITIVE
"False" { return FALSE; }   //  BOOLEAN PRIMITIVE

"RNG" { return RNG; } //  RANDOM NUMBER GENERATOR


%{
/*
  2.) Syntactic Operators
*/
%}

"&&" { return BOOL_AND; } // BOOLEAN AND
"||" { return BOOL_OR;  } // BOOLEAN OR
"^^" { return BOOL_XOR; } // BOOLEAN XOR

"<<" { return BIT_SHL; } // BITWISE SHIFT LEFT
">>" { return BIT_SHR; } // BITWISE SHIFT RIGHT
"&"  { return BIT_AND; } // BITWISE AND
"|"  { return BIT_OR;  } // BITWISE OR
"^"  { return BIT_XOR; } // BITWISE XOR

"*->"   { return MEM_READ; }  //  READ FROM MEMORY
"<-*"   { return MEM_SET; }   //  SET MEMORY

"<-"    { return ARROW_L; }   //  LEFT FACING ARROW
"->"    { return ARROW_R; }   //  RIGHT FACING ARROW

"+" { return OP_ADD; } //  ADDITION OPERATOR
"-" { return OP_SUB; } //  SUBTRACTION OPERATOR  
"*" { return OP_MUL; } //  MULTIPLICATION OPERATOR
"/" { return OP_DIV; } //  DIVISION OPERATOR
"%" { return OP_MOD; } //  MODULUS OPERATOR

"<=" { return OP_LTE; } // LESS THAN OR EQUAL TO
">=" { return OP_GTE; } // GREATER THAN OR EQUAL TO
"==" { return OP_EQ;  } // EXACTLY EQUAL TO
"<"  { return OP_LT;  } // LESS THAN
">"  { return OP_GT;  } // GREATER THAN

"(" { return PAR_LEFT; }  //  LEFT PARENTHESIS
")" { return PAR_RIGHT; } //  RIGHT PARENTHESIS

"="  { return OP_ASSIGN; } //  ASSIGNMENT OPERATOR
";;" { return OP_SEP; }    //  SEPERATOR OPERATOR
";"  { return OP_TUP; }    //  TUPPLE OPERATOR
","  { return OP_COMMA; }  //  COMMA OPERATOR

"["  { return OP_LIST_L; }  //  BEGINNING OF LIST
"]"  { return OP_LIST_R; }  //  END OF LIST

%{
/*
  3.) Conditional Keywords
*/
%}

"if"    {return IF; }
"then"  {return THEN; }
"else"  {return ELSE; }

"match" {return MATCH; }
"with"  {return WITH;  }

%{
/*
  4.) Functional Keywords
*/
%}

"const" { return CONST; }

"let" { return LET; }
"in"  { return IN;  }


%{
/*
  5.) Datatype Keywords
*/  
%}

"type"      { return TYPE;      }
"typeclass" { return TYPECLASS; }

"is"        { return IS;  }
"of"        { return OF;  }
"requires"  { return REQ; }



%{
/*
  6.) Special Operations
*/  
%}

"build"   { return BUILD; }
"run"     { return RUN;   }
"tether"  { return TETHER;}

"send"    { return SEND;    }
"receive" { return RECEIVE; }

"regex"   { return REGEX; }

"load"    { return LOAD; }

%{
/*
  A.) Tether Modules
*/  
%}

"!TETHER\n" { return TETHER_H; }

"offer" { return OFFER; }
"ask"   { return ASK;   }

%{
/*
  B.) Constructors/Identifiers
*/
%}

0[bB][01]+           { yylval.val_int = strtol(yytext, NULL,  2); return INT; } //  BINARY PRIMITIVE
0[oO][0-7]+          { yylval.val_int = strtol(yytext, NULL,  8); return INT; } //  OCTAL PRIMITIVE
0[xX][0-9a-fA-F]+    { yylval.val_int = strtol(yytext, NULL, 16); return INT; } //  HEXADECIMAL PRIMITIVE

[0-9]+            { yylval.val_int = atoi(yytext); return INT; }    //  INTEGER PRIMITIVE
[0-9]+\.[0-9]*    { yylval.val_real = atof(yytext); return REAL; }  //  REAL PRIMITIVE
\'\\[a-zA-Z0-9]\' { yylval.val_char = yytext[2]; return CHAR; }     //  ESCAPED CHARACTER
\'[a-zA-Z0-9]\'   { yylval.val_char =  yytext[1]; return CHAR; }    //  CHARACTER PRIMITIVE
\"(\\.|[^"\\])*\"  { yylval.val_string = strdup(yytext); return STRING; }  //  STRING PRIMITIVE

[A-Z][a-zA-Z0-9_]*\'?   { yylval.val_ident = strdup(yytext); return CONSTRUCTOR; }
[a-z_][a-zA-Z0-9_]*\'?  { yylval.val_ident = strdup(yytext); return IDENTIFIER;  }
