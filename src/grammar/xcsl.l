%{
/*
  xcsl.l (AArch64)
  Cody Fagley
  Authored on   January 30, 2019
  Last Modified January 30, 2019
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
*/

#include "xcsl.tab.c"
extern int yylex();

%}
%option noyywrap
%%
[ \t\n] ;           // Eliminate Whitespace


%{
/*
  1.) Primitive Data Types
*/
%}

[0-9]+              { printf("Found Int: %s\n", yytext); return INT; }       //  INTEGER PRIMITIVE
[0-9]+\.[0-9]*      { printf("Found Real: %s\n", yytext); return REAL; }     //  REAL PRIMITIVE
\'\\?[a-zA-Z0-9]\'  { printf("Found Char: %s\n", yytext); return CHAR; }     //  CHARACTER PRIMITIVE
\"[a-zA-Z0-9]+\"    { printf("Found String: %s\n", yytext); return STRING; } //  STRING PRIMITIVE

"True"  { printf("Found Boolean: %s\n", yytext); return TRUE; }    //  BOOLEAN PRIMITIVE
"False" { printf("Found Boolean: %s\n", yytext); return FALSE; }   //  BOOLEAN PRIMITIVE

%{
/*
  2.) Syntactic Operators
*/
%}

"+" { return OP_ADD; } //  ADDITION OPERATOR
"-" { return OP_SUB; } //  SUBTRACTION OPERATOR  
"*" { return OP_MUL; } //  MULTIPLICATION OPERATOR
"/" { return OP_DIV; } //  DIVISION OPERATOR
"%" { return OP_MOD; } //  MODULUS OPERATOR

"&&" { return BOOL_AND; } // BOOLEAN AND
"||" { return BOOL_OR;  } // BOOLEAN OR
"^^" { return BOOL_XOR; } // BOOLEAN XOR

"<<" { return BIT_SHL; } // BITWISE SHIFT LEFT
">>" { return BIT_SHR; } // BITWISE SHIFT RIGHT
"&"  { return BIT_AND; } // BITWISE AND
"|"  { return BIT_OR;  } // BITWISE OR
"^"  { return BIT_XOR; } // BITWISE XOR

"<=" { return OP_LTE; } // LESS THAN OR EQUAL TO
">=" { return OP_GTE; } // GREATER THAN OR EQUAL TO
"==" { return OP_EQ;  } // EXACTLY EQUAL TO
"<"  { return OP_LT;  } // LESS THAN
">"  { return OP_GT;  } // GREATER THAN

";;" { return OP_SEP; } // SEPERATOR OPERATOR



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

"let" { return LET; }
"in"  { return IN;  }


%{
/*
  5.) Datatype Keywords
*/  
%}

"type"      { return TYPE; }
"typeclass" { return TYPECLASS; }


