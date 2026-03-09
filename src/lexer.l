%{
#include "parser.tab.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
%}

%option noyywrap
%option yylineno

DIGIT      [0-9]
LETTER     [a-zA-Z_]
ID         {LETTER}({LETTER}|{DIGIT})*

%%

[ \t\r]+          ;
\n                ;

"fn"              { return FN; }
"let"             { return LET; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"return"          { return RETURN; }

"i32"             { return TYPE_I32; }
"f64"             { return TYPE_F64; }
"bool"            { return TYPE_BOOL; }
"char"            { return TYPE_CHAR; }
"str"             { return TYPE_STR; }

"->"              { return ARROW; }
":"               { return COLON; }
"="               { return ASSIGN; }

"<="              { return LE; }
">="              { return GE; }
"=="              { return EQ; }
"!="              { return NE; }
"<"               { return LT; }
">"               { return GT; }

"&&"              { return AND; }
"||"              { return OR; }
"!"               { return NOT; }

"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return MULT; }
"/"               { return DIV; }

"{"               { return LBRACE; }
"}"               { return RBRACE; }
"("               { return LPAREN; }
")"               { return RPAREN; }
","               { return COMMA; }
";"               { return SEMICOLON; }

{DIGIT}+          { yylval.ival = atoll(yytext); return INT_LIT; }

{ID}              { yylval.sval = strdup(yytext); return IDENTIFIER; }

.                 { printf("Unknown character at line %d\n", yylineno); }

%%